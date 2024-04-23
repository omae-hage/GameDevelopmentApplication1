#pragma once

//2�����x�N�g��
class Vector2D
{
public:
	float x;
	float y;

public:
	Vector2D();  //�R���X�g���N�^
	Vector2D(float scalar);//
	Vector2D(float mx, float my);//�@���Ƃ��̂��傫���p
	~Vector2D();//�f�X�g���N�^

	//���Z�q�I�[�o�[���[�h
public:
	Vector2D& operator = (const Vector2D& location);  //���

	const Vector2D operator + (const Vector2D& location) const; //���Z
	Vector2D& operator += (const Vector2D& location);  //���Z���
	 
	const Vector2D operator -(const Vector2D& location) const; //���Z
	Vector2D& operator -= (const Vector2D& location);          //���Z���

	const Vector2D operator * (const float& scalar)const;  //��Z
	const Vector2D operator*(const Vector2D& location) const;
	Vector2D& operator *= (const float& scalar);  //��Z���
	Vector2D& operator *= (const Vector2D& location); //��Z���

	const Vector2D operator / (const float& scalar) const; //���Z�@
	const Vector2D operator / (const Vector2D& location) const; //���Z�@
	Vector2D& operator /= (const float& scalar); //���Z���
	Vector2D& operator /= (const Vector2D& location); //���Z���

	//�����^�ɕϊ�
	void ToInt(int* x, int* y) const;

};

