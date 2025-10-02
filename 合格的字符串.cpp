#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool match(const string& str, const string& temp) {
	int len_temp = temp.size();
	int len_str = str.size();
	int i = 0, j = 0;
	// 分别指向 str 和 temp
	while (i < len_temp && j < len_str) {
		if (temp[i] != '[' && temp[i] != ']') {
			//  || abs(temp[i] - str[j]) == 'a' - 'A'
			if (temp[i] == str[j] || (temp[i] > '9' && abs(temp[i] - str[j]) == 'a' - 'A')) {
				i++;
				j++;
			}
			else {
				return false;
			}
		}
		else if (temp[i] == '[') {
			i++;
			bool match = false;
			while (temp[i] != ']' && !match) {
				if (temp[i] == str[j] || (temp[i] > '9' && abs(temp[i] - str[j]) == 'a' - 'A')) {
					match = true;
					break;
				}
				else {
					i++;
				}
			}
			if (!match) {
				return false;
			}
			i = temp.find(']', i) + 1;
			j++;
		}
	}
	return (i == len_temp && j == len_str);
}

int main() {
	int n = 0;
	cin >> n;
	cin.ignore();
	vector<string> strs(n, "");
	for (int i = 0; i < n; i++) {
		cin >> strs[i];
	}
	string temp_str;
	cin >> temp_str;
	for (int i = 0; i < n; i++) {
		if (match(strs[i], temp_str)) {
			cout << i + 1 << " " << strs[i] << endl;
		}
	}
	return 0;
}