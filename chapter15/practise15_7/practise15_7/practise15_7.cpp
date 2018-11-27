#include <iostream>
#include <string>
class Quote {
public:
	Quote() = default;
	Quote(const std::string& book, double p) :bookNo(book), price(p) {}
	std::string isbn() const {
		return bookNo;
	}
	virtual double net_price(std::size_t n) const { return price * n; }
private:
	std::string bookNo;
protected:
	double price = 0.0;
};
class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double p, std::size_t min, std::size_t max ,double disc) :Quote(book, p), min_qty(min), max_qty(max),discount(disc) {}
	double net_price(std::size_t) const override;
	double max_price(std::size_t) const ;
private:
	std::size_t min_qty = 0, max_qty = 10;
	double discount = 0;
};
double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due:: " << ret << std::endl;
	return ret;
}
double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt >= min_qty)
		return cnt * (1 - discount)*price;
	else
		return cnt * price;
}
double Bulk_quote::max_price(size_t cnt) const
{
	if (cnt <= max_qty)
		return cnt * (1 - discount)*price;
	else
		return max_qty * (1 - discount) *price + (cnt - max_qty)*price;
}

int main()
{
	Quote item;
	Bulk_quote bulk;
	Quote *p = &item;
	p = &bulk;
	Quote &r = bulk;
	print_total(std::cout, item, 2);
	print_total(std::cout, bulk, 2);
	system("pause");
	return 0;
}