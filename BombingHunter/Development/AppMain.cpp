#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Scene/Scene.h"

//メイン関数（プログラムはここにあります）
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//Windowモードで起動
	ChangeWindowMode(TRUE);

	//ウィンドウサイズ（横：640Px、縦：480ｐｘ）を設定
	SetGraphMode(640, 480, 32);

	//ＤＸライブラリの初期化
	if (DxLib_Init() == -1)
	{
		//異常を検知
		return -1;
	}

	//ローカル変数定義
	Scene* scene = new Scene();   //シーン情報
	int result = 0;  //修了条件

	//描画先を裏画面から始めるように指定する
	SetDrawScreen(DX_SCREEN_BACK);


	try
	{
		//シーンの初期化
		scene->Initialize();
		int get_time = GetNowCount();
		int set_time = get_time + 60000;
		int image = LoadGraph("Resource/Images/Evaluation/Finish.png");
		int bgm = LoadSoundMem("Resource/Sounds/Evaluation/BGM_arrows.wav");
		ChangeVolumeSoundMem(100, bgm);
		

		//メインループ（ウインドウの異常発生）
		while (ProcessMessage() != -1 && CheckHitKey(KEY_INPUT_ESCAPE) != TRUE)
		{
			PlaySoundMem(bgm, DX_PLAYTYPE_LOOP, FALSE);
			while (GetNowCount() - set_time < 60000)
			{
				//入力機能の更新
				InputControl::Update();

				//シーンの更新処理
				scene->Update();

				int time = GetNowCount();

				int time_time = (set_time - time) / 1000;

				if (time_time <= -1)
				{
					DeleteSoundMem(bgm);
					break;
				}

				//画面の初期化
				ClearDrawScreen();
				//シーンの描画処理
				scene->Draw();
				DrawFormatString(80.0f, 460.0f, GetColor(255, 255, 255), "%d",time_time);
				if (time_time == 0)
				{
					scene->Sc();
				}
				//裏画面の内容を表画面に反映する
				ScreenFlip();
				
			}
		}
	}
	catch (const char* error_log)
	{
		//えらー情報をLOG。TXTに出力する
		OutputDebugString(error_log);

		//異常情報に変更する
		result = -1;
	}

	//シーン情報の消去する
	if (scene != nullptr)
	{
	
		scene->Finalize();
		delete scene;
		scene = nullptr;
	}

	//DXライブラリの修了時処理
	DxLib_End();
	//修了状態を通知
	return result;
}