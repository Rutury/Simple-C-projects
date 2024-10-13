#include "lllint.h"

using std::vector;

bool sameSign(int a, int b) { return (a >= 0 && b >= 0) || (a <= 0 && b <= 0); }

lllint::lllint() : sign(1), digits({0}) {}

lllint::lllint(int x) : sign(x < 0 ? -1 : 1), digits({0}) {
    if (sign < 0) x = -x;
    plusDigit(x);
}

lllint lllint::operator+(int x) const {
    if (!sameSign(sign, x)) return *this - (-x);
    lllint result(*this);
    result.plusDigit(x);
    return result;
}

lllint lllint::operator-(int x) const {
    if (!sameSign(sign, x)) return *this + (-x);
    lllint result(*this);
    result.minusDigit(x);
    return result;
}

lllint lllint::operator+(const lllint& x) const { // TODO
    lllint result(*this);
    return result;
}

lllint lllint::operator-(const lllint& x) const { // TODO
    lllint result(*this);
    return result;
}

void lllint::appendDigit(int x) {
    while (x > 0) {
        digits.push_back(x % MAX_DIGIT);
        x /= MAX_DIGIT;
    }
}

void lllint::popDigit() { return digits.pop_back(); }

void lllint::plusDigit(int x) {
    int i = 0;
    while (x > 0) {
        if (i == int(digits.size())) {
            appendDigit(x);
            break;
        }
        digits[i] += x % MAX_DIGIT;
        x /= MAX_DIGIT;
        x += digits[i] / MAX_DIGIT;
        digits[i] %= MAX_DIGIT;
        i++;
    }
}

void lllint::minusDigit(int x) {
    // TODO
}
