/*
 * LootkitObjectImplementation.cpp
 *
 *  Created on: Apr 12, 2010
 *      Author: swgemu
 */

#include "server/zone/objects/tangible/loot/LootkitObject.h"
#include "server/zone/objects/tangible/TangibleObject.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/packets/scene/AttributeListMessage.h"
#include "server/zone/objects/scene/variables/CustomizationVariables.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/ZoneProcessServer.h"
#include "server/zone/templates/tangible/LootkitObjectTemplate.h"

void LootkitObjectImplementation::fillAttributeList(AttributeListMessage* alm, CreatureObject* object) {
	TangibleObjectImplementation::fillAttributeList(alm,object);

	const String boolean[] = {"No","Yes"};

	StringBuffer componentAttributes;
	for (int i=0; i<attributes.size();++i) {
		componentAttributes << boolean[components.get(comps.get(i))];
		alm->insertAttribute(attributes.get(comps.get(i)), componentAttributes);
		componentAttributes.deleteAll();
	}
}

void LootkitObjectImplementation::loadTemplateData(SharedObjectTemplate* templateData) {
	TangibleObjectImplementation::loadTemplateData(templateData);

	LootkitObjectTemplate* LootkitData = dynamic_cast<LootkitObjectTemplate*>(templateData);

	components = LootkitData->getComponents();
	attributes = LootkitData->getAttributes();

	comps = LootkitData->getComps();
	reward = LootkitData->getReward();

	deleteComponents = LootkitData->getDeleteComponents();
}

Reference<CreatureObject*> LootkitObjectImplementation::getPlayer() {
	ManagedReference<CreatureObject*> strong = getParentRecursively(SceneObjectType::PLAYERCREATURE).castTo<CreatureObject*>();
	return strong.get();
}

int LootkitObjectImplementation::notifyObjectInserted(SceneObject* object) {
	addToKit(object);
	return 0;
}

int LootkitObjectImplementation::notifyObjectRemoved(SceneObject* object) {
	removeFromKit(object);
	return 0;
}

void LootkitObjectImplementation::addToKit(SceneObject* object) {
	uint32 crc = object->getServerObjectCRC();
	if (components.contains(crc)) {

		if (hasObjectInContainer(object->getObjectID())) {

			if (deleteComponents) {
				ManagedReference<CreatureObject*> player = getPlayer();
				if (player == NULL)
					return;

				Locker locker(object);

				player->sendSystemMessage("@loot_kit:item_used"); // The kit accepts the item and quickly disassembles it, leaving nothing recognizable behind.

				object->destroyObjectFromWorld(true);

				if (object->isPersistent())
					object->destroyObjectFromDatabase(true);
			}

			components.drop(crc);
			components.put(crc,true);

			createItem();
		}
	}
}
void LootkitObjectImplementation::removeFromKit(SceneObject* object) {
	uint32 crc = object->getServerObjectCRC();
	if (!deleteComponents && components.contains(crc)) {
		components.drop(crc);
		components.put(crc,false);
	}
}

void LootkitObjectImplementation::createItem() {
	for (int i = 0; i<comps.size(); ++i) {
		if (components.get(comps.get(i)) == 0) {
			return; // Still missing pieces
		}
	}
	ManagedReference<CreatureObject*>  player = getPlayer();
	if (player != NULL) {

		ManagedReference<SceneObject*> inventory = player->getSlottedObject("inventory");

		if (inventory == NULL) {
			return;
		}

		ZoneServer* zoneServer = server->getZoneServer();

		ManagedReference<SceneObject*> rewardObject = zoneServer->createObject(reward.get(System::random(reward.size()-1)), 2);

		if (rewardObject == NULL) {
			return;
		}

		if (inventory->transferObject(rewardObject, -1, true)) {
			rewardObject->sendTo(player, true);
			destroyObjectFromWorld(true);

			if (isPersistent())
				destroyObjectFromDatabase(true);

			player->sendSystemMessage("@loot_kit:new_item_created"); // A new item was created, but it seems that the kit was destroyed in the process.

		} else {
			rewardObject->destroyObjectFromDatabase(true);
		}
	}
}

int LootkitObjectImplementation::canAddObject(SceneObject* object, int containmentType, String& errorDescription) {
	ManagedReference<CreatureObject*>  player = getPlayer();
	if (components.contains(object->getServerObjectCRC())) {
		if (!components.get(object->getServerObjectCRC()) && player != NULL) {
			ManagedReference<SceneObject*> inventory = player->getSlottedObject("inventory");

			if (inventory->hasFullContainerObjects()) {
				errorDescription = "@error_message:inv_full";
				return 5;
			}

			return TangibleObjectImplementation::canAddObject(object, containmentType, errorDescription);

		} else {

			if (player != NULL) {
				errorDescription = "@loot_kit:already_contains"; // That item is already contained by this kit.
			}

			return 5;
		}
	}

	if (player != NULL) {
		errorDescription = "@loot_kit:incorrect_item"; // The kit examines the item and rejects it. This kit will only accept items that are compatible with its design. For a list of what items this kit will accept examine it by using its radial menu.
	}

	return 5;
}
