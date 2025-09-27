// README
// 该代码输出结果完全相同，但是presentation error。
// 猜测是需要将结果储存起来统一输出
// 尚待验证
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Term {
    int a; // 系数
    int k; // 次数
    Term(int a = 0, int k = 0) : a(a), k(k) {};
    friend istream& operator>>(istream& i, Term& t) {
        i >> t.a >> t.k;
        return i;
    } // 重载 >>
    friend ostream& operator<<(ostream& o, const Term& t) {
        o << "[ " << t.a << " " << t.k << " ] ";
        return o;
    } // 重载 <<
    Term operator+(const Term& other) {
        Term result;
        if (this->k != other.k) {
            return result;
        }
        result.a = this->a + other.a;
        result.k = this->k;
        return result;
    } // 重载 +
    bool operator<(const Term& other) const {
        return this->k < other.k;
    } // 重载 <，便于 sort 函数
    bool operator==(const Term& other) const {
        return (this->k == other.k);
    }
};

class Polynomial {
public:
    vector<Term> terms;
    void init() {
        this->terms.erase(
            remove_if(this->terms.begin(), this->terms.end(), [](const Term& t) {
                return t.a == 0;
                }),
            this->terms.end()
        );
        sort(this->terms.begin(), this->terms.end());
        reverse(this->terms.begin(), this->terms.end());
    } // 实现排序
    friend istream& operator>>(istream& i, Polynomial& p) {
        Term t;
        while (true) {
            i >> t;
            if (t.k >= 0) {
                p.terms.push_back(t);
            }
            else {
                break;
            }
        }
        return i;
    } // 重载 >>
    friend ostream& operator<<(ostream& o, const Polynomial& p) {
        //for (size_t i = 0; i < p.terms.size(); i++) {
        //    if (i == p.terms.size() - 1) {
        //        o << p.terms[i];
        //    }
        //    else {
        //        o << p.terms[i] << " ";
        //    }
        //}
        for (Term t : p.terms) {
            o << t;
        }
        return o;
    } // 重载 <<
    Polynomial operator+(const Polynomial& other) {
        Polynomial result;
        for (Term t : this->terms) {
            result.terms.push_back(t);
        }
        for (Term tt : other.terms) {
            bool has = false;
            for (size_t i = 0; i < result.terms.size(); i++) {
                if (tt == result.terms[i]) {
                    result.terms[i] = result.terms[i] + tt;
                    has = true;
                    break;
                }
            }
            if (!has) {
                result.terms.push_back(tt);
            }
        }
        result.init();
        return result;
    }
};

int main() {
    int n = 0;
    cin >> n;
    cin.ignore();
    while (n--) {
        Polynomial p1, p2;
        cin >> p1;
        cin.ignore();
        cin >> p2;
        Polynomial res = p1 + p2;
        cout << res;
    }
    return 0;
}