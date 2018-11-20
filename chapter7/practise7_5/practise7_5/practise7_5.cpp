#include <iostream>
#include <string>
struct  Person
{
	std::string name;
	std::string address;
};
std::ostream &print(std::ostream& os, const Person& s)
{
	os<< s.name << " " << s.address<<std::endl;
	return os;
}
std::istream &read(std::istream& is, Person& s)
{
	is >> s.name >> s.address;
	return is;
}
int main()
{
	using namespace std;
	cout << "ÇëÊäÈëĞÕÃû µØÖ·£º" << endl;
	Person who;
	while (read(cin, who))
		print(cout, who);
	system("pause");
	return 0;
}