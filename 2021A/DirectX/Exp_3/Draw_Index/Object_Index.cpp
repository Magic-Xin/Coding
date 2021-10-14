#include "Object_Index.h"


Square_Index::Square_Index()
{

}

Square_Index::~Square_Index()
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
}


bool Square_Index::CreateBuffer(IDirect3DDevice9* _device)
{
	HRESULT hr = 0;
	//创建顶点缓存
	hr = _device->CreateVertexBuffer(
		4 *sizeof(Vertex), 
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX,
		D3DPOOL_MANAGED,
		&_vb,
		0);

	if (FAILED(hr))
	{
		MessageBox(0, "Square_Index: CreateVertexBuffer() - FAILED", 0, 0);
		return false;
	}
	//访问顶点缓存区域
	Vertex* v;
	_vb->Lock(0, 0, (void**)&v, 0);

	v[0] = Vertex(-0.5f, -0.5f, 0.0f);
	v[1] = Vertex( 0.5f, -0.5f, 0.0f);
	v[2] = Vertex(-0.5f, 0.5f,  0.0f);
	v[3] = Vertex( 0.5f, 0.5f,  0.0f);

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
		MessageBox(0, "Square_Index: CreateIndexBuffer() - FAILED", 0, 0);
		return false;
	}

	//访问索引缓存区域
	WORD* i = 0;
	_ib->Lock(0, 0, (void**)&i, 0);

	i[0] = 0; i[1] = 2; i[2] = 1;
	i[3] = 2; i[4] = 3; i[5] = 1;

	_ib->Unlock();

	return true;
}

void Square_Index::Render(IDirect3DDevice9* _device)
{
	_device->SetStreamSource(0, _vb, 0, sizeof(Vertex));
	_device->SetIndices(_ib);

	_device->SetFVF(FVF_VERTEX);

	_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	_device->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);

	_device->SetTransform( D3DTS_WORLD, &m_Transform);
	_device->DrawIndexedPrimitive( D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);
}



Plane_Index::Plane_Index()
{
	
}

Plane_Index::~Plane_Index()
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
}


bool Plane_Index::CreateBuffer(IDirect3DDevice9* _device)
{
	return CreateBuffer(_device, 2, 2, 1);
}


bool Plane_Index::CreateBuffer(IDirect3DDevice9* _device, int _width, int _height, float _resolution)
{
	if (_width <= 0 || _height <= 0 || _resolution <= 0)
	{
		MessageBox(0, "Plane_Index parameters are wrong!", 0, 0);
		return false;
	}

	d_width = _width;
	d_height = _height;
	d_resolution = _resolution;

	HRESULT hr = 0;
	//创建顶点缓存
	hr = _device->CreateVertexBuffer(
		(d_width + 1) * (d_height + 1) *sizeof(Vertex), 
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX,
		D3DPOOL_MANAGED,
		&_vb,
		0);

	if (FAILED(hr))
	{
		MessageBox(0, "Plane_Index: CreateVertexBuffer() - FAILED", 0, 0);
		return false;
	}
	//访问顶点缓存区域
	Vertex* _v;
	_vb->Lock(0, 0, (void**)&_v, 0);


	for(int i = 0; i <= d_height; i++)
	{
		for(int j = 0; j <= d_width; j++)
		{
			_v[i * (d_width + 1) + j] = Vertex((j - d_width * 0.5f) * d_resolution, 
							  			(i - d_height * 0.5f) * d_resolution, 
										0.0f);
		}
	}

	_vb->Unlock();

	//创建索引缓存
	hr = _device->CreateIndexBuffer(
		d_width * d_height * 6 * sizeof(WORD),
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&_ib,
		0);
	if (FAILED(hr))
	{
		MessageBox(0, "Plane_Index: CreateIndexBuffer() - FAILED", 0, 0);
		return false;
	}

	//访问索引缓存区域
	WORD* _i = 0;
	_ib->Lock(0, 0, (void**)&_i, 0);

	for(int i = 0; i < d_height; i++)
	{
		for(int j = 0; j < d_width; j++)
		{
			int _cell = i * d_width + j;
			_i[_cell * 6 + 0] = i * (d_width + 1) + j; 
			_i[_cell * 6 + 1] = (i + 1) * (d_width + 1) + j; 
			_i[_cell * 6 + 2] = i * (d_width + 1) + j + 1; 

			_i[_cell * 6 + 3] = (i + 1) * (d_width + 1) + j; 
			_i[_cell * 6 + 4] = (i + 1) * (d_width + 1) + j + 1;  
			_i[_cell * 6 + 5] = i * (d_width + 1) + j + 1;
		}
	}

	_ib->Unlock();

	return true;
}

