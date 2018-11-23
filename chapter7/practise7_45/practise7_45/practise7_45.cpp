#include <iostream>
#include <vector>
class NoDefault {
public:
	NoDefault(int) {}

};
class C {
public:
	NoDefault member;
	C() :member(0) {}
};
int main()
{
	std::vector<C> vec(10);
	system("pause");
	return 0;
}