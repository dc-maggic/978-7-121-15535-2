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
	cout << "������һ��Ӣ�ļ���Ƿ��д�д��ĸ��" << endl;
	string str;
	cin >> str;
	if (isUpper(str))
		cout << "��" << endl;
	else
		cout << "û" << endl;
	cout << "������һ��Ӣ�ģ��ɽ���ȫ��ת��Ϊ��д��ĸ��" << endl;
	cin >> str;
	toUpper(str);
	cout << str << endl;
	system("pause");
	return 0;
}