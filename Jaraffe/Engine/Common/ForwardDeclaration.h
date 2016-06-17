#pragma once

// TODO : ���� ���� ��� �����丵 �Ҷ� �̺κ� �������ų� �̵��Ҽ�����. ( �׳� ������� ����� �ٽ� ó������ ¥�°� ��������?.. )
namespace Jaraffe
{
	class CScene;
	class CD3DDevice;

	class Effect;
	class SimpleEffect;
	class BasicEffect;
	class Effects;

	class InputLayoutDesc;
	class InputLayouts;

	struct DirectionalLight;
	struct PointLight;
	struct SpotLight;
	struct Material;

	namespace Component
	{
		class Transform;
		class Camera;
		class Renderer;
		class Mesh;
		class Light;
		class Material;
	}

	namespace Util
	{
		class CGameTimer;
		class MyDirectUtil;
		class MathHelper;
	}

	namespace Geometry
	{
	}
}

