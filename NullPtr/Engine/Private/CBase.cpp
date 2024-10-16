#include "CBase.h"

void CBase::Set_Enable(bool enable)
{
	isEnable = enable;

	isEnable ? OnEnable() : OnDisable();
}

bool CBase::Is_Enable()
{
	return isEnable;
}

