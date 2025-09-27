// README
// 其实就是找最多重复子串
// TIPS：本问题输入量很大，请用scanf代替cin，从而避免超时。
#include <iostream>
#include <string>
#include <cstdio> // 使用scanf加快输入速度
#include <vector>

using namespace std;

// 求取字符串的最大n值，使得s=a^n
int find_max_n(const string &s) {
    int len = s.length();
    vector<int> prefix(len, 0); // KMP的prefix数组，存储部分匹配表

    // 构造KMP的部分匹配表
    for (int i = 1, j = 0; i < len; ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = prefix[j - 1]; // 匹配失败，回退
        }
        if (s[i] == s[j]) {
            ++j; // 成功匹配，增加长度
        }
        prefix[i] = j;
    }

    int repeated_length = len - prefix[len - 1]; // 基本单元a的长度
    if (len % repeated_length == 0) {
        return len / repeated_length; // 如果s是a的完整重复，计算n值
    } else {
        return 1; // 如果无法均匀分割，说明s就是a自身
    }
}

// 吐槽：如果使用VS，这一段代码是不会正常运行的
// scanf函数由于没有边界检查，会使得VS报告C4996错误
// 所以不会正常输入
int main() {
    char input[1000005]; // 使用字符数组以支持较大输入
    while (scanf("%s", input) == 1) { // 使用scanf读取输入
        string s(input);
        if (s == ".") {
            break; // 遇到"."则结束程序
        }
        int result = find_max_n(s); // 计算最大的n值
        printf("%d\n", result); // 输出结果
    }
    return 0;
}
