#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// 解析单个多项式字符串，转为指数->系数映射，同时忽略指数小于0的项
map<int, int> parsePolynomial(const string& line) {
    map<int, int> result;
    stringstream ss(line);
    int coefficient, exponent;
    while (ss >> coefficient >> exponent) {
        if (exponent >= 0) {  // 只处理指数大于等于0的项
            result[exponent] += coefficient; // 累加相同指数的系数
        }
    }
    return result;
}

// 将多项式映射转换为所需格式的字符串
string formatPolynomial(const map<int, int>& poly) {
    stringstream result;
    bool first = true; // 是否是第一项，用于控制空格
    for (auto it = poly.rbegin(); it != poly.rend(); ++it) { // 高次到低次遍历
        if (it->second != 0) { // 忽略系数为0的项
            if (!first) result << " "; // 非第一项时加空格
            first = false;
            result << "[ " << it->second << " " << it->first << " ]";
        }
    }
    return result.str();
}

int main() {
    int n; // 多项式对数
    cin >> n;
    cin.ignore(); // 忽略整数后面的换行符

    vector<string> output; // 用于存储每组结果

    for (int i = 0; i < n; ++i) {
        // 读取两个多项式字符串
        string line1, line2;
        getline(cin, line1);
        getline(cin, line2);

        // 分别解析两个多项式
        map<int, int> poly1 = parsePolynomial(line1);
        map<int, int> poly2 = parsePolynomial(line2);

        // 合并两个多项式
        for (const auto& term : poly2) {
            poly1[term.first] += term.second;
        }

        // 格式化合并后的多项式并保存到结果中
        output.push_back(formatPolynomial(poly1));
    }

    // 输出最终结果，每行一个多项式的结果
    for (const string& res : output) {
        cout << res << endl;
    }

    return 0;
}
