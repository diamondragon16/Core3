/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef OBJECTMANAGER_H_
#define OBJECTMANAGER_H_

#include "engine/engine.h"

#include "ObjectMap.h"

#include "server/zone/ZoneProcessServer.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "SceneObjectFactory.h"

class TemplateManager;
class UpdateModifiedObjectsThread;
class DeleteCharactersTask;

namespace engine {
namespace db {
namespace berkley {
	class Transaction;
}
}
}

namespace server {
namespace zone {

	namespace managers {
	namespace object {

	class ObjectManager : public DOBObjectManager, public Singleton<ObjectManager>, public Object {
		ManagedReference<ZoneProcessServer*> server;

		TemplateManager* templateManager;

		int galaxyId;
		Reference<ResultSet*> charactersSaved;

		AtomicInteger saveCounter;

		Reference<DeleteCharactersTask*> deleteCharactersTask;
		
		static uint32 serverObjectCrcHashCode;
		static uint32 _classNameHashCode;

	public:
		SceneObjectFactory<SceneObject* (), uint32> objectFactory;

	private:
		/**
		 * Loads the highest object id without the highest 16 bits that specify the table.
		 */
		void loadLastUsedObjectID();

		void registerObjectTypes();
		SceneObject* loadObjectFromTemplate(uint32 objectCRC);
		void deSerializeObject(ManagedObject* object, ObjectInputStream* data);

		SceneObject* instantiateSceneObject(uint32 objectCRC, uint64 oid, bool createComponents);

		//ManagedObject* cloneManagedObject(ManagedObject* object, bool makeTransient = false);


	public:
		ObjectManager();
		~ObjectManager();

		bool contains(uint32 objectCRC) {
			return objectFactory.containsObject(objectCRC);
		}

		void loadStaticObjects();

		// object methods
		SceneObject* createObject(uint32 objectCRC, int persistenceLevel, const String& database, uint64 oid = 0);

		ManagedObject* createObject(const String& className, int persistenceLevel, const String& database, uint64 oid = 0, bool initializeTransientMembers = true);

		void createObjectID(const String& name, DistributedObjectStub* object);

		/**
		 * Returns a clone of the passed object with new object id
		 * if the passed object is persistent, the new object will be too
		 */
		SceneObject* cloneObject(SceneObject* object, bool makeTransient = false);

		/**
		 * Assigns a new persistent object id, stores in the specified database
		 */
		void persistObject(ManagedObject* object, int persistenceLevel, const String& database);

		// persists a sceneObject and all of it's child, slotted, and container objects, recursively
		void persistSceneObjectsRecursively(SceneObject* object, int persistenceLevel);

		void printInfo();
		String getInfo();

		Reference<DistributedObjectStub*> loadPersistentObject(uint64 objectID);
		int updatePersistentObject(DistributedObject* object);
		int destroyObjectFromDatabase(uint64 objectID);

		uint64 getNextObjectID(const String& database);

		uint64 getNextFreeObjectID();

		void onUpdateModifiedObjectsToDatabase();

		void onCommitData();

		ObjectDatabase* loadTable(const String& database, uint64 objectID = 0);

		void updateObjectVersion();

		inline void setZoneProcessor(ZoneProcessServer* srv) {
			server = srv;
		}

	};

}
}
}
}

using namespace server::zone::managers::object;

#endif /*OBJECTMANAGER_H_*/
