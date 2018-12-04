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

class QueryResult; //ǰ������

class TextQuery {
public:
	//���ͱ���
	typedef vector<string>::size_type line_no;
	//���캯����
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wordMap;

};

//���캯�����塣��ȡ�ļ����д���vector�����ҽ����������к�ӳ�䡣
TextQuery::TextQuery(ifstream &fin) : file(new vector<string>)
{
	string line;
	//Ϊ��ʹ���кŴ�1��ʼ��Ӧ���Ұ�vector��λ��0����Ϊ�մ���
	file->push_back("");
	while (getline(fin, line)) {
		file->push_back(line);
		unsigned lineN = file->size() - 1; //lineN���������кš�
		istringstream sin(line);
		string word;
		while (sin >> word) {
			auto &lines = wordMap[word]; //lines��һ��shared_ptr
			if (!lines)
				lines.reset(new set<line_no>); //���linesΪ��ָ�루setû��Ԫ�أ�,����һ���µ�set
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
