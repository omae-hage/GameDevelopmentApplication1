#include "Player.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

//�R���X�g���N�^�@�������q���X�g
Player::Player() : location(), direction(0.0f), radius(15.0f)
{

}

//�R���X�g���N�^
Player::Player(float x, float y) : location(x, y), direction(0.0f), radius(15.0f)
{

}
//�R���X�g���N�^
Player::Player(Vector2D location) : direction(0.0f), radius(15.0f)
{
	this->location = location;
}

//�f�X�g���N�^
Player::~Player()
{

}

//�X�V����
void Player::Update()
{
	Movement();
}

//�`��
void Player::Draw() const
{
	DrawCircleAA(location.x, location.y, radius, 50, GetColor(255, 255, 255), TRUE);

}

//���W�Z�b�g
void Player::SetLocation(float x, float y)
{
	SetLocation(Vector2D(x, y));
}

//���W�Z�b�g
void Player::SetLocation(Vector2D location)
{
	this->location = location;
}

//���W�擾
Vector2D Player::GetLocation() const
{
	return location;
}

//���a���擾
float Player::GetRadius()
{
	return radius;
}

//�v���C���[�s��
void Player::Movement()
{
	//��ɍs��
	if (InputControl::GetKeyDown(KEY_INPUT_UP))
	{
		direction.y = -5.0f;
	}

	//���ɍs��
	if (InputControl::GetKeyDown(KEY_INPUT_DOWN))
	{
		direction.y = 5.0f;
	}

	//�E�ɍs��
	if (InputControl::GetKeyDown(KEY_INPUT_RIGHT))
	{
		direction.x = 5.0f;
	}

	//���ɍs��
	if (InputControl::GetKeyDown(KEY_INPUT_LEFT))
	{
		direction.x = -5.0f;
	}

	//���W�̈ړ�
	location += direction;
}