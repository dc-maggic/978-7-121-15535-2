#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
int main()
{
	cout << "please enter two words" << endl;
	string word1,word2;
	do {
		cin >> word1 >> word2;
		if (word1.size() > word2.size())
			cout << word1 << endl;
		else
			cout << word2 << endl;
	} while (cin);
	cout << "ok.there are two words." << endl;
	system("pause");
	return 0;
}