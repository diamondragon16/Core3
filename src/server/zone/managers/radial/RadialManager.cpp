/*
 *	server/zone/managers/radial/RadialManager.cpp generated by engine3 IDL compiler 0.60
 */

#include "RadialManager.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

/*
 *	RadialManagerStub
 */

RadialManager::RadialManager(ZoneServer* server) : ManagedObject(DummyConstructorParameter::instance()) {
	_impl = new RadialManagerImplementation(server);
	_impl->_setStub(this);
	_impl->_setClassHelper(RadialManagerHelper::instance());

	((RadialManagerImplementation*) _impl)->_serializationHelperMethod();
}

RadialManager::RadialManager(DummyConstructorParameter* param) : ManagedObject(param) {
}

RadialManager::~RadialManager() {
}

void RadialManager::handleObjectMenuSelect(PlayerCreature* player, byte selectID, unsigned long long objectID) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);
		method.addByteParameter(selectID);
		method.addUnsignedLongParameter(objectID);

		method.executeWithVoidReturn();
	} else
		((RadialManagerImplementation*) _impl)->handleObjectMenuSelect(player, selectID, objectID);
}

void RadialManager::handleObjectMenuRequest(PlayerCreature* player, ObjectMenuResponse* defaultMenuResponse, unsigned long long objectID) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);
		method.addObjectParameter(defaultMenuResponse);
		method.addUnsignedLongParameter(objectID);

		method.executeWithVoidReturn();
	} else
		((RadialManagerImplementation*) _impl)->handleObjectMenuRequest(player, defaultMenuResponse, objectID);
}

void RadialManager::handleUseObject(PlayerCreature* player, SceneObject* object) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);
		method.addObjectParameter(object);

		method.executeWithVoidReturn();
	} else
		((RadialManagerImplementation*) _impl)->handleUseObject(player, object);
}

/*
 *	RadialManagerImplementation
 */

RadialManagerImplementation::~RadialManagerImplementation() {
}

void RadialManagerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (RadialManager*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* RadialManagerImplementation::_getStub() {
	return _this;
}

RadialManagerImplementation::operator const RadialManager*() {
	return _this;
}

void RadialManagerImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void RadialManagerImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void RadialManagerImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void RadialManagerImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void RadialManagerImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void RadialManagerImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void RadialManagerImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void RadialManagerImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	addSerializableVariable("zoneServer", &zoneServer);
}

/*
 *	RadialManagerAdapter
 */

RadialManagerAdapter::RadialManagerAdapter(RadialManagerImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* RadialManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter(), inv->getUnsignedLongParameter());
		break;
	case 7:
		handleObjectMenuRequest((PlayerCreature*) inv->getObjectParameter(), (ObjectMenuResponse*) inv->getObjectParameter(), inv->getUnsignedLongParameter());
		break;
	case 8:
		handleUseObject((PlayerCreature*) inv->getObjectParameter(), (SceneObject*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void RadialManagerAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectID, unsigned long long objectID) {
	((RadialManagerImplementation*) impl)->handleObjectMenuSelect(player, selectID, objectID);
}

void RadialManagerAdapter::handleObjectMenuRequest(PlayerCreature* player, ObjectMenuResponse* defaultMenuResponse, unsigned long long objectID) {
	((RadialManagerImplementation*) impl)->handleObjectMenuRequest(player, defaultMenuResponse, objectID);
}

void RadialManagerAdapter::handleUseObject(PlayerCreature* player, SceneObject* object) {
	((RadialManagerImplementation*) impl)->handleUseObject(player, object);
}

/*
 *	RadialManagerHelper
 */

RadialManagerHelper* RadialManagerHelper::staticInitializer = RadialManagerHelper::instance();

RadialManagerHelper::RadialManagerHelper() {
	className = "RadialManager";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void RadialManagerHelper::finalizeHelper() {
	RadialManagerHelper::finalize();
}

DistributedObject* RadialManagerHelper::instantiateObject() {
	return new RadialManager(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* RadialManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new RadialManagerAdapter((RadialManagerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

