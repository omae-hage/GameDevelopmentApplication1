#include "Bom_FX.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

//コンストラクタ
Bom_FX::Bom_FX() : animation_count(0),hit()
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//デストラクタ
Bom_FX::~Bom_FX()
{

}

//初期化処理
void Bom_FX::Initialize()
{
	
	//画像の読み込み
	animation[0] =   LoadGraph("Resource/Images/Blast/1.png");
	animation[1] = LoadGraph("Resource/Images/Blast/2.png");

	//大きさの設定
	box_size = 35.0f;
	//初期画像の設定
	image = animation[0];

	type = bom_fx;

	
}

//更新処理
void Bom_FX::Update()
{

	//アニメーション制御
	AnimeControl();

}

void Bom_FX::OnHitCollision(GameObject* hit_object)
{
	//あたった時の処理
	hit = true;
}


//描画処理
void Bom_FX::Draw()const
{
	//爆弾画像の描画
	DrawRotaGraphF(location.x, location.y, 0.5, radian, image, TRUE);


}


//修了時処理
void Bom_FX::Finalize()
{
	//使用した画像を解放する
	
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	

}


void Bom_FX::AnimeControl()
{
	//ℱれーむカウントを加算する
	animation_count++;

	//60フレーム目に到達したら
	if (animation_count >= 60)
	{
		//カウントのリセット
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
}