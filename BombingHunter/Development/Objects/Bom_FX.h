#pragma once
#include "GameObject.h"
#include "../../Scene/Scene.h"
	class Bom_FX : public GameObject
{
private:
	

private:
	int animation[2];  //�A�j���[�V�����摜
	int animation_count; //�A�j���[�V��������
	int hit;
	

public:
	Bom_FX();
	~Bom_FX();

	virtual void Initialize() override;  //����������
	virtual void Update() override;    //�X�V����
	virtual void Draw() const override; //�`�揈��
	virtual void Finalize() override;  //�C��������

	virtual void OnHitCollision(GameObject* hit_object) override;


	

private:
	//�ړ�����
	
	//�A�j���[�V��������
	void AnimeControl();
	};


