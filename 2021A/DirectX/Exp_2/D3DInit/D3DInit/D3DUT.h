//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// File: D3DUT.h
// 
// Author: Song Wei (C) All Rights Reserved
//
// System: 3.20 GHz Intel® Core™ Quad CPU, a GeForce GT 770 graphics card, 4 GB RAM, Windows 7.
//
// Desc: Provides utility functions for simplifying common tasks.
//          
//////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __d3dUtilityH__
#define __d3dUtilityH__

#include <d3dx9.h>
#include <string>


bool InitWindow(
	HINSTANCE hInstance,       // Application instance.
	int width, int height,     // Backbuffer dimensions.
	bool windowed);             // Windowed (true)or full screen (false).).

bool InitD3D(
	HINSTANCE hInstance,       // [in] Application instance.
	int width, int height,     // [in] Backbuffer dimensions.
	bool windowed,             // [in] Windowed (true)or full screen (false).
	D3DDEVTYPE deviceType,     // [in] HAL or REF
	IDirect3DDevice9** device);// [out]The created device.


LRESULT CALLBACK WndProc(
	HWND hwnd,
	UINT msg, 
	WPARAM wParam,
	LPARAM lParam);


#endif // __d3dUtilityH__