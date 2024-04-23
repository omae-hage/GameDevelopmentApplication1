#include "GameObject.h"
#include "../Utility/ResourceManager.h"
#include "DxLib.h"

//コンストラクタ
GameObject::GameObject() : image(NULL), location(0.0f), box_size(0.0f)
{

}
//デストラクタ
GameObject::~GameObject()
{

}
//初期化
void GameObject::Initialize()
{
	image = NULL;
	box_size = Vector2D(32.0f);
	location = box_size;

}
//更新処理
void GameObject::Update()
{
	//右へ移動し続ける
	location.x += 1.0f;
	//右の壁に当たると左の壁に行く
	if (location.x >= 640.0f)
	{
		location.x = 0.0f;
	}
}
//描画
void GameObject::Draw() const
{
	DrawROtaGraphF(locattion.xlocation.y, 1.0, 0.0, image, TRUE);

	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, GetColor(255,0,0),TRUE);
}

//しゅうりょう
void GameObject::Finalize()
{

}
//座標セット
void GameObject::SetLocation(Vector2D location)
{
	this->location = location;

}
//座標の取得
Vector2D GameObject::GetLocation() const
{
	return this->location;
}

//当たり判定取得
Vector2D GameObject::GetBoxSize() const
{
	return this->box_size;
}
