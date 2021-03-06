#include <bits/stdc++.h>
using namespace std;

#define pi 3.1415926535

int main()
{
    int a,b,H,M;
    double j,x;
    scanf("%d%d%d%d",&a,&b,&H,&M);

    j=fabs(H*30+M*0.5-M*6);
    x=sqrt(a*a+b*b-2*a*b*cos(j*pi/180));
    printf("%.9f\n",x);

    return 0;
}