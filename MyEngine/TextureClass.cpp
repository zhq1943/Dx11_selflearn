#include "TextureClass.h"


TextureClass::TextureClass(void)
{
	m_texture = 0;
}

TextureClass::TextureClass( const TextureClass& )
{

}


TextureClass::~TextureClass(void)
{
}

bool TextureClass::Initialize( ID3D11Device* device,WCHAR* filename)
{
	HRESULT resutl;
	resutl = D3DX11CreateShaderResourceViewFromFile(device,filename,NULL,NULL,&m_texture,NULL);

	if (FAILED(resutl))
	{
		return false;
	}

	return true;
}

void TextureClass::Shutdown()
{
	if (m_texture)
	{
		m_texture->Release();
		m_texture = 0;
	}
}

ID3D11ShaderResourceView* TextureClass::GetTexture()
{
	return m_texture;
}
