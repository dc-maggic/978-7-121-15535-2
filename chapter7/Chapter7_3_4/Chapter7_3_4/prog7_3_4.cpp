#include <iostream>
#include <string>
#include <vector>
class Screen {
	//Window_mgr �ĳ�Ա���Է��� Screen ���˽�в��֣�
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
	//��Ӻ��� set(char) set(pos,pos,char)
	Screen &set(char);
	Screen &set(pos, pos, char);
	//���ݶ����Ƿ��� const ������ display ������
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
	//���� do_display ������ʾ Screen �����ݣ�
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
//���õ�ǰ�������λ�õ���ֵ���� this ������Ϊ��ֵ���أ�
inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
//���ø���λ�õ���ֵ��
inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
}
class Window_mgr {
public:
	//����ÿ����Ļ�ı�ţ�
	using ScreenIndex = std::vector<Screen>::size_type;
	//���ձ�Ž�ָ���� Screen ����Ϊ�հף�
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