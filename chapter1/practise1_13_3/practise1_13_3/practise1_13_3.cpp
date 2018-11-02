#include <iostream>
int main()
{
	int sum = 0;
	std::cout << "Enter two number(the first number must be smaller than second):" << std::endl;
	int val_1 = 0, val_2 = 0;
	std::cin >> val_1 >> val_2;
	for (int val = val_1; val <= val_2; ++val)
		sum += val;
	std::cout << "The sum  is " << sum << std::endl;
	return 0;
}