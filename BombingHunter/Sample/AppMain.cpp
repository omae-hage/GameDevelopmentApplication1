#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Scene/Scene.h"

//���C���֐��i�v���O�����͂����ɂ���܂��j
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//Window���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//�E�B���h�E�T�C�Y�i���F640Px�A�c�F480�����j��ݒ�
	SetGraphMode(640, 480, 32);

	//�c�w���C�u�����̏�����
	if(DxLib_Init())
}