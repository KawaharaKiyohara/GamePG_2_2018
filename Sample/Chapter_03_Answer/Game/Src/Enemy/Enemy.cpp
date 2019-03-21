/*!
 * @brief	エネミー。
 */

#include "stdafx.h"
#include "Enemy.h"
#include "Player/Player.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
	DeleteGO(m_skinModelRender);
}

void Enemy::InitAnimationClips()
{
	//アニメーションクリップのロード。
	m_animClips[enAnimation_Idle].Load(L"animData/enemy/idle.tka");
	m_animClips[enAnimation_Idle].SetLoopFlag(true);

	m_animClips[enAnimation_Walk].Load(L"animData/enemy/walk.tka");
	m_animClips[enAnimation_Walk].SetLoopFlag(true);

	m_animClips[enAnimation_Attack].Load(L"animData/enemy/attack.tka");
	m_animClips[enAnimation_Attack].SetLoopFlag(false);
}
void Enemy::InitSkinModelRender()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/enemy_00.cmo", m_animClips, enAnimation_Num);
	m_skinModelRender->SetShadowCasterFlag(true);
	m_skinModelRender->SetShadowReceiverFlag(true);
}
bool Enemy::Start()
{
	//アニメーションクリップの初期化。
	InitAnimationClips();
	//スキンモデルの初期化。
	InitSkinModelRender();

	m_skinModelRender->SetScale({ 4.0f, 4.0f, 4.0f });
	m_state = enState_Idle; //初期ステートは待機状態
	return true;
}

void Enemy::Update()
{
	if (m_state == enState_Idle) {
		//待機状態の時の処理。
		//まずプレイヤーのインスタンスを検索する。
		CPlayer* player = FindGO<CPlayer>("Player");
		//敵からプレイヤーに向かって伸びるベクトルdiffを計算する。
		CVector3 diff = player->GetPosition() - m_position;
		//diffの長さを求めてdistanceに代入する。
		float distance = diff.Length();
		//プレイヤーとの距離が400以下になったら追跡状態に遷移する。
		if (distance < 400) {
			//歩くアニメーションを再生する。
			m_skinModelRender->PlayAnimation(enAnimation_Walk);
			//状態を追跡にする。
			m_state = enState_Tracking;
		}
	}
	else if (m_state == enState_Tracking) {
		//追跡状態の時の処理。
		//まずプレイヤーのインスタンスを検索する。
		CPlayer* player = FindGO<CPlayer>("Player");
		//敵からプレイヤーに向かって伸びるベクトルvを計算する。
		CVector3 v = player->GetPosition() - m_position;
		//後で使うので、プレイヤーまでの距離を計算する。
		float distance = v.Length();
		//vを正規化して大きさ１にする(方向のみのベクトルにする)
		v.Normalize();
		//vの大きさを３倍にして、敵の座標に足し算する。
		m_position += v * 3.0f;
		//プレイヤーとの距離が400以下になったら追跡状態に遷移する。
		if (distance < 50) {
			//歩くアニメーションを再生する。
			m_skinModelRender->PlayAnimation(enAnimation_Attack);
			//状態を追跡にする。
			m_state = enState_Attack;
		}
	}
	else if (m_state == enState_Attack) {
		if (m_skinModelRender->IsPlayingAnimation() == false) {
			m_skinModelRender->PlayAnimation(enState_Idle);
			m_state = enState_Idle;
		}
	}
	
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	
}
