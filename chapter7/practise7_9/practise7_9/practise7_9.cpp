#include <iostream>
#include <string>
struct  Person
{
	std::string name;
	std::string address;
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