#include <iostream>
#include <string>
struct Sales_data {
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
int main()
{
	using namespace std;
	Sales_data total;
	if (read(cin, total)) {
		Sales_data trans;
		while (read(cin, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else {
		cerr << "No data?!" << endl;
	}
	system("pause");
	return 0;
}