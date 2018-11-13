#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	unsigned vowelCnt = 0;
	char ch;
	while (cin >> ch) {
		switch (ch)
		{
		case 'a': case 'o':case 'e': case 'i': case 'u': case'A':case 'O': case 'E': case 'I': case 'U':
			++vowelCnt;
			break;
		default:
			break;
		}
	}
	cout << vowelCnt << endl;
	system("pause");
}