#include <iostream>
#include <string>
using namespace std;

string check(const string& s, const string& t){
	if (s.size() > t.size()) {
		return "No";
	}
	int index = 0;
	for (int i = 0; i < t.size(); i++) {
		if (t[i] == s[index]) {
			index++;
		}
		if (index == s.size()) {
			return "Yes";
		}
	}
	return "No";
}

int main() {
	string s, t;
	while (cin >> s >> t) {
		cout << check(s, t) << endl;
	}
}