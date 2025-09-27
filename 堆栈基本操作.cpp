#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

vector<string> op(const vector<int>& input, int n) {
	int current_num = 1;
	stack<int> nums;
	vector<string> result;
	for (int target_num : input) {
		bool access = true; // 是否有解？
		bool found = false; // 是否已经找到？
		if (!nums.empty() && nums.top() == target_num) {
			found = true;
			result.push_back("POP " + to_string(nums.top()));
			nums.pop();
		}
        // 如果栈堆有则pop，否则push试试
		while (!found) {
			nums.push(current_num);
			result.push_back("PUSH " + to_string(current_num));
			if (target_num == current_num) {
				found = true;
				nums.pop();
				result.push_back("POP " + to_string(current_num));
			}
			current_num++;
			if (current_num == n + 2) {
				access = false;
				break;
			}
		}
        // 已经不可能再有结果了
		if (!access) {
			vector<string> res;
			res.push_back("NO");
			return res;
		}
	}
	return result;
}

int main() {
	int n = 0;
	cin >> n;
	vector<int> input(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
    // 用一个栈来模拟操作
	vector<string> ops = op(input, n);
	for (string op : ops) {
		cout << op << endl;
	}
	return 0;
}