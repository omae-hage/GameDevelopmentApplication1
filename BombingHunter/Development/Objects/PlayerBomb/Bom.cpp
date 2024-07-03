#include "Bom.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

//コンストラクタ
Bom::Bom() :  direction(0.0f),images(NULL),se(),hit()
{

}

//デストラクタ
Bom::~Bom()
{

}

//初期化処理
void Bom::Initialize()
{
	se = LoadSoundMem("Resource/Sounds/teki_gahee.wav");
	//画像の読み込み
	images = LoadGraph("Resource/Images/Bomb/Bomb.png");
	//大きさの設定
	box_size = 35.0f;
	//初期画像の設定
	image = images;

	type = bom;

	//爆弾左斜め方向
	if (InputControl::GetKey(KEY_INPUT_LEFT) || InputControl::GetKeyDown(KEY_INPUT_LEFT))
	{
		radian = 2.0;
		direction = Vector2D(-1.5f, 1.0f); 
	}
	//爆弾右斜め方向
	else if (InputControl::GetKey(KEY_INPUT_RIGHT) || InputControl::GetKeyDown(KEY_INPUT_RIGHT))
	{
		radian = 1.0;
		direction = Vector2D(1.5f, 1.0f);
	}
	//爆弾↓方向
	else
	{
		radian = DX_PI_F/2;
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

	//でバック用
#if _DEBUG
	//当たり判定のかしか
	Vector2D box_collision_upper_left = location - (box_size / 2.0f);
	Vector2D box_collision_lower_right = location + (box_size / 2.0f);

	DrawBoxAA(box_collision_upper_left.x, box_collision_upper_left.y,
		box_collision_lower_right.x, box_collision_lower_right.y,
		GetColor(255, 0, 0), FALSE);

#endif
}


//修了時処理
void Bom::Finalize()
{
	//使用した画像を解放する
	DeleteGraph(images);

}


//当たり判定通知処理
void Bom::OnHitCollision(GameObject* hit_object)
{
	//あたった時の処理
	hit = true;
}

//オブジェクト消去
bool Bom::deleteObject()
{
	bool ret = false;

	if (location.x > 640.0f + box_size.x || location.x < 0.0f - box_size.x || hit == true)
	{
		ret = true;
	}

	return ret;
}

//移動処理
void Bom::Movement()
{
	//sitaへ移動し続ける
	location+= direction;
	
}
	