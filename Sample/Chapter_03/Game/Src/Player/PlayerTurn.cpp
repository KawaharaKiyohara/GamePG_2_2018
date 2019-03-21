/*!
 * @brief	�v���C���[�̐��񏈗��B
 */

#include "stdafx.h"
#include "Player/PlayerTurn.h"
#include "Player/Player.h"

namespace {
	const float ROT_SPEED = 8.0f;	//��]���x�B�P��(���W�A��/�b)�B
}
/*!
 * @brief	�X�V�B
 */
void CPlayerTurn::Update()
{
	CVector3 moveSpeed = m_player->GetMoveSpeed();
	moveSpeed.y = 0.0f;	//y�͕s�v�B
	if (moveSpeed.LengthSq() < 0.01f) {
		//�ړ����Ă��Ȃ��B
		return;
	}
	CVector3 forwardXZ = m_player->GetForwardXZ();
	float angle = atan2f(moveSpeed.x, moveSpeed.z);
	
	CQuaternion qRot;
	qRot.SetRotation(CVector3::AxisY, -angle);
	m_player->SetRotation(qRot);
}
