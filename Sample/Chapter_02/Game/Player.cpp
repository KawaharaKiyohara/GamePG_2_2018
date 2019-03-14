#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	
}
Player::~Player()
{
}
bool Player::Start()
{
	m_modelRender = NewGO<prefab::CSkinModelRender>(0);
	m_modelRender->Init(L"modelData/unityChan.cmo");
	//キャラクターコントローラーの初期化。
	m_charaCon.Init(
		20.0f,	//カプセルコライダーの半径。
		40.0f,	//カプセルコライダーの高さ。
		m_position	//キャラクターコントローラーの座標。
	);
	return true;
}
void Player::Update()
{
	//ゲームパッドの入力から、移動させる量を決める。
	m_moveSpeed.x = Pad(0).GetLStickXF() * -300.0f;
	m_moveSpeed.z = Pad(0).GetLStickYF() * -300.0f;
	
	if (Pad(0).IsTrigger(enButtonA)) {
		//Aボタンが押されたらジャンプさせる。
		//上方向に速度を設定する。
		m_moveSpeed.y = 600;
	}
	//重力により、下方向に力を加える。
	m_moveSpeed.y -= 20.0f;

	//キャラコンを移動速度を渡して、キャラコンを動かす。
	m_position = m_charaCon.Execute(m_moveSpeed);

	m_modelRender->SetPosition(m_position);
	m_modelRender->SetRotation(m_rotation);
}
