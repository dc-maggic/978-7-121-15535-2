#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<memory>
#include<sstream>
#include "TextQuery.h"
using namespace std;


class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;//eval 返回与当前 Query 匹配的 QueryResult
	virtual string rep() const = 0;//rep 是表示查询的一个 string
};

class Query {
	//这些运算符需要接受访问接受 shared_ptr 的构造函数，而该函数是私有的
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const string&);//构建一个新的 WordQuery
	//接口函数：调用对应的 Query_base 操作
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }
	string rep() const { return q->rep(); }
private:
	Query(shared_ptr<Query_base> query) :q(query) {}
	shared_ptr<Query_base> q;
};

ostream& operator<<(ostream& os, const Query &query)
{
	return os << query.rep();
}
class WordQuery : public Query_base {
	friend class Query;
	WordQuery(const string &s) :query_word(s) {}
	QueryResult eval(const TextQuery &t)const { return t.query(query_word); }
	string rep() const { return query_word; }
	string query_word;//要查找的单词
};
inline Query::Query(const string &s) :q(new  WordQuery(s)) {}
class NotQuery : public Query_base {
	friend Query operator~(const Query &);
	NotQuery(const Query &q):query(q) { }
	string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&) const;
	Query query;
};
inline Query operator~(const Query &operand)
{
	return shared_ptr<Query_base>(new NotQuery(operand));
}
class BinaryQuery : public Query_base {
protected:
	BinaryQuery(const Query &l, const Query &r, string s) :
		lhs(l), rhs(r), opSym(s) {}
	string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
	Query lhs, rhs;
	string opSym;
};
class AndQuery :public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "&") {}
	QueryResult eval(const TextQuery&) const;
};
inline Query operator&(const Query &lhs, const Query &rhs)
{
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
class OrQuery :public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "|") {}
	QueryResult eval(const TextQuery&) const;
};
inline Query operator|(const Query &lhs, const Query &rhs)
{
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}