#include <iostream>
using namespace std;
void print1(const char *cp)
{
	if (cp)
		while (*cp)
			cout << *cp++ ;
}
void print2(const int *beg, const int *end)
{
	while (beg != end)
		cout << *beg++ << endl;
}
void print3(const int ia[], size_t size)
{
	for (size_t i = 0; i != size; ++i)
		cout << ia[i] << endl;
}
void print4(int(&arr)[10])
{
	for (auto elem : arr)
		cout << elem << endl;
}
int main()
{
	int j[2] = { 0,1 };
	cout << "---" << endl;
	print2(begin(j), end(j));
	print3(j, end(j)-begin(j));
	int k[10] = { 0,1,2,3,4,5,6,7,8,9 };
	print4(k);
	system("pause");
	return 0;
}