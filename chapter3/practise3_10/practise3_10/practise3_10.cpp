#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	string s,str;
	cin >> s;
	for (auto c : s)
		if (!ispunct(c))
			str += c;
	cout << str << endl;
	system("pause");
}