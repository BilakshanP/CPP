#include <boost/regex.hpp>
#include <iostream>
#include <string>

using namespace boost;
using namespace std;

int main()
{
	string s = "Hello, world!";
	regex expr("(\\w+),\\s(\\w+)!");
	string fmt("\\1, Boost.Regex!");
	cout << regex_replace(s, expr, fmt) << endl;
	return 0;
}
