#pragma once
#include <D3DX10math.h>
class LightClass
{
public:
	LightClass(void);
	LightClass(const LightClass&);
	~LightClass(void);

	void SetDiffuseColor(float,float,float,float);
	void SetDirction(float,float,float);

	D3DXVECTOR4 GetDiffuseColor(){return m_diffuseColor;};
	D3DXVECTOR3 GetDirection(){return m_direction;};

private:
	D3DXVECTOR4 m_diffuseColor;
	D3DXVECTOR3 m_direction;
};

