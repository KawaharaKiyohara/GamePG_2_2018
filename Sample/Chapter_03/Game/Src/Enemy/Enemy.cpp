/*!
 * @brief	�G�l�~�[�B
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
	//�A�j���[�V�����N���b�v�̃��[�h�B
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
	//�A�j���[�V�����N���b�v�̏������B
	InitAnimationClips();
	//�X�L�����f���̏������B
	InitSkinModelRender();

	m_skinModelRender->SetScale({ 4.0f, 4.0f, 4.0f });
	m_state = enState_Idle; //�����X�e�[�g�͑ҋ@���
	return true;
}

void Enemy::Update()
{
	if (m_state == enState_Idle) {
		//�ҋ@��Ԃ̎��̏����B

	}
	
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	
}
