#include "Object_Texture.h"

Plane_Texture::Plane_Texture()
{

}

Plane_Texture::~Plane_Texture()
{
	if ( _ib )
	{
		_ib->Release();
		_ib = 0;
	}
	if ( _vb )
	{
		_vb->Release();
		_vb = 0;
	}
	if ( _texture )
	{
		_texture->Release();
		_texture = 0;
	}
}


bool Plane_Texture::CreateBuffer(IDirect3DDevice9* _device)
{
	HRESULT hr = 0;
	//创建顶点缓存
	hr = _device->CreateVertexBuffer(
		4 *sizeof(TextureVertex), 
		D3DUSAGE_WRITEONLY,
		TextureVertex::FVF,
		D3DPOOL_MANAGED,
		&_vb,
		0);

	if (FAILED(hr))
	{
		MessageBox(0, "Plane_Texture: CreateVertexBuffer() - FAILED", 0, 0);
		return false;
	}
	//访问顶点缓存区域
	TextureVertex* v;
	_vb->Lock(0, 0, (void**)&v, 0);

	v[0] = TextureVertex(-0.5f, -0.5f, 0.0f, 0.0f, 1.0f);
	v[1] = TextureVertex( 0.5f, -0.5f, 0.0f, 1.0f, 1.0f);
	v[2] = TextureVertex(-0.5f, 0.5f,  0.0f, 0.0f, 0.0f);
	v[3] = TextureVertex( 0.5f, 0.5f,  0.0f, 1.0f, 0.0f);

	_vb->Unlock();

	//创建索引缓存
	hr = _device->CreateIndexBuffer(
		2 * 3 * sizeof(WORD),
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&_ib,
		0);
	if (FAILED(hr))
	{
		MessageBox(0, "Plane_Texture: CreateIndexBuffer() - FAILED", 0, 0);
		return false;
	}

	//访问索引缓存区域
	WORD* i = 0;
	_ib->Lock(0, 0, (void**)&i, 0);

	i[0] = 0; i[1] = 2; i[2] = 1;
	i[3] = 2; i[4] = 3; i[5] = 1;

	_ib->Unlock();

	D3DXCreateTextureFromFile(_device, ".\\img\\banana.bmp", &_texture);

	_device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	_device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);

	return true;
}

void Plane_Texture::Render(IDirect3DDevice9* _device)
{
	_device->SetStreamSource(0, _vb, 0, sizeof(TextureVertex));
	_device->SetIndices(_ib);
	_device->SetFVF(TextureVertex::FVF);

	_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	_device->SetRenderState(D3DRS_LIGHTING, false);

	_device->SetTransform( D3DTS_WORLD, &m_Transform);
	_device->SetTexture(0, _texture);
	_device->DrawIndexedPrimitive( D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);
}



Box_Texture::Box_Texture()
{

}

Box_Texture::~Box_Texture()
{
	if ( _ib )
	{
		_ib->Release();
		_ib = 0;
	}
	if ( _vb )
	{
		_vb->Release();
		_vb = 0;
	}
	for (int i = 0 ; i < 8; i++)
	{
		if ( _texture[i] )
		{
			_texture[i]->Release();
			_texture[i] = 0;
		}
	}
}


