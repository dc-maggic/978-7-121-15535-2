#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
	vector<int> num;
	int i;
	while (cin >> i)
		num.push_back(i);
	for (auto &it : num)
		cout << ((it % 2 == 1) ? it *2 : it)<< " ";
	cout << endl;
	system("pause");
}