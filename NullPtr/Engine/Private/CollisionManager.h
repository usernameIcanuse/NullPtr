#pragma once
#include "CBase.h"

class Collider;
class CollisionManager : public CBase
{
	DECLARE_SINGLETON(CollisionManager)
public:
	void Tick(float deltaTime);

private:
	void Update_CollisionGroup(const int leftLayer, const int rightLayer);
	bool Is_Collided(weak_ptr<Collider> leftCollider, weak_ptr<Collider> rightCollider);

private:
	vector<list<weak_ptr<Collider>>> colliderList;
	vector<int> tagCheck;
};

