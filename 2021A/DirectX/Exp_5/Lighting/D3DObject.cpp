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

#include "D3DObject.h"

D3DObject::D3DObject()
{
	v_Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	v_Translate = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	v_Rotate = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	D3DXMatrixScaling(&m_Scale, v_Scale.x, v_Scale.y, v_Scale.z);
	D3DXMatrixTranslation(&m_Translate, v_Translate.x, v_Translate.y, v_Translate.z);
	D3DXMatrixRotationYawPitchRoll(&m_Rotation, v_Rotate.y, v_Rotate.x, v_Rotate.z);

	m_Transform = m_Scale * m_Rotation * m_Translate;
}

D3DObject::~D3DObject()
{
	
}

void D3DObject::SetScale(D3DXVECTOR3 _scale)
{
	v_Scale = _scale;

	D3DXMatrixScaling(&m_Scale, v_Scale.x, v_Scale.y, v_Scale.z);
	m_Transform = m_Scale * m_Rotation * m_Translate;
}

void D3DObject::SetTranslation(D3DXVECTOR3 _translate)
{
	v_Translate = _translate;

	D3DXMatrixTranslation(&m_Translate, v_Translate.x, v_Translate.y, v_Translate.z);
	m_Transform = m_Scale * m_Rotation * m_Translate;
}

void D3DObject::SetRotation(D3DXVECTOR3 _rotate)
{
	v_Rotate = _rotate;

	D3DXMatrixRotationYawPitchRoll(&m_Rotation, v_Rotate.y, v_Rotate.x, v_Rotate.z);
	m_Transform = m_Scale * m_Rotation * m_Translate;
}
