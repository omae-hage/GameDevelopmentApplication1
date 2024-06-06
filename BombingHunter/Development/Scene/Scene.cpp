#include "Scene.h"
#include "DxLib.h"
#include "../Objects/Player/Player.h"
#include"../Objects/Enemy/Enemy.h"
#include"../Objects/PlayerBomb/Bom.h"
#include"../Utility/InputControl.h"
#include"../Objects/Enemy/Enemy_hane.h"
#include"../Objects/Enemy/Enemy_Harpy.h"
#include"../Objects/Enemy/Enemy_bullet.h"

//�R���X�g���N�^
Scene::Scene() : objects(), back_image(NULL)
{
	
}

Scene::~Scene()
{
	//�Y��h�~
	Finalize();
}

//����������
void Scene::Initialize()
{
	back_image = LoadGraph("Resource/Images/BackGround.png");

	//�v���C���[�𐶐�����
	CreateObject<Player>(Vector2D(320.0f, 50.0f));
	CreateObject<Enemy>(Vector2D(0.0f, 390.0f));
	/*if (GetRand(100) <= 50)
	{
		CreateObject<Enemy>(Vector2D(0.0f, 390.0f));
	}*/

	/*if(GetRand(100) < 40)
	{
		CreateObject<Enemy_hane>(Vector2D(0.0f, 120.0f));
	}

	if (GetRand(100) < 60)
	{
		CreateObject<Enemy_Harpy>(Vector2D(0.0f, 200.0f));
	}*/
	
	


}

//�X�V����
void Scene::Update()
{
	//�V�[���ɑ��݂���I�u�W�F�N�g�̍X�V����
	for (GameObject* obj : objects)
	{
		obj->Update();
	}
	
	/*z�������Ɣ��e���o��*/
	if (InputControl::GetKeyDown(KEY_INPUT_Z))
	{
		CreateObject<Bom>(objects[0]->GetLocation());
	}
	
	//s�������ƓG�̒e�𔠓I�ŏo��
	if (GetRand(20000) <= 33)
	{
		CreateObject<Enemy_bullet>(objects[1]->GetLocation());

		
	}

	if (GetRand(100) <= 2)
	{
		CreateObject<Enemy>(Vector2D(0.0f, 390.0f));
	}
}

//�`�揈��
void Scene::Draw() const
{
	 DrawRotaGraphF(320.0f,195.0f,0.8,0,back_image,TRUE,0);
	

	//�V�[���ɑ��݂���u�W�F�N�g�̕`�揈��
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}
}

//�I������
void Scene::Finalize()
{
	 
	//���I�z�񂪋�Ȃ珈�����I������
	if (objects.empty())
	{
		return;
	}
	//�e�I�u�W�F�N�g����������
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}
	//���I�z��̉��
	objects.clear();
}
