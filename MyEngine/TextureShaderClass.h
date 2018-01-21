#pragma once
#include <d3d11.h>
#include <D3DX10math.h>
#include <D3DX11async.h>
#include <fstream>

using namespace  std;
class TextureShaderClass
{
private:
	struct MatrixBufferType
	{
		D3DXMATRIX world;
		D3DXMATRIX view;
		D3DXMATRIX projection;
	};
public:
	TextureShaderClass(void);
	TextureShaderClass(const TextureShaderClass&);
	virtual ~TextureShaderClass(void);

	bool Initialize(ID3D11Device* device,HWND hwnd);
	void Shutdown();
	bool Render(ID3D11DeviceContext* deviceContext,int,D3DXMATRIX,D3DXMATRIX,D3DXMATRIX,ID3D11ShaderResourceView* texture);

private:
	bool InitializeShader(ID3D11Device* device,HWND hwnd,WCHAR* ,WCHAR*);
	void ShutdownShader();
	void OutputShaderErrorMessage(ID3D10Blob* errorMessage,HWND hwnd,WCHAR* shaderFilename);

	bool SetShaderParameters(ID3D11DeviceContext* deviceContext,D3DXMATRIX,D3DXMATRIX ,D3DXMATRIX,ID3D11ShaderResourceView* );
    void RenderShader(ID3D11DeviceContext* devicecContext,int);

private:
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11Buffer* m_matrixBuffer;

	ID3D11SamplerState* m_sampleState;
};

