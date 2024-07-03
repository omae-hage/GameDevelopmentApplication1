#pragma once
#include "../Utility/Vector2D.h"

#define player (10)
#define enemy (20)
#define enemy_hane (30)
#define enemy_Harpy (40)
#define enemy_bullet (50)
#define bom_fx (60)
#define bom (70)
#define enemy_kin (80)


class GameObject
{
protected:
	Vector2D location;
	Vector2D box_size;
	double scale;
	double radian;
	int image;
	int sound;
	int type;
	int count;

public:
	GameObject();
	virtual ~GameObject();

	virtual void Initialize();
	virtual void Update();
	virtual void Draw() const;
	virtual void Finalize();

	//当たり判定通知処理
	virtual void OnHitCollision(GameObject* hit_object);

	//位置情報取得処理
	Vector2D GetLocation() const;
	//位置情報変更処理
	void SetLocation(const Vector2D& location);

	Vector2D GetBoxSize() const;

	

	 int GetType();
	 void SetType(int object_type);


	virtual bool deleteObject();
	virtual bool sc_count();

};



