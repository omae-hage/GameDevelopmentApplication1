#include "GameObject.h"
#include"DxLib.h"
//�R���X�g���N�^
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

//�f�X�g���N�^
GameObject::~GameObject()
{

}

//����������
void GameObject::Initialize()
{

}

//�X�V����
void GameObject::Update()
{

}

//�`�揈��
void GameObject::Draw()const
{
	Vector2D tl = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);

	DrawBoxAA(tl.x, tl.y, br.x, br.y, GetColor(255, 0, 0), FALSE);

}



//�`�揈��
void GameObject::Finalize()
{

}

//�����蔻��ʒm����
void GameObject::OnHitCollision(GameObject* hit_object)
{
	//�����������Ɏg������
}

//�ʒu���擾����
Vector2D GameObject::GetLocation() const
{
	return location;
}
//�ʒu���ݒ菈��
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