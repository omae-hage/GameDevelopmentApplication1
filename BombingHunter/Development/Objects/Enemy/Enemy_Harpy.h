#pragma once
#include "../GameObject.h"
class Enemy_Harpy : public GameObject
{
private:
	int animation[2];  //アニメーション画像
	int animation_count; //アニメーション時間
	int flip_flag;  //反転グラフ
	Vector2D direction;
	int hit;//オブジェクト消去通知
	bool is_count;//スコア計算

public:
	Enemy_Harpy();
	~Enemy_Harpy();

	virtual void Initialize() override;  //初期化処理
	virtual void Update() override;    //更新処理
	virtual void Draw() const override; //描画処理
	virtual void Finalize() override;  //修了時処理

	//あ有判定通知処理
	virtual void OnHitCollision(GameObject* hit_object) override;
	//オブジェクト消去
	virtual bool deleteObject() override;
	//スコア計算
	virtual bool sc_count() override;
private:
	//移動処理
	void Movement();
	//アニメーション制御
	void AnimeControl();
};