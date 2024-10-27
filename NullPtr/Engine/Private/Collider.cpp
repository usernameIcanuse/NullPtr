#include "Collider.h"
#include "GameObject.h"

unsigned int Collider::assignedColliderIndex = 0;

Collider::Collider()
{
}

Collider::~Collider()
{
}

void Collider::OnCollision(weak_ptr<Collider> otherCollider, bool isCollided)
{
	auto iter = find_if(preOtherColliderList.begin(),
		preOtherColliderList.end(),
		[&](weak_ptr<Collider> preOtherCollider)
		{
			if (!preOtherCollider.lock().get() || otherCollider.lock().get())
			{
				return false;
			}
			
			return preOtherCollider.lock()->Get_ColliderIndex() == otherCollider.lock()->Get_ColliderIndex();
		});

	if (iter == preOtherColliderList.end())
	{
		if (isCollided)
		{
			CollisionStart(otherCollider);
			preOtherColliderList.push_back(otherCollider);
		}
	}
	else
	{
		if (isCollided)
		{
			CollisionStay(otherCollider);
		}
		else
		{
			CollisionExit(otherCollider);
			preOtherColliderList.erase(iter);
		}
	}
}

unsigned int Collider::Get_ColliderIndex() const
{
	return colliderIndex;
}

void Collider::CollisionStart(weak_ptr<Collider> otherCollider)
{
	ownerObject.lock()->OnCollisionStart(weakThisCollider, otherCollider);
}

void Collider::CollisionStay(weak_ptr<Collider> otherCollider)
{
	ownerObject.lock()->OnCollisionStay(weakThisCollider, otherCollider);
}

void Collider::CollisionExit(weak_ptr<Collider> otherCollider)
{
	ownerObject.lock()->OnCollisionExit(weakThisCollider, otherCollider);
}

shared_ptr<Collider> Collider::Create()
{
	shared_ptr<Collider> instance = make_shared<Collider>();
	instance->weakThis = instance;
	instance->Initialize();

	return instance;
}

HRESULT Collider::Initialize()
{
	weakThisCollider = static_pointer_cast<Collider>(weakThis.lock());
	colliderIndex = assignedColliderIndex++;

	return S_OK;
}

void Collider::OnEnable()
{
}

void Collider::OnDisable()
{
}

void Collider::OnDestroy()
{
}

void Collider::Free()
{
}
