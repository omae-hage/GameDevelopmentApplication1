#include"DxLib.h"
#include"Utility/InputControl.h"
#include"Objects/Player/Player.h"
//�J�n
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}
	
	GameObject* objects[2] = { nullptr,nullptr };
	objects[0] = new GameObject(); 
	objects[1] = new Player();

	for (int i = 0; i < 2; i++)
	{
		objects[i]->Initialize();
	}
	//�`���𗠉�ʂɐݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);
	//���[�v�J�n
	while (ProcessMessage() != -1)
	{
		InputControl::Update();
		for (int i = 0; i < 2; i++)
		{
			objects[i]->Update();
		}
		ClearDrawScreen();//�V�[������

		for (int i = 0; i < 2; i++)
		{
			objects[i]->Draw();//�摜����
		}
		
		ScreenFlip();//��ʂ̍X�V
		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}

	}

	for (int i = 0; i < 2; i++)
	{
		objects[i]->Finalize();
		delete objects[i]; //�I�u�W�F�N�g����
	}
	DxLib_End();//DxLib�@�I���

	return 0;
}