#include <iostream>
using namespace std;
void change(int *x, int *y)
{
	int i;
	i = *x;
	*x = *y;
	*y = i;
}
int main()
{
	int val1 = 1, val2 = 2;
	change(&val1, &val2);
	cout << val1 << val2 << endl;
	system("pause");
	return 0;
}