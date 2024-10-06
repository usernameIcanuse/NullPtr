#pragma once
#include "Engine_Defines.h"

class CBase abstract
{
protected:
	CBase() = default;
	virtual ~CBase() = default;

public:
	void Set_Enable(bool enable);
	bool Get_Enable();

public:
	virtual void OnEnable() {}
	virtual void OnDisable() {}
	virtual void OnDestroy() {}

	virtual void Free() {}
private:
	bool isEnable;
};

