#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	string s;
	for (auto &c : s)
		c = 'x';
	cout << s << endl;
	system("pause");
}