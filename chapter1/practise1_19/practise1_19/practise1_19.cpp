#include <iostream>
int main()
{
	int sum = 0, currVal = 0, val = 0;
	if (std::cin >> currVal) {
		sum = currVal;
		while (std::cin >> val) {
			if (val >= currVal) {
				sum += val ;
				currVal = val;
				std::cout << val << sum << currVal << std::endl;
			}
		}
		
	}
	std::cout << "The sum is " << sum << std::endl;
	system("pause");
}