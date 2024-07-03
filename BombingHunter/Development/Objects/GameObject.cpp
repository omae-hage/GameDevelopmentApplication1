#include "GameObject.h"
#include"DxLib.h"
//コンストラクタ
GameObject::GameObject() :
	location(0.0f),
	scale(0.0),
	radian(0.0),
	image(0),
	sound(0),
	type(),
	count()
{

}

//デストラクタ
GameObject::~GameObject()
{

}

//初期化処理
void GameObject::Initialize()
{

}

//更新処理
void GameObject::Update()
{

}

//描画処理
void GameObject::Draw()const
{
	Vector2D tl = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);

	DrawBoxAA(tl.x, tl.y, br.x, br.y, GetColor(255, 0, 0), FALSE);

}



//描画処理
void GameObject::Finalize()
{

}

//当たり判定通知処理
void GameObject::OnHitCollision(GameObject* hit_object)
{
	//あたった時に使う処理
}

//位置情報取得処理
Vector2D GameObject::GetLocation() const
{
	return location;
}
//位置情報設定処理
void GameObject::SetLocation(const Vector2D& location)
{
	this->location = location;
}

Vector2D GameObject::GetBoxSize()const
{
	return box_size;
}

int GameObject::GetType()
{
	return this->type;
}

void GameObject::SetType(int object_type)
{
	type = object_type;
}

bool GameObject::deleteObject()
{
	bool ret = false;
	return ret;
}
 
bool GameObject::sc_count()
{
	bool com = true;
	return com;
}