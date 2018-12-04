#ifndef TEXTQUERY_H_INCLUDED
#define TEXTQUERY_H_INCLUDED

#include<vector>
#include<fstream>
#include<memory>
#include<sstream>
#include<string>
#include<map>
#include<set>

using namespace std;

class QueryResult; //前向声明

class TextQuery {
public:
	//类型别名
	typedef vector<string>::size_type line_no;
	//构造函数。
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wordMap;

};

//构造函数定义。读取文件按行存入vector，并且建立单词与行号映射。
TextQuery::TextQuery(ifstream &fin) : file(new vector<string>)
{
	string line;
	//为了使得行号从1开始对应。我把vector的位置0先设为空串。
	file->push_back("");
	while (getline(fin, line)) {
		file->push_back(line);
		unsigned lineN = file->size() - 1; //lineN用来保存行号。
		istringstream sin(line);
		string word;
		while (sin >> word) {
			auto &lines = wordMap[word]; //lines是一个shared_ptr
			if (!lines)
				lines.reset(new set<line_no>); //如果lines为空指针（set没有元素）,分配一个新的set
			lines->insert(lineN);
		}
	}
}


class QueryResult {
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(const string& str, shared_ptr<set<TextQuery::line_no>> l,
		shared_ptr<vector<string>> f) : sought(str), lines(l), file(f) { }
private:
	string sought;
	shared_ptr<set<TextQuery::line_no>> lines;
	shared_ptr<vector<string>> file;

};

QueryResult TextQuery::query(const string &s) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	auto loc = wordMap.find(s);
	if (loc == wordMap.end())
		return QueryResult(s, nodata, file);
	else
		return QueryResult(s, loc->second, file);
}

ostream& print(ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size()
		<< ((qr.lines->size() > 1) ? " times" : " time")
		<< endl;
	for (auto num : *(qr.lines))
		os << "\t(line " << num << ") " << *(qr.file->begin() + num) << endl;
	return os;
}

#endif
