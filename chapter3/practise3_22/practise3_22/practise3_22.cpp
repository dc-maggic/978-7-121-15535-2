#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
int main()
{
	vector<string> text{ "hello","word","hellow world" ,"","ok"};
	for (auto it = text.begin();
		it != text.end() && !it->empty(); ++it) {
		for (auto &w : *it)
		{
			w = toupper(w);
			cout << w;
		}
		cout << endl;
	}
		
	system("pause");
}