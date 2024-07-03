#pragma once
#include <vector>
#include<string>
#include "../Objects/GameObject.h"

class Scene : public GameObject
{
private:
	int back_image;//�w�i��`��
	int frame; //�t���[���v�Z
	int tim; //����
	int tim_image; //���v�̉摜��`��
	int hi; //�n�C�X�R�A�̉摜�`��
	int sc; //�X�R�A�̉摜�`��
	int count; //���I�̊m��
	int count1; //�H�G�̊m��
	int count2; //�n�[�s�[�̊m��
	int count3; //���G�̊m��
	int Enemy_count;  //�n�R�G�̐�����
	int Enemy_count1; //�H�G�̐���������
	int Enemy_count2; //�n�[�s�[�̐���������
	int Enemy_count3; //���G�̐��������
	int cha; //�H�G�̍��W�������_����
	int cha1; //�n�[�s�[�̍��W�������_����
	int sc_sc; //�X�R�A�v�Z
	int sc_sc1; //�X�R�A�v�Z
	int sc_sc2; //�X�R�A�v�Z
	int bom_fps; //�����G�t�F�N�g���o�����߂̃^�C���v�Z
	int se_bom;//�{�����˂�se
	int se_enemy; //���I���j��se
	int se_hako;//�n�R�G���jse
	int se_hapy;//�n�[�s�[���jse
	int se_kin;//���I���jse
	int bom_count; //���e�̐���������
	int bom_count_fps;//bom�����̂��߂̎��Ԃ������Ă������
	int Perfect; //�@�p�[�t�F�N�g����
	int GOOD;  //�����Ƃ̉���
	int OK;  //�����̉���
	int BAD;//�o�b�g�̉���
	int hi_sc;//�n�C�X�R�A
	

	
	
		

private:
	std::vector<GameObject*>objects;

public:
	Scene();
	~Scene();

	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();
	void Sc();

private:

	

	void HitCheckObject(GameObject* a, GameObject* d);
	//�I�u�W�F�N�g��������
	template <class T>
	T* CreateObject(const Vector2D& location)
	{
		//�w�肵���N���X���쐬����
		T* new_instance = new T();
		//GameObject�N���X���p�����Ă��邩�m�F
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		//�G���[�`�F�b�N
		if (new_object == nullptr)
		{
			delete new_instance;
			throw std::string("�Q�[���I�u�W�F�N�g�������ł��܂���ł���");
		}
		
		//����������
		new_object->Initialize();
		//�ʒu���̐ݒ�
		new_object->SetLocation(location);

		//�I�u�W�F�N�g���X�g�ɒǉ�
		objects.push_back(new_object);

		//�C���X�^���X�̃|�C���^��ԋp
		return new_instance;
	}
};


