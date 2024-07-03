#include "Scene.h"
#include "DxLib.h"
#include "../Objects/Player/Player.h"
#include"../Objects/Enemy/Enemy.h"
#include"../Objects/PlayerBomb/Bom.h"
#include"../Utility/InputControl.h"
#include"../Objects/Enemy/Enemy_hane.h"
#include"../Objects/Enemy/Enemy_Harpy.h"
#include"../Objects/Enemy/Enemy_bullet.h"
#include"../Objects/Bom_FX.h"
#include"../Objects/Enemy/Enemy_kin.h"



#define D_PIVOT_CENTER
//�R���X�g���N�^
Scene::Scene() : objects(),back_image(NULL),frame(0),tim(), tim_image(),sc(),hi(),count(),count1(),count2(),count3(),Enemy_count(4),Enemy_count1(4),Enemy_count2(4),Enemy_count3(1), cha(), cha1(), sc_sc(), sc_sc1(),sc_sc2(), bom_fps(),se_bom(),se_enemy(),se_hako(),se_hapy(),se_kin(),bom_count(1), bom_count_fps(), Perfect(), GOOD(), OK(), BAD(),hi_sc()

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
	tim_image = LoadGraph("Resource/Images/TimeLimit/timer-03.png");
    hi = LoadGraph("Resource/Images/Score/hs.png");
	sc = LoadGraph("Resource/Images/Score/font-21.png");
	se_bom = LoadSoundMem("Resource/Sounds/pan.wav");
	se_enemy = LoadSoundMem("Resource/Sounds/teki_gahee.wav");
	se_kin = LoadSoundMem("Resource/Sounds/arrows_perfect03_short.wav");
	se_hako =  LoadSoundMem("Resource/Sounds/arrows_perfect03_short.wav");
	se_hapy = LoadSoundMem("Resource/Sounds/pokan.wav");
	Perfect = LoadSoundMem("Resource/Sounds/Evaluation/SE_perfect.wav");
	GOOD = LoadSoundMem("Resource/Sounds/Evaluation/SE_good.wav");
	OK = LoadSoundMem("Resource/Sounds/Evaluation/SE_ok.wav");
	BAD = LoadSoundMem("Resource/Sounds/Evaluation/SE_bad.wav");
	

//�v���C���[��G�l�~�[�̐���
	CreateObject<Player>(Vector2D(320.0f, 50.0f));

	//���G�̊m��
	count = GetRand(100);

	//�H�G�̊m��
	count1= GetRand(100);

	//�n�[�s�[�̊m��
	count2 = GetRand(100);

	//���G�̊m��
	count3 = GetRand(100);

	//�H�G�̍��W�������_���ɂ���
	cha = GetRand(2);

	//�́[�ҁ[�̍��W�������_���ɂ���
	cha1 = GetRand(2);

}

