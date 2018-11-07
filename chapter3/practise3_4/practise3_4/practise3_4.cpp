#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	cout << "please enter two words to compare their,the result is the bigger." << endl;
	string st1, st2;
	cin >> st1 >> st2;
	if (st1 > st2)
		cout << st1 << endl;
	else
		cout << st2 << endl;
	cout << "please enter two words to compare their size,the result is the bigger." << endl;
	string st3, st4;
	cin >> st3 >> st4;
	if (st3.size() > st4.size())
		cout << st3 << endl;
	else
		cout << st4 << endl;
	system("pause");
}