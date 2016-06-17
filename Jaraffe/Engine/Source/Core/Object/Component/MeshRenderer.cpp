#include "stdafx.h"
#include "MeshRenderer.h"

DECLARE_IDENTIFIER(Jaraffe::Component::MeshRenderer);

Jaraffe::Component::MeshRenderer::MeshRenderer()
{
}

Jaraffe::Component::MeshRenderer::~MeshRenderer()
{
}

void Jaraffe::Component::MeshRenderer::Init()
{
	
}

void Jaraffe::Component::MeshRenderer::Update()
{

}

void Jaraffe::Component::MeshRenderer::Render()
{
	auto* transform = GetOwner()->GetComponent<Jaraffe::Component::Transform>();
	auto* mesh		= GetOwner()->GetComponent<Jaraffe::Component::Mesh>();

	// Set Layout And Topology
	gRENDERER->GetDC()->IASetInputLayout(mesh->m_pInputLayout);
	gRENDERER->GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// Set VertexBuffer And IndexBuffer
	UINT stride = mesh->m_Stride;
	UINT offset = 0;
	gRENDERER->GetDC()->IASetVertexBuffers(0, 1, &mesh->m_pVB, &stride, &offset);
	gRENDERER->GetDC()->IASetIndexBuffer(mesh->m_pIB, DXGI_FORMAT_R32_UINT, 0);

	// worldViewProj ����� ���Ѵ�.
	XMMATRIX world	= XMLoadFloat4x4(&transform->GetTransformMatrix());
	XMMATRIX view	= Camera::g_pMainCamera->GetView();
	XMMATRIX proj	= Camera::g_pMainCamera->GetProj();
	XMMATRIX worldViewProj = world * view * proj;

	XMMATRIX worldInvTranspose = Jaraffe::Util::MathHelper::InverseTranspose(world);

	// ���̴��� ����� ����.
	Effects::BasicFX->SetEyePosW(Camera::g_pMainCamera->GetEyePos());
	Effects::BasicFX->SetDirLights(Jaraffe::Component::Light::m_vLights[0]->GetDirectionalLight());		// TODO : ������ �����丵 1����. ���� ������.

	Effects::BasicFX->SetWorldViewProj(worldViewProj);
	Effects::BasicFX->SetWorld(world);
	Effects::BasicFX->SetWorldInvTranspose(worldInvTranspose);
	Effects::BasicFX->SetMaterial(m_Material->m_Material);

	XMMATRIX I = XMMatrixIdentity();
	Effects::BasicFX->SetTexTransform(I);																// TODO : ��� ���ٰ� ���� ������... �ϴ��� ������ ����� ��Ʈ���� ���� ����.
	Effects::BasicFX->SetDiffuseMap(m_Material->m_MainTexture->m_pTexture);								// TODO : �ؽ��� �Ŵ����� ���� �ʱ�ܰ�.
	Effects::BasicFX->SetTime(0.0f);																	// TODO : ���� �ð� �Ŵ��� �ȸ���.

	ID3DX11EffectTechnique* tech = Effects::BasicFX->Light1TexTech;

	D3DX11_TECHNIQUE_DESC techDesc;
	tech->GetDesc(&techDesc);
	for (UINT p = 0; p < techDesc.Passes; ++p)
	{
		tech->GetPassByIndex(p)->Apply(0, gRENDERER->GetDC());

		// ���� 36���� ���ڸ� �׸���.
		gRENDERER->GetDC()->DrawIndexed(mesh->m_IndexCount, 0, 0);
	}
}

void Jaraffe::Component::MeshRenderer::Receve()
{

}

void Jaraffe::Component::MeshRenderer::Release()
{

}