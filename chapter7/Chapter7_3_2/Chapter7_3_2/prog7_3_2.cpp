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
private:
	std::vector<Screen> sreens{ Screen(24,80,' ') };
};