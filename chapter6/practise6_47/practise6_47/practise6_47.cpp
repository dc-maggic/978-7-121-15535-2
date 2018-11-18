
#include <iostream>
#include <vector>
using namespace std;
void printv(vector<int> &vec)
{
	if (vec.size())
	{
		auto temp = vec.back();
#ifndef NDEBUG
		cout << __FUNCTION__ << ":" << __FILE__ << endl;
#endif
		vec.pop_back();
		printv(vec);
		cout << temp;
	}
}
int main()
{
	vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v2 = {};
	printv(vi);
	printv(v2);
	system("pause");
	return 0;
}