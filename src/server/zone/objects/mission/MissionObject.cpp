/*
 *	server/zone/objects/mission/MissionObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "MissionObject.h"

/*
 *	MissionObjectStub
 */

MissionObject::MissionObject(LuaObject* templateData) : SceneObject(DummyConstructorParameter::instance()) {
	_impl = new MissionObjectImplementation(templateData);
	_impl->_setStub(this);
	_impl->_setClassHelper(MissionObjectHelper::instance());

	((MissionObjectImplementation*) _impl)->_serializationHelperMethod();
}

MissionObject::MissionObject(DummyConstructorParameter* param) : SceneObject(param) {
}

MissionObject::~MissionObject() {
}

void MissionObject::sendBaselinesTo(SceneObject* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((MissionObjectImplementation*) _impl)->sendBaselinesTo(player);
}

/*
 *	MissionObjectImplementation
 */

MissionObjectImplementation::~MissionObjectImplementation() {
}

void MissionObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (MissionObject*) stub;
	SceneObjectImplementation::_setStub(stub);
}

DistributedObjectStub* MissionObjectImplementation::_getStub() {
	return _this;
}

MissionObjectImplementation::operator const MissionObject*() {
	return _this;
}

void MissionObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void MissionObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void MissionObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void MissionObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void MissionObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void MissionObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void MissionObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void MissionObjectImplementation::_serializationHelperMethod() {
	SceneObjectImplementation::_serializationHelperMethod();

}

/*
 *	MissionObjectAdapter
 */

MissionObjectAdapter::MissionObjectAdapter(MissionObjectImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* MissionObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendBaselinesTo((SceneObject*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void MissionObjectAdapter::sendBaselinesTo(SceneObject* player) {
	((MissionObjectImplementation*) impl)->sendBaselinesTo(player);
}

/*
 *	MissionObjectHelper
 */

MissionObjectHelper* MissionObjectHelper::staticInitializer = MissionObjectHelper::instance();

MissionObjectHelper::MissionObjectHelper() {
	className = "MissionObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void MissionObjectHelper::finalizeHelper() {
	MissionObjectHelper::finalize();
}

DistributedObject* MissionObjectHelper::instantiateObject() {
	return new MissionObject(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* MissionObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new MissionObjectAdapter((MissionObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

