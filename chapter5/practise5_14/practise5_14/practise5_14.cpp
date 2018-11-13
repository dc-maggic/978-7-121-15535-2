#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main()
{
	string word,beforeWord, flagWord;
	unsigned number = 1, flag = 1;
	while (cin >> word) {
		if (word == beforeWord)
			++number;
		else
		{
			beforeWord = word;
			number = 1;
		}
		if (flag < number) {
			flag = number;
			flagWord = beforeWord;
		}
	}
	cout << "The most is " << flagWord << " and the number is " << flag << endl;
	system("pause");
	return 0;
}