
#pragma once
#include "../GameObject.h"
class Enemy_kin : public GameObject
{
private:
	int animation[2];  //アニメーション画像
	int animation_count; //アニメーション時間
	int flip_flag;  //反転グラフ
	//int set_taim;
	Vector2D direction;
	int se;
	bool hit;
	int rand;
	bool is_count;
public:
	Enemy_kin();
	~Enemy_kin();

	virtual void Initialize() override;  //初期化処理
	virtual void Update() override;    //更新処理
	virtual void Draw() const override; //描画処理
	virtual void Finalize() override;  //修了時処理u

	//あ有判定通知処理
	virtual void OnHitCollision(GameObject* hit_object) override;
	virtual bool deleteObject() override;
	virtual bool sc_count() override;


private:
	//移動処理
	void Movement();
	//アニメーション制御
	void AnimeControl();

public:



};





//<^^>//
