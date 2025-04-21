#include "enemy.h"

C_Enemy::C_Enemy()
{

}

C_Enemy::~C_Enemy()
{

}

void C_Enemy::Init()
{
	m_pos.x = 0;
	m_pos.y = 100;
	m_move.x = m_enemymove;
	m_move.y = 0;


}

void C_Enemy::Update()
{
	m_pos += m_move;

	if (m_pos.x >= 640 - 32 || m_pos.x <= -640 + 32)
	{
		m_move.x *= -1;
	}

	m_emat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
}

void C_Enemy::Draw()
{
	//行列をセットする
	SHADER.m_spriteShader.SetMatrix(m_emat);
	SHADER.m_spriteShader.DrawTex(m_eTex, Math::Rectangle(0, 0, 64, 64), 1.0f);
}

void C_Enemy::SetTex(KdTexture* eTex)
{
	m_eTex = eTex;
}
