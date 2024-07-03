#include "Enemy.h"
#include"DxLib.h"

//コンストラクタ
Enemy::Enemy() : animation_count(0), direction(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//デストラクタ
Enemy::~Enemy()
{

}

//初期化処理
void Enemy::Initialize()
{
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/BoxEnemy/1.png");
	animation[1] = LoadGraph("Resource/Images/BoxEnemy/2.png");

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw ("箱敵の画像がありません/n");
	}
	//向きの設定
	radian = 0.0;
	//大きさの設定
	box_size = 64.0f;
	//初期画像の設定
	image = animation[0];

	//初期振興報告の設定
	direction = Vector2D(1.0f, -0.5f);
}

//更新処理
void Enemy::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimeControl();
}

//描画処理
void Enemy::Draw() const
{
	//画像反転フラグ
	int flip_flag = FALSE;

	//進行方法によって、反転状態を決定する
	if (direction.x > 0.0f)
	{
		flip_flag = FALSE;
	}
	else
	{
		flip_flag = TRUE;
	}
	//プレイヤー画像の描画
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

	//親クラスの描画処理を呼び出す
	/*__super::Draw();*/
}
	//でバック用
//#if _DEBUG
//	//当たり判定のかしか
//	Vector2D ul = location - (scale / 1.0f);
//	Vector2D br = location + (scale / 1.0f);
//
//	DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
//
//#endif
//}

//修了時処理
void Enemy::Finalize()
{
	//使用した画像を解放する
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//当たり判定通知処理
void Enemy::OnHitCollision(GameObject* hit_object)
{
	//あたった時の処理
	direction = 0.0f;
}

//移動処理
void Enemy::Movement()
{
	//画面端に到達したら、進行方向を反転する
	if (((location.x + direction.x) < box_size.x) ||
		(640.0f - box_size.x) < (location.x + direction.x))
	{
		direction.x *= -1.0f;
	}
	if (((location.y + direction.y) < box_size.y) ||
		(480.0f - box_size.y) < (location.y + direction.y))
	{
		direction.y *= -1.0f;
	}
	//進行方向に向かって、位置情報を変更する
	location += direction;
}
//あにめーしょん制御
void Enemy::AnimeControl()
{
	//ℱれーむカウントを加算する
	animation_count++;

	//30フレーム目に到達したら
	if (animation_count >= 30)
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
