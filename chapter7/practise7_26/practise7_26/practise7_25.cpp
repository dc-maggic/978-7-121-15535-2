#include <iostream>
#include <string>
class Sales_data {
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	friend std::ostream &print(std::ostream &, const Sales_data &);
public:
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p*n) {}
	Sales_data(std::istream&);
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	inline double avg_price() const {
		return units_sold ? revenue / units_sold : 0;
	}

};
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream &, const Sales_data &);
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