#include <iostream>
int main()
{
	int i = 42;
	int &r = i;
	std::cout << r << std::endl;
	int *p;
	p = &i;
	*p = i;
	std::cout << p << " " << *p << std::endl;
	int &r2 = *p;
	system("pause");
}