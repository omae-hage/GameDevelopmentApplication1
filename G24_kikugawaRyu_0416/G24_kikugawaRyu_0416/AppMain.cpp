#include "DxLib.h"
#include"Utility/InputControl.h"
#include"Objects/GameObject.h"
#include "Objects/Player.h"

//ここからプログラム開始
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}
	//描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	
	GameObject* object1 = new GameObject();
	GameObject* object2  = new Player();
	/*Player* object2 = new Player();*/

	object1->Initialize();
	object2->Initialize();

	//ループさせる
	while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
	{

		InputControl::Update();

		object1->Update();
		object2->Update();

		ClearDrawScreen();//シーン消去

		object1->Draw();

		ScreenFlip();//画面更新
	}

	delete object1;//オブジェクトの消去
	delete object2;//オブジェクトの消去

	DxLib_End();//Dxライブラリの修了

	return 0;
}