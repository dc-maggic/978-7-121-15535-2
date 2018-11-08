#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
	vector<int> numbers(10);
	for (auto it = numbers.begin(); it != numbers.end(); ++it) {
		cin >> *it;
		*it *= 2;
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
}