#ifndef __PLANETH__
#define __PLANETH__

#include "D3DUT.h"

class Planet
{
public:
	Planet();
	~Planet();

	void Release();

	HRESULT CreateBuffer(IDirect3DDevice9* _device, float radius);
	ID3DXMesh* GetMesh();

private:
	ID3DXMesh* Mesh_Sphere;

};

#endif // __PLANETH__