#include<bits/stdc++.h>
#include"ch6.1,h.h"
using namespace std;
/*class sstring
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


sstring::sstring()
{
    chang=0;
    s=NULL;
}
/*sstring::sstring(char m[],int n)
{
    if(n==0)
        s=NULL;
    else
        chang=n;
        s=new char [n];
        for(int i=0;i<n;++i)
        {
            cout<<m[i];
        }
}


sstring::sstring(const sstring & g)
{
    chang=g.chang;
    if(s==g.s)
    if(s)
    delete []s;
    if(g.s)
    {
        s=new char [chang+1];
        strcpy(s,g.s);
    }
    else
    {
        chang=0;
        s=NULL;
    }
}


sstring & sstring::operator =(const char *k)
{
    if(s)
        delete []s;
    if(k)
    {
        chang=strlen(k);
        s=new char [strlen(k)+1];
        strcpy(s,k);
    }
    else
    {
        chang=0;
        s=NULL;
    }
    return *this;
}
sstring & sstring::operator +(sstring & g)
{
    if(s==NULL)
    {
        return g;
    }
    else
    {
        if(g.s==NULL)
            return *this;
        else
        {
            sstring ss;
            ss.chang=chang;
            ss.s=new char [chang];
            strcpy(ss.s,s);
            s=new char [chang+g.chang];
            for(int i=0;i<chang;++i)
            {
                s[i]=ss[i];
            }
            strcat(s,g.s);
            chang=chang+g.chang;
            return *this;

            /*ʧ��
            sstring ss;
            sstring *k;
            k=(sstring *) & ss;
            ss.chang=chang+g.chang;
            ss.s=new char [chang+g.chang];
            for(int i=0;i<chang;++i)
            {
                ss[i]=s[i];
            }
            strcat(ss.s,g.s);
            return k;

        }
    }
}
int sstring::operator ==(sstring & g)
{
    if(chang!=g.chang)
        return -1;
    else
    {
        for(int i=0;i<chang;++i)
        {
            if(s[i]!=g.s[i])
                return -1;
        }
        return 0;
    }
}
int sstring::operator !=(sstring & g)
{
    if(chang!=g.chang)
        return 0;
    else
    {
        for(int i=0;i<chang;++i)
        {
            if(s[i]!=g.s[i])
                return 0;
        }
        return -1;
    }
}
void sstring::operator >(sstring & g)
{
    if(chang>g.chang)
        cout<<"��sstring������һ��sstring"<<endl;
    else
        cout<<"��sstring��������һ��sstring"<<endl;
}
void sstring::operator <(sstring & g)
{
    if(chang<g.chang)
        cout<<"��sstringС����һ��sstring"<<endl;
    else
        cout<<"��sstring��С����һ��sstring"<<endl;
}
void sstring::operator <=(sstring & g)
{
    if(chang<=g.chang)
        cout<<"��sstringС�ڵ�����һ��sstring"<<endl;
    else
        cout<<"��sstring��С�ڵ�����һ��sstring"<<endl;
}
void sstring::operator >=(sstring & g)
{
    if(chang>=g.chang)
        cout<<"��sstring���ڵ�����һ��sstring"<<endl;
    else
        cout<<"��sstring�����ڵ�����һ��sstring"<<endl;
}



char & sstring::operator [](int i)
{
    return s[i];
}


sstring::~sstring()
{
    if(s)
        delete []s;
}
*/
int main()
{
    sstring k;
    k="work";
    sstring m(k);
    k+m;
    cout<<k.chang<<endl;
    for(int i=0;i<8;++i)
    {
        cout<<k[i];
    }
    cout<<endl;
    cout<<(k==k)<<endl;
    cout<<(k==m)<<endl;
    cout<<(k!=k)<<endl;
    cout<<(k!=m)<<endl;
    k>=m;
    k<m;
    return 0;
}
