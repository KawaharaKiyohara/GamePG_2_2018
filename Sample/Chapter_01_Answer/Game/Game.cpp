#include "stdafx.h"
#include "Game.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Player.h"
#include "Star.h"

Game::Game()
{
	//�J������ݒ�B
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 500.0f, 1000.0f });
	MainCamera().Update();

	m_level.Init(L"test.tkl", [&](LevelObjectData& objData) {
		if (objData.EqualObjectName(L"unityChan")) {
			//���[�h���悤�Ƃ��Ă���I�u�W�F�N�g�̓��j�e�B�����B
			//�t�b�N���āA�v���C���[�N���X�����B
			Player* pl = NewGO<Player>(0, "�v���C���[");
			//�z�u��񂩂���W�Ɖ�]���v���C���[�ɓn���B
			pl->m_position = objData.position;
			pl->m_rotation = objData.rotation;
			return true;
		}
		else if (objData.EqualObjectName(L"star")) {
			Star* s = NewGO<Star>(0, "��");
			s->m_position = objData.position;
			s->m_rotation = objData.rotation;
			s->m_scale = objData.scale;
			return true;
		}
		return false;
	});
}
Game::~Game()
{
	//���Ƃ������O�̃I�u�W�F�N�g�����ׂč폜�B
	DeleteGOs("��");
	//�v���C���[�Ƃ������O�̃I�u�W�F�N�g�����ׂč폜�B
	DeleteGOs("�v���C���[");
}
void Game::Update()
{
}