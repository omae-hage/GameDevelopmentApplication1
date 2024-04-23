#include"DxLib.h"
#include"Utility/InputControl.h"
#include"Objects/Player/Player.h"
//開始
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
	//描画先を裏画面に設定する
	SetDrawScreen(DX_SCREEN_BACK);
	//ループ開始
	while (ProcessMessage() != -1)
	{
		InputControl::Update();
		for (int i = 0; i < 2; i++)
		{
			objects[i]->Update();
		}
		ClearDrawScreen();//シーン消去

		for (int i = 0; i < 2; i++)
		{
			objects[i]->Draw();//画像消去
		}
		
		ScreenFlip();//画面の更新
		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}

	}

	for (int i = 0; i < 2; i++)
	{
		objects[i]->Finalize();
		delete objects[i]; //オブジェクト消去
	}
	DxLib_End();//DxLib　終わり

	return 0;
}