#pragma once
class Star_02 : public IGameObject
{
public:
	Star_02();
	~Star_02();
	bool Start();
	void Update();
	
	//状態を表す列挙。
	enum EnState {
		enState_PositiveX,		//+Xの方向に移動中。
		enState_NegativeX		//-Xの方向に移動中。
	};
	EnState						m_state;		//状態。
	int							m_timer;		//タイマー。
	CVector3					m_position;		//座標。
	CVector3					m_scale;		//拡大率。
	prefab::CSkinModelRender*	m_modelRender;	//スキンモデルレンダー。
};

