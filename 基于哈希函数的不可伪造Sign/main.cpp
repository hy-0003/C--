//���ڹ�ϣ�����Ĳ���α��Sign
//�涨messageΪint���ͣ�����Ϊ10
//������Ĺ�ϣ����Ϊ���й��죬��ȫ�Խϵ�
#include<bits/stdc++.h>
using namespace std;
int * sk(int a[])
{
    int * sk1=new int [20];
    for(int i=0;i<10;++i)
    {
        sk1[2*i]=a[i]-1;
        sk1[2*i+1]=a[i]+1;
    }
    return sk1;
    delete []sk1;
}
int * pk(int * sk1)
{
    int * pk1=new int [20];
    for(int i=0;i<19;++i)
    {
        if(sk1[i]>=sk1[i+1]&&sk1[i]-sk1[i+1]>4)
            pk1[i]=sk1[i]%sk1[i+1];
        else if(sk1[i+i]>sk1[i]&&sk1[i+1]-sk1[i]>4)
            pk1[i]=sk1[i+1]%sk1[i];
        else
            pk1[i]=(sk1[i+1]+sk1[i])/2;
    }
    pk1[19]=sk1[19]%6;
    return pk1;
    delete []pk1;
}
int * sign(int * sk1,int * message)
{
    int * sign1=new int [10];
    for(int i=0;i<10;++i)
    {
        if(message[i]==0)
        {
            sign1[i]=sk1[2*i];
        }
        if(message[i]==1)
        {
            sign1[i]=sk1[2*i+1];
        }
    }
    return sign1;
    delete []sign1;
}
bool prove(int * pk1,int * message,int * sign)
{
    int sum=0;

    //��ȫsk
    int * skey=new int [20];
    for(int i=0;i<10;++i)
    {
        if(message[i]==0)
        {
            //sign1[i]=sk1[2*i];
            skey[2*i]=sign[i];
            skey[2*i+1]=sign[i]+2;
        }
        if(message[i]==1)
        {
            //sign1[i]=sk1[2*i+1];
            skey[2*i+1]=sign[i];
            skey[2*i]=sign[i]-2;
        }
    }
    //��ȫ��ȷpk
    int * pkey=new int [20];
    for(int i=0;i<19;++i)
    {
        if(skey[i]>=skey[i+1]&&skey[i]-skey[i+1]>4)
            pkey[i]=skey[i]%skey[i+1];
        else if(skey[i+i]>skey[i]&&skey[i+1]-skey[i]>4)
            pkey[i]=skey[i+1]%skey[i];
        else
            pkey[i]=(skey[i+1]+skey[i])/2;
    }
    pkey[19]=skey[19]%6;

    for(int i=0;i<20;++i)
    {
        if(pkey[i]!=pk1[i])
            ++sum;
    }
    delete []skey;
    delete []pkey;

    if(sum==0)
        return true;
    else
        return false;
}
int main()
{
    int l=10;
    int a[10];
    int message[10]={0,1,1,1,0,0,1,0,1,0};

    srand(time(0));
    for(int i=0;i<l;++i)
    {
        a[i]=rand()%100+1;
    }
    for(int i=0;i<10;++i)
    {
        cout<<a[i]<<endl;
    }
    cout<<"-------------------------------------------------����a[i]"<<endl;
    int * skey=sk(a);
    for(int i=0;i<20;++i)
    {
        cout<<skey[i]<<endl;
    }
    cout<<"-------------------------------------------------������Կ"<<endl;
    int * pkey=pk(skey);
    for(int i=0;i<20;++i)
    {
        cout<<pkey[i]<<endl;
    }
    cout<<"-------------------------------------------------���Ϲ�Կ"<<endl;
    int * signn=sign(skey,message);
    for(int i=0;i<10;++i)
    {
        cout<<signn[i]<<endl;
    }
    cout<<"-------------------------------------------------����ǩ��"<<endl;
    cout<<prove(pkey,message,signn)<<endl;
    cout<<"-------------------------------------------------���ϲ��Խ���"<<endl;
    return 0;
}
