#include "GameObject.h"
#include "DxLib.h"
//コンストラクタ
GameObject::GameObject(): color(0x0),location(),box_size()
{
	
}
//デストラクタ
GameObject::~GameObject()
{

}
//初期化処理
void GameObject::Initialize()
{
	location = Vector2D(32.0f, 24.0f);
	box_size = Vector2D(32.0f, 24.0f);
	color = GetColor(0, 255, 0);
}
//更新処理
void GameObject::Update()
{
	location += 0.1f;
}
//描画処理
void GameObject::Draw() const
{
	Vector2D tl = this->location - (this->box_size / 2.0f);
	Vector2D br = this->location + (this->box_size / 2.0f);

	DrawBoxAA(tl.x, tl.y, br.x, br.y, color, TRUE);
}
//終了処理
void GameObject::Finalize()
{

}
//座標をセットする
void GameObject::SetLocation(Vector2D location)
{
	this->location = location;

}
//座標を取得
Vector2D GameObject::GetLocation() const
{
	return this->location;
}
//当たり判定を取得
Vector2D GameObject::GetBoxSize() const
{
	return this->box_size;
}

