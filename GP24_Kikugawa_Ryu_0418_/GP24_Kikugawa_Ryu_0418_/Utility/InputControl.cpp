#include "InputControl.h"
#include "DxLib.h"

char InputControl::now_key[D_KEYCODE_MAX] = {};
char InputControl::old_key[D_KEYCODE_MAX] = {};
//更新処理
void InputControl::Update()
{
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));
	GetHitKeyStateAll(now_key);
}
//キーコード取得
bool InputControl::GetKey(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE)
		&& (old_key[key_code] == TRUE));
}
//キが押された時の情報取得
bool InputControl::GetKeyDown(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE)
		&& (old_key[key_code] == FALSE));

}
////キーが離れた時の情報取得
bool InputControl::GetKeyUp(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == FALSE)
		&& (old_key[key_code] == TRUE));
}
//キーが有効か調べる
bool InputControl::CheckKeyCodeRange(int key_code)
{
	return(0 <= key_code && key_code < D_KEYCODE_MAX);
}

