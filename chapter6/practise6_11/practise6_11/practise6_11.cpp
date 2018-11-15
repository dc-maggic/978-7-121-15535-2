#include <iostream>
using namespace std;
void reset(int &x)
{
	x = 0;
}
int main()
{
	int n = 1;
	reset(n);
	cout << "reset n is " << n << endl;
	system("pause");
	return 0;
}