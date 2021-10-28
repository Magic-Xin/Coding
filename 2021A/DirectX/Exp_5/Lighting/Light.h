//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// File: __Object_MatrialH__
// 
// Author: Song Wei (C) All Rights Reserved
//
// System: 3.20 GHz Intel® Core™ Quad CPU, a GeForce GT 770 graphics card, 4 GB RAM, Windows 7.
//
// Desc: This is a D3D object definition header, which provides basic functions and attributes for 3d objects.
//          
//////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __LightH__
#define __LightH__

#include <d3dx9.h>


class PointLight
{
public:
	PointLight();
	~PointLight();
	
	void Initialize(IDirect3DDevice9* _device, int _id, D3DXVECTOR3 _pos, 
		D3DXCOLOR _ambient, D3DXCOLOR _diffuse, D3DXCOLOR _specular, float _range,
		float _a0 = 1.0f, float _a1  = 0.0f, float _a2  = 0.0f);
	void SetPosition(D3DXVECTOR3 _pos);
	void Enable(IDirect3DDevice9* _device, bool _state);
	void Reset(IDirect3DDevice9* _device);
	D3DLIGHT9		_light;
	
protected:

private:
	int				d_id;
};


class DirectionalLight
{
public:
	DirectionalLight();
	~DirectionalLight();

	void Initialize(IDirect3DDevice9* _device, int _id, D3DXVECTOR3 _dir, D3DXCOLOR _ambient, D3DXCOLOR _diffuse, D3DXCOLOR _specular);
	void SetDirection(D3DXVECTOR3 _dir);
	void Enable(IDirect3DDevice9* _device, bool _state);
	void Reset(IDirect3DDevice9* _device);
	D3DLIGHT9		_light;

protected:

private:
	int				d_id;
};



class SpotLight
{
public:
	SpotLight();
	~SpotLight();

	void Initialize(IDirect3DDevice9* _device, int _id, D3DXVECTOR3 _pos, D3DXVECTOR3 _dir, 
		D3DXCOLOR _ambient, D3DXCOLOR _diffuse, D3DXCOLOR _specular,
		float _range, float _falloff = 1.0f, float _theta = 0.3, float _phi = 0.8,
		float _a0 = 1.0f, float _a1  = 0.0f, float _a2  = 0.0f);

	void SetPosition(D3DXVECTOR3 _pos);
	void SetDirection(D3DXVECTOR3 _dir);
	void MoveDirectionX(float _x);
	void ChangeTheta(float _theta);
	void Enable(IDirect3DDevice9* _device, bool _state);
	void Reset(IDirect3DDevice9* _device);

	D3DLIGHT9		_light;

protected:

private:
	int				d_id;
};

#endif // __LightH__