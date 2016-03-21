#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

int toInt(string s) {
	int i;
	stringstream sin(s);
	sin >> i;
	return i;
}

int main() {
	int f, r;
	string c;
	char s;
	while (cin >> f >> s >> r) {
		c="";
		for (int i = 1000000000; i; i /= 10) {
			if (f / i == r / i) {
				c = "";
				for (int k = i / 10; k; k /= 10)
					c += '0' + (r / k) % 10;
			} else if (i >= 10 && f / i + 1 == r / i && f % i >= r % i) {
				c = "";
				for (int k = i / 10; k; k /= 10)
					c += '0' + (r / k) % 10;
			}
		}
		cout << f << char(s);
		if (c == "")
			cout << r << endl;
		else
			cout << c << endl;
	}
}


