#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	string s("some string");
	if (s.begin() != s.end()) {
		auto it = s.begin();
		*it = toupper(*it);
		cout << *it << endl;
	}
	cout << s << endl;
	for (auto i = s.begin(); i != s.end() && !isspace(*i); ++i)
		*i = toupper(*i);
	cout << s << endl;
	vector<string> text{ "hello","word","hello world" ,"","ok" };
	for (auto it = text.cbegin();
		it != text.cend() && !it->empty(); ++it)
		cout << *it << endl;
	system("pause");
}