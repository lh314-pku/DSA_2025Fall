// README
// 此事在 编程网格 的计算概论题中已有记载
#include <iostream>
#include <vector>
using namespace std;

// C++初始模板程序

int main() {
    int k = 0;
    cin >> k;
    k = k * 2 - 1; // 确保 k 是奇数
    vector<vector<int>> square(k, vector<int>(k, 0)); // 初始化为全 0 的矩阵

    // 填充幻方
    int i = 0, j = k / 2; // 从第一行、中间列开始
    square[i][j] = 1; // 第一个数字
    for (int num = 2; num <= k * k; num++) {
        int ni = (i - 1 + k) % k; // 上一行（环绕）
        int nj = (j + 1) % k;     // 下一列（环绕）
        if (square[ni][nj] != 0) { // 如果该位置已被填充
            ni = (i + 1) % k;     // 回退到当前列下一行
            nj = j;
        }
        square[ni][nj] = num; // 填充数字
        i = ni;
        j = nj;
    }

    // 输出幻方
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cout << square[i][j];
            if (j < k - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}

