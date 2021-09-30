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
	f_rot_z = 0.0f;
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
	
	//D3DXCreateTeapot(p_Device, &Teapot, 0);
	sun.CreateBuffer(p_Device, 1.0f);
	earth.CreateBuffer(p_Device, 0.5f);
	moon.CreateBuffer(p_Device, 0.2f);

	// Initialize VirtualCamera.

	D3DXVECTOR3 position(0.0f, 0.0f, -5.0f);
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

	// Set render state.

	p_Device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	//If you want to change the viewport, you can change the code here.
	//D3DVIEWPORT9  _vp = {0, 0, 640, 480, 0, 1};
	//p_Device->SetViewport(&_vp);
	return true;
}

void MyD3D::FrameMove(float timeDelta)
{
	D3DXMatrixRotationZ(&m_sun, f_rot_z);

	D3DXMATRIX earthRotation, earthTransform;
	D3DXMatrixTranslation(&earthTransform, 0.0f, 4.0f, 0.0f);
	D3DXMatrixRotationZ(&earthRotation, f_rot_z);
	D3DXMatrixMultiply(&m_earth, &m_sun, &earthTransform);
	D3DXMatrixMultiply(&m_earth, &m_earth, &earthRotation);

	D3DXMATRIX moonRotation, moonTransform;
	D3DXMatrixTranslation(&moonTransform, 2.0f, 0.0f, 0.0f);
	D3DXMatrixRotationZ(&moonRotation, f_rot_z);
	D3DXMatrixMultiply(&m_moon, &moonRotation, &moonTransform);
	D3DXMatrixMultiply(&m_moon, &m_moon, &moonRotation);
	D3DXMatrixMultiply(&m_moon, &m_moon, &m_earth);

	f_rot_z += timeDelta;
	if(f_rot_z >= 6.28f)
		f_rot_z = 0.0f;
}

bool MyD3D::Render()
{
	if( p_Device ) 
	{
		// Set back buffer - 0xffffffff (white)
		//Set each pixel on the depth buffer to a value of 1.0.
		p_Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0);

		p_Device->BeginScene();
		// Draw sun sphere
		p_Device->SetTransform(D3DTS_WORLD, &m_sun);
		sun.GetMesh()->DrawSubset(0);
		// Draw earth sphere
		p_Device->SetTransform(D3DTS_WORLD, &m_earth);
		earth.GetMesh()->DrawSubset(0);
		// Draw moon sphere
		p_Device->SetTransform(D3DTS_WORLD, &m_moon);
		moon.GetMesh()->DrawSubset(0);
		p_Device->EndScene();

		// Swap the back and front buffers.
		p_Device->Present(0, 0, 0, 0);
	}
	return true;
}


void MyD3D::Release()
{
	sun.Release();
	earth.Release();
	moon.Release();
}

IDirect3DDevice9*  MyD3D::getDevice()
{
	return p_Device;
}