#include <iostream>
using namespace std;
void print(const int *x,size_t size)
{
	for (size_t i = 0; i != size; ++i)
		cout << x[i] << endl;
}
int main()
{
	int i = 1, j[2] = { 0,1 };
	print(&i,1);
	print(j, end(j) - begin(j));
	system("pause");
	return 0;
}