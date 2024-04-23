#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/Player.h"

//プログラム開始
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	Player* player = new Player();

	//描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	//ループさせる
	while (ProcessMessage() != -1)
	{

		InputControl::Update();
		player->Update();

		//画面の端に行くと逆の壁に行く
		Vector2D tmp = player->GetLocation();

		
		if (tmp.x < 0.0f || 640.0f < tmp.x)
		{
			//右から左へ
			if (tmp.x < 0)
			{
				tmp.x = 640.0f;
			}
			//左から右へ
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
		player->SetLocation(tmp); //座標更新
		ClearDrawScreen();  //シーン消去
		player->Draw(); //画像消去
		ScreenFlip(); //画面の更新

		//修了
		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}
	delete player; //プレイヤー消去
	DxLib_End(); //Dxライブラり　修了
	return 0;

}