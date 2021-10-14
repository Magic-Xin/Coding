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
};
#define FVF_VERTEX (D3DFVF_XYZ)


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


protected:
	D3DXMATRIX		m_Transform;
	D3DXMATRIX		m_Scale;
	D3DXMATRIX		m_Translate;
	D3DXMATRIX		m_Rotation;

private:

};

#endif // __D3DObjectH__