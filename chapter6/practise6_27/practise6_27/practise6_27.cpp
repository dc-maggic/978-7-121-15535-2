#include <iostream>
#include <initializer_list>
using namespace std;
void sum(initializer_list<int>val)
{
	int sum = 0;
	for (auto beg = val.begin(); beg != val.end(); ++beg)
		sum += *beg;
	cout << sum << endl;
}
int main()
{
	sum({ 1,2,3,4,5,6,7,8,9 });
	system("pause");
	return 0;

}