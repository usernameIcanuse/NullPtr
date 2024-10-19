#pragma once
#include "CBase.h"

class Component : public CBase
{
public:
	Component();
	virtual ~Component();

public:
	virtual void OnEnable() override;
	virtual void OnDisable() override;
	virtual void OnDestroy() override;

	virtual void Free() override;
};

