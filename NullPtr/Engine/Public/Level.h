#pragma once
#include "CBase.h"
class Level : public CBase
{
public:
	virtual HRESULT Initialize();
	void Tick(float deltaTime);

};

