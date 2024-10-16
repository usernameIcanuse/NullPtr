#pragma once
#include "CBase.h"

class GameObject : public CBase
{
protected:
	GameObject();
	virtual ~GameObject();

public:
	virtual void Start();
	virtual void Tick(float deltaTime);
	virtual void LateTick(float deltaTime);

	virtual void OnEnable() {}
	virtual void OnDisable() {}
	virtual void OnDestroy() {}

	virtual void Free() {}

};

