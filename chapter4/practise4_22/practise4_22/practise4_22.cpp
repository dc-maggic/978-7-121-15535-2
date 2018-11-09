#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
	unsigned grade;
	cin >> grade;
	cout << ((grade > 90) ? "high pass"
		: (grade > 75) ? "pass"
		: (grade > 60) ? "low pass"
		: "fail") << endl;
	if (grade > 90)
		cout << "high pass" << endl;
	else if (grade > 75)
		cout << "pass" << endl;
	else if (grade > 60)
		cout << "low pass" << endl;
	else
		cout << "fail" << endl;
	system("pause");
}