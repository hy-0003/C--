#include<bits/stdc++.h>
#include"t.h"
using namespace std;
/*class vvectors
{
public:
    double *p;
    int n;

    //���캯��
    vvectors();
    vvectors(double x[],int l);
    vvectors(string x);


    //���ƺ���
    vvectors(const vvectors & x);


    //��������
    //[]����
    double & operator [](int i);

    //double����Ϊ��ģ
    operator double ();

    //=
    vvectors & operator =(const vvectors & x);

    //+,-,���ˣ��ڻ���������н�
    vvectors operator +(const vvectors x);//+
    vvectors operator -(const vvectors x);//-
    vvectors operator *(const double x);//c*2��ʽ
    //ȫ�ֺ���vvectors operator *(const double x,const vvectors a);//2*c��ʽ
    double operator *(const vvectors & x);//�ڻ�
    vvectors operator &&(const vvectors & x);//���
    double operator ^(const vvectors & x);//�н�


    //�������
    friend ostream & operator <<(ostream & os,const vvectors & x);
    friend istream & operator >>(istream & is,vvectors & x);


    //��������
    ~vvectors();
};


vvectors::vvectors()
{
    n=0;
    p=NULL;
}
vvectors::vvectors(double x[],int l)
{
    n=l;
    p=new double [n];
    for(int i=0;i<n;++i)
    {
        p[i]=x[i];
    }
}
vvectors::vvectors(string x)
{
    int l=x.length();
    int sum=0;
    for(int i=0;i<l;++i)
    {
        if(x[i]==',')
            ++sum;
    }
    n=sum+1;
    p=new double [n];


    string x1=x;
    int d[sum+1]={0,0};
    for(int i=1;i<sum+1;++i)
    {
        for(int j=0;j<x1.length();++j)
        {
            if(x1[j]==',')
            {
                d[i]=j;
                x1[j]=0;
                break;
            }
        }
    }
    string w[n];
    for(int i=0;i<n;++i)
    {
        w[i]=x.substr(d[i]+1,d[i+1]-d[i]-1);
    }
    w[n-1]=w[n-1].substr(0,w[n-1].length()-1);



    for(int i=0;i<n;++i)
    {
        p[i]=stod(w[i]);
    }
}


vvectors::vvectors(const vvectors & x)
{
    if(x.p)
    {
        p=new double [x.n];
        //memcpy(p,x.p,sizeof(double)*x.n);
        for(int i=0;i<x.n;++i)
        {
            p[i]=x.p[i];
        }
        n=x.n;
    }
    else
    {
        n=0;
        p=NULL;
    }
}


vvectors::operator double()
{
    double mmould=0;
    for(int i=0;i<n;++i)
    {
        mmould=mmould+p[i]*p[i];
    }
    return sqrt(mmould);
}
double & vvectors::operator [](int i)
{
    return p[i];
}
vvectors & vvectors::operator =(const vvectors & x)
{
    if(p)
    {
        delete []p;
        n=0;
    }
    n=x.n;
    p=new double [n];
    for(int i=0;i<n;++i)
    {
        p[i]=x.p[i];
    }
    return *this;
}
vvectors vvectors::operator +(const vvectors x)
{
    if(n!=x.n)
    {
        cout<<"�����������ӷ���������"<<endl;
        return *this;
    }
    else
    {
        double d[n];
        for(int i=0;i<n;++i)
        {
            d[i]=p[i]+x.p[i];
        }
        return vvectors(d,n);
    }
}
vvectors vvectors::operator -(const vvectors x)
{
    if(n!=x.n)
    {
        cout<<"����������������������"<<endl;
        return *this;
    }
    else
    {
        double d[n];
        for(int i=0;i<n;++i)
        {
            d[i]=p[i]-x.p[i];
        }
        return vvectors(d,n);
    }
}

vvectors vvectors::operator *(const double x)
{
    if(n==0)
    {
        return *this;
    }
    else
    {
        double d[n];
        for(int i=0;i<n;++i)
        {
            d[i]=p[i]*x;
        }
        return vvectors(d,n);
    }
}
vvectors operator *(const double x,const vvectors a)
{
    if(a.n==0)
    {
        return a;
    }
    else
    {
        double d[a.n];
        for(int i=0;i<a.n;++i)
        {
            d[i]=a.p[i]*x;
        }
        return vvectors(d,a.n);
    }
}

double vvectors::operator *(const vvectors & x)
{
    if(n!=x.n)
    {
        cout<<"�����������ڻ���������"<<endl;
        return 0;
    }
    else
    {
        double sum=0;
        for(int i=0;i<n;++i)
        {
            sum=sum+p[i]*x.p[i];
        }
        return sum;
    }
}
double vvectors::operator ^(const vvectors & x)
{
    if(n!=x.n)
    {
        cout<<"�������������㷨��������"<<endl;
        return 0;
    }
    double sum=0;
    for(int i=0;i<n;++i)
    {
        sum=sum+p[i]*x.p[i];
    }
    double x1=(double)*this;
    double x2=0;
    for(int i=0;i<n;++i)
    {
        x2=x2+x.p[i]*x.p[i];
    }
    x2=sqrt(x2);
    return acos(sum/(x1*x2));
}
vvectors vvectors::operator &&(const vvectors & x)
{
    if(n!=x.n)
    {
        cout<<"���������������������"<<endl;
        return *this;
    }
    else
    {
        if(n!=3)
        {
            cout<<"��3ά�⣬����ά�ȵļ��㹦�ܻ�δ����"<<endl;
            return *this;
        }
        else
        {
             double d[3];
             d[0]=x.p[2]*p[1]-p[2]*x.p[1];
             d[1]=x.p[0]*p[2]-p[0]*x.p[2];
             d[2]=x.p[1]*p[0]-p[1]*x.p[0];
             return vvectors(d,3);
        }
    }
}



ostream & operator <<(ostream & os,const vvectors & x)
{
    if(x.n==0)
    {
        os<<0;
        return os;
    }
    else
    {
        os<<"(";
        for(int i=0;i<x.n-1;++i)
        {
            os<<x.p[i]<<",";
        }
        os<<x.p[x.n-1]<<")";
        return os;
    }
}
istream & operator >>(istream & is,vvectors & x)
{
    string a;
    is>>a;

    int l=a.length();
    int sum=0;
    for(int i=0;i<l;++i)
    {
        if(a[i]==',')
            ++sum;
    }
    x.n=sum+1;
    x.p=new double [x.n];


    string x1=a;
    int d[sum+1]={0,0};
    for(int i=1;i<sum+1;++i)
    {
        for(int j=0;j<x1.length();++j)
        {
            if(x1[j]==',')
            {
                d[i]=j;
                x1[j]=0;
                break;
            }
        }
    }
    string w[x.n];
    for(int i=0;i<x.n;++i)
    {
        w[i]=a.substr(d[i]+1,d[i+1]-d[i]-1);
    }
    w[x.n-1]=w[x.n-1].substr(0,w[x.n-1].length()-1);


    for(int i=0;i<x.n;++i)
    {
        x.p[i]=stod(w[i]);
    }
    return is;
}
vvectors::~vvectors()
{
    if(p)
    delete []p;
}

*/

