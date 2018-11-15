#include <iostream>
using namespace std;
int compare(int i, int *p)
{
	if (i > *p)
		return i;
	else return *p;
}
int main()
{
	int x = 2,y = 6;
	int z = compare(x, &y);
	cout << z << endl;
	system("pause");
	return 0;

}