#include <iostream>
int main()
{
	std::cout << "Enter two number to count their sum (the first number must be smaller than the second):  " << std::endl;
	int sum = 0, val_1 = 0, val_2 = 0;
	std::cin >> val_1 >> val_2;
	while (val_1 <= val_2) {
		sum += val_1;
		++val_1;
	}
	std::cout << "The sum  is " << sum << std::endl;
	return 0;
}