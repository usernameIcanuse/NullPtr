#pragma once
#include "Component.h"

class Collider : public Component
{
public:
	Collider();
	virtual ~Collider();

public:
	void OnCollision(weak_ptr<Collider> otherCollider, bool isCollided);
	unsigned int Get_ColliderIndex() const;

	void CollisionStart(weak_ptr<Collider> otherCollider);
	void CollisionStay(weak_ptr<Collider> otherCollider);
	void CollisionExit(weak_ptr<Collider> otherCollider);

public:
	virtual HRESULT Initialize();
	virtual void OnEnable() override;
	virtual void OnDisable() override;
	virtual void OnDestroy() override;

	virtual void Free() override;

private:
	list<weak_ptr<Collider>> preOtherColliderList;
	weak_ptr<Collider> weakThisCollider;
	unsigned int colliderIndex;
};

