#include <iostream>
#include <vector>
using std::vector;
using std::begin;
using std::end;
using std::cout;
using std::endl;
int main()
{
	vector<int> v{ 10,10,20,3,4,-1,2 };
	auto pbeg = v.begin();
	while (pbeg != v.end() && *pbeg >= 0)
		cout << * pbeg++ <<" ";
	cout << endl;
	auto beg = v.begin();
	while (beg != v.end() && *beg >= 0)
		cout << *++beg << endl;
	system("pause");
}