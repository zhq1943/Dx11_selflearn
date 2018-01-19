#pragma once
#include <d3d11.h>
#include <D3DX11tex.h>
class TextureClass
{
public:
	TextureClass(void);
	TextureClass(const TextureClass&);
	~TextureClass(void);

	bool Initialize(ID3D11Device* ,WCHAR*);
	void Shutdown();

	ID3D11ShaderResourceView* GetTexture();

private:
	ID3D11ShaderResourceView* m_texture;
};

