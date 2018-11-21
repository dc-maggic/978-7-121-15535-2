#include <iostream>
#include <string>
class Screen {
public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(0) {}
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {}
	Screen move(pos, pos);
	Screen set(char);
	Screen set(pos, pos, char);
	Screen display(std::ostream &os)
	{
		do_display(os); return *this;
	}
	const Screen display(std::ostream &os) const
	{
		do_display(os); return *this;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream &os) const { os << contents; }
};
inline Screen Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = r + c;
	return *this;
}
inline Screen Screen::set(char ch)
{
	contents[cursor] = ch;
	return *this;
}
inline Screen Screen::set(pos r, pos c, char ch)
{
	contents[r*width + c] = ch;
	return *this;
}
int main()
{
	using namespace std;
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";
	system("pause");
	return 0;
}