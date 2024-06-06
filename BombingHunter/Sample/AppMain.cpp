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

		//メインループ（ウインドウの異常発生）
		while (ProcessMessage() != -1 && CheckHitKey(KEY_INPUT_ESCAPE) != TRUE)
		{
			//入力機能の更新
			InputControl::Update();

			//シーンの更新処理
			scene->Update();

			//画面の初期化
			ClearDrawScreen();

			//シーンの描画処理
			scene->Draw();

			//裏画面の内容を表画面に反映する
			ScreenFlip();
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