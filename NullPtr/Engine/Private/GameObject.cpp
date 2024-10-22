#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Start()
{
}

void GameObject::Tick(float deltaTime)
{
}

void GameObject::LateTick(float deltaTime)
{
}

void GameObject::OnCollisionStart(weak_ptr<Collider> myCollider, weak_ptr<Collider> otherCollider)
{
}

void GameObject::OnCollisionStay(weak_ptr<Collider> myCollider, weak_ptr<Collider> otherCollider)
{
}

void GameObject::OnCollisionExit(weak_ptr<Collider> myCollider, weak_ptr<Collider> otherCollider)
{
}
