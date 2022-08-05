#include <bits/stdc++.h>

#define LL long long
#define ULL unsigned long long
#define LLT long long int
#define ULLT unsigned long long int

namespace shulun
{
    bool zeroerr = false;
    bool shuchucheck(LLT a){
        for(LL i = 2;i * i <= n;i++){
            if(a % i == 0){
                return false;
            }
        }
        return true;
    }
    LLT qpow(LL base, LL p, LL K)
    {
        LLT ans = 1, tmp = base;
        while (p != 0)
        {
            if (p & 1)
            {
                ans = (ans % K * tmp % K) % K;
            }
            tmp = (tmp % K * tmp % K) % K;
            p = p >> 1;
        }
        ans = ans % K;
        return ans;
    }
    long long exgcd(long long a, long long b, long long &x, long long &y) //扩展GCD
    {
        long long d = a;
        if (b == 0)
            x = 1, y = 0;
        else
            d = exgcd(b, a % b, y, x), y -= a / b * x;
        return d;
    }
    unsigned long long int jc(long long a)
    {
        if (a == 0)
        {
            return 1;
        }
        unsigned long long int out = a;
        while (--a)
        {
            out *= a;
        }
        return out;
    }
    unsigned long long int C(unsigned long long int n, unsigned long long int m)
    {
        unsigned long long int tmp = (jc(m) * jc(n - m));
        if (tmp == 0)
        {
            zeroerr = true;
            return 0;
        }
        return jc(n) / tmp;
    }
    bool modcheck(long long int base, long long int another)
    {
        if (base % another || another == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
