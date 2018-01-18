#pragma once

#pragma  comment(lib,"dxgi.lib")
#pragma  comment(lib,"d3d11.lib")
#pragma  comment(lib,"d3dx11.lib")
#pragma  comment(lib,"d3dx10.lib")

#include <dxgi.h>
#include <D3DCommon.h>
#include <d3d11.h>
#include <D3DX10math.h>


class D3DClass
{
public:
	D3DClass(void);
	D3DClass(const D3DClass&);
	~D3DClass(void);

	bool Initialize(int,int,bool,HWND,bool,float,float);
	void Shutdown();

	void BeginScene(float,float,float,float);
	void EndScene();

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetDeviceContext();

	void GetProjectionMatrix(D3DXMATRIX&);
	void GetWorldMatrix(D3DXMATRIX&);
	void GetOrthoMatrix(D3DXMATRIX&);

	void GetVedioCardInfo(char*, int&);

private:
	bool m_vsync_enable;
	int m_videoCardMemory;
	char m_vedioCardDescription[128];
	IDXGISwapChain* m_swapChain; //交换链
	ID3D11Device* m_device; //设备
	ID3D11DeviceContext* m_deviceContext; //设备上下文
	ID3D11RenderTargetView* m_renderTargetView; //渲染目标
	ID3D11Texture2D* m_depthStencilBuffer;
	ID3D11DepthStencilState* m_depthStencilState;
	ID3D11DepthStencilView* m_depthStencilView;
	ID3D11RasterizerState* m_rasterState;
	D3DXMATRIX m_projectionMatrix;
	D3DXMATRIX m_worldMatrix;
	D3DXMATRIX m_orthoMatrix;
};

