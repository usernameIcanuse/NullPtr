#include "Component.h"

Component::Component()
{
}

Component::~Component()
{
}

void Component::OnEnable()
{
}

void Component::OnDisable()
{
}

void Component::OnDestroy()
{
}

void Component::Free()
{
}

weak_ptr<GameObject> Component::Get_OwnerObject()
{
	return ownerObject;
}

void Component::Set_Owner(weak_ptr<GameObject> owner)
{
	ownerObject = owner;
}
