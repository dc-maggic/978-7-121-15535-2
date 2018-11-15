#include <iostream>
using namespace std;
void swap(int &v1, int &v2)
{
	if (v1 == v2)
		return;
	int tmp = v2;
	v2 = v1;
	v1 = tmp;

}
int main()
{
	int x = 2, y = 4;
	swap(x, y);
	cout << x << " " << y << endl;
	system("pause");
	return 0;
}