#pragma once
#include "CBase.h"

class GameObject;
class ObjectManager final : public CBase
{
	DECLARE_SINGLETON(ObjectManager)

public:
	HRESULT Reserve_Container(unsigned int iNumLevels);
	void StartObject();
	void Tick(float deltaTime);
	void LateTick(float deltaTime);
	
	virtual void Free() override;
private:
	vector<list<shared_ptr<GameObject>>> StartObjects;
	vector<list<shared_ptr<GameObject>>> ObjectLayers;

	int currentLevel;
	int levelNum;
};

