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
	//�L�����N�^�[�R���g���[���[�̏������B
	m_charaCon.Init(
		20.0f,	//�J�v�Z���R���C�_�[�̔��a�B
		40.0f,	//�J�v�Z���R���C�_�[�̍����B
		m_position	//�L�����N�^�[�R���g���[���[�̍��W�B
	);
	return true;
}
void Player::Update()
{
	//�Q�[���p�b�h�̓��͂���A�ړ�������ʂ����߂�B
	m_moveSpeed.x = Pad(0).GetLStickXF() * -300.0f;
	m_moveSpeed.z = Pad(0).GetLStickYF() * -300.0f;
	
	if (Pad(0).IsTrigger(enButtonA)) {
		//A�{�^���������ꂽ��W�����v������B
		//������ɑ��x��ݒ肷��B
		m_moveSpeed.y = 600;
	}
	//�d�͂ɂ��A�������ɗ͂�������B
	m_moveSpeed.y -= 20.0f;

	//�L�����R�����ړ����x��n���āA�L�����R���𓮂����B
	m_position = m_charaCon.Execute(m_moveSpeed);

	m_modelRender->SetPosition(m_position);
	m_modelRender->SetRotation(m_rotation);
}
