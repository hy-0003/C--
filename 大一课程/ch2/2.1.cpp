#include<bits/stdc++.h>
using namespace std;
class yuan
{
public:
    double r;
    double s();
    double l();
};
double yuan::s()
{
    return 3.14*r*r;
}
double yuan::l()
{
    return 6.28*r;
}
int main()
{
    double r;yuan k;
    cout<<"������Բ�İ뾶:";
    cin>>r;
    k.r=r;
    cout<<"Բ�����Ϊ��"<<endl<<k.s()<<endl<<"Բ���ܳ�Ϊ��"<<endl<<k.l();
    return 0;
}
