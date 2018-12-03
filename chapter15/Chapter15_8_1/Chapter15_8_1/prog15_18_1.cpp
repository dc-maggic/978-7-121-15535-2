#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<set>
class Quote {

	friend double print_total(std::ostream &, const Quote &, size_t);
public:
	Quote() = default;
	std::string isbn() const { return bookNo; }
	virtual ~Quote() { std::cout << "Quote's destructor." << std::endl; };
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual void debug() const;
	Quote(const std::string &book, double p) :bookNo(book), price(p) { std::cout << "Quote's constructor." << std::endl; }
	//拷贝函数
	Quote(const Quote&eg) :bookNo(eg.bookNo), price(eg.price) { std::cout << "Quote's copy constructor." << std::endl; }
	//拷贝构造函数
	Quote& operator=(const Quote &eg) {
		std::cout << "Quote's synthesized copy_assignment operator" << std::endl;
		bookNo = eg.bookNo,
			price = eg.price;
		return *this;
	}
	//拷贝赋值运算符

	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move(*this)); }
private:
	std::string bookNo;
protected:
	double price = 0;
};
void Quote::debug() const {
	std::cout << "bookNo=" << isbn() << " price= " << price << std::endl;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total deu: " << ret << std::endl;
	return ret;
}

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book, double price, std::size_t qty, double disc) :
		Quote(book, price), qty(qty), discount(disc)
	{
		std::cout << "Disc_quote's constructor." << std::endl;
	}
	Disc_quote(const Disc_quote& eg) :Quote(eg), qty(eg.qty), discount(eg.discount) {
		std::cout << "Disc_quote's synthesized copy constructor." << std::endl;
	}
	Disc_quote& operator=(const Disc_quote &eg) {
		std::cout << "Disc_quote's synthesized copy_assignment operator" << std::endl;
		Quote::operator=(eg);
		discount = eg.discount;
		qty = eg.qty;
		return *this;
	}
	virtual double net_price(std::size_t) const = 0;
	~Disc_quote() { std::cout << "Disc_quote's destructor." << std::endl; }
protected:
	std::size_t qty = 0; //折扣使用的购买量
	double discount = 0;  //折扣的小数值
};

class Bulk_quote :public Disc_quote {
public:
	using Disc_quote::Disc_quote;//继承Disc_quote的构造函数
	double net_price(std::size_t n) const override {
		if (n > qty)
			return n * price*(1 - discount);
		else
			return n * price;
	}
	Bulk_quote* clone() const & { return new Bulk_quote(*this); }
	Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }
};
class Basket {
public:
	void add_item(const Quote& sale)
	{
		items.insert(std::shared_ptr<Quote>(sale.clone()));
	}//拷贝给定对象
	void add_item(Quote&& sale) 
	{
		items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
	}//移动给定对象
	void add_item(const std::shared_ptr<Quote> &sale)
	{
		items.insert(sale);
	}
	double total_receipt(std::ostream&)const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*>items{ compare };
};
double Basket::total_receipt(std::ostream &os) const
{
	double sum = 0.0;
	for (auto iter = items.cbegin();
		iter != items.cend();
		iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << std::endl;
	return sum;
}


int main()
{
	using namespace std;
	Quote basic("0-201-82470-1", 50);
	Bulk_quote bulk("0-201-82470-1", 50, 10, 0.25);
	Basket bsk;
	bsk.add_item(basic);
	bsk.add_item(bulk);
	bsk.total_receipt(cout);
	system("pause");
	return 0;
}