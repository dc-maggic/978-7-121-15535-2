#include <iostream>
#include <stddef.h>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	unsigned scores[11] = {};
	unsigned grade;
	while (cin >> grade) {
		if (grade <= 100)
			++scores[grade / 10];
	}
	for (auto i : scores)
		cout << i << " ";
	cout << endl;
	system("pause");
}