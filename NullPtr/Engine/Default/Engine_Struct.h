#pragma once

typedef struct tagGraphicDesc
{
	enum WINMODE {MODE_FULL, MODE_WIN, MODE_END};

	unsigned int iWinCX, iWinCY;
	HWND hwnd;
	WINMODE isWindowMode;
}GRAPHICDESC;