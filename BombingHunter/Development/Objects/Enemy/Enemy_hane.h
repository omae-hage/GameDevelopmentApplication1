
#pragma once
#include "../GameObject.h"
class Enemy_hane : public GameObject
{
private:
	int animation[2];  //�A�j���[�V�����摜
	int animation_count; //�A�j���[�V��������
	int flip_flag;  //���]�O���t
	Vector2D direction;
	bool hit;
	bool is_count;

public:
	Enemy_hane();
	~Enemy_hane();

	virtual void Initialize() override;  //����������
	virtual void Update() override;    //�X�V����
	virtual void Draw() const override; //�`�揈��
	virtual void Finalize() override;  //�C��������

	//���L����ʒm����
	virtual void OnHitCollision(GameObject* hit_object) override; 
	//�I�u�W�F�N�g����
	virtual bool deleteObject() override;
	//�X�R�A�v�Z
	virtual bool sc_count() override;

private:
	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	void AnimeControl();
};