#ifndef CH6_1,H_H_INCLUDED
#define CH6_1,H_H_INCLUDED
#include<bits/stdc++.h>
class sstring
{
public:
    char *s;
    int chang;
public:
    //1.sstring�Ĺ���
    sstring();
    //ʧ��sstring(char m[],int n);

    //2.sstring�ĸ��ƹ��캯��
    sstring(const sstring & g);
    //3.sstring������
    //=��+��==����=��<,>,<=,>=
    sstring & operator =(const char *k);
    sstring & operator +(sstring & g);
    int operator ==(sstring & g);
    int operator !=(sstring & g);
    void operator >(sstring & g);
    void operator <(sstring & g);
    void operator <=(sstring & g);
    void operator >=(sstring & g);
    //4.sstring��������ʽ
    char & operator [](int i);
    //5.sstring����������
    ~sstring();
};


#endif // CH6_1,H_H_INCLUDED
