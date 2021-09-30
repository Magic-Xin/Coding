#include "Planet.h"

Planet::Planet()
{
}

Planet::~Planet()
{
}

void Planet::Release()
{
	Mesh_Sphere->Release();
}

HRESULT Planet::CreateBuffer(IDirect3DDevice9* _device, float radius)
{
	HRESULT hr = 0;
	hr = D3DXCreateSphere(_device, radius, 15, 15, &Mesh_Sphere, NULL);
	return hr;
}

ID3DXMesh* Planet::GetMesh()
{
	return Mesh_Sphere;
}
