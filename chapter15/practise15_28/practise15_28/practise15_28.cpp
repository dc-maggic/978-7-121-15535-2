#include<iostream>
#include<string>
#include<vector>
#include<memory>
class Quote {
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
protected:
	std::string bookNo;
	double price = 0;
};
void Quote::debug() const {
	std::cout << "bookNo=" << isbn() << " price= " << price << std::endl;
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
};
int main()
{
	using namespace std;
	vector<Quote> basket;
	basket.push_back(Quote("0-201-82470-1", 50));
	basket.push_back(Bulk_quote("0-201-82470-1", 50, 10, 0.25));
	double sum = 0;
	for (auto &p : basket) {
		sum += p.net_price(15);
	}
	cout << sum << endl;
	system("pause");
	return 0;
}