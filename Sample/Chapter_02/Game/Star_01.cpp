#include "stdafx.h"
#include "Star_01.h"


Star_01::Star_01()
{
}


Star_01::~Star_01()
{
}
bool Star_01::Start()
{
	//初期ステートは上昇にする。
	m_state = enState_Up;
	//タイマーの初期値を0にする。
	m_timer = 0;
	//CSkinModelRenderのインスタンスを作成する。
	m_modelRender = NewGO<prefab::CSkinModelRender>(0);
	//cmoファイルをロードする。
	m_modelRender->Init(L"modelData/star.cmo");
	//各打率を設定する。
	m_modelRender->SetScale(m_scale);
	return true;
}
void Star_01::Update()
{
	//タイマーをインクリメント。
	m_timer++;
	if (m_state == enState_Down) {
		//下降状態の時の処理。
		m_position.y -= 1.0f;
		if (m_timer == 120) {
			//120フレーム経過したので、状態を切り替える。
			m_state = enState_Up;
			//タイマーをリセットする。
			m_timer = 0;
		}
	}
	else if (m_state == enState_Up) {
		//上昇状態の時の処理。
		m_position.y += 1.0f;
		if (m_timer == 120) {
			//120フレーム経過したので、状態を切り替える。
			m_state = enState_Down;
			//タイマーをリセットする。
			m_timer = 0;
		}

	}
	//座標を設定する。
	m_modelRender->SetPosition(m_position);
}
