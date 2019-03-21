#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	////////////////////////////////
	//�������烁���o�ϐ��B
	////////////////////////////////
	CVector3 m_position;	//�L�����̍��W�B
	CQuaternion m_rotation;	//�L�����̉�]�B
	CVector3 m_moveSpeed;	//�L�����̈ړ����x�B
	CCharacterController m_charaCon; //�L�����N�^�[�R���g���[���B
	prefab::CSkinModelRender* m_modelRender;	//�X�L�����f�������_���[�B
};

