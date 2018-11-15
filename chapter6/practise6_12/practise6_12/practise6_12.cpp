#include<iostream>
using namespace std;
void change(int &ip, int &iq)
{
	int x;
	x = ip;
	ip = iq;
	iq = x;
}
int main()
{
	int  i = 42, j = 10;
	change(i, j);
	cout << "i = " << i << "j = " << j << endl;
	system("pause");
	return 0;
}
