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
	//≤ªø…∑√Œ 
};
struct Priv_derv :private Base {
	int f() const {
		return prot_mem;
	}
};
struct Prot_derv : protected Base {
	int f() { return prot_mem; }
};
struct Derived_from_Public : public Pub_derv{
	int use_base() { return prot_mem; }
};
struct Derived_from_Private : public Priv_derv {
	//int use_base() {return prot_mem;}
};
struct Derived_from_Protected :protected Prot_derv {
	int f() { return prot_mem; }
};

int main()
{
	system("pause");
	return 0;
}