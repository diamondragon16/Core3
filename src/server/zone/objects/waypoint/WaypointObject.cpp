/*
 *	server/zone/objects/waypoint/WaypointObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "WaypointObject.h"

/*
 *	WaypointObjectStub
 */

WaypointObject::WaypointObject(LuaObject* templateData) : IntangibleObject(DummyConstructorParameter::instance()) {
	_impl = new WaypointObjectImplementation(templateData);
	_impl->_setStub(this);
	_impl->_setClassHelper(WaypointObjectHelper::instance());

	((WaypointObjectImplementation*) _impl)->_serializationHelperMethod();
}

WaypointObject::WaypointObject(DummyConstructorParameter* param) : IntangibleObject(param) {
}

WaypointObject::~WaypointObject() {
}

void WaypointObject::changeStatus(bool status) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addBooleanParameter(status);

		method.executeWithVoidReturn();
	} else
		((WaypointObjectImplementation*) _impl)->changeStatus(status);
}

void WaypointObject::switchStatus() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		((WaypointObjectImplementation*) _impl)->switchStatus();
}

bool WaypointObject::getStatus() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithBooleanReturn();
	} else
		return ((WaypointObjectImplementation*) _impl)->getStatus();
}

void WaypointObject::setInternalNote(const String& message) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addAsciiParameter(message);

		method.executeWithVoidReturn();
	} else
		((WaypointObjectImplementation*) _impl)->setInternalNote(message);
}

void WaypointObject::setPlanetName(const String& planet) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addAsciiParameter(planet);

		method.executeWithVoidReturn();
	} else
		((WaypointObjectImplementation*) _impl)->setPlanetName(planet);
}

unsigned int WaypointObject::getPlanetCRC() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((WaypointObjectImplementation*) _impl)->getPlanetCRC();
}

String WaypointObject::getInternalNote() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		method.executeWithAsciiReturn(_return_getInternalNote);
		return _return_getInternalNote;
	} else
		return ((WaypointObjectImplementation*) _impl)->getInternalNote();
}

String WaypointObject::getPlanetName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		method.executeWithAsciiReturn(_return_getPlanetName);
		return _return_getPlanetName;
	} else
		return ((WaypointObjectImplementation*) _impl)->getPlanetName();
}

/*
 *	WaypointObjectImplementation
 */

WaypointObjectImplementation::~WaypointObjectImplementation() {
}

void WaypointObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (WaypointObject*) stub;
	IntangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* WaypointObjectImplementation::_getStub() {
	return _this;
}

WaypointObjectImplementation::operator const WaypointObject*() {
	return _this;
}

void WaypointObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void WaypointObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void WaypointObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void WaypointObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void WaypointObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void WaypointObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void WaypointObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void WaypointObjectImplementation::_serializationHelperMethod() {
	IntangibleObjectImplementation::_serializationHelperMethod();

	addSerializableVariable("internalNote", &internalNote);
	addSerializableVariable("planetName", &planetName);
	addSerializableVariable("active", &active);
}

void WaypointObjectImplementation::changeStatus(bool status) {
	// server/zone/objects/waypoint/WaypointObject.idl(60):  active = status;
	active = status;
}

void WaypointObjectImplementation::switchStatus() {
	// server/zone/objects/waypoint/WaypointObject.idl(64):  
	if (active)	// server/zone/objects/waypoint/WaypointObject.idl(65):  active = false;
	active = false;

	else 	// server/zone/objects/waypoint/WaypointObject.idl(68):  active = true;
	active = true;
}

bool WaypointObjectImplementation::getStatus() {
	// server/zone/objects/waypoint/WaypointObject.idl(72):  return active;
	return active;
}

void WaypointObjectImplementation::setInternalNote(const String& message) {
	// server/zone/objects/waypoint/WaypointObject.idl(76):  internalNote = message;
	internalNote = message;
}

void WaypointObjectImplementation::setPlanetName(const String& planet) {
	// server/zone/objects/waypoint/WaypointObject.idl(80):  planetName = planet;
	planetName = planet;
}

String WaypointObjectImplementation::getInternalNote() {
	// server/zone/objects/waypoint/WaypointObject.idl(86):  return internalNote;
	return internalNote;
}

String WaypointObjectImplementation::getPlanetName() {
	// server/zone/objects/waypoint/WaypointObject.idl(90):  return planetName;
	return planetName;
}

/*
 *	WaypointObjectAdapter
 */

WaypointObjectAdapter::WaypointObjectAdapter(WaypointObjectImplementation* obj) : IntangibleObjectAdapter(obj) {
}

Packet* WaypointObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		changeStatus(inv->getBooleanParameter());
		break;
	case 7:
		switchStatus();
		break;
	case 8:
		resp->insertBoolean(getStatus());
		break;
	case 9:
		setInternalNote(inv->getAsciiParameter(_param0_setInternalNote__String_));
		break;
	case 10:
		setPlanetName(inv->getAsciiParameter(_param0_setPlanetName__String_));
		break;
	case 11:
		resp->insertInt(getPlanetCRC());
		break;
	case 12:
		resp->insertAscii(getInternalNote());
		break;
	case 13:
		resp->insertAscii(getPlanetName());
		break;
	default:
		return NULL;
	}

	return resp;
}

void WaypointObjectAdapter::changeStatus(bool status) {
	((WaypointObjectImplementation*) impl)->changeStatus(status);
}

void WaypointObjectAdapter::switchStatus() {
	((WaypointObjectImplementation*) impl)->switchStatus();
}

bool WaypointObjectAdapter::getStatus() {
	return ((WaypointObjectImplementation*) impl)->getStatus();
}

void WaypointObjectAdapter::setInternalNote(const String& message) {
	((WaypointObjectImplementation*) impl)->setInternalNote(message);
}

void WaypointObjectAdapter::setPlanetName(const String& planet) {
	((WaypointObjectImplementation*) impl)->setPlanetName(planet);
}

unsigned int WaypointObjectAdapter::getPlanetCRC() {
	return ((WaypointObjectImplementation*) impl)->getPlanetCRC();
}

String WaypointObjectAdapter::getInternalNote() {
	return ((WaypointObjectImplementation*) impl)->getInternalNote();
}

String WaypointObjectAdapter::getPlanetName() {
	return ((WaypointObjectImplementation*) impl)->getPlanetName();
}

/*
 *	WaypointObjectHelper
 */

WaypointObjectHelper* WaypointObjectHelper::staticInitializer = WaypointObjectHelper::instance();

WaypointObjectHelper::WaypointObjectHelper() {
	className = "WaypointObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void WaypointObjectHelper::finalizeHelper() {
	WaypointObjectHelper::finalize();
}

DistributedObject* WaypointObjectHelper::instantiateObject() {
	return new WaypointObject(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* WaypointObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new WaypointObjectAdapter((WaypointObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

