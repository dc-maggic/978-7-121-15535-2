#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
int main()
{
	vector<unsigned> scores(11, 0);
	unsigned grade;
	while (cin >> grade) {
		if (grade <= 100)
			++scores[grade / 10];
	}
	for (auto c : scores)
		cout<< c << " ";
	cout << endl;
	system("pause");
}