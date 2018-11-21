#include <iostream>
#include <string>
#include <vector>
class Screen {
public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {}
	char get() const { return contents[cursor]; }
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	void some_member() const;
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	mutable size_t access_ctr;
};
inline
Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}
void Screen::some_member() const
{
	++access_ctr;
}
class Window_mgr {
private:
	std::vector<Screen> sreens{ Screen(24,80,' ') };
};