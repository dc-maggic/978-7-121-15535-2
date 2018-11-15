#include <iostream>
using namespace std;
int fact(int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}
int main()
{
	int j ;
	cout << "please enter n to count n!" << endl;
	cin >> j;
	int result = fact(j);
	cout << j << "! is " << result << endl;
	system("pause");
	return 0;
}
