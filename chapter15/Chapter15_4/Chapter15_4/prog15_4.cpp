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
	virtual void debug()const;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};
void Quote::debug() const
{
	std::cout << "ISBN: " << isbn() << " price: " << price << std::endl;
}

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book, double price, std::size_t qty, double disc) :Quote(book, price), quantity(qty), discount(disc) {}
	double net_price(std::size_t) const = 0;
protected:
	std::size_t quantity = 0; //折扣使用的购买量
	double discount = 0;  //折扣的小数值
};

class Bulk_quote : public Disc_quote{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :Disc_quote(book,price,qty,disc){}
	double net_price(std::size_t) const override;
	void debug() const override;
private:
	std::size_t min_qty = 0;
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
void Bulk_quote::debug() const
{
	std::cout << "ISBN: " << isbn() << " min_qty: " << min_qty << " price: " << price << " discount: " << discount << std::endl;
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
	Quote base;
	print_total(std::cout, base, 10);
	Bulk_quote derived("0-201-82470-1", 50, 5, .19);
	print_total(std::cout, derived, 10);
	base = derived;
	base.net_price(20);
	item.debug();
	bulk.debug();
	system("pause");
	return 0;
}