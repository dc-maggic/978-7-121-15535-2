#include<iostream>
using namespace std;
void reset(int *ip)
{
	*ip = 0;
	int y = 1;
	int *s = &y;
	ip = s;
}
int main()
{
	int n = 0, i = 42;
	int *p = &n, *q = &i;
	*p = 42;
	cout << n << endl;
	p = q;
	cout << *p << " " << n << endl;
	reset(&i);
	cout << "i = " << i << endl;
	system("pause");
	return 0;
}
