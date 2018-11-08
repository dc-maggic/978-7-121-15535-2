#include <iostream>
using std::begin;
using std::end;
int main()
{
	int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
	int *pbeg = begin(ia);
	int *pend = end(ia);
	while (pbeg != pend && *pbeg >= 0)
		++pbeg;
}