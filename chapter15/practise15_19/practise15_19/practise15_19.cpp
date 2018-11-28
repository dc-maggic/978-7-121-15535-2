#include <iostream>
#include <string>
class Base {
	friend class Pal;
public:
	void pub_mem();
	std::size_t size() const { return n; }
private:
	char priv_mem;
protected:
	int prot_mem;
	std::size_t n;
};
class Sneaky : public Base {
	friend void clobber(Sneaky&);
	int j;
};
class Pal {
public:
	int f(Base b) { return b.prot_mem; }
	int f3(Sneaky s) { return s.prot_mem; }
};
class Derived :private Base {
public:
	using Base::size;
protected:
	using Base::n;
};
struct Pub_derv : public Base {
	int f() { return prot_mem; }
	//char g() { return priv_mem; }
	//不可访问
	void memfcn(Base &b) { b = *this; }
};
struct Priv_derv :private Base {
	int f() const {
		return prot_mem;
	}
	void memfcn(Base &b) { b = *this; }
};
struct Prot_derv : protected Base {
	int f() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Public : public Pub_derv {
	int use_base() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Private : public Priv_derv {
	//int use_base() {return prot_mem;}
	//void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Protected :protected Prot_derv {
	int f() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

int main()
{
	Pub_derv d1;
	Base *p = &d1;
	Priv_derv d2;
	//p = &d2;不允许对不可访问的基类Base进行转换；
	Prot_derv d3;
	//p = &d3;
	Derived_from_Public dd1;
	p = &dd1;
	Derived_from_Private dd2;
	//p = &dd2;
	Derived_from_Protected dd3;
	//p = &dd3;
	system("pause");
	return 0;
}