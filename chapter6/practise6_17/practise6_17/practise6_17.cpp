#include <iostream>
#include <string>
using namespace std;
bool isUpper(const string &s)
{
	size_t ret = s.size();
	for (size_t i = 0; i != s.size(); ++i) {
		if (isupper(s[i]))
			return isupper(s[i]);
	}
	return 0;
	
}
void toUpper(string &s)
{
	for (auto &c : s)
		c = toupper(c);
}
int main()
{
	cout << "请输入一段英文检测是否含有大写字母：" << endl;
	string str;
	cin >> str;
	if (isUpper(str))
		cout << "有" << endl;
	else
		cout << "没" << endl;
	cout << "请输入一段英文，可将其全部转换为大写字母：" << endl;
	cin >> str;
	toUpper(str);
	cout << str << endl;
	system("pause");
	return 0;
}