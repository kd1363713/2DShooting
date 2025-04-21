#pragma once

class C_Enemy
{
public:

	C_Enemy();
	~C_Enemy();

	void Init();
	void Update();
	void Draw();

	void SetTex(KdTexture* eTex);

private:

	const float m_enemymove = 7.0f;

	KdTexture* m_eTex;
	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	Math::Matrix m_emat;

};