int main()
{
    vvectors k;//����������
    cout<<k<<endl;


    vvectors j("(1.33478,2.36677,5.406,0.788)");//���磨a+b+c���Ĺ���
    cout<<j<<endl;


    double h[3]={0.3,0.4,0.5};
    int l=3;
    vvectors d(h,l);
    cout<<d<<endl;
    //���캯��vvectors(double d[],int n)


    vvectors a(j);//���ƹ��캯��
    cout<<a<<endl;


    vvectors b("(3.0,4.0)");
    cout<<(double)b<<endl;//��b��ģ


    //�Ӽ����������ˣ��ڻ�
    vvectors c=b+b+b;//+
    cout<<c<<endl;

    c=c-d;//-
    c=c-b;
    cout<<c<<endl;

    c=c*2;//����
    cout<<c<<endl;
    c=2*c;
    cout<<c<<endl;
    //�ڻ�
    cout<<c*c<<endl;
    cout<<c<<endl;


    cout<<"����������(a,b,c,...n)������"<<endl;
    vvectors ddd;
    //cin>>ddd;
    //cout<<ddd<<endl;
    //�������


    //�������н�
    vvectors x1("(1,0,0)");
    vvectors x2("(0,1,0)");
    double w=x1^x2;
    cout<<w<<endl;

    cout<<(x1&&x2)<<endl;
    cout<<(x2&&x1)<<endl;


    cout<<"����Ϊ����"<<endl;
    cout<<"<-------------------------------------------------------------------------------------------------->"<<endl;
    cout<<endl<<endl;
    //���
    cout<<"���������ļ��㣬�ֹ���7�м��㷽��"<<endl;
    cout<<"����1���ӷ�"<<endl;
    cout<<"����2������"<<endl;
    cout<<"����3������"<<endl;
    cout<<"����4���ڻ�"<<endl;
    cout<<"����5�����"<<endl;
    cout<<"����6����ģ��"<<endl;
    cout<<"����7����н�"<<endl;
    cout<<"�������Ӧ���������������(01,02,03,04,05,06,07):"<<endl;
    string df;int n;
    cin>>df;
    if(df=="01")//+
    {
        cout<<"�������м���������"<<endl;
        cin>>n;
        vvectors sum[n];
        cout<<"������"<<n<<"������(a,b,c,...n)������:"<<endl;
        for(int i=0;i<n;++i)
        {
            cin>>sum[i];
        }
        vvectors k(sum[0]);
        for(int i=1;i<n;++i)
        {
            k=k+sum[i];
        }
        cout<<"���Ϊ-->"<<k<<endl;
    }
    if(df=="02")//-
    {
        cout<<"�������м���������"<<endl;
        cin>>n;
        vvectors sum[n];
        cout<<"������"<<n<<"������(a,b,c,...n)������:"<<endl;
        for(int i=0;i<n;++i)
        {
            cin>>sum[i];
        }
        vvectors k(sum[0]);
        for(int i=1;i<n;++i)
        {
            k=k-sum[i];
        }
        cout<<"���Ϊ-->"<<k<<endl;
    }
    if(df=="03")//����
    {
        cout<<"������Ĭ��Ϊһ��������һ����"<<endl;
        double k;
        vvectors a;
        cout<<"����������������������:��������(a,b,c,...n)���룩"<<endl;
        cin>>a>>k;
        cout<<"���Ϊ-->"<<(k*a)<<endl;
    }
    if(df=="04")//�ڻ�
    {
        cout<<"������Ĭ��Ϊ��������"<<endl;
        cout<<"������"<<2<<"������(a,b,c,...n)������:"<<endl;
        vvectors x1,y1;
        cin>>x1>>y1;
        cout<<"���Ϊ-->"<<(x1*y1)<<endl;
    }
    if(df=="05")//���
    {
        cout<<"������Ĭ��Ϊ������ά����"<<endl;
        vvectors x2,y2;
        cout<<"������"<<2<<"������(a,b,c,...n)������:"<<endl;
        cin>>x2>>y2;
        cout<<"���Ϊ-->"<<(x2&&y2)<<endl;
    }
    if(df=="06")//��ģ��
    {
        cout<<"�������м���������"<<endl;
        cin>>n;
        cout<<"������"<<n<<"������(a,b,c,...n)������:"<<endl;
        vvectors m[n];
        for(int i=0;i<n;++i)
        {
            cin>>m[i];
        }
        for(int i=0;i<n;++i)
        {
            cout<<"��"<<i+1<<"�������Ľ��Ϊ->"<<(double)(m[i])<<endl;
        }
    }
    if(df=="07")//��н�
    {
        cout<<"������Ĭ��Ϊ����������"<<endl;
        cout<<"������"<<2<<"������(a,b,c,...n)������:"<<endl;
        vvectors x3,y3;
        cin>>x3>>y3;
        cout<<"���Ϊ-->"<<(x3^y3)<<endl;
    }
    if(df!="01"&&df!="02"&&df!="03"&&df!="04"&&df!="05"&&df!="06"&&df!="07")
    {
        cout<<"�밴�涨������š�"<<endl;
    }
    return 0;
}
