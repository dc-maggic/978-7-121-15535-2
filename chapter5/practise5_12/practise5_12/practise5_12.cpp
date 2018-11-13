#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::noskipws;
int main()
{
	unsigned vowelCnt = 0, otherCnt = 0, fCnt = 0;
	bool flag = 0;
	char ch,beforeCh ='\0';
	while (cin >> noskipws >> ch) {
		switch (ch)
		{
		case 'a': case 'o':case 'e':  case 'u': case'A':case 'O': case 'E': case 'I': case 'U':
			++vowelCnt;
			break;
		case 'i':
		{
			if (beforeCh == 'f')
				++fCnt;
			else
				++vowelCnt;
		}
		break;
		case '\n':	case ' ': case '\t':
			++otherCnt;
			break;
		case 'f':  case'l':
			if (beforeCh == 'f') {
				++fCnt;
			}
			break;
		default:
			break;
		}
		if (ch == 'f' && beforeCh == 'f')
			beforeCh = '\0';
		else
			beforeCh = ch;
	}
	cout << "vowelCnt is " << vowelCnt << " otherCnt is " << otherCnt << "fCnt is " << fCnt << endl;
	system("pause");
}