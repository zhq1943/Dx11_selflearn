#include "CameraClass.h"


CameraClass::CameraClass(void)
{
	m_positionX = 0.0f;
	m_positionY = 0.0f;
	m_positionZ = 0.0f;

	m_rotationX = 0.0f;
	m_rotationY = 0.0f;
	m_rotationZ = 0.0f;
}


CameraClass::CameraClass(const CameraClass&)
{

}

CameraClass::~CameraClass(void)
{
}

void CameraClass::SetPosition(float x,float y,float z)
{
	m_positionX = x;
	m_positionY = y;
	m_positionZ = z;
}

void CameraClass::SetRotation(float x,float y,float z)
{
	m_rotationX = x;
	m_rotationY = y;
	m_rotationZ = z;
}

D3DXVECTOR3 CameraClass::GetPosition()
{
	return D3DXVECTOR3(m_positionX,m_positionY,m_positionZ);
}

D3DXVECTOR3 CameraClass::GetRotation()
{
	return D3DXVECTOR3(m_rotationX,m_rotationY,m_rotationZ);
}

void CameraClass::Render()
{
	D3DXVECTOR3 up,position,lookAt;
	float yaw,pitch,roll;
	D3DXMATRIX rotationMatrix;

	up.x = 0;
	up.y = 1;
	up.z = 0;

	position.x = m_positionX;
	position.y = m_positionY;
	position.z = m_positionZ;

	lookAt.x = 0.0f;
	lookAt.y = 0.0f;
	lookAt.z = 1.0f;

	pitch = m_rotationX*0.01745;
	yaw = m_rotationY*0.01745;
	roll = m_rotationZ*0.01745;

	D3DXMatrixRotationYawPitchRoll(&rotationMatrix,yaw,pitch,roll);
	D3DXVec3TransformCoord(&lookAt,&lookAt,&rotationMatrix);
	D3DXVec3TransformCoord(&up,&up,&rotationMatrix);

	lookAt = position + lookAt;

	D3DXMatrixLookAtLH(&m_viewMatrix,&position,&lookAt,&up);

}

void CameraClass::GetViewMatrix(D3DXMATRIX& viewMatrix)
{
	viewMatrix = m_viewMatrix;
}
