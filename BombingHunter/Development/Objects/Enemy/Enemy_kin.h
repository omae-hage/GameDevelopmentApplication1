
#pragma once
#include "../GameObject.h"
class Enemy_kin : public GameObject
{
private:
	int animation[2];  //�A�j���[�V�����摜
	int animation_count; //�A�j���[�V��������
	int flip_flag;  //���]�O���t
	//int set_taim;
	Vector2D direction;
	int se;
	bool hit;
	int rand;
	bool is_count;
public:
	Enemy_kin();
	~Enemy_kin();

	virtual void Initialize() override;  //����������
	virtual void Update() override;    //�X�V����
	virtual void Draw() const override; //�`�揈��
	virtual void Finalize() override;  //�C��������u

	//���L����ʒm����
	virtual void OnHitCollision(GameObject* hit_object) override;
	virtual bool deleteObject() override;
	virtual bool sc_count() override;


private:
	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	void AnimeControl();

public:



};





//<^^>//
