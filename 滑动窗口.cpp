// README
// 不要试图把所有窗口下的最大值和最小值都遍历求出、
// 否则你时间就炸了
// Time Limit Exceeded警告()
// 显然用双端队列来维护（队列内只存储索引）时间更优
// 当前元素比队列尾部的值小/大，那么队列尾部元素显然不可能是最小/大值，可以移除。
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// 使用单调队列解决滑动窗口最大值和最小值问题
void slidingWindowMinAndMax(const vector<int>& nums, int n, int k, vector<int>& minRes, vector<int>& maxRes) {
    deque<int> minDeque, maxDeque;

    for (int i = 0; i < n; i++) {
        // 维护最小值的队列
        while (!minDeque.empty() && minDeque.front() <= i - k) {
            minDeque.pop_front(); // 滑出窗口
        }
        while (!minDeque.empty() && nums[minDeque.back()] >= nums[i]) {
            minDeque.pop_back(); // 保持单调性
        }
        minDeque.push_back(i);

        // 维护最大值的队列
        while (!maxDeque.empty() && maxDeque.front() <= i - k) {
            maxDeque.pop_front(); // 滑出窗口
        }
        while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[i]) {
            maxDeque.pop_back(); // 保持单调性
        }
        maxDeque.push_back(i);

        // 在窗口形成后记录结果
        if (i >= k - 1) {
            minRes.push_back(nums[minDeque.front()]);
            maxRes.push_back(nums[maxDeque.front()]);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> minRes, maxRes;
    slidingWindowMinAndMax(nums, n, k, minRes, maxRes);

    // 输出最小值
    for (int i = 0; i < minRes.size(); i++) {
        if (i > 0) cout << " ";
        cout << minRes[i];
    }
    cout << endl;

    // 输出最大值
    for (int i = 0; i < maxRes.size(); i++) {
        if (i > 0) cout << " ";
        cout << maxRes[i];
    }
    cout << endl;

    return 0;
}
