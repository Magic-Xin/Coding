//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// File: MyD3D.h
// 
// Author: Song Wei (C) All Rights Reserved
//
// System: 3.20 GHz Intel® Core™ Quad CPU, a GeForce GT 770 graphics card, 4 GB RAM, Windows 7.
//
// Desc: This is a D3D object definition header, which provides basic functions and attributes for 3d objects.
//          
//////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __D3DObjectH__
#define __D3DObjectH__
#include <d3dx9.h>
#include <stdio.h>

struct Vertex
{
	Vertex(){}
	Vertex(	float x, float y, float z)			
	{
		_x  = x;  _y  = y;  _z  = z;
	}
	float _x, _y, _z;

	static const DWORD FVF  = D3DFVF_XYZ;
};


struct ColorVertex
{
	ColorVertex(){}

	ColorVertex(float x, float y, float z, D3DCOLOR c)
	{
		_x = x;	 _y = y;  _z = z;  _color = c;
	}

	float _x, _y, _z;
	D3DCOLOR _color;

	static const DWORD FVF  = D3DFVF_XYZ | D3DFVF_DIFFUSE;
};

struct TextureVertex
{
	TextureVertex() {}

	TextureVertex(float x, float y, float z, float u, float v)
	{
		_x = x;	 _y = y;  _z = z;  _u = u;  _v = v; 
	}

	
	float _x, _y, _z;
	float _u, _v;

	static const DWORD FVF = D3DFVF_XYZ | D3DFVF_TEX1;
};

struct TextureNormalVertex
{
	TextureNormalVertex() : _pos(0.0f,0.0f,0.0f),_normal(0.0f,0.0f,0.0f),  _u(0.0f), _v(0.0f){}

	TextureNormalVertex(float x,float y,float z,
		float nx,float ny,float nz, float u, float v) : 
	_pos(x,y,z),_normal(nx,ny,nz), _u(u), _v(v){}

	D3DXVECTOR3		_pos;
	D3DXVECTOR3		_normal;
	float			_u, _v;

	static const DWORD FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 ;
};


struct NormalVertex
{
	NormalVertex() : _pos(0.0f,0.0f,0.0f),_normal(0.0f,0.0f,0.0f){}

	NormalVertex(float x,float y,float z,
		float nx,float ny,float nz) : 
	_pos(x,y,z),_normal(nx,ny,nz){}

	D3DXVECTOR3		_pos;
	D3DXVECTOR3		_normal;

	static const DWORD FVF = D3DFVF_XYZ | D3DFVF_NORMAL;
};

class D3DObject
{
public:
	D3DObject();
	~D3DObject();

	virtual bool	CreateBuffer(IDirect3DDevice9* _device) = 0;
	virtual void	Render(IDirect3DDevice9* _device) = 0;
	void			SetScale(D3DXVECTOR3 _scale);
	void			SetTranslation(D3DXVECTOR3 _translate);
	void			SetRotation(D3DXVECTOR3 _rotate);

	D3DXVECTOR3     v_Scale;
	D3DXVECTOR3     v_Translate;
	D3DXVECTOR3     v_Rotate;

	D3DXMATRIX		m_Transform;
	D3DXMATRIX		m_Scale;
	D3DXMATRIX		m_Translate;
	D3DXMATRIX		m_Rotation;

protected:


private:

};

#endif // __D3DObjectH__