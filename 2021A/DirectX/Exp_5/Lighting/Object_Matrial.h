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

#ifndef __Object_MatrialH__
#define __Object_MatrialH__

#include "D3DObject.h"


class Plane_Matrial : public D3DObject
{
public:
	Plane_Matrial();
	~Plane_Matrial();

	bool		CreateBuffer(IDirect3DDevice9* _device);
	bool        CreateBuffer(IDirect3DDevice9* _device, int _width, int _height, float _resolution);
	void		Render(IDirect3DDevice9* _device);

protected:

private:
	IDirect3DVertexBuffer9*			_vb;	//顶点缓存
	IDirect3DIndexBuffer9*			_ib;	//索引缓存
	D3DMATERIAL9					_mtrl;  //材质

	int                             d_width;
	int                             d_height;
	float                           d_resolution;
};


class Texture_Matrial : public D3DObject
{
public:
	Texture_Matrial();
	~Texture_Matrial();

	bool		CreateBuffer(IDirect3DDevice9* _device);
	bool        CreateBuffer(IDirect3DDevice9* _device, int _width, int _height, float _resolution);
	void		Render(IDirect3DDevice9* _device);

protected:

private:
	IDirect3DVertexBuffer9*			_vb;		//顶点缓存
	IDirect3DIndexBuffer9*			_ib;		//索引缓存
	IDirect3DTexture9*				_texture;   //纹理
	D3DMATERIAL9					_mtrl;      //材质

	int                             d_width;
	int                             d_height;
	float                           d_resolution;
};



class Box_Matrial : public D3DObject
{
public:
	Box_Matrial();
	~Box_Matrial();

	bool		CreateBuffer(IDirect3DDevice9* _device);
	void		Render(IDirect3DDevice9* _device);

protected:

private:
	IDirect3DVertexBuffer9*			_vb;	//顶点缓存
	IDirect3DIndexBuffer9*			_ib;	//索引缓存
	D3DMATERIAL9					_mtrl;  //材质
};
#endif // __Object_MatrialH__