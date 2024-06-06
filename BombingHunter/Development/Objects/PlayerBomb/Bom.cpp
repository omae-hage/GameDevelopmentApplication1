#include "Bom.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

//コンストラクタ
Bom::Bom() :  direction(0.0f),images(NULL)
{

}

//デストラクタ
Bom::~Bom()
{

}

//初期化処理
void Bom::Initialize()
{
	//画像の読み込み
	images = LoadGraph("Resource/Images/Bomb/Bomb.png");
	//向きの設定
	radian = 1.5;
	//大きさの設定
	scale = 64.0f;
	//初期画像の設定
	image = images;

	//初期振興報告の設定
	if (InputControl::GetKey(KEY_INPUT_LEFT) || InputControl::GetKeyDown(KEY_INPUT_LEFT))
	{
		radian = 2.0;
		direction = Vector2D(-1.5f, 1.0f); 
	}
	else if (InputControl::GetKey(KEY_INPUT_RIGHT) || InputControl::GetKeyDown(KEY_INPUT_RIGHT))
	{
		radian = 1.0;
		direction = Vector2D(1.5f, 1.0f);
	}
	else
	{
		radian = 1.5;
		direction = Vector2D(0.0f, 1.0f);
	}
	
}

//更新処理
void Bom::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	/*AnimeControl();*/
}

//描画処理
void Bom::Draw()const
{
	
	//爆弾画像の描画
	DrawRotaGraphF(location.x, location.y, 0.4, radian, image, TRUE, 0);

	
	//親クラスの描画処理を呼び出す
	__super::Draw();
}


//修了時処理
void Bom::Finalize()
{
	//使用した画像を解放する
	DeleteGraph(images);
	/*DeleteGraph(animation[1]);*/
}

//当たり判定通知処理
void Bom::OnHitCollision(GameObject* hit_object)
{
	//あたった時の処理
	direction = 0.0f;
}

//移動処理
void Bom::Movement()
{
	//sitaへ移動し続ける
	location+= direction;
	

	//右の壁に当たると左の壁に行く
}
	//画面端に到達したら、進行方向を反転する
	/*if (((location.x + direction.x) < box_size.x) ||
		(640.0f - box_size.x) < (location.x + direction.x))
	{
		direction.x *= -1.0f;
	}
	if (((location.y + direction.y) < box_size.y) ||
		(480.0f - box_size.y) < (location.y + direction.y))
	{
		direction.y *= -1.0f;
	}*/
	//進行方向に向かって、位置情報を変更する
	/*location += direction;
}*/
//あにめーしょん制御
//void Bom::AnimeControl()
//{
//	//ℱれーむカウントを加算する
//	animation_count++;
//
//	//30フレーム目に到達したら
//	if (animation_count >= 30)
//	{
//		//カウントのリセット
//		animation_count = 0;
//
//		//画像の切り替え
//		if (image == animation[0])
//		{
//			image = animation[1];
//		}
//		else
//		{
//			image = animation[0];
//		}
//	}
//}

