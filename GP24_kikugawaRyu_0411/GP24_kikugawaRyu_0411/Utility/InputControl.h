#pragma once

#define D_KEYCODE_MAX (256)

class InputControl
{
private:
	static char now_key[D_KEYCODE_MAX];
	static char old[D_KEYCODE_MAX];

public:
	static void Update();
	static bool GetKeyDown(int key_code);
	static bool GetKeyUp(int key_code);

private:
	static bool CheckkeyCodeRange(int key_code);

};

