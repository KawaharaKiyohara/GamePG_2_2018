#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	////////////////////////////////
	//ここからメンバ変数。
	////////////////////////////////
	CVector3 m_position;	//キャラの座標。
	CQuaternion m_rotation;	//キャラの回転。
	CVector3 m_moveSpeed;	//キャラの移動速度。
	CCharacterController m_charaCon; //キャラクターコントローラ。
	prefab::CSkinModelRender* m_modelRender;	//スキンモデルレンダラー。
};

