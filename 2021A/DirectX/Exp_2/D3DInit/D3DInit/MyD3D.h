//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// File: MyD3D.h
// 
// Author: Song Wei (C) All Rights Reserved
//
// System: 3.20 GHz Intel® Core™ Quad CPU, a GeForce GT 770 graphics card, 4 GB RAM, Windows 7.
//
// Desc: This is a D3D initialization header, which provides basic framework for common applications.
//          
//////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __MyD3DH__
#define __MyD3DH__

#include "Planet.h"


class MyD3D
{
public:
	MyD3D();
	~MyD3D();

	bool CreateDevice(HINSTANCE hInstance, int _width, int _height);
	bool Initialize();
	void FrameMove(float timeDelta);
	bool Render();
	void Release();

	IDirect3DDevice9*  getDevice();
	
protected:


private:
	HWND				hwnd;     //window handle
	IDirect3DDevice9*	p_Device;
	D3DXMATRIX			m_sun;
	D3DXMATRIX			m_earth;
	D3DXMATRIX			m_moon;
	float               f_rot_z;

	// Teapot Mesh: provided by D3D sdk.
	Planet				sun;
	Planet				earth;
	Planet				moon;
	int					d_width;
	int					d_height;
};


#endif // __MyD3DH__