/*
 */

#include <bits/stdc++.h>

#define MAXN 200 //乘法越界寄存数组大小

using namespace std;

namespace gaojingdu
{
    bool jinwei;                           //加法越界寄存变量
    bool sub[MAXN] = {0};                  //乘法越界寄存器数组
    int sizeofa;                           // a[] 大小
    int sizeofb;                           // b[] 大小
    inline void init(int sizea, int sizeb) //初始化（总）
    {
        memset(sub, 0, sizeof(sub)); //初始化乘法越界寄存数组
        jinwei = false;              //初始化加法越界寄存变量
        sizeofa = sizea;             // a大小 （2进制）
        sizeofb = sizeb;             // b大小 (2进制)
        return;
    }
    inline void MAX_SCANF(bool a[])
    {
        string tmp;
        cin >> tmp;
        for (int i = 0; i < tmp.size(); i++)
        {
            int tt = int(tmp[i] - '0');
            int cnt = 0;
            while (a != 0)
            {
                a[4 * i + cnt] = tt % 2;
                tt = tt / 2;
                cnt++;
            }
        }
        return;
    }
    inline void ADD(bool a[], bool b[])                                //参考数电二进制加法器  ADD a b ;a = a + b
    {                                                                  // now: unknow
        bool _and = false, _xor = false, _tmp1 = false, _tmp2 = false; //零时变量
        jinwei = false;                                                //初始化进位为false
        for (int i = 0; i < sizeofa; i++)
        {
            _and = a[i] & b[i];
            _xor = a[i] ^ b[i];
            _tmp1 = jinwei & _and;
            _tmp2 = jinwei ^ _xor;
            a[i] = _tmp2;
            // jinwei = _tmp1 or _and;
            jinwei = _and;
        }
    }

    inline void SBB(bool a[], bool b[]) // now:WA all
    {                                   // SBB a b ;a = a - b
        bool _and = false, _xor = false, _tmp1 = false, _tmp2 = false;
        jinwei = false;
        bool __tmp[sizeof(b)]; // = {false};
        for (int i = 0; i <= sizeofa; i++)
        {
            __tmp[i] = !b[i];
        }
        for (int i = 0; i < sizeofa; i++)
        {
            _and = a[i] & b[i];
            _xor = a[i] ^ b[i];
            _tmp1 = jinwei & _and;
            _tmp2 = jinwei ^ _xor;
            a[i] = _tmp2;
            jinwei = _tmp1 || _and;
        }
    }
    // has not finished
    inline void SUB(bool a[], bool b[]) // now:unknow
    {                                   // SUB a b ;a = a * b
        bool out[sizeofa], tmp = b[0];
        for (int i = 0; i < sizeofa; i++)
        {
            bool tmp2[sizeofa];
            if (!tmp)
            {
                tmp = b[i + 1];
                continue;
            }
            for (int j = 0; j < sizeofb; j++)
            {
                if (i + j >= sizeofa)
                {
                    sub[i + j - sizeofa] = tmp & b[j];
                }
                else
                {
                    tmp2[i + j] = tmp & b[j];
                }
            }
            bool _and = false, _xor = false, _tmp1 = false, _tmp2 = false;
            for (int j = 0; j < sizeofa; j++)
            {
                _and = out[i] & tmp2[i];
                _xor = out[i] ^ tmp2[i];
                _tmp1 = jinwei & _and;
                _tmp2 = jinwei ^ _xor;
                out[i] = _tmp2;
                jinwei = _tmp1 || _and;
            }
            tmp = b[i + 1];
        }
        for (int i = 0; i < sizeofa; i++)
        {
            a[i] = out[i];
        }
        return;
    }
    inline void XOR(bool a[], bool b[])
    { // XOR a b ;a = a xor b
        for (int i = 0; i < sizeofa; i++)
        {
            a[i] = a[i] ^ b[i];
        }
        return;
    }
    inline void AND(bool a[], bool b[])
    {
        for (int i = 0; i < sizeofa; i++)
        {
            a[i] = a[i] & b[i];
        }
        return;
    }
    inline void OR(bool a[], bool b[])
    { // OR a b ;a = a or b
        for (int i = 0; i < sizeofa; i++)
        {
            a[i] = a[i] or b[i];
        }
        return;
    }
    inline void NOR(bool a[], bool b[])
    { // NOR a b ;a = !(a or b)
        for (int i = 0; i < sizeofa; i++)
        {
            a[i] = a[i] or b[i];
            a[i] = !a[i];
        }
        return;
    }
    inline void NOT(bool a[])
    { // NOT a b ;a = !a
        for (int i = 0; i < sizeofa; i++)
        {
            a[i] = !a[i];
        }
        return;
    }
    inline void NAND(bool a[], bool b[])
    { // NAND a b ;a = !(a & b)
        for (int i = 0; i < sizeofa; i++)
        {
            a[i] = !(a[i] & b[i]);
        }
        return;
    }
    inline void NO(bool a[])
    { // NO a b ;a =  !a
        for (int i = 0; i < sizeofa; i++)
        {
            a[i] = !a[i];
        }
        return;
    }
}