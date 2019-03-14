#include "stdafx.h"
#include "Star.h"


Star::Star()
{
}


Star::~Star()
{
	DeleteGO(m_modelRender);
}

bool Star::Start()
{
	m_modelRender = NewGO<prefab::CSkinModelRender>(0);
	//cmo�t�@�C�������[�h�B
	m_modelRender->Init(L"modelData/star.cmo");
	//���f����\��������W��������B
	m_modelRender->SetPosition(m_position);
	//���f���̉�]��������B
	m_modelRender->SetRotation(m_rotation);
	//���f���̊g�嗦��������B
	m_modelRender->SetScale(m_scale);
	return true;
}
void Star::Update()
{
	//���t���[�������Â�]�����Ă����B
	CQuaternion addRot;
	addRot.SetRotationDeg(
		{0, 1, 0},		//��]���B�����Y�����w�肵�Ă���B
		3.0f			//���Z�����]�p�x�B
	);
	m_rotation *= addRot;
	m_modelRender->SetRotation(m_rotation);
}
