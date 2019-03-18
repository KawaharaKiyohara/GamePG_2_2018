#pragma once
class Star_03 : public IGameObject
{
public:
	Star_03();
	~Star_03();
	bool Start();
	void Update();
	
	//状態を表す列挙。
	enum EnState {
		enState_PositiveRotY,		//Y軸周りに+の方向に回転中。
		enState_NegativeRotY		//Y軸周りに-の方向に回転中。
	};
	EnState						m_state;		//状態。
	int							m_timer;		//タイマー。
	CVector3					m_position;		//座標。
	CQuaternion					m_rotation;		//回転クォータニオン。
	CVector3					m_scale;		//拡大率。
	prefab::CSkinModelRender*	m_modelRender;	//スキンモデルレンダー。
};

