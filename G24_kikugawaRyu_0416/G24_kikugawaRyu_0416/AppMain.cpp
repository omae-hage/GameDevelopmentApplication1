#include "DxLib.h"
#include"Utility/InputControl.h"
#include"Objects/GameObject.h"
#include "Objects/Player.h"

//��������v���O�����J�n
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}
	//�`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	
	GameObject* object1 = new GameObject();
	GameObject* object2  = new Player();
	/*Player* object2 = new Player();*/

	object1->Initialize();
	object2->Initialize();

	//���[�v������
	while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
	{

		InputControl::Update();

		object1->Update();
		object2->Update();

		ClearDrawScreen();//�V�[������

		object1->Draw();

		ScreenFlip();//��ʍX�V
	}

	delete object1;//�I�u�W�F�N�g�̏���
	delete object2;//�I�u�W�F�N�g�̏���

	DxLib_End();//Dx���C�u�����̏C��

	return 0;
}