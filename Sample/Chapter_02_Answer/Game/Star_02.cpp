#include "stdafx.h"
#include "Star_02.h"


Star_02::Star_02()
{
}


Star_02::~Star_02()
{
}
bool Star_02::Start()
{
	//�����X�e�[�g��+X�̕����Ɉړ�����B
	m_state = enState_PositiveX;
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
void Star_02::Update()
{
	//�^�C�}�[���C���N�������g�B
	m_timer++;
	if (m_state == enState_PositiveX) {
		//+X�̕����Ɉړ����̎��̏����B
		m_position.x += 1.0f;
		if (m_timer == 120) {
			//120�t���[���o�߂����̂ŁA��Ԃ�؂�ւ���B
			m_state = enState_NegativeX;
			//�^�C�}�[�����Z�b�g����B
			m_timer = 0;
		}
	}
	else if (m_state == enState_NegativeX) {
		//-X�̕����Ɉړ����̎��̏����B
		m_position.x -= 1.0f;
		if (m_timer == 120) {
			//120�t���[���o�߂����̂ŁA��Ԃ�؂�ւ���B
			m_state = enState_PositiveX;
			//�^�C�}�[�����Z�b�g����B
			m_timer = 0;
		}

	}
	//���W��ݒ肷��B
	m_modelRender->SetPosition(m_position);
}
