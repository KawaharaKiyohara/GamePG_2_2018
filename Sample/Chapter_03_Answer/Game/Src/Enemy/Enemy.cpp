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
		//�܂��v���C���[�̃C���X�^���X����������B
		CPlayer* player = FindGO<CPlayer>("Player");
		//�G����v���C���[�Ɍ������ĐL�т�x�N�g��diff���v�Z����B
		CVector3 diff = player->GetPosition() - m_position;
		//diff�̒��������߂�distance�ɑ������B
		float distance = diff.Length();
		//�v���C���[�Ƃ̋�����400�ȉ��ɂȂ�����ǐՏ�ԂɑJ�ڂ���B
		if (distance < 400) {
			//�����A�j���[�V�������Đ�����B
			m_skinModelRender->PlayAnimation(enAnimation_Walk);
			//��Ԃ�ǐՂɂ���B
			m_state = enState_Tracking;
		}
	}
	else if (m_state == enState_Tracking) {
		//�ǐՏ�Ԃ̎��̏����B
		//�܂��v���C���[�̃C���X�^���X����������B
		CPlayer* player = FindGO<CPlayer>("Player");
		//�G����v���C���[�Ɍ������ĐL�т�x�N�g��v���v�Z����B
		CVector3 v = player->GetPosition() - m_position;
		//��Ŏg���̂ŁA�v���C���[�܂ł̋������v�Z����B
		float distance = v.Length();
		//v�𐳋K�����đ傫���P�ɂ���(�����݂̂̃x�N�g���ɂ���)
		v.Normalize();
		//v�̑傫�����R�{�ɂ��āA�G�̍��W�ɑ����Z����B
		m_position += v * 3.0f;
		//�v���C���[�Ƃ̋�����400�ȉ��ɂȂ�����ǐՏ�ԂɑJ�ڂ���B
		if (distance < 50) {
			//�����A�j���[�V�������Đ�����B
			m_skinModelRender->PlayAnimation(enAnimation_Attack);
			//��Ԃ�ǐՂɂ���B
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
