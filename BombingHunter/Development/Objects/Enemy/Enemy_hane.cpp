#include "Enemy_hane.h"
#include "../../Utility/InputControl.h"
#include"DxLib.h"

//コンストラクタ
Enemy_hane::Enemy_hane() : animation_count(0), flip_flag(FALSE), hit()
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//デストラクタ
Enemy_hane::~Enemy_hane()
{

}

//初期化処理
void Enemy_hane::Initialize()
{
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/WingEnemy/1.png");
	animation[1] = LoadGraph("Resource/Images/WingEnemy/2.png");

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw ("羽敵の画像がありません/n");
	}
	//向きの設定
	radian = 0.0;
	//大きさの設定
	scale = 20.0;
	//初期画像の設定
	image = animation[0];

	type = enemy_hane;
}

//更新処理
void Enemy_hane::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimeControl();
}

//描画処理
void Enemy_hane::Draw() const
{
	//プレイヤー画像の描画
	DrawRotaGraphF(location.x, location.y, 0.6, radian, image, TRUE, flip_flag);

	//でバック用
#if _DEBUG
	//当たり判定のかしか
	Vector2D ul = location - (scale / 1.0f);
	Vector2D br = location + (scale / 1.0f);

	DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);

#endif
}

//修了時処理
void Enemy_hane::Finalize()
{
	//使用した画像を解放する
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//当たり判定通知処理
void Enemy_hane::OnHitCollision(GameObject* hit_object)
{
	//あたった時の処理
	hit = true;

	is_count = true;
}

//スコア計算
bool Enemy_hane::sc_count()
{
	bool com = false;

	if (is_count == true)
	{
		com = true;
	}

	return com;
}

//オブジェクト消去処理
bool Enemy_hane::deleteObject()
{
	bool ret = false;

	if (location.x > 640.0f + box_size.x || location.x < 0.0f - box_size.x || hit == true)
	{
		ret = true;
	}

	return ret;
}
//
//移動処理
void Enemy_hane::Movement()
{
	//右へ移動し続ける
	location.x += 0.5f;
	//右の壁に当たると左の壁に行く
	/*if (location.x >= 640.0f)
	{
		location.x = 0.0f;
	}*/
}
//あにめーしょん制御
void Enemy_hane::AnimeControl()
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