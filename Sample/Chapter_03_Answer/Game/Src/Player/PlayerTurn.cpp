/*!
 * @brief	プレイヤーの旋回処理。
 */

#include "stdafx.h"
#include "Player/PlayerTurn.h"
#include "Player/Player.h"

namespace {
	const float ROT_SPEED = 8.0f;	//回転速度。単位(ラジアン/秒)。
}
/*!
 * @brief	更新。
 */
void CPlayerTurn::Update()
{
	CVector3 moveSpeed = m_player->GetMoveSpeed();
	moveSpeed.y = 0.0f;	//yは不要。
	if (moveSpeed.LengthSq() < 0.01f) {
		//移動していない。
		return;
	}
	CVector3 forwardXZ = m_player->GetForwardXZ();
	float angle = atan2f(moveSpeed.x, moveSpeed.z);
	
	CQuaternion qRot;
	qRot.SetRotation(CVector3::AxisY, -angle);
	m_player->SetRotation(qRot);
}
