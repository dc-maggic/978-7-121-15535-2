#include <iostream>
#include "chapter6.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{
	{
		int val;
		cout << "������Ҫ����Ľ׳�" << endl;
		cin >> val;
		int ret = fact(val);
		if (ret > 0)
		{
			cout << val << "!�ǣ� " << ret << endl;
		}
	}

	{
		fact();
	}
	{
		int val;
		cout << "������һ������:" << endl;
		cin >> val;
		cout << val << "�ľ���ֵ�ǣ� " << fun(val) << endl;
	}
	system("pause");
	return 0;
}