//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// File: Object_Index.h
// 
// Author: Song Wei (C) All Rights Reserved
//
// System: 3.20 GHz Intel® Core™ Quad CPU, a GeForce GT 770 graphics card, 4 GB RAM, Windows 7.
//
// Desc: This is a D3D object definition header, which provides basic functions and attributes for 3d objects.
//          
//////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Object_IndexH__
#define __Object_IndexH__

#include "D3DObject.h"

class Square_Index : public D3DObject
{
public:
	Square_Index();
	~Square_Index();

	bool		CreateBuffer(IDirect3DDevice9* _device);
	void		Render(IDirect3DDevice9* _device);

protected:

private:
	IDirect3DVertexBuffer9*			_vb;	//顶点缓存
	IDirect3DIndexBuffer9*			_ib;	//索引缓存
};


class Plane_Index : public D3DObject
{
public:
	Plane_Index();
	~Plane_Index();

	bool		CreateBuffer(IDirect3DDevice9* _device);
	bool        CreateBuffer(IDirect3DDevice9* _device, int _width, int _height, float _resolution);
	void		Render(IDirect3DDevice9* _device);

protected:

private:
	IDirect3DVertexBuffer9*			_vb;	//顶点缓存
	IDirect3DIndexBuffer9*			_ib;	//索引缓存

	int                             d_width;
	int                             d_height;
	float                           d_resolution;
};

class Cube_Index : public D3DObject
{
public:
	Cube_Index();
	~Cube_Index();

	bool		CreateBuffer(IDirect3DDevice9* _device);
	void		Render(IDirect3DDevice9* _device);

protected:

private:

	IDirect3DVertexBuffer9* _vb;	//顶点缓存
	IDirect3DIndexBuffer9* _ib;	//索引缓存
};


#endif // __Object_IndexH__