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

			bool isCollided = Is_Collided(elem_left, elem_right);
			elem_left.lock()->OnCollision(elem_right, isCollided);
			elem_right.lock()->OnCollision(elem_left, isCollided);
		}
	}
}

bool CollisionManager::Is_Collided(weak_ptr<Collider> leftCollider, weak_ptr<Collider> rightCollider)
{
	return false;
}
