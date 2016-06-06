#include "stdafx.h"
#include "RenderStates.h"

// Staitc Values
ID3D11RasterizerState* Jaraffe::RenderStates::m_WireframeRS = 0;	// ���̾������� ������.
ID3D11RasterizerState* Jaraffe::RenderStates::m_SolidRS = 0;	// �ϴ� ����ü ������.

void Jaraffe::RenderStates::InitAll(ID3D11Device * device)
{
	//
	// WireframeRS
	//
	D3D11_RASTERIZER_DESC wireframeDesc;
	ZeroMemory(&wireframeDesc, sizeof(D3D11_RASTERIZER_DESC));
	wireframeDesc.FillMode = D3D11_FILL_WIREFRAME;
	wireframeDesc.CullMode = D3D11_CULL_BACK;
	wireframeDesc.FrontCounterClockwise = false;
	wireframeDesc.DepthClipEnable = true;

	HR(device->CreateRasterizerState(&wireframeDesc, &m_WireframeRS));

	//
	// NoCullRS
	//
	D3D11_RASTERIZER_DESC noCullDesc;
	ZeroMemory(&noCullDesc, sizeof(D3D11_RASTERIZER_DESC));
	noCullDesc.FillMode = D3D11_FILL_SOLID;
	noCullDesc.CullMode = D3D11_CULL_NONE;
	noCullDesc.FrontCounterClockwise = false;
	noCullDesc.DepthClipEnable = true;

	HR(device->CreateRasterizerState(&noCullDesc, &m_SolidRS));
}

void Jaraffe::RenderStates::DestroyAll()
{
}
