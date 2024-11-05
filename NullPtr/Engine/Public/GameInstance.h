#pragma once
#include "CBase.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "LevelManager.h"

class GameInstance : public CBase
{
	DECLARE_SINGLETON(GameInstance)

public:
	void Initial_Engine();
	void Tick_Engine(float deltaTime);
	void Render_Engine();

	void LevelEnter();
	void LevelExit();

	void Destroy_Engine();

	void Free();

private:
	shared_ptr<ObjectManager> objectManager;
	shared_ptr<CollisionManager> collisionManager;
	shared_ptr<LevelManager> levelManager;
};

