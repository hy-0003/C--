#ifndef T_H_INCLUDED
#define T_H_INCLUDED
#include<bits/stdc++.h>
using namespace std;
class vvectors
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
    //ȫ�ֺ���
    friend vvectors operator *(const double x,const vvectors a);//2*c��ʽ
    double operator *(const vvectors & x);//�ڻ�
    vvectors operator &&(const vvectors & x);//���
    double operator ^(const vvectors & x);//�н�


    //�������
    friend ostream & operator <<(ostream & os,const vvectors & x);
    friend istream & operator >>(istream & is,vvectors & x);


    //��������
    ~vvectors();
};

#endif // T_H_INCLUDED
