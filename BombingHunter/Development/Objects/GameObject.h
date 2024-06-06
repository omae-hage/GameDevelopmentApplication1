#pragma once
#include "../Utility/Vector2D.h"
class GameObject
{
protected:
	Vector2D location;
	Vector2D box_size;
	double scale;
	double radian;
	int image;
	int sound;

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
};



