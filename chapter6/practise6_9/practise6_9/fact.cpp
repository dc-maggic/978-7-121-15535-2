#include <iostream>
#include "chapter6.h"
using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;
int fact(int val)
{
	try
	{
		if (val <= 0)
		{
			throw runtime_error("����ֵҪ����0");
		}
		int ret = 1;
		for (int i = 0; i != val; ++i)
		{
			ret *= i + 1;
		}
		return ret;
	}
	catch (runtime_error e)
	{
		cout << e.what() << endl;
		return val;
	}
}
int fact()
{
	int val;
	cout << "������Ҫ����Ľ׳�" << endl;
	try
	{
		cin >> val;
		if (val <= 0)
		{
			throw runtime_error("����ֵҪ����0");
		}
		int ret = 1;
		for (int i = 0; i != val; ++i)
		{
			ret *= i + 1;
		}
		cout << val << "!�ǣ� " << ret << endl;
		return ret;
	}
	catch (runtime_error e)
	{
		cout << e.what() << endl;
		return val;
	}
}
int fun(int val)
{
	if (val < 0)
	{
		return -1 * val;
	}


	return val;
}