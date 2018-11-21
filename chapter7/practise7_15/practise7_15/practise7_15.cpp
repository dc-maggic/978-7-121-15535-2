#include <iostream>
#include <string>
struct  Person
{
	std::string name;
	std::string address;
	Person(const std::string &n, const std::string &a) :name(n), address(a) {}
	Person(std::istream &);
};

std::istream &read(std::istream& is, Person &s)
{
	is >> s.name >> s.address;
	return is;
}
std::ostream &print(std::ostream &os, const Person &s)
{
	os << s.name << " " << s.address;
	return os;
}
Person::Person(std::istream &is) {
	read(is, *this);
}
int main()
{
	using namespace std;
	Person Tom("Tom", "SZ");
	print(cout, Tom)<<endl;
	Person who(cin);
	print(cout, who) << endl;
	system("pause");
	return 0;
}