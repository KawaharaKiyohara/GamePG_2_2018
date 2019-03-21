#pragma once
class Star : public IGameObject
{
public:
	Star();
	~Star();
	bool Start() override;
	void Update() override;
	CVector3 m_position;
	CQuaternion m_rotation;
	CVector3 m_scale;
	prefab::CSkinModelRender* m_modelRender = nullptr;
};

