#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Scene/Scene.h"

//���C���֐��i�v���O�����͂����ɂ���܂��j
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//Window���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//�E�B���h�E�T�C�Y�i���F640Px�A�c�F480�����j��ݒ�
	SetGraphMode(640, 480, 32);

	//�c�w���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		//�ُ�����m
		return -1;
	}

	//���[�J���ϐ���`
	Scene* scene = new Scene();   //�V�[�����
	int result = 0;  //�C������

	//�`���𗠉�ʂ���n�߂�悤�Ɏw�肷��
	SetDrawScreen(DX_SCREEN_BACK);


	try
	{
		//�V�[���̏�����
		scene->Initialize();
		int get_time = GetNowCount();
		int set_time = get_time + 60000;
		int image = LoadGraph("Resource/Images/Evaluation/Finish.png");
		int bgm = LoadSoundMem("Resource/Sounds/Evaluation/BGM_arrows.wav");
		ChangeVolumeSoundMem(100, bgm);
		

		//���C�����[�v�i�E�C���h�E�ُ̈픭���j
		while (ProcessMessage() != -1 && CheckHitKey(KEY_INPUT_ESCAPE) != TRUE)
		{
			PlaySoundMem(bgm, DX_PLAYTYPE_LOOP, FALSE);
			while (GetNowCount() - set_time < 60000)
			{
				//���͋@�\�̍X�V
				InputControl::Update();

				//�V�[���̍X�V����
				scene->Update();

				int time = GetNowCount();

				int time_time = (set_time - time) / 1000;

				if (time_time <= -1)
				{
					DeleteSoundMem(bgm);
					break;
				}

				//��ʂ̏�����
				ClearDrawScreen();
				//�V�[���̕`�揈��
				scene->Draw();
				DrawFormatString(80.0f, 460.0f, GetColor(255, 255, 255), "%d",time_time);
				if (time_time == 0)
				{
					scene->Sc();
				}
				//����ʂ̓��e��\��ʂɔ��f����
				ScreenFlip();
				
			}
		}
	}
	catch (const char* error_log)
	{
		//����[����LOG�BTXT�ɏo�͂���
		OutputDebugString(error_log);

		//�ُ���ɕύX����
		result = -1;
	}

	//�V�[�����̏�������
	if (scene != nullptr)
	{
	
		scene->Finalize();
		delete scene;
		scene = nullptr;
	}

	//DX���C�u�����̏C��������
	DxLib_End();
	//�C����Ԃ�ʒm
	return result;
}