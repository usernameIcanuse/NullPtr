#include "CollisionManager.h"
#include "Collider.h"

void CollisionManager::Tick(float deltaTime)
{
	for (int i = 0; i < tagCheck.size(); ++i)
	{
		for (int j = i; j < tagCheck.size(); ++j)
		{
			if (tagCheck[i] & (1 << j))
			{
				Update_CollisionGroup(i, j);
			}
		}
	}
}

void CollisionManager::Update_CollisionGroup(const int leftLayer, const int rightLayer)
{
	for (auto& elem_left : colliderList[leftLayer])
	{
		for (auto& elem_right : colliderList[rightLayer])
		{
			if (!elem_right.lock().get() || !elem_left.lock().get())
			{
				//비어잇는 경우
			}

			if (elem_right.lock().get() == elem_left.lock().get())
			{
				continue;
			}

			if (Is_Collided(elem_left, elem_right))
			{
				elem_left.lock()->OnCollisionStay(elem_right);
				elem_right.lock()->OnCollisionStay(elem_left);
			}
		}
	}
}

bool CollisionManager::Is_Collided(weak_ptr<Collider> leftCollider, weak_ptr<Collider> rightCollider)
{
	return false;
}
