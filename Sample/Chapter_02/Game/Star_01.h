#pragma once
class Star_01 : public IGameObject
{
public:
	Star_01();
	~Star_01();
	bool Start();
	void Update();
	
	//状態を表す列挙。
	enum EnState {
		enState_Down,		//下降中
		enState_Up,			//上昇中
	};
	EnState						m_state;		//状態。
	int							m_timer;		//タイマー。
	CVector3					m_position;		//座標。
	CVector3					m_scale;		//拡大率。
	prefab::CSkinModelRender*	m_modelRender;	//スキンモデルレンダー。
};

