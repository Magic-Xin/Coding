//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// File: MyD3D.cpp
// 
// Author: Song Wei (C) All Rights Reserved
//
// System: 3.20 GHz Intel® Core™ Quad CPU, a GeForce GT 770 graphics card, 4 GB RAM, Windows 7.
//
// Desc: Provides utility functions for simplifying common tasks.
//          
//////////////////////////////////////////////////////////////////////////////////////////////////


#include "MyD3D.h"

MyD3D::MyD3D() 
{
	
}

MyD3D::~MyD3D() 
{

}


bool MyD3D::CreateDevice(HINSTANCE hInstance, int _width, int _height)
{
	d_width = _width;
	d_height = _height;

	if(!InitWindow(hInstance, _width, _height,  true))
	{
		MessageBox(0, "InitD3D() - FAILED", 0, 0);
		return 0;
	}
	if(!InitD3D(hInstance, _width, _height,  true, D3DDEVTYPE_HAL, &p_Device))
	{
		MessageBox(0, "InitD3D() - FAILED", 0, 0);
		return 0;
	}

	return true;
}

bool MyD3D::Initialize()
{
	// Initialize VirtualCamera.

	D3DXVECTOR3 position(0.0f, 0.0f, -18.0f);
	D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXMATRIX V;
	D3DXMatrixLookAtLH(&V, &position, &target, &up);
	p_Device->SetTransform(D3DTS_VIEW, &V);

	// Set projection matrix.
	
	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(
			&proj,
			D3DX_PI * 0.5f, 
			(float)d_width / (float)d_height,
			1.0f,
			1000.0f);
	p_Device->SetTransform(D3DTS_PROJECTION, &proj);


	//create objects
	
	obj_texture_matrial.CreateBuffer(p_Device, 200, 200, 0.1f);
	obj_texture_matrial.SetTranslation(D3DXVECTOR3(0.0f, 0.0f, 2.0f));
	
	//Light position
	light_box.CreateBuffer(p_Device);
	light_box.v_Translate.x = 3.0f;
	light_box.v_Translate.y = -2.0f;
	light_box.v_Translate.z = 1.0f;
	light_box.SetTranslation(light_box.v_Translate);

	//create light;
	light_pos = D3DXVECTOR3(0.0f, 0.0f, 3.0f);
	D3DXCOLOR  _color = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);
	light_point.Initialize(p_Device, 0, light_pos, _color * 0.5f, _color * 0.6f , _color, 8.0f, 1.0f, 1.0f, 1.3f);
	
	light_dir = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	_color = D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);
	light_directional.Initialize(p_Device, 1, light_dir, _color * 0.5f, _color * 0.6f, _color);

	_color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	light_dir = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	light_pos = D3DXVECTOR3(0.0f, 0.0f, 5.0f);
	light_spot.Initialize(p_Device, 2, light_pos, light_dir, _color, _color, _color, 20.0f, 1.0f, 0.8, 0.9, 
		0.5f, 0.5f, 0.01f);


	return true;
}

void MyD3D::FrameMove(float timeDelta)
{
	if (light_box.v_Rotate.z > D3DX_PI * 2)
	{
		light_box.v_Rotate.z = 0.0f;
	}
	light_box.v_Rotate.z += 0.5f * timeDelta;

	light_box.SetRotation(light_box.v_Rotate);
	light_box.SetTranslation(light_box.v_Translate);
	light_box.m_Transform = light_box.m_Scale * light_box.m_Translate * light_box.m_Rotation;

	light_pos = light_box.v_Translate;
	D3DXVec3TransformCoord(&light_pos,&light_pos,&light_box.m_Rotation);
	light_dir = D3DXVECTOR3(0.0f, -5.0f, 0.0f) - light_pos;

	if (GetAsyncKeyState('E') & 0x8000)
		light_directional.Enable(p_Device, true);
	else
		light_directional.Enable(p_Device, false);

	if (GetAsyncKeyState('R') & 0x8000)
		light_spot.Enable(p_Device, true);
	else
		light_spot.Enable(p_Device, false);

	if (GetAsyncKeyState('T') & 0x8000)
		light_point.Enable(p_Device, true);
	else
		light_point.Enable(p_Device, false);

	if (GetAsyncKeyState('A') & 0x8000)
	{
		light_spot.MoveDirectionX(-1.0f * timeDelta);
		light_spot.Reset(p_Device);
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		light_spot.MoveDirectionX(1.0f * timeDelta);
		light_spot.Reset(p_Device);
	}
	if (GetAsyncKeyState('N') & 0x8000)
	{
		light_spot.ChangeTheta(-0.2f * timeDelta);
		light_spot.Reset(p_Device);
	}
	if (GetAsyncKeyState('M') & 0x8000)
	{
		light_spot.ChangeTheta(0.2f * timeDelta);
		light_spot.Reset(p_Device);
	}
}

bool MyD3D::Render()
{
	if( p_Device ) 
	{
		p_Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xff0000ff, 1.0f, 0);
		p_Device->BeginScene();

        //drawing 
		obj_texture_matrial.Render(p_Device);
		light_box.Render(p_Device);

		p_Device->EndScene();
		p_Device->Present(0, 0, 0, 0);
	}
	return true;
}


void MyD3D::Release()
{

}

IDirect3DDevice9*  MyD3D::getDevice()
{
	return p_Device;
}