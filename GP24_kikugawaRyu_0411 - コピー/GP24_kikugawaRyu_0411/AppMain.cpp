#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/Player.h"

//�v���O�����J�n
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	Player* player = new Player();

	//�`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//���[�v������
	while (ProcessMessage() != -1)
	{

		InputControl::Update();
		player->Update();

		//��ʂ̒[�ɍs���Ƌt�̕ǂɍs��
		Vector2D tmp = player->GetLocation();

		
		if (tmp.x < 0.0f || 640.0f < tmp.x)
		{
			//�E���獶��
			if (tmp.x < 0)
			{
				tmp.x = 640.0f;
			}
			//������E��
			else
			{
				tmp.x = 0.0f;
			}
			player->SetLocation(tmp);
		}
		//
		if (tmp.y < 0.0f || 480.0f < tmp.y)
		{
			if (tmp.y < 0)
			{
				tmp.y = 480.0f;
			}
			else
			{
				tmp.y = 0.0f;
			}
		}
		player->SetLocation(tmp); //���W�X�V
		ClearDrawScreen();  //�V�[������
		player->Draw(); //�摜����
		ScreenFlip(); //��ʂ̍X�V

		//�C��
		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}
	delete player; //�v���C���[����
	DxLib_End(); //Dx���C�u����@�C��
	return 0;

}