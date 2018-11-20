#include <iostream>
#include <string>
struct Sales_data {
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p*n) {}
	Sales_data(std::istream &);
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
};
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
double Sales_data::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
std::istream &read(std::istream& is, Sales_data &s)
{
	double price = 0;
	is >> s.bookNo >> s.units_sold >> price;
	s.revenue = price * s.units_sold;
	return is;
}
std::ostream &print(std::ostream &os, const Sales_data &s)
{
	os << s.isbn() << " " << s.units_sold << " " << s.revenue << " " << s.avg_price();
	return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}
int main()
{
	using namespace std;
	Sales_data example1("123-456-78");
	print(cout, example1) << endl;
	Sales_data example2;
	print(cout, example2) << endl;
	Sales_data example3("123-456-789", 2, 2.5);
	print(cout, example3) << endl;
	Sales_data example4(cin);
	print(cout, example4) << endl;
	system("pause");
	return 0;
}