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

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object);

	//�ʒu���擾����
	Vector2D GetLocation() const;
	//�ʒu���ύX����
	void SetLocation(const Vector2D& location);

	Vector2D GetBoxSize() const;

	

	 int GetType();
	 void SetType(int object_type);


	virtual bool deleteObject();
	virtual bool sc_count();

};



