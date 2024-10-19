#pragma once
#include "Component.h"

class Collider : public Component
{
public:
	Collider();
	virtual ~Collider();

public:
	virtual void OnCollisionStart(weak_ptr<Collider> otherCollider);
	virtual void OnCollisionStay(weak_ptr<Collider> otherCollider);
	virtual void OnCollisionExit(weak_ptr<Collider> otheCollider);

public:
	virtual void OnEnable() override;
	virtual void OnDisable() override;
	virtual void OnDestroy() override;

	virtual void Free() override;
};

