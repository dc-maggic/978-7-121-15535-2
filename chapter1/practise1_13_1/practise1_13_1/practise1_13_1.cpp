#include <iostream>
int main()
{
	int sum = 0;
	for (int val = 50; val <= 100; ++val)
		sum += val;
	std::cout << "The sum of 50 to 100 inclusive is " << sum << std::endl;
	system("pause");
}