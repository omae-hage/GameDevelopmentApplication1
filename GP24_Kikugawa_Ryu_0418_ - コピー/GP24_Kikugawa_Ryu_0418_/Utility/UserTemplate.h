#pragma once
//�����̒l���Βl�ɕϊ�����e���v���[�g
//����
//t�@Value �ϊ�����l
//�߂�l
// t
//

template <typename T>
T Abs(T value)
{
	T result;
	if (value > 0)
	{
		result = value = value;
	}
	else
	{
		result = -value;
	}
	return result;
}
//�ő�l��Ԃ��e���v���[�g
template <typename T>
T Max(T a, T b)
{
	T result;
	if (a < b)
	{
		result = b;
	}
	else
	{
		result = a;
	}
	return result;
}
//�ŏ��l��Ԃ��e���v���[�g
template <typename T>
T Min(T a, T b)
{
	T result;
	if (a > b)
	{
		result = b;
	}
	else
	{
		result = a;
	}
	return result;
}