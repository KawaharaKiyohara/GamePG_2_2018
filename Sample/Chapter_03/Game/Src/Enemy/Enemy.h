/*!
 * @brief	�G�l�~�[�B
 */

#pragma once

#include "tkEngine/graphics/tkSkinModelRender.h"

class Enemy : public IGameObject {
public:
	/*!
	 * @brief	�R���X�g���N�^�B
	 */
	Enemy();
	/*!
	 * @brief	�f�X�g���N�^�B��
	 */
	~Enemy();
	/*!
	 * @brief	�X�^�[�g�B
	 */
	bool Start() override;
	/*!
	 * @brief	�X�V�B
	 */
	void Update() override;

	/*!
	 *@brief	���W��ݒ�B
	 */
	void SetPosition(const CVector3& pos)
	{
		m_position = pos;
	}
private:
	/*!
	 *@brief	�A�j���[�V�����N���b�v�̏������B
	 */
	void InitAnimationClips();
	/*!
	 *@brief	�X�L�����f�������_�[�̏������B
	 */
	void InitSkinModelRender();
private:
	//�A�j���[�V����
	enum EnAnimation {
		enAnimation_Idle,	//�ҋ@�A�j���[�V�����B
		enAnimation_Walk,	//�����A�j���[�V�����B
		enAnimation_Attack, //�U���A�j���[�V�����B
		enAnimation_Num,    //�A�j���[�V�����̐��B
	};
	//��ԁB
	enum EnState {
		enState_Idle,		//�ҋ@���
	};
	EnState m_state;											//���݂̏�ԁB
	CAnimationClip m_animClips[enAnimation_Num];				//!<�A�j���[�V�����N���b�v�B
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//!<�X�L�����f�������_���[�B
	CVector3		m_position;									//!<���W�B
	CQuaternion		m_rotation = CQuaternion::Identity;			//!<��]�B
};