bool Box_Texture::CreateBuffer(IDirect3DDevice9* _device)
{
	HRESULT hr = 0;
	hr = _device->CreateVertexBuffer(
		4 * 4 * 2 * sizeof(TextureVertex), 
		D3DUSAGE_WRITEONLY,
		TextureVertex::FVF,
		D3DPOOL_MANAGED,
		&_vb,
		0);

	if (FAILED(hr))
	{
		MessageBox(0, "Box_Texture: CreateVertexBuffer() - FAILED", 0, 0);
		return false;
	}

	TextureVertex* v;
	_vb->Lock(0, 0, (void**)&v, 0);

	//front face
	v[0] = TextureVertex(-0.5f, -0.5f, -0.5f, 0.0f, 1.0f);
	v[1] = TextureVertex(-0.5f,  0.5f, -0.5f, 0.0f, 0.0f);
	v[2] = TextureVertex( 0.5f,  0.5f, -0.5f, 1.0f, 0.0f);
	v[3] = TextureVertex( 0.5f, -0.5f, -0.5f, 1.0f, 1.0f);

	v[4] = TextureVertex(0.5f, -0.5f, -0.5f, 0.0f, 1.0f);
	v[5] = TextureVertex(0.5f, 0.5f, -0.5f, 0.0f, 0.0f);
	v[6] = TextureVertex(-0.5f, 0.5f, -0.5f, 1.0f, 0.0f);
	v[7] = TextureVertex(-0.5f, -0.5f, -0.5f, 1.0f, 1.0f);

	// left face
	v[8] = TextureVertex(-0.5f, -0.5f, -0.5f, 0.0f, 1.0f);
	v[9] = TextureVertex(-0.5f, -0.5f, 0.5f, 0.0f, 0.0f);
	v[10] = TextureVertex(-0.5f, 0.5f, 0.5f, 1.0f, 0.0f);
	v[11] = TextureVertex(-0.5f, 0.5f, -0.5f, 1.0f, 1.0f);

	v[12] = TextureVertex(-0.5f, 0.5f, -0.5f, 0.0f, 1.0f);
	v[13] = TextureVertex(-0.5f, 0.5f, 0.5f, 0.0f, 0.0f);
	v[14] = TextureVertex(-0.5f, -0.5f, 0.5f, 1.0f, 0.0f);
	v[15] = TextureVertex(-0.5f, -0.5f, -0.5f, 1.0f, 1.0f);

	//back face
	v[16] = TextureVertex(-0.5f, -0.5f, 0.5f, 0.0f, 1.0f);
	v[17] = TextureVertex(-0.5f, 0.5f, 0.5f, 0.0f, 0.0f);
	v[18] = TextureVertex(0.5f, 0.5f, 0.5f, 1.0f, 0.0f);
	v[19] = TextureVertex(0.5f, -0.5f, 0.5f, 1.0f, 1.0f);

	v[20] = TextureVertex(0.5f, -0.5f, 0.5f, 0.0f, 1.0f);
	v[21] = TextureVertex(0.5f, 0.5f, 0.5f, 0.0f, 0.0f);
	v[22] = TextureVertex(-0.5f, 0.5f, 0.5f, 1.0f, 0.0f);
	v[23] = TextureVertex(-0.5f, -0.5f, 0.5f, 1.0f, 1.0f);

	// right face
	v[24] = TextureVertex(0.5f, -0.5f, -0.5f, 0.0f, 1.0f);
	v[25] = TextureVertex(0.5f, -0.5f, 0.5f, 0.0f, 0.0f);
	v[26] = TextureVertex(0.5f, 0.5f, 0.5f, 1.0f, 0.0f);
	v[27] = TextureVertex(0.5f,  0.5f, -0.5f, 1.0f, 1.0f);

	v[28] = TextureVertex(0.5f, 0.5f, -0.5f, 0.0f, 1.0f);
	v[29] = TextureVertex(0.5f, 0.5f, 0.5f, 0.0f, 0.0f);
	v[30] = TextureVertex(0.5f, -0.5f, 0.5f, 1.0f, 0.0f);
	v[31] = TextureVertex(0.5f, -0.5f, -0.5f, 1.0f, 1.0f);
	
	_vb->Unlock();

	WORD indecies[] = {
		0, 1, 2,
		0, 2, 3,
		4, 5, 6,
		4, 6, 7,
		8, 9, 10,
		8, 10, 11,
		12, 13, 14,
		12, 14, 15,
		16, 17, 18,
		16, 18, 19,
		20, 21, 22,
		20, 22, 23,
		24, 25, 26,
		24, 26, 27,
		28, 29, 30,
		28, 30, 31
	};
	
	hr = _device->CreateIndexBuffer(
		sizeof(indecies),
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&_ib,
		0);
	if (FAILED(hr))
	{
		MessageBox(0, "Box_Texture: CreateIndexBuffer() - FAILED", 0, 0);
		return false;
	}
	
	VOID* i;
	_ib->Lock(0, 0, (&i), 0);
	
	memcpy(i, indecies, sizeof(indecies));

	_ib->Unlock();

	D3DXCreateTextureFromFile(_device,	".\\img\\banana1.bmp", &_texture[0]);
	D3DXCreateTextureFromFile(_device,	".\\img\\banana2.bmp", &_texture[1]);
	D3DXCreateTextureFromFile(_device, ".\\img\\banana3.bmp", &_texture[2]);
	D3DXCreateTextureFromFile(_device, ".\\img\\banana4.bmp", &_texture[3]);
	D3DXCreateTextureFromFile(_device, ".\\img\\banana5.bmp", &_texture[4]);
	D3DXCreateTextureFromFile(_device, ".\\img\\banana6.bmp", &_texture[5]);
	D3DXCreateTextureFromFile(_device, ".\\img\\banana7.bmp", &_texture[6]);
	D3DXCreateTextureFromFile(_device, ".\\img\\banana8.bmp", &_texture[7]);
	
	_device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	_device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	
	return true;
}

void Box_Texture::Render(IDirect3DDevice9* _device)
{
	_device->SetStreamSource(0, _vb, 0, sizeof(TextureVertex));
	_device->SetIndices(_ib);
	_device->SetFVF(TextureVertex::FVF);

	_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	_device->SetRenderState(D3DRS_LIGHTING, false);
	_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);


	_device->SetTransform( D3DTS_WORLD, &m_Transform);
	//draw
	_device->SetTexture(0, _texture[0]);
	_device->DrawIndexedPrimitive( D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);

	_device->SetTexture(0, _texture[1]);
	_device->DrawIndexedPrimitive( D3DPT_TRIANGLELIST, 0, 0, 4, 6, 2);

	_device->SetTexture(0, _texture[2]);
	_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 12, 2);

	_device->SetTexture(0, _texture[3]);
	_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 18, 2);

	_device->SetTexture(0, _texture[4]);
	_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 24, 2);

	_device->SetTexture(0, _texture[5]);
	_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 30, 2);

	_device->SetTexture(0, _texture[6]);
	_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 36, 2);

	_device->SetTexture(0, _texture[7]);
	_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 42, 2);
}

