#include "stdafx.h"
#include "Star_02.h"


Star_02::Star_02()
{
}


Star_02::~Star_02()
{
}
bool Star_02::Start()
{
	//初期ステートは+Xの方向に移動する。
	m_state = enState_PositiveX;
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
void Star_02::Update()
{
	//タイマーをインクリメント。
	m_timer++;
	if (m_state == enState_PositiveX) {
		//+Xの方向に移動中の時の処理。
		m_position.x += 1.0f;
		if (m_timer == 120) {
			//120フレーム経過したので、状態を切り替える。
			m_state = enState_NegativeX;
			//タイマーをリセットする。
			m_timer = 0;
		}
	}
	else if (m_state == enState_NegativeX) {
		//-Xの方向に移動中の時の処理。
		m_position.x -= 1.0f;
		if (m_timer == 120) {
			//120フレーム経過したので、状態を切り替える。
			m_state = enState_PositiveX;
			//タイマーをリセットする。
			m_timer = 0;
		}

	}
	//座標を設定する。
	m_modelRender->SetPosition(m_position);
}
