#pragma once
#include "CBase.h"
#include "ObjectManager.h"

class GameInstance : public CBase
{
	DECLARE_SINGLETON(GameInstance)

public:
	void Initial_Engine();
	void Tick_Engine();
	void Render_Engine();

	void Destroy_Engine();

	virtual void Free() override;
};

