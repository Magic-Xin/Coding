//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// File: Light.cpp
// 
// Author: Song Wei (C) All Rights Reserved
//
// System: 3.20 GHz Intel® Core™ Quad CPU, a GeForce GT 770 graphics card, 4 GB RAM, Windows 7.
//
// Desc: Provides utility functions for simplifying common tasks.
//          
//////////////////////////////////////////////////////////////////////////////////////////////////


#include "Light.h"

PointLight::PointLight()
{
	_light.Type = D3DLIGHT_POINT;
}

PointLight::~PointLight()
{

}

void PointLight::Initialize(IDirect3DDevice9* _device, int _id, D3DXVECTOR3 _pos, 
	D3DXCOLOR _ambient, D3DXCOLOR _diffuse, D3DXCOLOR _specular, float _range,
	float _a0, float _a1, float _a2)
{
	_light.Position = _pos;

	_light.Ambient		= _ambient;
	_light.Diffuse		= _diffuse;
	_light.Specular		= _specular;
	_light.Range		= _range;
	_light.Attenuation0 = _a0;
	_light.Attenuation0 = _a1;
	_light.Attenuation0 = _a2;

	d_id = _id;
	_device->SetLight(d_id, &_light);
	_device->LightEnable(d_id, true);
}

void PointLight::SetPosition(D3DXVECTOR3 _pos)
{
	_light.Position = _pos;
}

void PointLight::Enable(IDirect3DDevice9* _device, bool _state)
{
	_device->LightEnable(d_id, _state);
}

void PointLight::Reset(IDirect3DDevice9* _device)
{
	_device->SetLight(d_id, &_light);
	_device->LightEnable(d_id, true);
}



DirectionalLight::DirectionalLight()
{
	_light.Type = D3DLIGHT_DIRECTIONAL;
}

DirectionalLight::~DirectionalLight()
{

}

void DirectionalLight::Initialize(IDirect3DDevice9* _device, int _id, D3DXVECTOR3 _dir,
			D3DXCOLOR _ambient, D3DXCOLOR _diffuse, D3DXCOLOR _specular)
{
	_light.Direction = _dir;

	_light.Ambient   = _ambient;
	_light.Diffuse   = _diffuse;
	_light.Specular  = _specular;

	d_id = _id;
	_device->SetLight(d_id, &_light);
	_device->LightEnable(d_id, true);
}

void DirectionalLight::SetDirection(D3DXVECTOR3 _dir)
{
	_light.Direction = _dir;
}

void DirectionalLight::Enable(IDirect3DDevice9* _device, bool _state)
{
	_device->LightEnable(d_id, _state);
}

void DirectionalLight::Reset(IDirect3DDevice9* _device)
{
	_device->SetLight(d_id, &_light);
	_device->LightEnable(d_id, true);
}


SpotLight::SpotLight()
{
	_light.Type = D3DLIGHT_SPOT;
}

SpotLight::~SpotLight()
{

}

void SpotLight::Initialize(IDirect3DDevice9* _device, int _id, D3DXVECTOR3 _pos, D3DXVECTOR3 _dir, 
	D3DXCOLOR _ambient, D3DXCOLOR _diffuse, D3DXCOLOR _specular,
	float _range, float _falloff, float _theta, float _phi,
	float _a0, float _a1, float _a2)
{
	_light.Position = _pos;
	_light.Direction = _dir;

	_light.Ambient   = _ambient;
	_light.Diffuse   = _diffuse;
	_light.Specular  = _specular;

	_light.Range = _range;
	_light.Falloff = _falloff;
	_light.Theta = _theta;
	_light.Phi = _phi;
	_light.Attenuation0 = _a0;
	_light.Attenuation1 = _a1;
	_light.Attenuation2 = _a2;

	d_id = _id;
	_device->SetLight(d_id, &_light);
	_device->LightEnable(d_id, true);
}


void SpotLight::SetPosition(D3DXVECTOR3 _pos)
{
	_light.Position = _pos;
}

void SpotLight::SetDirection(D3DXVECTOR3 _dir)
{
	_light.Direction = _dir;
}

void SpotLight::MoveDirectionX(float _x)
{
	_light.Direction.x += _x;
}

void SpotLight::ChangeTheta(float _theta)
{
	_light.Theta += _theta;
	if (_light.Theta < 0.0f)
		_light.Theta = 0.0f;
	if (_light.Theta > 1.0f)
		_light.Theta = 1.0f;
}


void SpotLight::Enable(IDirect3DDevice9* _device, bool _state)
{
	_device->LightEnable(d_id, _state);
}

void SpotLight::Reset(IDirect3DDevice9* _device)
{
	_device->SetLight(d_id, &_light);
	_device->LightEnable(d_id, true);
}