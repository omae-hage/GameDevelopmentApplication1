#pragma once
#include "GameObject.h"
class Player : public GameObject
{
private:

public:
		Player();//�R���X�g���N�^
		~Player();//�f�X�g���N�^

		void Initialize ()override;//����������
		void Update()override;//�X�V����
		void Draw() const override;//�`�揈��
		void Finalize()override;//�I������

private:
	void Movement();//����

};

