#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
int main()
{
	vector<int> numbers;
	int sum1, sum2;
	int num;
	while (cin >> num)
		numbers.push_back(num);
	auto len = numbers.size();
	for (decltype(numbers.size()) i = 1; i < len; ++i) {
		sum1 = numbers[i - 1] + numbers[i];
		cout << sum1 << " ";
	}
	cout << endl;
	for (decltype(numbers.size()) j = 0; j < (len+1)/2; ++j) {
		sum2 = numbers[j] + numbers[len-j-1];
		cout << sum2 << " ";
	}
	system("pause");
}