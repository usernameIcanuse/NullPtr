#include "ObjectManager.h"
#include "GameObject.h"

HRESULT ObjectManager::Reserve_Container(unsigned int iNumLevels)
{
	if (0 != ObjectLayers.size())
		return E_FAIL;

	levelNum = iNumLevels;

	for (unsigned int i = 0; i < levelNum; ++i)
	{
		ObjectLayers.push_back({});
	}

	return E_NOTIMPL;
}

void ObjectManager::StartObject()
{
	auto iter = StartObjects[currentLevel].begin();

	for (; iter != StartObjects[currentLevel].end();)
	{
		(*iter)->Start();
		ObjectLayers[currentLevel].push_back((*iter));
		iter = StartObjects[currentLevel].erase(iter);
	}
}

void ObjectManager::Tick(float deltaTime)
{
	for (auto& elem : ObjectLayers[currentLevel])
	{
		if (elem->Is_Enable())
		{
			elem->Tick(deltaTime);
		}
	}
}

void ObjectManager::LateTick(float deltaTime)
{
	for (auto& elem : ObjectLayers[currentLevel])
	{
		if (elem->Is_Enable())
		{
			elem->LateTick(deltaTime);
		}
	}
}

void ObjectManager::OnDestroy()
{
}

void ObjectManager::Free()
{
}

void ObjectManager::OnLevelEnter()
{
}

void ObjectManager::OnLevelExit()
{
}

void ObjectManager::Clear_LayerObject(unsigned int levelIndex)
{
	for (auto& obj : ObjectLayers[levelIndex])
	{
		if (obj.get())
			obj->OnDestroy();

		obj.reset();
	}
}
