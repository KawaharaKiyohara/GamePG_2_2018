#pragma once
class Star_02 : public IGameObject
{
public:
	Star_02();
	~Star_02();
	bool Start();
	void Update();
	
	//��Ԃ�\���񋓁B
	enum EnState {
		enState_PositiveX,		//+X�̕����Ɉړ����B
		enState_NegativeX		//-X�̕����Ɉړ����B
	};
	EnState						m_state;		//��ԁB
	int							m_timer;		//�^�C�}�[�B
	CVector3					m_position;		//���W�B
	CVector3					m_scale;		//�g�嗦�B
	prefab::CSkinModelRender*	m_modelRender;	//�X�L�����f�������_�[�B
};

