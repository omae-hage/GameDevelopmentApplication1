#pragma once
//引数の値を絶対値に変換するテンプレート
//引数
//t　Value 変換する値
//戻り値
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
//最大値を返すテンプレート
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
//最小値を返すテンプレート
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