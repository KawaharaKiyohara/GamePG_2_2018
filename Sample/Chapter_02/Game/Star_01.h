#pragma once
class Star_01 : public IGameObject
{
public:
	Star_01();
	~Star_01();
	bool Start();
	void Update();
	
	//��Ԃ�\���񋓁B
	enum EnState {
		enState_Down,		//���~��
		enState_Up,			//�㏸��
	};
	EnState						m_state;		//��ԁB
	int							m_timer;		//�^�C�}�[�B
	CVector3					m_position;		//���W�B
	CVector3					m_scale;		//�g�嗦�B
	prefab::CSkinModelRender*	m_modelRender;	//�X�L�����f�������_�[�B
};

