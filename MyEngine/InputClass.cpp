#include "InputClass.h"
InputClass::InputClass()
{

}

InputClass::InputClass(const InputClass&)
{

}

InputClass::~InputClass()
{

}

void InputClass::Initiallize()
{
	int i;
	for (i=0;i<256;i++)
	{
		m_keys[i]=false;
	}
}

void InputClass::KeyDown(unsigned int input)
{
	m_keys[input] = true;
	return;
}

void InputClass::KeyUp(unsigned int input)
{
	m_keys[input]=false;
	return;
}

bool InputClass::IsKeyDown(unsigned int key)
{
	return m_keys[key];
}

