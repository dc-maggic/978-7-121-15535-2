#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
	string str;
	for (auto i = 0; i != argc; ++i)
		str = str + argv[i] + argv[i];
	cout << str << endl;
	system("pause");
	return 0;
}