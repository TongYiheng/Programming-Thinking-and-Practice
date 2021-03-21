#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,sum=0,last=0,i=0;
    while(~scanf("%d",&x) && x!=0)
    {
        i++;
        
        if(i==1)    //first jump
        {
            if(x==1)    {sum+=1; last=1;}
            else    {sum+=2; last=2;}
        }
        else
        {
            if(x==1)
            {
                sum+=1;
                last=1;
            }
            if(x==2)
            {
                if(last==1)
                {
                    sum+=2;
                    last=2;
                }
                else
                {
                    sum+=last+2;
                    last+=2;
                }
            }
        }
    }
    printf("%d\n",sum);

    return 0;
}