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

	position = D3DXVECTOR3(0.0f, -3.0f, -7.0f);
	target = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	this->UpdateCamera();

	//create objects
	//d3d_square.CreateBuffer(p_Device);
	//d3d_square.SetTranslation(D3DXVECTOR3(-1.5f, 0.0f,0));

	d3d_plane.CreateBuffer(p_Device, 20, 20, 1);
	//d3d_plane.SetTranslation(D3DXVECTOR3(1.5f, 0.0f,0));

	d3d_cube.CreateBuffer(p_Device);

	return true;
}

void MyD3D::FrameMove(float timeDelta)
{
	if (GetAsyncKeyState(VK_UP) & 0x8000f)
	{
		d3d_cube.v_Translate += D3DXVECTOR3(0.0f, 1.0f * timeDelta, 0.0f);
		d3d_cube.SetTranslation(d3d_cube.v_Translate);
		this->position += D3DXVECTOR3(0.0f, 1.0f * timeDelta, 0.0f);
		this->target += D3DXVECTOR3(0.0f, 1.0f * timeDelta, 0.0f);
		this->UpdateCamera();
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000f)
	{
		d3d_cube.v_Translate -= D3DXVECTOR3(0.0f, 1.0f * timeDelta, 0.0f);
		d3d_cube.SetTranslation(d3d_cube.v_Translate);
		this->position -= D3DXVECTOR3(0.0f, 1.0f * timeDelta, 0.0f);
		this->target -= D3DXVECTOR3(0.0f, 1.0f * timeDelta, 0.0f);
		this->UpdateCamera();
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000f)
	{
		d3d_cube.v_Translate -= D3DXVECTOR3(1.0f * timeDelta, 0.0f, 0.0f);
		d3d_cube.SetTranslation(d3d_cube.v_Translate);
		this->position -= D3DXVECTOR3(1.0f * timeDelta, 0.0f, 0.0f);
		this->target -= D3DXVECTOR3(1.0f * timeDelta, 0.0f, 0.0f);
		this->UpdateCamera();
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000f)
	{
		d3d_cube.v_Translate += D3DXVECTOR3(1.0f * timeDelta, 0.0f, 0.0f);
		d3d_cube.SetTranslation(d3d_cube.v_Translate);
		this->position += D3DXVECTOR3(1.0f * timeDelta, 0.0f, 0.0f);
		this->target += D3DXVECTOR3(1.0f * timeDelta, 0.0f, 0.0f);
		this->UpdateCamera();
	}
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
		//d3d_square.Render(p_Device);
		d3d_plane.Render(p_Device);
		d3d_cube.Render(p_Device);

		p_Device->EndScene();

		// Swap the back and front buffers.
		p_Device->Present(0, 0, 0, 0);
	}
	return true;
}

void MyD3D::UpdateCamera()
{
	D3DXMatrixLookAtLH(&V, &position, &target, &up);
	p_Device->SetTransform(D3DTS_VIEW, &V);

	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(
		&proj,
		D3DXToRadian(90), // 90 - degree
		(float)d_width / (float)d_height,
		1.0f,
		1000.0f);
	p_Device->SetTransform(D3DTS_PROJECTION, &proj);
}


void MyD3D::Release()
{

}

IDirect3DDevice9*  MyD3D::getDevice()
{
	return p_Device;
}