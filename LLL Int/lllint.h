#ifndef _LLLINT_H_
#define _LLLINT_H_

#include <vector>

class lllint {
public:
    lllint();
    lllint(int x);

    lllint operator+(int x) const;
    lllint operator-(int x) const;
    lllint operator+(const lllint& x) const;
    lllint operator-(const lllint& x) const;

private:
    static const int MAX_DIGIT = 45000; // sqrt(MAX_IINT)
    int sign;
    std::vector<int> digits;

    void appendDigit(int x);
    void popDigit();
    void plusDigit(int x);
    void minusDigit(int x);
};

#endif // _LLLINT_H_