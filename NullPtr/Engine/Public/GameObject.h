#pragma once
#include "CBase.h"

class GameObject : public CBase
{
public:
	GameObject();

public:
	virtual void Start();
	virtual void Tick();
	virtual void LateTick();

public:
	virtual void OnEnable() {}
	virtual void OnDisable() {}
	virtual void OnDestroy() {}

	virtual void Free() {}
};

