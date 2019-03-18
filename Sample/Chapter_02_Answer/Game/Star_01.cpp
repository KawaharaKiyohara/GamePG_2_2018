#include "stdafx.h"
#include "Star_01.h"


Star_01::Star_01()
{
}


Star_01::~Star_01()
{
}
bool Star_01::Start()
{
	//�����X�e�[�g�͏㏸�ɂ���B
	m_state = enState_Up;
	//�^�C�}�[�̏����l��0�ɂ���B
	m_timer = 0;
	//CSkinModelRender�̃C���X�^���X���쐬����B
	m_modelRender = NewGO<prefab::CSkinModelRender>(0);
	//cmo�t�@�C�������[�h����B
	m_modelRender->Init(L"modelData/star.cmo");
	//�e�ŗ���ݒ肷��B
	m_modelRender->SetScale(m_scale);
	return true;
}
void Star_01::Update()
{
	//�^�C�}�[���C���N�������g�B
	m_timer++;
	if (m_state == enState_Down) {
		//���~��Ԃ̎��̏����B
		m_position.y -= 1.0f;
		if (m_timer == 120) {
			//120�t���[���o�߂����̂ŁA��Ԃ�؂�ւ���B
			m_state = enState_Up;
			//�^�C�}�[�����Z�b�g����B
			m_timer = 0;
		}
	}
	else if (m_state == enState_Up) {
		//�㏸��Ԃ̎��̏����B
		m_position.y += 1.0f;
		if (m_timer == 120) {
			//120�t���[���o�߂����̂ŁA��Ԃ�؂�ւ���B
			m_state = enState_Down;
			//�^�C�}�[�����Z�b�g����B
			m_timer = 0;
		}

	}
	//���W��ݒ肷��B
	m_modelRender->SetPosition(m_position);
}
