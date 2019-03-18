#include "stdafx.h"
#include "Star_03.h"


Star_03::Star_03()
{
}


Star_03::~Star_03()
{
}
bool Star_03::Start()
{
	//初期ステートは+Xの方向に移動する。
	m_state = enState_PositiveRotY;
	//単位クォータニオン(回転しないクォータニオン)で初期化する。
	m_rotation = CQuaternion::Identity;
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
void Star_03::Update()
{
	//タイマーをインクリメント。
	m_timer++;
	if (m_state == enState_PositiveRotY) {
		//Y軸周りに+の方向に回転中。
		//Y軸周りに+1度回す回転クォータニオンを作成。
		CQuaternion qAddRotY;
		qAddRotY.SetRotationDeg(CVector3::AxisY, 1.0f);
		//回転を加算する。
		m_rotation *= qAddRotY;

		if (m_timer == 45) {
			//45フレーム経過したので、状態を切り替える。
			m_state = enState_NegativeRotY;
			//タイマーをリセットする。
			m_timer = 0;
		}
	}
	else if (m_state == enState_NegativeRotY) {
		//Y軸周りに+の方向に回転中。
		//Y軸周りに+1度回す回転クォータニオンを作成。
		CQuaternion qAddRotY;
		qAddRotY.SetRotationDeg(CVector3::AxisY, -1.0f);
		//回転を加算する。
		m_rotation *= qAddRotY;

		if (m_timer == 45) {
			//120フレーム経過したので、状態を切り替える。
			m_state = enState_PositiveRotY;
			//タイマーをリセットする。
			m_timer = 0;
		}

	}
	//回転を設定する。
	m_modelRender->SetRotation(m_rotation);
	//座標を設定する。
	m_modelRender->SetPosition(m_position);

}
