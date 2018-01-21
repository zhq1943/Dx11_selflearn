#include "LightClass.h"


LightClass::LightClass(void)
{
}


LightClass::LightClass(const LightClass&)
{

}

LightClass::~LightClass(void)
{
}

void LightClass::SetDiffuseColor(float r,float g,float b,float a)
{
	m_diffuseColor = D3DXVECTOR4(r,g,b,a);
}

void LightClass::SetDirction(float x,float y,float z)
{
	m_direction = D3DXVECTOR3(x,y,z);
}
