/*
 *	server/zone/objects/draftschematic/DraftSchematic.cpp generated by engine3 IDL compiler 0.60
 */

#include "DraftSchematic.h"

/*
 *	DraftSchematicStub
 */

DraftSchematic::DraftSchematic() : IntangibleObject(DummyConstructorParameter::instance()) {
	_impl = new DraftSchematicImplementation();
	_impl->_setStub(this);
}

DraftSchematic::DraftSchematic(DummyConstructorParameter* param) : IntangibleObject(param) {
}

DraftSchematic::~DraftSchematic() {
}


void DraftSchematic::initializeTransientMembers() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->initializeTransientMembers();
}

void DraftSchematic::loadTemplateData(SharedObjectTemplate* templateData) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((DraftSchematicImplementation*) _impl)->loadTemplateData(templateData);
}

void DraftSchematic::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((DraftSchematicImplementation*) _impl)->fillAttributeList(msg, object);
}

void DraftSchematic::sendBaselinesTo(SceneObject* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->sendBaselinesTo(player);
}

void DraftSchematic::sendDraftSlotsTo(PlayerCreature* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->sendDraftSlotsTo(player);
}

void DraftSchematic::sendResourceWeightsTo(PlayerCreature* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->sendResourceWeightsTo(player);
}

SceneObject* DraftSchematic::createManufactureSchematic() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return (SceneObject*) method.executeWithObjectReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->createManufactureSchematic();
}

void DraftSchematic::setSchematicID(unsigned int id) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addUnsignedIntParameter(id);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setSchematicID(id);
}

unsigned int DraftSchematic::getSchematicID() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getSchematicID();
}

int DraftSchematic::getDraftSlotCount() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getDraftSlotCount();
}

DraftSlot* DraftSchematic::getDraftSlot(int i) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((DraftSchematicImplementation*) _impl)->getDraftSlot(i);
}

int DraftSchematic::getResourceWeightCount() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getResourceWeightCount();
}

ResourceWeight* DraftSchematic::getResourceWeight(int i) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((DraftSchematicImplementation*) _impl)->getResourceWeight(i);
}

float DraftSchematic::getComplexity() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		return method.executeWithFloatReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getComplexity();
}

unsigned int DraftSchematic::getToolTab() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getToolTab();
}

float DraftSchematic::getSize() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		return method.executeWithFloatReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getSize();
}

String DraftSchematic::getXpType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		method.executeWithAsciiReturn(_return_getXpType);
		return _return_getXpType;
	} else
		return ((DraftSchematicImplementation*) _impl)->getXpType();
}

int DraftSchematic::getXpAmount() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getXpAmount();
}

String DraftSchematic::getAssemblySkill() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);

		method.executeWithAsciiReturn(_return_getAssemblySkill);
		return _return_getAssemblySkill;
	} else
		return ((DraftSchematicImplementation*) _impl)->getAssemblySkill();
}

String DraftSchematic::getExperimentationSkill() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);

		method.executeWithAsciiReturn(_return_getExperimentationSkill);
		return _return_getExperimentationSkill;
	} else
		return ((DraftSchematicImplementation*) _impl)->getExperimentationSkill();
}

String DraftSchematic::getCustomizationSkill() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);

		method.executeWithAsciiReturn(_return_getCustomizationSkill);
		return _return_getCustomizationSkill;
	} else
		return ((DraftSchematicImplementation*) _impl)->getCustomizationSkill();
}

String DraftSchematic::getCustomName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);

		method.executeWithAsciiReturn(_return_getCustomName);
		return _return_getCustomName;
	} else
		return ((DraftSchematicImplementation*) _impl)->getCustomName();
}

unsigned int DraftSchematic::getTanoCRC() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getTanoCRC();
}

String DraftSchematic::getGroupName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);

		method.executeWithAsciiReturn(_return_getGroupName);
		return _return_getGroupName;
	} else
		return ((DraftSchematicImplementation*) _impl)->getGroupName();
}

/*
 *	DraftSchematicImplementation
 */

DraftSchematicImplementation::DraftSchematicImplementation(DummyConstructorParameter* param) : IntangibleObjectImplementation(param) {
	_initializeImplementation();
}

DraftSchematicImplementation::~DraftSchematicImplementation() {
}


void DraftSchematicImplementation::finalize() {
}

void DraftSchematicImplementation::_initializeImplementation() {
	_setClassHelper(DraftSchematicHelper::instance());

	_serializationHelperMethod();
}

void DraftSchematicImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (DraftSchematic*) stub;
	IntangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* DraftSchematicImplementation::_getStub() {
	return _this;
}

DraftSchematicImplementation::operator const DraftSchematic*() {
	return _this;
}

void DraftSchematicImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void DraftSchematicImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void DraftSchematicImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void DraftSchematicImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void DraftSchematicImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void DraftSchematicImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void DraftSchematicImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void DraftSchematicImplementation::_serializationHelperMethod() {
	IntangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("DraftSchematic");

	addSerializableVariable("schematicID", &schematicID);
}

DraftSchematicImplementation::DraftSchematicImplementation() {
	_initializeImplementation();
	// server/zone/objects/draftschematic/DraftSchematic.idl(68):  		Logger.setLoggingName("DraftSchematic");
	Logger::setLoggingName("DraftSchematic");
}

void DraftSchematicImplementation::setSchematicID(unsigned int id) {
	// server/zone/objects/draftschematic/DraftSchematic.idl(126):  		schematicID = id;
	schematicID = id;
}

