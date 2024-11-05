#pragma once
#include "Engine_Defines.h"

class CBase
{
public:
	CBase() = default;
	virtual ~CBase() = default;

public:
	void Set_Enable(bool enable);
	bool Is_Enable();

public:
	virtual void OnEnable() {}
	virtual void OnDisable() {}
	virtual void OnDestroy() {}

	virtual void OnLevelEnter() {}
	virtual void OnLevelExit() {}

	virtual void Free() {}

protected:
	weak_ptr<CBase> weakThis;

private:
	bool isEnable;
};

