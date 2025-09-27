#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, substr;
    while (cin >> str >> substr) {
        // 找到 ASCII 码最大字符的位置
        char maxChar = str[0];
        int maxIndex = 0;
        for (int i = 1; i < str.size(); i++) {
            if (str[i] > maxChar) {
                maxChar = str[i];
                maxIndex = i;
            }
        }
        // 在最大字符后插入 substr
        str.insert(maxIndex + 1, substr);
        // 输出结果
        cout << str << endl;
    }
    return 0;
}
