#include <iostream>
int main()
{
	int sum = 0;
	for (int val = 10; val >= 0; --val)
		sum += val;
	std::cout << "Sum of 10 to 0 inclusive is " << sum << std::endl;
	return 0;
}