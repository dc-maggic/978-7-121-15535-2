#include <iostream>
#include <string>
#include <vector>
class Screen {
	//Window_mgr 的成员可以访问 Screen 类的私有部分；
	friend class Window_mgr;
	friend void Window_mgr::clear(ScreenIndex);
public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {}
	char get() const { return contents[cursor]; }
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	void some_member() const;
	//添加函数 set(char) set(pos,pos,char)
	Screen &set(char);
	Screen &set(pos, pos, char);
	//根据对象是否是 const 重载了 display 函数；
	Screen &display(std::ostream &os)
	{
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os) const
	{
		do_display(os);
		return *this;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	mutable size_t access_ctr;
	//函数 do_display 负责显示 Screen 的内容；
	void do_display(std::ostream &os) const { os << contents; }
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
//设置当前光标所在位置的新值，将 this 对象作为左值返回；
inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
//设置给定位置的新值；
inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
}
class Window_mgr {
public:
	//窗口每个屏幕的编号；
	using ScreenIndex = std::vector<Screen>::size_type;
	//按照编号将指定的 Screen 重置为空白；
	void clear(ScreenIndex);
private:
	std::vector<Screen> screens{ Screen(24,80,' ') };
};
void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = std::string(s.height*s.width, ' ');
}
struct X {
	friend void f() {}
	X() { f(); }
	void g();
	void h();
};
void X::g() { return f(); }
void f();
void X::h() { return f(); }