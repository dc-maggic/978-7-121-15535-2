#include <iostream>
#include "chapter6.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{
	{
		int val;
		cout << "请输入要计算的阶乘" << endl;
		cin >> val;
		int ret = fact(val);
		if (ret > 0)
		{
			cout << val << "!是： " << ret << endl;
		}
	}

	{
		fact();
	}
	{
		int val;
		cout << "请输入一个整数:" << endl;
		cin >> val;
		cout << val << "的绝对值是： " << fun(val) << endl;
	}
	system("pause");
	return 0;
}