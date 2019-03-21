#include "stdafx.h"
#include "Star.h"


Star::Star()
{
}


Star::~Star()
{
	DeleteGO(m_modelRender);
}

bool Star::Start()
{
	m_modelRender = NewGO<prefab::CSkinModelRender>(0);
	//cmoファイルをロード。
	m_modelRender->Init(L"modelData/star.cmo");
	//モデルを表示する座標を教える。
	m_modelRender->SetPosition(m_position);
	//モデルの回転を教える。
	m_modelRender->SetRotation(m_rotation);
	//モデルの拡大率を教える。
	m_modelRender->SetScale(m_scale);
	return true;
}
void Star::Update()
{
	//毎フレーム少しづつ回転させていく。
	CQuaternion addRot;
	addRot.SetRotationDeg(
		{0, 1, 0},		//回転軸。今回はY軸を指定している。
		3.0f			//加算する回転角度。
	);
	m_rotation *= addRot;
	m_modelRender->SetRotation(m_rotation);
}
