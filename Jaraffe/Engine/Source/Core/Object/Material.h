#pragma once

namespace Jaraffe 
{

// TODO : �ӽ� ����.
class Material : public Jaraffe::Object
{
// ****************************************************************************
// Constructor/Destructor)
// ----------------------------------------------------------------------------
public:
	Material();
	virtual ~Material();

// ****************************************************************************
// Public Members)
// ----------------------------------------------------------------------------
public:
	Jaraffe::Light::Material	m_Material;
	Jaraffe::Texture*			m_MainTexture;
};

}