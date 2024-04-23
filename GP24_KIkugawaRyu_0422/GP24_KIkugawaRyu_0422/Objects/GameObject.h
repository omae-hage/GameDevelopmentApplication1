#pragma once
#include "../Utility/Vector2D.h"
class GameObject
{
protected:
	int image;
	Vector2D location;//座標
	Vector2D box_size;//当たり判定

public:
	GameObject();//コンストラクタ
	virtual ~GameObject();//デストラクタ

	virtual void Initialize();//初期化
	virtual void Update();//更新処理
	virtual void Draw()const;//描画処理
	virtual void Finalize();//終了処理

public:
	void SetLocation(Vector2D location);//座標セット
	Vector2D GetLocation() const;//座標取得
	Vector2D GetBoxSize() const;//当たり判定取得