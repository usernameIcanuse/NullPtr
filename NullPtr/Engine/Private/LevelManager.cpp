#include "LevelManager.h"
#include "GameInstance.h"
#include "Level.h"

HRESULT LevelManager::OpenLevel(unsigned int levelID, shared_ptr<Level> level)
{
	

	currentLevel = level;
	currentLevelID = levelID;
	return S_OK;
}

weak_ptr<Level> LevelManager::Get_CurrentLevel()
{
	return currentLevel;
}

void LevelManager::Tick(float deltaTime)
{
	if (currentLevel == nullptr)
		return;

	currentLevel->Tick(deltaTime);
}

void LevelManager::OnDestroy()
{
}

void LevelManager::Free()
{
}
