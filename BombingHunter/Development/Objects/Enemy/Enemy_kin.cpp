#include "Enemy_kin.h"
#include "../../Utility/InputControl.h"
#include"DxLib.h"

//コンストラクタ
Enemy_kin::Enemy_kin() : animation_count(0), flip_flag(FALSE)/*set_taim()*/, se(), hit(), rand(), is_count()
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//デストラクタ
Enemy_kin::~Enemy_kin()
{

}

//初期化処理
void Enemy_kin::Initialize()
{
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/GoldEnemy/3.png");
	animation[1] = LoadGraph("Resource/Images/GoldEnemy/5.png");
	/*se = LoadSoundMem("Resource/Sounds/teki_gahee.wav");*/

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw ("ゴールドの敵の画像がありません / n");
	}
	//向きの設定
	radian = 0.0;
	//大きさの設定
	box_size = 2.0;
	//初期画像の設定
	image = animation[0];

	type = enemy_kin;

	/*rand = GetRand(1);*/
}

//更新処理
void Enemy_kin::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimeControl();


}


//描画処理
void Enemy_kin::Draw() const
{


	//エネミーー画像の描画
	DrawRotaGraphF(location.x, location.y, 0.7, radian, image, TRUE, flip_flag);

	//でバック用
#if _DEBUG
	//当たり判定のかしか
	Vector2D ul = location - (box_size / 1.0f);
	Vector2D br = location + (box_size / 1.0f);

	DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);

#endif
}

//修了時処理
void Enemy_kin::Finalize()
{
	//使用した画像を解放する
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//当たり判定通知処理
void Enemy_kin::OnHitCollision(GameObject* hit_object)
{
	//あたった時の処理
	hit = true;

	is_count = true;
}

//移動処理
void Enemy_kin::Movement()
{
	//右へ移動し続ける
	location.x += 2.0f;
	
}

//スコアを計算する時の処理
bool Enemy_kin::sc_count()
{
	bool com = false;

	if (is_count == true)
	{
		com = true;
	}

	return com;
}

//オブジェクト消しますの処理
bool Enemy_kin::deleteObject()
{
	bool ret = false;

	if (location.x > 640.0f + box_size.x || location.x < 0.0f - box_size.x || hit == true)
	{
		ret = true;
	}

	return ret;

}

//あにめーしょん制御
void Enemy_kin::AnimeControl()
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