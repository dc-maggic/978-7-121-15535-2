#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using namespace std;
int main()
{
	cout << "输入除数和被除数，空格隔开" << endl;
	int x, y, result;
	while (cin >> x >> y) {
		try {
			if (y == 0)
				throw runtime_error("除数不能为0");
			cout << "结果" << x / y << endl;
		}
		catch (runtime_error err) {
			cout << err.what() << endl;
			cout << "请重新再来" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;
		}
		cout << "输入除数和被除数，空格隔开" << endl;
	}
	
	system("pause");
	return 0;
}