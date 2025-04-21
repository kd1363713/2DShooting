#pragma once
#include"player.h"
#include"enemy.h"
#include"bullet.h"


class Scene
{
private:

	POINT m_mousePos;

	C_Player m_player;//クラスの変数
	KdTexture m_playerTex;

	C_Enemy m_enemy;//クラスの変数
	KdTexture m_enemyTex;


public:

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理
	void Update();

	// 描画処理
	void Draw2D();

	// GUI処理
	void ImGuiUpdate();

	//マウス座標計算
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
