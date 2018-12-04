#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<memory>
#include<sstream>
using namespace std;
class QueryResult;
class TextQuery {
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;//输入文件
	map<string, shared_ptr<set<line_no>>> wm;
};
TextQuery::TextQuery(ifstream &is) :file(new vector<string>)
{
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}
class QueryResult {
	friend ostream& print(ostream&, const QueryResult&);

public:
	using line_no = vector<string>::size_type;
	QueryResult(string s, shared_ptr<set<line_no>> p,
		shared_ptr<vector<string>> f) :sought(s), lines(p), file(f) {}
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};
QueryResult TextQuery::query(const string &sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}
string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}
ostream &print(ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << endl;
	for (auto num : *qr.lines)
		os << "\t(line" << num + 1 << ")"
		<< *(qr.file->begin() + num) << endl;
	return os;
}

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