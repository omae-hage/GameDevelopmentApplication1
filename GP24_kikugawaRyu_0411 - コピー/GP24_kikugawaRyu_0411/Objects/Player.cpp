#include "Player.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

//コンストラクタ　初期化子リスト
Player::Player() : location(), direction(0.0f), radius(15.0f)
{

}

//コンストラクタ
Player::Player(float x, float y) : location(x, y), direction(0.0f), radius(15.0f)
{

}
//コンストラクタ
Player::Player(Vector2D location) : direction(0.0f), radius(15.0f)
{
	this->location = location;
}

//デストラクタ
Player::~Player()
{

}

//更新処理
void Player::Update()
{
	Movement();
}

//描画
void Player::Draw() const
{
	DrawCircleAA(location.x, location.y, radius, 50, GetColor(255, 255, 255), TRUE);

}

//座標セット
void Player::SetLocation(float x, float y)
{
	SetLocation(Vector2D(x, y));
}

//座標セット
void Player::SetLocation(Vector2D location)
{
	this->location = location;
}

//座標取得
Vector2D Player::GetLocation() const
{
	return location;
}

//半径情報取得
float Player::GetRadius()
{
	return radius;
}

//プレイヤー行動
void Player::Movement()
{
	//上に行く
	if (InputControl::GetKeyDown(KEY_INPUT_UP))
	{
		direction.y = -5.0f;
	}

	//下に行く
	if (InputControl::GetKeyDown(KEY_INPUT_DOWN))
	{
		direction.y = 5.0f;
	}

	//右に行く
	if (InputControl::GetKeyDown(KEY_INPUT_RIGHT))
	{
		direction.x = 5.0f;
	}

	//左に行く
	if (InputControl::GetKeyDown(KEY_INPUT_LEFT))
	{
		direction.x = -5.0f;
	}

	//座標の移動
	location += direction;
}