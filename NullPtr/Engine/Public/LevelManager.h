#pragma once
#include "CBase.h"

class Level;
class LevelManager : public CBase
{
	DECLARE_SINGLETON(LevelManager)
public:
	HRESULT OpenLevel(unsigned int levelID, shared_ptr<Level> level);
	weak_ptr<Level> Get_CurrentLevel();
	void Tick(float deltaTime);

	virtual void OnDestroy() override;
	void Free();
private:
	shared_ptr<class Level> currentLevel;
	unsigned int currentLevelID;
};

