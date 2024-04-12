﻿#include "Player.h"
#include "../../Utility/InputControl.h"
#include"DxLib.h"

//コンストラクタ
Player::Player() : animation_count(0), flip_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//デストラクタ
Player::~Player()
{

}

//初期化処理
void Player::Initialize()
{
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/Tri_pilot/1.pug");
	animation[1] = LoadGraph("Resource/Images/Tri_pilot/2.pug");

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw ("鳥パイロットの画像がありません/n");
	}
	//向きの設定
	radian = 0.0;
	//大きさの設定
	scale = 64.0;
	//初期画像の設定
	image = animation[0];
}

//更新処理
void Player::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimeControl();
}

//描画処理
void Player::Draw() const
{
	//プレイヤー画像の描画
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

	//でバック用
	#if _DEBUG
		//当たり判定のかしか
		Vector2D box_collision_upper_left = location - (Vector2D(1.0f) * (float)scale / 2.0f);
		Vector2D box_collision_lower_right = location + (Vector2D(1.0f) * (float)scale / 2.0f);

		DrawBoxAA(box_collision_upper_left.x, box_collision_upper_left.y, box_collision_lower_right.x, box_collision_lower_right.y, GetColor(255, 0, 0), FALSE);

#endif
}

//修了時処理
void Player::Finalize()
{
	//使用した画像を解放する
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//当たり判定通知処理
void Player::OnHitCollision(GameObject* hit_object)
{
	//あたった時の処理
}

//移動処理
void Player::Movement()
{
	//移動の速さ
	Vector2D velocity = 0.0f;

	//左右移動
	if (InputControl::GetKey(KEY_INPUT_LEFT))
	{
		velocity.x += -1.0f;
		flip_flag = TRUE;
	}
	else if (InputControl::GetKey(KEY_INPUT_RIGHT))
	{
		velocity.x += 1.0f;
		flip_flag = FALSE;
	}
	else
	{
		velocity.x += 0.0f;
	}

	//現在の位置座標に速さを加算する
	location += velocity;
}
//あにめーしょん制御
void Player::AnimeControl()
{
	//ℱれーむカウントを加算する
	animation_count++;

	//60フレーム目に到達したら
	if (animation_count >= 60)
	{
		//カウントのリセット
		animation_count = 0;

		//画像の切り替え
		if (image == animation[0])
		{
			image = animation[1];
		}
		else
		{
			image = animation[0];
		}
	}
}
	

