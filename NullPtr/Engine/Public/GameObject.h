#pragma once
#include "CBase.h"

class Collider;
class GameObject : public CBase
{
protected:
	GameObject();
	virtual ~GameObject();

public:
	virtual void Start();
	virtual void Tick(float deltaTime);
	virtual void LateTick(float deltaTime);

	virtual void OnCollisionStart(weak_ptr<Collider> myCollider, weak_ptr<Collider> otherCollider);
	virtual void OnCollisionStay(weak_ptr<Collider> myCollider, weak_ptr<Collider> otherCollider);
	virtual void OnCollisionExit(weak_ptr<Collider> myCollider, weak_ptr<Collider> otherCollider);

	virtual void OnEnable() {}
	virtual void OnDisable() {}
	virtual void OnDestroy() {}

	virtual void Free() {}

};

