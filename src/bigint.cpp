#include "bigint.h"

bigint::bigint()
{
    for (int i = 0; i < size; i++) {
        digits[i] = 0;
    }
}

bigint::bigint(ll x)
{
    
    for (int i = 0; i < size; i++) {
        digits[i] = 0;
    }
    
    int next = 0;
    while (x) {
        digits[next++] = x % base;
        x /= base;
    }
    
}

bigint::bigint(const bigint &other)
{
    for (int i = 0; i < size; i++) {
        digits[i] = other.digits[i];
    }
}

bigint& bigint::operator=(const bigint &other)
{
    for (int i = 0; i < size; i++) {
        digits[i] = other.digits[i];
    }
    
    return *this;
}

void bigint::print()
{
    cout << "\n";
    for (int i = size - 1; i >= 0; i--) {
        if (digits[i] > 0) {
            cout << digits[i];
        }
    }
    
    cout << "\n";
}

void bigint::operator +=(const bigint &other) {
    
    for (int i = 0; i < size; i++) {
        digits[i] += other.digits[i];
    }
    
    for (int i = 0; i < size - 1; i++) {
        if (digits[i] >= base) {
            digits[i] -= base;
            digits[i + 1]++;
        }
    }
    
}

bigint bigint::operator +(const bigint &other) {
    bigint n(*this);
    n += other;
    return n;
}

bigint& bigint::operator ++() {
    *this += 1;
    return *this;
}

void bigint::operator -=(const bigint &other) {
    
    for (int i = 0; i < size; i++) {
        digits[i] -= other.digits[i];
    }
    
    for (int i = 0; i < size - 1; i++) {
        if (digits[i] <= 0) {
            digits[i] += base;
            digits[i + 1]--;
        }
    }
    
}

bigint bigint::operator -(const bigint &other) {
    bigint n(*this);
    n -= other;
    return n;
}

bigint& bigint::operator --() {
    *this -= 1;
    return *this;
}

void bigint::operator *=(const bigint &other) {
    *this = *this * other;
}

bigint bigint::operator *(const bigint &other) {
    bigint result;
    for (int i = 0; i < size; i++) {
        ll carry = 0;
        for (int j = 0; i + j < size; j++) {
            result.digits[i + j] += digits[i] * other.digits[j] + carry;
            carry = result.digits[i + j] / base;
            result.digits[i + j] %= base;
        }
    }
    return result;
}

void bigint::operator /=(ll x) {
    
    for (int i = size - 1; i >= 0; i--) {
        if (i) {
            digits[i - 1] += (digits[i] % x) * base;
        }
        digits[i] /= x;
    } 
}

bigint bigint::operator /(ll x) {
    bigint n(*this);
    n /= x;
    return n;
}

void bigint::pow(ll x) {
    
    bigint temp(*this);
    bigint result(1);
    
    while (x > 0) {
        if (x % 2 == 1) {
            result *= temp;
        }
        x /= 2;
        temp *= temp;
    }
    
    *this = result;
  
}













