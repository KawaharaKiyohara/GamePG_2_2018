#pragma once
class Star_03 : public IGameObject
{
public:
	Star_03();
	~Star_03();
	bool Start();
	void Update();
	
	//��Ԃ�\���񋓁B
	enum EnState {
		enState_PositiveRotY,		//Y�������+�̕����ɉ�]���B
		enState_NegativeRotY		//Y�������-�̕����ɉ�]���B
	};
	EnState						m_state;		//��ԁB
	int							m_timer;		//�^�C�}�[�B
	CVector3					m_position;		//���W�B
	CQuaternion					m_rotation;		//��]�N�H�[�^�j�I���B
	CVector3					m_scale;		//�g�嗦�B
	prefab::CSkinModelRender*	m_modelRender;	//�X�L�����f�������_�[�B
};

