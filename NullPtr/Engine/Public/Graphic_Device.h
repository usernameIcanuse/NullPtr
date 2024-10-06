#pragma once
#include "CBase.h"

class Graphic_Device : public CBase
{
	DECLARE_SINGLETON(Graphic_Device)
public:
	HRESULT Ready_Graphic_Device(HWND hWnd, GRAPHICDESC::WINMODE WinMode, unsigned int iWinCX, unsigned int iWinCY);
};

