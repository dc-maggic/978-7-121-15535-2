#include <iostream>
#include <string>
using namespace std;
void reset(int &i)
{
	i = 0;
}
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
	auto ret = s.size();
	occurs = 0;
	for (decltype(ret) i = 0; i != s.size(); ++i) {
		if (s[i] == c) {
			if (ret == s.size())
				ret = i;
			++occurs;
		}
	}
	return ret;
}
int main()
{
	int j = 42;
	reset(j);
	cout << "j = " << j << endl;
	string s = "helloworld";
	size_t ctr;
	auto index = find_char(s, 'o', ctr);
	cout << index << endl;
	system("pause");
	return 0;
}