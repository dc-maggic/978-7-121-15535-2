#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using namespace std;
int main()
{
	cout << "��������ͱ��������ո����" << endl;
	int x, y, result;
	while (cin >> x >> y) {
		try {
			if (y == 0)
				throw runtime_error("��������Ϊ0");
			cout << "���" << x / y << endl;
		}
		catch (runtime_error err) {
			cout << err.what() << endl;
			cout << "����������" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;
		}
		cout << "��������ͱ��������ո����" << endl;
	}
	
	system("pause");
	return 0;
}