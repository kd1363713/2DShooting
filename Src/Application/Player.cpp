#include "Player.h"

C_Player::C_Player()
{
	
}

C_Player::~C_Player()
{
	m_bulletTex.Release();
}

void C_Player::Init()
{
	m_pos.x = -300;
	m_pos.y = 0;

	m_bulletTex.Load("Texture/bullet.png");

	for (int i = 0; i < m_bulletNum; i++)
	{
		m_bullet[i].SetTex(&m_bulletTex);
		m_bullet[i].Init();
	}
}

void C_Player::Update(POINT mousePos)
{
	//if (GetAsyncKeyState('D') & 0x8000)m_pos.x += m_moveSpeed;
	//if (GetAsyncKeyState('A') & 0x8000)m_pos.x -= m_moveSpeed;
	if (GetAsyncKeyState('W') & 0x8000) {
		if ( m_pos.y<= 150)
		{
			m_pos.y += m_moveSpeed;
		}
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		if (m_pos.y >= -150)m_pos.y -= m_moveSpeed;
	}


	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		for (int i = 0; i < m_bulletNum; i++)
		{
			if (!m_bullet[i].GetAlive())
			{
				const float x = mousePos.x - m_pos.x;
				const float y = mousePos.y - m_pos.y;
				const float radian = atan2(y, x);

				m_bullet[i].Shot(m_pos, radian);
				break;
			}
		}
	}
	m_mat = Math::Matrix::CreateTranslation(m_pos.x/4, m_pos.y/4, 0);
	
	for (int i = 0; i < m_bulletNum; i++)
	{
		m_bullet[i].Update();
	}
}

void C_Player::Draw()
{
	//行列をセットする
	SHADER.m_spriteShader.SetMatrix(m_mat);
	Math::Rectangle srcRect = { 0,0,64,64 }; //テクスチャ座標
	Math::Color color = { 1.0f,1.0f,1.0f,1.0f }; //色RGB
	SHADER.m_spriteShader.DrawTex(m_pTex, m_pos.x, m_pos.y, &srcRect, &color);
	
	for (int i = 0; i < m_bulletNum; i++)
	{
		m_bullet[i].Draw();
	}
}

void C_Player::SetTex(KdTexture* pTex)
{
	m_pTex = pTex;
}
