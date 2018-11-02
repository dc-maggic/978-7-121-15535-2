#include <iostream>
int main()
{
	int val = 10; 
	std::cout << "The number 10 to 0 are " << std::endl;
	while (val >= 0) {
		std::cout << val<< std::endl;
		--val;
	}
	return 0;
}