#pragma once
#include"player.h"
#include"enemy.h"
#include"bullet.h"


class Scene
{
private:

	POINT m_mousePos;

	C_Player m_player;//�N���X�̕ϐ�
	KdTexture m_playerTex;

	C_Enemy m_enemy;//�N���X�̕ϐ�
	KdTexture m_enemyTex;


public:

	// �����ݒ�
	void Init();

	// ���
	void Release();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw2D();

	// GUI����
	void ImGuiUpdate();

	//�}�E�X���W�v�Z
	void CalcMousePos();

private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
