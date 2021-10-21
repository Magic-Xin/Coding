//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// File: __Object_ColorH__
// 
// Author: Song Wei (C) All Rights Reserved
//
// System: 3.20 GHz Intel® Core™ Quad CPU, a GeForce GT 770 graphics card, 4 GB RAM, Windows 7.
//
// Desc: This is a D3D object definition header, which provides basic functions and attributes for 3d objects.
//          
//////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Object_ColorH__
#define __Object_ColorH__

#include "D3DObject.h"



class Plane_Texture : public D3DObject
{
public:
	Plane_Texture();
	~Plane_Texture();

	bool		CreateBuffer(IDirect3DDevice9* _device) override;
	void		Render(IDirect3DDevice9* _device) override;

protected:

private:
	IDirect3DVertexBuffer9*			_vb;		//顶点缓存
	IDirect3DIndexBuffer9*			_ib;		//索引缓存
	IDirect3DTexture9*				_texture;	//纹理缓存
};

class Box_Texture : public D3DObject
{
public:
	Box_Texture();
	~Box_Texture();

	bool		CreateBuffer(IDirect3DDevice9* _device) override;
	void		Render(IDirect3DDevice9* _device) override;

protected:

private:
	IDirect3DVertexBuffer9*			_vb;			//顶点缓存
	IDirect3DIndexBuffer9*			_ib;			//索引缓存
	IDirect3DTexture9*				_texture[8];	//8张纹理缓存
};

#endif // __Object_IndexH__