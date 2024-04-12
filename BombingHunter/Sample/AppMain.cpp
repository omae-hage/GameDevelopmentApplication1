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
	if(DxLib_Init())
}