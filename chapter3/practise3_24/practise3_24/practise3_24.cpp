#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
	vector<int> numbers{ 1,2,3,4,5,6,7,8,9,10 };
	for (auto it = numbers.begin(); it != numbers.end() - 1; ++it) {
		auto sum = *it + *(it + 1);
		cout << sum << " ";
	}
	cout << endl;
	auto beg = numbers.begin(),end = numbers.end()-1;
	auto mid = beg + (end - beg) / 2;
	while (beg <= mid && end >= mid) {
		auto sum1 = *beg + *end;
		cout << sum1<< " ";
		++beg;
		--end;
	}
	system("pause");
}