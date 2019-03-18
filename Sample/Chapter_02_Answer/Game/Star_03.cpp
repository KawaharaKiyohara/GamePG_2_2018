#include "stdafx.h"
#include "Star_03.h"


Star_03::Star_03()
{
}


Star_03::~Star_03()
{
}
bool Star_03::Start()
{
	//�����X�e�[�g��+X�̕����Ɉړ�����B
	m_state = enState_PositiveRotY;
	//�P�ʃN�H�[�^�j�I��(��]���Ȃ��N�H�[�^�j�I��)�ŏ���������B
	m_rotation = CQuaternion::Identity;
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
void Star_03::Update()
{
	//�^�C�}�[���C���N�������g�B
	m_timer++;
	if (m_state == enState_PositiveRotY) {
		//Y�������+�̕����ɉ�]���B
		//Y�������+1�x�񂷉�]�N�H�[�^�j�I�����쐬�B
		CQuaternion qAddRotY;
		qAddRotY.SetRotationDeg(CVector3::AxisY, 1.0f);
		//��]�����Z����B
		m_rotation *= qAddRotY;

		if (m_timer == 45) {
			//45�t���[���o�߂����̂ŁA��Ԃ�؂�ւ���B
			m_state = enState_NegativeRotY;
			//�^�C�}�[�����Z�b�g����B
			m_timer = 0;
		}
	}
	else if (m_state == enState_NegativeRotY) {
		//Y�������+�̕����ɉ�]���B
		//Y�������+1�x�񂷉�]�N�H�[�^�j�I�����쐬�B
		CQuaternion qAddRotY;
		qAddRotY.SetRotationDeg(CVector3::AxisY, -1.0f);
		//��]�����Z����B
		m_rotation *= qAddRotY;

		if (m_timer == 45) {
			//120�t���[���o�߂����̂ŁA��Ԃ�؂�ւ���B
			m_state = enState_PositiveRotY;
			//�^�C�}�[�����Z�b�g����B
			m_timer = 0;
		}

	}
	//��]��ݒ肷��B
	m_modelRender->SetRotation(m_rotation);
	//���W��ݒ肷��B
	m_modelRender->SetPosition(m_position);

}
