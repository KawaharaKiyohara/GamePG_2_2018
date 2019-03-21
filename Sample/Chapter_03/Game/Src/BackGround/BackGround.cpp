/*!
 * @brief	�w�i
 */

#include "stdafx.h"
#include "BackGround/BackGround.h"

/*!
 * @brief	�R���X�g���N�^�B
 */
CBackGround::CBackGround()
{
}
/*!
 * @brief	�f�X�g���N�^�B
 */
CBackGround::~CBackGround()
{
	DeleteGO(m_skinModelRender);
}

bool CBackGround::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/background.cmo" );
	m_skinModelRender->SetShadowCasterFlag(false);
	m_skinModelRender->SetShadowReceiverFlag(true);

	//�ÓI�����I�u�W�F�N�g���쐬�B
	m_phyStaticObject.CreateMesh(CVector3::Zero, CQuaternion::Identity, CVector3::One, m_skinModelRender);
	return true;
}