//�X�V����
void Scene::Update()
{
	/*PlaySoundMem(bgm, DX_PLAYTYPE_LOOP, FALSE);*/
	/*if (count >= 60)
	{
		CreateObject<Enemy>(Vector2D(0.0f, 390.0f));
	}*/

	frame++;
	if (frame >= 180) //3�b�ɂP��
	{

		//���G����
		if (Enemy_count > 0) //��ʏ�ɂS�̂܂�
		{
			if (count <= 40)
			{
				CreateObject<Enemy>(Vector2D(0.0f, 380.0f));
				Enemy_count--;

			}
		}
		//�H�G����
		if (Enemy_count1 > 0)
		{
			if (count1 <= 30)
			{
				
				if (cha == 0)
				{
					CreateObject<Enemy_hane>(Vector2D(0.0f, 120.0f));
				}
				else if (cha == 1)
				{
					CreateObject<Enemy_hane>(Vector2D(0.0f, 200.0f));
				}

				else if (cha == 2)
				{
					CreateObject<Enemy_hane>(Vector2D(0.0f, 260.0f));
				}

				Enemy_count1--;



			}
		}

		//�n�[�s�[����
		if (Enemy_count2 > 0)
		{
			if (count2 <= 50)
			{
				if (cha1 == 0)
				{
					CreateObject<Enemy_Harpy>(Vector2D(0.0f, 200.0f));
				}

				else if (cha1 == 1)
				{
					CreateObject<Enemy_Harpy>(Vector2D(0.0f, 120.0f));
				}

				else if (cha1 == 2)
				{
					CreateObject<Enemy_Harpy>(Vector2D(0.0f, 260.0f));
				}
				Enemy_count2--;
			}
		}

		//���G�̐���
		if (Enemy_count3 > 0)
		{
			if (count <= 10)
			{
				CreateObject<Enemy_kin>(Vector2D(0.0f, 400.0f));
				Enemy_count3--;
			}
		}




		count = GetRand(100);
		count1 = GetRand(100);
		count2 = GetRand(100);
		count3 = GetRand(100);

		cha = GetRand(2);
		cha1 = GetRand(2);

		frame = 0;

	}

	if (bom_count == 1)
	{
		if (InputControl::GetKeyDown(KEY_INPUT_SPACE))
		{

			CreateObject<Bom>(objects[0]->GetLocation())->SetType(1);
			bom_count = 0;
			PlaySoundMem(se_bom, DX_PLAYTYPE_BACK);

		}
	}

	//�V�[���ɑ��݂���I�u�W�F�N�g�̍X�V����
	for (GameObject* obj : objects)
	{
		obj->Update();
	}

	
	
	/*z�������Ɣ��e���o��*/
	


	//�I�u�W�F�N�ǂ����̂����蔻��`�F�b�N
	for (int i = 1; i < objects.size(); i++)
	{
		for (int j = i + 1; j < objects.size(); j++)
		{
			//�����I�u�W�F�N�g�ǂ����͊����Ȃ�
			if (objects[i]->GetType() != objects[j]->GetType())
			{
			/*if (objects[i]->GetType() == enemy != objects[j]->GetType() == enemy_kin)*/
				/*{*/
					HitCheckObject(objects[i], objects[j]);
				/*}*/
				//�����蔻��`�F�b�N����

			}
		}
	}


	//�G�̒e���o������
		/*tim++;
		if (tim > 120)
		{
			 CreateObject<Enemy_bullet>(objects[1]->GetLocation());
			tim =0;
		}*/

		//�ǂɍs���Ə���
		for (int i = 1; i < objects.size(); i++)
		{
			if (objects[i]->GetLocation().x < 0)
			{
				objects.erase(objects.begin() + i);
			}
		}

		for (int i = 1; i < objects.size(); i++)
		{
			if (objects[i]->GetLocation().y > 440)
			{
				bom_count = 1;
				objects.erase(objects.begin() + i);
			}
		}

		
		//�G��|���ƃX�R�A�����Z
		for (int i = 1; i < objects.size(); i++)
		{
			if (objects[i]->sc_count() == true)
			{
	
				//���I��|�������̃X�R�A�l��
				if (objects[i]->GetType() == enemy)
				{
					PlaySoundMem(se_hako, DX_PLAYTYPE_BACK);
					sc_sc1 += 200;
				}
				//�H�G��|�������̃X�R�A�l��
				else if (objects[i]->GetType() == enemy_hane)
				{
					PlaySoundMem(se_enemy, DX_PLAYTYPE_BACK);
					sc_sc1 += 40;
				}
				//�n�[�s�[��|�������̃X�R�A����
				else if (objects[i]->GetType() == enemy_Harpy)
				{
					PlaySoundMem(se_hapy, DX_PLAYTYPE_BACK);
					sc_sc1 += -200;
				}
				//���I��|�������̃X�R�A�l��
				else if (objects[i]->GetType() == enemy_kin)
				{
					PlaySoundMem(se_kin, DX_PLAYTYPE_BACK);
					sc_sc1 += 1000;
				}
				
				//�X�R�A���v�Z
				sc_sc2 = sc_sc + sc_sc1;
				hi_sc = sc_sc2;
			}
		}

		//�I�u�W�F�N�g����
	for (int i = 0; i < objects.size(); i++)
	{
		//����`�F�b�N����
		if (objects[i]->deleteObject() == true)
		{
			
			//���I�̏o�������v���X
			if (objects[i]->GetType() == enemy)
			{
				bom_count = 1;
				Enemy_count++; 
				/*CreateObject<Bom_FX>(objects[i]->GetLocation());
				bom_fps++;
				if (bom_fps >= 60)
				{
					objects.erase(objects.begin() + i);
				}*/
			}
			//�H�G�̏o�������v���X
			else if (objects[i]->GetType() == enemy_hane)
			{
				bom_count = 1;
				Enemy_count1++;
				
			}
			//�n�[�s�[�̏o�������v���X
			else if (objects[i]->GetType() == enemy_Harpy)
			{
				bom_count = 1;
				Enemy_count2++;
				
			}

			//���I�̏o�������v���X
			else if (objects[i]->GetType() == enemy_kin)
			{
				bom_count = 1;
				Enemy_count3++;

			}
			//�I�u�W�F�N�g����
			objects.erase(objects.begin() + i);
		}
	}
}




//�`�揈��
void Scene::Draw() const
{
	 DrawRotaGraphF(320.0f,195.0f,0.8,0,back_image,TRUE,0);
	 DrawRotaGraphF(30.0f, 460.0f, 0.6, 0, tim_image, TRUE, 0);
	 DrawRotaGraphF(300.0f, 460.0f, 1, 0, hi, TRUE, 0);
	 DrawRotaGraphF(170.0f, 460.0f, 1, 0, sc, TRUE, 0);
	 
	//�V�[���ɑ��݂���u�W�F�N�g�̕`�揈
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}

	//�X�R�A��`��
	DrawFormatString(200.0f, 460.0f, GetColor(255, 255, 255), "%d", sc_sc2);
	DrawFormatString(340.0f, 460.0f, GetColor(255, 255, 255), "%d", hi_sc);
}

void Scene::Sc()
{
	if (sc_sc2 >= 3000)
	{
		PlaySoundMem(Perfect, DX_PLAYTYPE_BACK);
		LoadGraphScreen(30, 150, "Resource/Images/Evaluation/Perfect.png",TRUE);
	}

	else if (sc_sc2 >= 1500)
	{
		PlaySoundMem(GOOD, DX_PLAYTYPE_BACK);
		LoadGraphScreen(40, 130, "Resource/Images/Evaluation/GOOD.png",TRUE);
	}

	else if (sc_sc2 >= 1000)
	{
		PlaySoundMem(OK, DX_PLAYTYPE_BACK);
		LoadGraphScreen(40, 50, "Resource/Images/Evaluation/OK.png",TRUE);
	}

	else
	{
		PlaySoundMem(BAD, DX_PLAYTYPE_BACK);
		LoadGraphScreen(100, 150, "Resource/Images/Evaluation/BAD.png",TRUE);
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
	/*DeleteSoundMem(bgm);*/
	//���I�z��̉��
	objects.clear();

	Initialize();
}

//�����蔻��`�F�b�N����(���S�ł����蔻����Ƃ�)
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//2�̃I�u�W�F�N�g�̋������擾
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//�Q�̃I�u�W�F�N�g�̂����蔻��̑傫�����擾
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	//�������傫���ꍇ�Ahit����Ƃ���
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		//�����������Ƃ��I�u�W�F�N�g�ɒʒm����
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}

