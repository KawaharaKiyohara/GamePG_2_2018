/*!
 * @brief	エネミー。
 */

#pragma once

#include "tkEngine/graphics/tkSkinModelRender.h"

class Enemy : public IGameObject {
public:
	/*!
	 * @brief	コンストラクタ。
	 */
	Enemy();
	/*!
	 * @brief	デストラクタ。ｓ
	 */
	~Enemy();
	/*!
	 * @brief	スタート。
	 */
	bool Start() override;
	/*!
	 * @brief	更新。
	 */
	void Update() override;

	/*!
	 *@brief	座標を設定。
	 */
	void SetPosition(const CVector3& pos)
	{
		m_position = pos;
	}
private:
	/*!
	 *@brief	アニメーションクリップの初期化。
	 */
	void InitAnimationClips();
	/*!
	 *@brief	スキンモデルレンダーの初期化。
	 */
	void InitSkinModelRender();
private:
	//アニメーション
	enum EnAnimation {
		enAnimation_Idle,	//待機アニメーション。
		enAnimation_Walk,	//歩きアニメーション。
		enAnimation_Attack, //攻撃アニメーション。
		enAnimation_Num,    //アニメーションの数。
	};
	//状態。
	enum EnState {
		enState_Idle,		//待機状態
	};
	EnState m_state;											//現在の状態。
	CAnimationClip m_animClips[enAnimation_Num];				//!<アニメーションクリップ。
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//!<スキンモデルレンダラー。
	CVector3		m_position;									//!<座標。
	CQuaternion		m_rotation = CQuaternion::Identity;			//!<回転。
};