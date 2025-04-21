#pragma once
#include"bullet.h"

class C_Player
{
public:

	C_Player();
	~C_Player();

	void Init();
	void Update(POINT mousePos);
	void Draw();

	void SetTex(KdTexture* pTex);

private:

	static const int m_bulletNum = 100;

	const float m_moveSpeed = 5.0f;

	C_Bullet m_bullet[m_bulletNum];
	KdTexture m_bulletTex;

	KdTexture *m_pTex;
	Math::Vector2 m_pos;
	Math::Matrix m_mat;
};