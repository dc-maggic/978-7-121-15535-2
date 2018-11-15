#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
	for (auto i = 1; i != argc; ++i)
		cout << argv[i] << endl;
	system("pause");
	return 0;
}