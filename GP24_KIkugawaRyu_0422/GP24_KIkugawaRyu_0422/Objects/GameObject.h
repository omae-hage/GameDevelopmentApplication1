#pragma once
#include "../Utility/Vector2D.h"
class GameObject
{
protected:
	int image;
	Vector2D location;//���W
	Vector2D box_size;//�����蔻��

public:
	GameObject();//�R���X�g���N�^
	virtual ~GameObject();//�f�X�g���N�^

	virtual void Initialize();//������
	virtual void Update();//�X�V����
	virtual void Draw()const;//�`�揈��
	virtual void Finalize();//�I������

public:
	void SetLocation(Vector2D location);//���W�Z�b�g
	Vector2D GetLocation() const;//���W�擾
	Vector2D GetBoxSize() const;//�����蔻��擾