void Plane_Index::Render(IDirect3DDevice9* _device)
{
	_device->SetStreamSource(0, _vb, 0, sizeof(Vertex));
	_device->SetIndices(_ib);

	_device->SetFVF(FVF_VERTEX);

	_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	_device->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);

	_device->SetTransform( D3DTS_WORLD, &m_Transform);
	_device->DrawIndexedPrimitive( D3DPT_TRIANGLELIST, 0, 0, 
		          (d_width + 1) * (d_height + 1) , 0, d_width * d_height * 2);
}


Cube_Index::Cube_Index()
{
	
}

Cube_Index::~Cube_Index()
{
	if (_ib)
	{
		_ib->Release();
		_ib = 0;
	}
	if (_vb)
	{
		_vb->Release();
		_vb = 0;
	}
}

bool Cube_Index::CreateBuffer(IDirect3DDevice9* _device)
{
	HRESULT hr = 0;
	//Create 
	hr = _device->CreateVertexBuffer(
		8 * sizeof(Vertex),
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX,
		D3DPOOL_MANAGED,
		&_vb,
		0);

	if (FAILED(hr))
	{
		MessageBox(0, "Square_Index: CreateVertexBuffer() - FAILED", 0, 0);
		return false;
	}
	//访问顶点缓存区域
	VOID* v;
	_vb->Lock(0, 0, (void**)&v, 0);

	Vertex vertices[] = {
		{-1.0f, 1.0f, -1.0f },
		{1.0f, 1.0f, -1.0f},
		{-1.0f, -1.0f, -1.0f},
		{1.0f, -1.0f, -1.0f},
		{-1.0f, 1.0f, 1.0f},
		{1.0f, 1.0f, 1.0f},
		{-1.0f, -1.0f, 1.0f},
		{1.0f, -1.0f, 1.0f}
	};
	memcpy(v, vertices, sizeof(vertices));

	_vb->Unlock();

	//创建索引缓存
	hr = _device->CreateIndexBuffer(
		6 * 2 * 3 * sizeof(WORD),
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&_ib,
		0);
	if (FAILED(hr))
	{
		MessageBox(0, "Square_Index: CreateIndexBuffer() - FAILED", 0, 0);
		return false;
	}

	//访问索引缓存区域
	VOID* i = 0;
	_ib->Lock(0, 0, (void**)&i, 0);

	short indices[] =
	{
		0, 1, 2,
		2, 1, 3,
		4, 0, 6,
		6, 0, 2,
		7, 5, 6,
		6, 5, 4,
		3, 1, 7,
		7, 1, 5,
		4, 5, 0,
		0, 5, 1,
		3, 7, 2,
		2, 7, 6,
	};
	memcpy(i, indices, sizeof(indices));

	_ib->Unlock();

	return true;
}

void Cube_Index::Render(IDirect3DDevice9* _device)
{
	_device->SetStreamSource(0, _vb, 0, sizeof(Vertex));
	_device->SetIndices(_ib);

	_device->SetFVF(FVF_VERTEX);

	_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	_device->SetTransform(D3DTS_WORLD, &m_Transform);
	_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0,8, 0, 12);
}