unsigned int DraftSchematicImplementation::getSchematicID() {
	// server/zone/objects/draftschematic/DraftSchematic.idl(134):  		return schematicID;
	return schematicID;
}

/*
 *	DraftSchematicAdapter
 */

DraftSchematicAdapter::DraftSchematicAdapter(DraftSchematicImplementation* obj) : IntangibleObjectAdapter(obj) {
}

Packet* DraftSchematicAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	case 7:
		sendBaselinesTo((SceneObject*) inv->getObjectParameter());
		break;
	case 8:
		sendDraftSlotsTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 9:
		sendResourceWeightsTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 10:
		resp->insertLong(createManufactureSchematic()->_getObjectID());
		break;
	case 11:
		setSchematicID(inv->getUnsignedIntParameter());
		break;
	case 12:
		resp->insertInt(getSchematicID());
		break;
	case 13:
		resp->insertSignedInt(getDraftSlotCount());
		break;
	case 14:
		resp->insertSignedInt(getResourceWeightCount());
		break;
	case 15:
		resp->insertFloat(getComplexity());
		break;
	case 16:
		resp->insertInt(getToolTab());
		break;
	case 17:
		resp->insertFloat(getSize());
		break;
	case 18:
		resp->insertAscii(getXpType());
		break;
	case 19:
		resp->insertSignedInt(getXpAmount());
		break;
	case 20:
		resp->insertAscii(getAssemblySkill());
		break;
	case 21:
		resp->insertAscii(getExperimentationSkill());
		break;
	case 22:
		resp->insertAscii(getCustomizationSkill());
		break;
	case 23:
		resp->insertAscii(getCustomName());
		break;
	case 24:
		resp->insertInt(getTanoCRC());
		break;
	case 25:
		resp->insertAscii(getGroupName());
		break;
	default:
		return NULL;
	}

	return resp;
}

void DraftSchematicAdapter::initializeTransientMembers() {
	((DraftSchematicImplementation*) impl)->initializeTransientMembers();
}

void DraftSchematicAdapter::sendBaselinesTo(SceneObject* player) {
	((DraftSchematicImplementation*) impl)->sendBaselinesTo(player);
}

void DraftSchematicAdapter::sendDraftSlotsTo(PlayerCreature* player) {
	((DraftSchematicImplementation*) impl)->sendDraftSlotsTo(player);
}

void DraftSchematicAdapter::sendResourceWeightsTo(PlayerCreature* player) {
	((DraftSchematicImplementation*) impl)->sendResourceWeightsTo(player);
}

SceneObject* DraftSchematicAdapter::createManufactureSchematic() {
	return ((DraftSchematicImplementation*) impl)->createManufactureSchematic();
}

void DraftSchematicAdapter::setSchematicID(unsigned int id) {
	((DraftSchematicImplementation*) impl)->setSchematicID(id);
}

unsigned int DraftSchematicAdapter::getSchematicID() {
	return ((DraftSchematicImplementation*) impl)->getSchematicID();
}

int DraftSchematicAdapter::getDraftSlotCount() {
	return ((DraftSchematicImplementation*) impl)->getDraftSlotCount();
}

int DraftSchematicAdapter::getResourceWeightCount() {
	return ((DraftSchematicImplementation*) impl)->getResourceWeightCount();
}

float DraftSchematicAdapter::getComplexity() {
	return ((DraftSchematicImplementation*) impl)->getComplexity();
}

unsigned int DraftSchematicAdapter::getToolTab() {
	return ((DraftSchematicImplementation*) impl)->getToolTab();
}

float DraftSchematicAdapter::getSize() {
	return ((DraftSchematicImplementation*) impl)->getSize();
}

String DraftSchematicAdapter::getXpType() {
	return ((DraftSchematicImplementation*) impl)->getXpType();
}

int DraftSchematicAdapter::getXpAmount() {
	return ((DraftSchematicImplementation*) impl)->getXpAmount();
}

String DraftSchematicAdapter::getAssemblySkill() {
	return ((DraftSchematicImplementation*) impl)->getAssemblySkill();
}

String DraftSchematicAdapter::getExperimentationSkill() {
	return ((DraftSchematicImplementation*) impl)->getExperimentationSkill();
}

String DraftSchematicAdapter::getCustomizationSkill() {
	return ((DraftSchematicImplementation*) impl)->getCustomizationSkill();
}

String DraftSchematicAdapter::getCustomName() {
	return ((DraftSchematicImplementation*) impl)->getCustomName();
}

unsigned int DraftSchematicAdapter::getTanoCRC() {
	return ((DraftSchematicImplementation*) impl)->getTanoCRC();
}

String DraftSchematicAdapter::getGroupName() {
	return ((DraftSchematicImplementation*) impl)->getGroupName();
}

/*
 *	DraftSchematicHelper
 */

DraftSchematicHelper* DraftSchematicHelper::staticInitializer = DraftSchematicHelper::instance();

DraftSchematicHelper::DraftSchematicHelper() {
	className = "DraftSchematic";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void DraftSchematicHelper::finalizeHelper() {
	DraftSchematicHelper::finalize();
}

DistributedObject* DraftSchematicHelper::instantiateObject() {
	return new DraftSchematic(DummyConstructorParameter::instance());
}

DistributedObjectServant* DraftSchematicHelper::instantiateServant() {
	return new DraftSchematicImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* DraftSchematicHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DraftSchematicAdapter((DraftSchematicImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

