#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
int main()
{
	vector<string> s;
	string word;
	while (cin >> word)
		s.push_back(word);
	for (auto w : s) {
		for (auto c : w) {
			c = toupper(c);
			cout << c;
		}
		cout << endl;
	}
	system("pause");
}