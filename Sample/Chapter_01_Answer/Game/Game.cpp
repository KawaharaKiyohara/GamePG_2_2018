#include "stdafx.h"
#include "Game.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Player.h"
#include "Star.h"

Game::Game()
{
	//カメラを設定。
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 500.0f, 1000.0f });
	MainCamera().Update();

	m_level.Init(L"test.tkl", [&](LevelObjectData& objData) {
		if (objData.EqualObjectName(L"unityChan")) {
			//ロードしようとしているオブジェクトはユニティちゃん。
			//フックして、プレイヤークラスを作る。
			Player* pl = NewGO<Player>(0, "プレイヤー");
			//配置情報から座標と回転をプレイヤーに渡す。
			pl->m_position = objData.position;
			pl->m_rotation = objData.rotation;
			return true;
		}
		else if (objData.EqualObjectName(L"star")) {
			Star* s = NewGO<Star>(0, "星");
			s->m_position = objData.position;
			s->m_rotation = objData.rotation;
			s->m_scale = objData.scale;
			return true;
		}
		return false;
	});
}
Game::~Game()
{
	//星という名前のオブジェクトをすべて削除。
	DeleteGOs("星");
	//プレイヤーという名前のオブジェクトをすべて削除。
	DeleteGOs("プレイヤー");
}
void Game::Update()
{
}