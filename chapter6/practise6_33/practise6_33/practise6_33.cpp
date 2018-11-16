#include <iostream>
#include <vector>
#include <string>
using namespace std;
void factorial(vector<string>::const_iterator beg, vector<string>::const_iterator end)
{
	if (beg != end)
	{
		cout << *beg << endl;
		return factorial(++beg, end);
	}
}
int main()
{
	const vector<string> str{ "sasd","sadasf","but","koh" };
	auto s = str.begin();
	factorial(str.begin(), str.end());
	system("pause");
	return 0;
}