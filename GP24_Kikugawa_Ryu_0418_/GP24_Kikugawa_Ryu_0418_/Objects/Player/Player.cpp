#include "Player.h"
#include"../../Utility/InputControl.h"
#include "../../Utility/UserTemplate.h"
#include "DxLib.h"

//コンストラクタ
Player::Player() : velocity(0.0f)
{

}
//デストラクタ
Player::~Player()
{

}
//初期化
void Player::Initialize()
{
	color = GetColor(255, 255, 255);

	box_size = Vector2D(32.0f);

	location = Vector2D(320.0f, 240.0f);

}
//更新処理
void Player::Update()
{
	Movement();
}
//描画処理
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
//プレイヤー動き
void Player::Movement()
{
	Vector2D direction = Vector2D(0.0f);

	//左移動
	if (InputControl::GetKey(KEY_INPUT_LEFT))
	{
		direction.x= -0.5f;//方向設定
		float max_speed = Abs<float>((5.0f * direction.x));//最高速度
		velocity.x += direction.x;//速度に加算
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);//最高速度を超えないようにする
	}
	//右移動
	else if (InputControl::GetKey(KEY_INPUT_RIGHT))
	{
		direction.x = 0.5f;//方向設定
		float max_speed = Abs<float>((5.0f * direction.x));//さいこうそくど
		velocity.x += direction.x;//速度に加算
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);//最高速度に到達
	}
	//入力がない時の処理
	//減速する
	else
	{
		if (velocity.x > 1e-6f)
		{
			//右に移動してる時の減速の処理
			float calc_speed = velocity.x - 0.1f; 
			velocity.x = Min<float>(Max<float>(calc_speed, 0.0f), velocity.x);
		}
		else if (velocity.x < -1e-6f)
		{
			//左に移動してる時の減速の処理
			float calc_speed = velocity.x + 0.1f;
			velocity.x = Min<float>(Max<float>(calc_speed, velocity.x), 0.0f);
		}
	}
	//壁にあたった時の処理
	if (location.x < (box_size.x / 2.0f))
	{
		//左壁
		velocity.x = 0.0f;
		location.x = box_size.x / 2.0f;
	}
	//右壁
	else if (location.x > (640.0f - box_size.x / 2.0f))
	{
		velocity.x = 0.0f;
		location.x = 640.0f - box_size.x / 2.0f;
	}
	location += direction;

}

