#pragma once

#define D_KEYCODE_MAX (256) //キーの総数

class InputControl
{
private:
	static char now_key[D_KEYCODE_MAX];  //現在の入力情報
	static char old_key[D_KEYCODE_MAX];  //前フレームの入力情報

public:
	static void Update(); //更新

	static bool GetKey(int key_code); //キー情報取得
	static bool GetKeyDown(int key_code); //キーが押された時の情報取得
	static bool GetKeyUp(int key_code); //キーが離された時の情報取得

private:
	static bool CheckkeyCodeRange(int key_code); //キーが有効か調べる

};
