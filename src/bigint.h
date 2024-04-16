#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
using namespace std;

#define ll long long

class bigint
{
public:
    bigint();
    bigint(ll x);
    bigint(const bigint &other);
    bigint& operator =(const bigint &other);
    void print();
    void operator +=(const bigint &other);
    bigint operator +(const bigint &other);
    bigint& operator ++();
    void operator -=(const bigint &other);
    bigint operator -(const bigint &other);
    bigint& operator --();
    void operator *=(const bigint &other);
    bigint operator *(const bigint &other);
    void operator /=(ll x);
    bigint operator /(ll x);
    void pow(ll x);
private:
    static const ll base = 1e9;
    static const ll size = 10;
    ll digits[size];
};

#endif // BIGINT_H
