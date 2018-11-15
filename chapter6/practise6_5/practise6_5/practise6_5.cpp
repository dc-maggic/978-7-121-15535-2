#include <iostream>
using namespace std;
int absoluteNumber(int val)
{
	if (val >= 0)
		return val;
	else
		return -val;
}
int main()
{
	cout << "please enter a number: ";
	int j;
	cin >> j;
	int result = absoluteNumber(j);
	cout << result << endl;
	system("pause");
	return 0;
}
