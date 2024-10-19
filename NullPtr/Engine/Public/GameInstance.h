#pragma once
#include "CBase.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
class GameInstance : public CBase
{
	DECLARE_SINGLETON(GameInstance)

public:
	void Initial_Engine();
	void Tick_Engine(float deltaTime);
	void Render_Engine();

	void Destroy_Engine();

	virtual void Free() override;

private:
	shared_ptr<ObjectManager> objectManager;
	shared_ptr<CollisionManager> collisionManager;
};

