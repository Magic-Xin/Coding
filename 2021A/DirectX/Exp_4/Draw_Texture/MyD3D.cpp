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

	D3DXVECTOR3 position(0.0f, 0.0f, -3.0f);
	D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXMATRIX V;
	D3DXMatrixLookAtLH(&V, &position, &target, &up);
	p_Device->SetTransform(D3DTS_VIEW, &V);

	// Set projection matrix.
	
	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(
			&proj,
			D3DX_PI * 0.5f, // 90 - degree
			(float)d_width / (float)d_height,
			1.0f,
			1000.0f);
	p_Device->SetTransform(D3DTS_PROJECTION, &proj);


	//create objects
	obj_texture_box.CreateBuffer(p_Device);
	obj_texture_box.SetScale(D3DXVECTOR3(1.5f, 1.5f, 1.5f));
	obj_texture_box.SetTranslation(D3DXVECTOR3(2.0f, 0.0f, 0.0f));
	
	obj_texture_plane.CreateBuffer(p_Device);
	obj_texture_plane.SetScale(D3DXVECTOR3(3.0f, 3.0f, 3.0f));
	obj_texture_plane.SetTranslation(D3DXVECTOR3(-2.0f, 0.0f, 0.0f));
	
	return true;
}

void MyD3D::FrameMove(float timeDelta)
{
	static D3DXVECTOR3 _v_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	if (_v_rot.x > D3DX_PI * 2)
	{
		_v_rot.x = 0.0f;
	}
	if (_v_rot.y > D3DX_PI * 2)
	{
		_v_rot.y = 0.0f;
	}
	obj_texture_box.SetRotation(_v_rot);
	
	_v_rot.x += 0.5f * timeDelta;
	_v_rot.y += 0.5f * timeDelta;
}

bool MyD3D::Render()
{
	if( p_Device ) 
	{
		// Set back buffer - 0xffffffff (white)
		//Set each pixel on the depth buffer to a value of 1.0.
		p_Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0);

		p_Device->BeginScene();
        //drawing 
		
		obj_texture_plane.Render(p_Device);
		//p_Device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_ANISOTROPIC);
		//p_Device->SetSamplerState(0, D3DSAMP_MAXANISOTROPY, 10);
		obj_texture_box.Render(p_Device);

		p_Device->EndScene();

		// Swap the back and front buffers.
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