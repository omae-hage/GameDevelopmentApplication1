
#pragma once
#include "../GameObject.h"
class Enemy : public GameObject
{
private:
	int animation[2];  //�A�j���[�V�����摜
	int animation_count; //�A�j���[�V��������
	int flip_flag;  //���]�O���t
	//int set_taim;
	Vector2D direction;

public:
	Enemy();
	~Enemy();

	virtual void Initialize() override;  //����������
	virtual void Update() override;    //�X�V����
	virtual void Draw() const override; //�`�揈��
	virtual void Finalize() override;  //�C��������

	//���L����ʒm����
	/*virtual void OnHitCollision(GameObject* hit_object) override;*/

private:
	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	void AnimeControl();

public:
	


};