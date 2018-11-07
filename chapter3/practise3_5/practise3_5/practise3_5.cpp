#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	cout << "输入多个字符串并把它们连接起来输出大字符串" << endl;
	string line;
	while (cin >> line)
		cout << line;
	cout << endl;
	system("pause");
}