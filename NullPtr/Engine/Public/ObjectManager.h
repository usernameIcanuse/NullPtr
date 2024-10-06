#pragma once
#include "CBase.h"

class GameObject;
class ObjectManager final : public CBase
{
	DECLARE_SINGLETON(ObjectManager)
public:
	void OnEnable_Object();

	void StartObject();
	void Tick();
	void LateTick();

	void OnDisable_Object();
	void OnDestroy_Object();
	
private:
	list<GameObject> Layers;
};

