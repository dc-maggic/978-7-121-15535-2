#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	cout << "please enter many words" << endl;
	string word1, word2;
	do {
		cin >> word1;
		if (word1 ==  word2)
			break;
		else {
			word2 = word1;
			cout << word1 << endl;
		}
	} while (cin);
	cout << "ok.there are two words." << endl;
	system("pause");
	return 0;
}