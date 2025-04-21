#pragma once
class C_Bullet
{
public:

	C_Bullet();
	~C_Bullet();

	void Init();
	void Update();
	void Draw();

	void SetTex(KdTexture* bTex);
	bool GetAlive();

	void Shot(Math::Vector2 pos, float targetAngle);

private:

	const float m_moveSpeed = 10.0f;

	KdTexture* m_bTex;
	Math::Vector2 m_pos;
	Math::Matrix m_mat;
	float m_angle;
	bool m_alive;
};