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

#include "D3DUT.h"
#include "Object_Matrial.h"
#include "Light.h"

class MyD3D
{
public:
	MyD3D();
	~MyD3D();

	bool CreateDevice(HINSTANCE hInstance, int _width, int _height);
	virtual bool Initialize();
	virtual void FrameMove(float timeDelta);
	virtual bool Render();
	void Release();

	IDirect3DDevice9*  getDevice();
	
protected:


private:
	HWND				hwnd;     //window handle
	IDirect3DDevice9*	p_Device;
	int					d_width;
	int					d_height;

	Texture_Matrial		obj_texture_matrial;
	Box_Matrial         light_box;

	PointLight          light_point;
	DirectionalLight    light_directional;
	SpotLight			light_spot;

	D3DXVECTOR3			light_pos;
	D3DXVECTOR3			light_dir;
};

#endif // __MyD3DH__