#include <iostream>
#include <string>
class Sales_data {
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	friend std::ostream &print(std::ostream &, const Sales_data &);
public:
	Sales_data(std::string s, unsigned cnt, double price) :bookNo(s), units_sold(cnt), revenue(price*cnt) {}
	Sales_data() :Sales_data("", 0, 0) {}
	Sales_data(std::string s) :Sales_data(s, 0, 0) {}
	Sales_data(std::istream &is ) {
		read(is, *this);
	}
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price() const {
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
	std::string null_book = "9-999-99999-9";
	Sales_data item;
	item.combine(null_book);
	item.combine(std::cin);
	system("pause");
	return 0;
}