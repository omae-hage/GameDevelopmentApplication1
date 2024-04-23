#pragma once

#include "../Utility/Vector2D.h"

class Player
{
private:
	Vector2D location;  //座標
	Vector2D direction;//方向
	float radius;      //半径


public:
	Player(); //コンストラクた
	Player(float x, float y); 
	Player(Vector2D location); 
	~Player();

	void Update();  //更新処理
	void Draw() const;   //表示

	void SetLocation(float x, float y); //座標セット　
	void SetLocation(Vector2D location); //座標設定？
	Vector2D GetLocation() const; //座標取得
	float GetRadius(); //半径情報取得

private:
	//移動
	void Movement();  

};

