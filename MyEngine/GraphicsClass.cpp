#include "GraphicsClass.h"

GraphicsClass::GraphicsClass()
{
	m_D3D = 0;
	m_Camera = 0;
	m_Model = 0;
	m_ColorShader = 0;

	m_TextureShader = 0;

	m_Light = 0;
	m_LightShader = 0;
}

GraphicsClass::GraphicsClass(const GraphicsClass&)
{

}

GraphicsClass::~GraphicsClass()
{

}

bool GraphicsClass::Initialize(int screenWidth,int screenHeight,HWND hwnd)
{
	bool result;

	m_D3D = new D3DClass;
	if (!m_D3D)
	{
		return false;
	}

	result = m_D3D->Initialize(screenWidth,screenHeight,VSYNC_ENABLED,hwnd,FULL_SCREEN,SCREEN_DEPTH,SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd,L"Could not initialize Direct3D",L"Error",MB_OK);
		return false;
	}

	m_Camera = new CameraClass;
	if (!m_Camera)
	{
		return false;
	}

	m_Camera->SetPosition(0,0,-10);

	m_Model = new ModelClass;
	if (!m_Model)
	{
		return false;
	}

	result = m_Model->Initialize(m_D3D->GetDevice(),L"../MyEngine/data/test.dds");
	if (!result)
	{
		MessageBox(hwnd,L"model error",L"error",MB_OK);
		return false;
	}

// 	m_ColorShader = new ColorShaderClass;
// 	if (!m_ColorShader)
// 	{
// 		return false;
// 	}
// 
// 	result = m_ColorShader->Initialize(m_D3D->GetDevice(),hwnd);
// 	if (!result)
// 	{
// 		MessageBox(hwnd,L"ColorShader error",L"error",MB_OK);
// 		return false;
// 	}

// 	m_TextureShader = new TextureShaderClass;
// 	if (!m_TextureShader)
// 	{
// 		return false;
// 	}
// 
// 	result = m_TextureShader->Initialize(m_D3D->GetDevice(),hwnd);
// 	if (!result)
// 	{
// 		MessageBox(hwnd,L"texture shader error",L"error",MB_OK);
// 		return false;
// 	}

	m_LightShader = new LightShaderClass;
	if(!m_LightShader)
	{
		return false;
	}

	result = m_LightShader->Initialize(m_D3D->GetDevice(),hwnd);
	if (!result)
	{
		MessageBox(hwnd,L"light shader object error",L"Error",MB_OK);
		return false;
	}

	m_Light = new LightClass;
	if (!m_Light)
	{
		return false;
	}

	m_Light->SetDiffuseColor(1.0f,1.0f,1.0f,1.0f);
	m_Light->SetDirction(0.0f,0.0f,1.0f);

	return true;
}

void GraphicsClass::Showdown()
{
// 	if (m_ColorShader)
// 	{
// 		m_ColorShader->Shutdown();
// 		delete m_ColorShader;;
// 		m_ColorShader = 0;
// 	}

	if (m_Light)
	{
		delete m_Light;
		m_Light = 0;
	}

	if (m_LightShader)
	{
		m_LightShader->Shutdown();
		delete m_LightShader;
		m_LightShader = 0;
	}

	if (m_TextureShader)
	{
		m_TextureShader->Shutdown();
		delete m_TextureShader;
		m_TextureShader = 0;
	}

	if (m_Model)
	{
		m_Model->Shutdown();
		delete m_Model;;
		m_Model = 0;
	}

	if (m_Camera)
	{
		delete m_Camera;;
		m_Camera = 0;
	}

	if (m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}
	return;
}

bool GraphicsClass::Frame()
{
	bool result;

	static float rotation = 0.0f;

	rotation += (float)D3DX_PI*0.01f;
	if (rotation > 360)
	{
		rotation -= 360;
	}
	result = Render(rotation);
	if (!result)
	{
		return false;
	}
	return true;
}

bool GraphicsClass::Render(float rotation)
{
	D3DXMATRIX viewMatrix,projectMatrix,worldMatrix;
	bool result;
	m_D3D->BeginScene(0.5f,0.5f,0.5f,1.0f);

	m_Camera->Render();
	m_Camera->GetViewMatrix(viewMatrix);
	m_D3D->GetWorldMatrix(worldMatrix);
	m_D3D->GetProjectionMatrix(projectMatrix);

	D3DXMatrixRotationY(&worldMatrix,rotation);

	m_Model->Render(m_D3D->GetDeviceContext());
// 	result = m_ColorShader->Render(m_D3D->GetDeviceContext(),m_Model->GetIndexCount(),worldMatrix,viewMatrix,projectMatrix);
// 	if (!result)
// 	{
// 		return false;
// 	}
// 	result = m_TextureShader->Render(m_D3D->GetDeviceContext(),m_Model->GetIndexCount(),worldMatrix,viewMatrix,projectMatrix,m_Model->GetTexture());
//     if (!result)
//     {
// 		return false;
//     }

	result = m_LightShader->Render(m_D3D->GetDeviceContext(),m_Model->GetIndexCount(),worldMatrix,viewMatrix,projectMatrix,m_Model->GetTexture(),m_Light->GetDirection(),m_Light->GetDiffuseColor());
	if (!result)
	{
		return false;
	}
	m_D3D->EndScene();
	return true;
}
