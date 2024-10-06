#pragma once
#include "CBase.h"

class GameInstance final : public CBase
{
	DECLARE_SINGLETON(GameInstance)

public:
	void Initial_Engine();
	void Tick_Engine();
	void Render_Engine();

	void Destroy_Engine();
};

