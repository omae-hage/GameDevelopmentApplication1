#pragma once

#define D_KEYCODE_MAX (256) //�L�[�̑���

class InputControl
{
private:
	static char now_key[D_KEYCODE_MAX];  //���݂̓��͏��
	static char old_key[D_KEYCODE_MAX];  //�O�t���[���̓��͏��

public:
	static void Update(); //�X�V

	static bool GetKey(int key_code); //�L�[���擾
	static bool GetKeyDown(int key_code); //�L�[�������ꂽ���̏��擾
	static bool GetKeyUp(int key_code); //�L�[�������ꂽ���̏��擾

private:
	static bool CheckkeyCodeRange(int key_code); //�L�[���L�������ׂ�

};
