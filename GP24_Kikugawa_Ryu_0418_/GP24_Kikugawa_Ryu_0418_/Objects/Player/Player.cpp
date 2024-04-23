#include "Player.h"
#include"../../Utility/InputControl.h"
#include "../../Utility/UserTemplate.h"
#include "DxLib.h"

//�R���X�g���N�^
Player::Player() : velocity(0.0f)
{

}
//�f�X�g���N�^
Player::~Player()
{

}
//������
void Player::Initialize()
{
	color = GetColor(255, 255, 255);

	box_size = Vector2D(32.0f);

	location = Vector2D(320.0f, 240.0f);

}
//�X�V����
void Player::Update()
{
	Movement();
}
//�`�揈��
void Player::Draw()const
{
	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_left = location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_left.x, lower_left.y, color, TRUE);
}
//
void Player::Finalize()
{

}
//�v���C���[����
void Player::Movement()
{
	Vector2D direction = Vector2D(0.0f);

	//���ړ�
	if (InputControl::GetKey(KEY_INPUT_LEFT))
	{
		direction.x= -0.5f;//�����ݒ�
		float max_speed = Abs<float>((5.0f * direction.x));//�ō����x
		velocity.x += direction.x;//���x�ɉ��Z
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);//�ō����x�𒴂��Ȃ��悤�ɂ���
	}
	//�E�ړ�
	else if (InputControl::GetKey(KEY_INPUT_RIGHT))
	{
		direction.x = 0.5f;//�����ݒ�
		float max_speed = Abs<float>((5.0f * direction.x));//��������������
		velocity.x += direction.x;//���x�ɉ��Z
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);//�ō����x�ɓ��B
	}
	//���͂��Ȃ����̏���
	//��������
	else
	{
		if (velocity.x > 1e-6f)
		{
			//�E�Ɉړ����Ă鎞�̌����̏���
			float calc_speed = velocity.x - 0.1f; 
			velocity.x = Min<float>(Max<float>(calc_speed, 0.0f), velocity.x);
		}
		else if (velocity.x < -1e-6f)
		{
			//���Ɉړ����Ă鎞�̌����̏���
			float calc_speed = velocity.x + 0.1f;
			velocity.x = Min<float>(Max<float>(calc_speed, velocity.x), 0.0f);
		}
	}
	//�ǂɂ����������̏���
	if (location.x < (box_size.x / 2.0f))
	{
		//����
		velocity.x = 0.0f;
		location.x = box_size.x / 2.0f;
	}
	//�E��
	else if (location.x > (640.0f - box_size.x / 2.0f))
	{
		velocity.x = 0.0f;
		location.x = 640.0f - box_size.x / 2.0f;
	}
	location += direction;

}
