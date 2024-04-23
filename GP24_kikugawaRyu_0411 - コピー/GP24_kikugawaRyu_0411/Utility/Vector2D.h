#pragma once

//2次元ベクトル
class Vector2D
{
public:
	float x;
	float y;

public:
	Vector2D();  //コンストラクタ
	Vector2D(float scalar);//
	Vector2D(float mx, float my);//　ｘとｙのしょきか用
	~Vector2D();//デストラクタ

	//演算子オーバーロード
public:
	Vector2D& operator = (const Vector2D& location);  //代入

	const Vector2D operator + (const Vector2D& location) const; //加算
	Vector2D& operator += (const Vector2D& location);  //加算代入
	 
	const Vector2D operator -(const Vector2D& location) const; //減算
	Vector2D& operator -= (const Vector2D& location);          //減算代入

	const Vector2D operator * (const float& scalar)const;  //乗算
	const Vector2D operator*(const Vector2D& location) const;
	Vector2D& operator *= (const float& scalar);  //乗算代入
	Vector2D& operator *= (const Vector2D& location); //乗算代入

	const Vector2D operator / (const float& scalar) const; //除算　
	const Vector2D operator / (const Vector2D& location) const; //除算　
	Vector2D& operator /= (const float& scalar); //除算代入
	Vector2D& operator /= (const Vector2D& location); //除算代入

	//整数型に変換
	void ToInt(int* x, int* y) const;

};

