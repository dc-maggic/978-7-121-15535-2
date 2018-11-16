#include <iostream>
#include <vector>
#include <string>
using namespace std;
int factorial(int val)
{
	if (val > 1)
		return factorial(val - 1) *val;
	return 1;
}
int main()
{
	int sum = factorial(5);
	cout << sum << endl;
	system("pause");
	return 0;
}