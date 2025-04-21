#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	m_player.Draw();
	m_enemy.Draw();
}

void Scene::Update()
{
	CalcMousePos();
	m_player.Update(m_mousePos);
	m_enemy.Update();
}

void Scene::Init()
{
	m_playerTex.Load("Texture/player.png");
	m_player.SetTex(&m_playerTex);
	m_enemyTex.Load("Texture/enemy.png");
	m_enemy.SetTex(&m_enemyTex);

	m_player.Init();
	m_enemy.Init();
}

void Scene::Release()
{
	m_playerTex.Release();
	m_enemyTex.Release();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(10, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}

void Scene::CalcMousePos()
{
	//マウスカーソルを読み込む
	GetCursorPos(&m_mousePos);
	//スクリーン座標をクライアント座標に変更
	ScreenToClient(APP.m_window.GetWndHandle(), &m_mousePos);
	m_mousePos.x -= 640;
	m_mousePos.y -= 360;
	m_mousePos.y *= -0.25;
}
