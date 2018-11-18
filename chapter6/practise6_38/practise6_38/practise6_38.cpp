#include <iostream>
using namespace std;

	int odd[] = { 1,3,5,7,9 };
	int even[] = { 0,2,4,6,8 };
	decltype(odd) &arrPtr(int i)
	{
		return (i % 2) ? odd : even;
	}

	int main()
	{
		int i = 2;
		for (auto &c : arrPtr(i))
			cout << c << endl;
		system("pause");
		return 0;
	}
