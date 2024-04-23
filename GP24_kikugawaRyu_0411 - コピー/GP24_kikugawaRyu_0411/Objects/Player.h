#pragma once

#include "../Utility/Vector2D.h"

class Player
{
private:
	Vector2D location;  //���W
	Vector2D direction;//����
	float radius;      //���a


public:
	Player(); //�R���X�g���N��
	Player(float x, float y); 
	Player(Vector2D location); 
	~Player();

	void Update();  //�X�V����
	void Draw() const;   //�\��

	void SetLocation(float x, float y); //���W�Z�b�g�@
	void SetLocation(Vector2D location); //���W�ݒ�H
	Vector2D GetLocation() const; //���W�擾
	float GetRadius(); //���a���擾

private:
	//�ړ�
	void Movement();  

};

