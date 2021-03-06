#include <bits/stdc++.h>
using namespace std;

struct card
{
    int number;
    int color;
    bool operator > (const card& theCard) const {return number>theCard.number;}
    bool operator < (const card& theCard) const {return number<theCard.number;}
}p[5];

int res[10];

void solve()
{
    sort(p,p+5);
    bool sameColor=false,straight=false;
    if(p[0].color==p[1].color && p[1].color==p[2].color && p[2].color==p[3].color && p[3].color==p[4].color)
        sameColor=true;
    if(p[0].number+1==p[1].number && p[1].number+1==p[2].number && p[2].number+1==p[3].number && p[3].number+1==p[4].number)
        straight=true;

    if(sameColor && straight)
        res[1]++;
    else if((p[0].number==p[1].number && p[1].number==p[2].number && p[2].number==p[3].number) ||
            (p[1].number==p[2].number && p[2].number==p[3].number && p[3].number==p[4].number))
        res[2]++;
    else if((p[0].number==p[1].number && p[1].number==p[2].number && p[3].number==p[4].number) ||
            (p[0].number==p[1].number && p[2].number==p[3].number && p[3].number==p[4].number))
        res[3]++;
    else if(sameColor && !straight)
        res[4]++;
    else if(!sameColor && straight)
        res[5]++;
    else if((p[0].number==p[1].number && p[1].number==p[2].number) || (p[1].number==p[2].number && p[2].number==p[3].number) ||
            (p[2].number==p[3].number && p[3].number==p[4].number))
        res[6]++;
    else if((p[1].number==p[2].number && p[3].number==p[4].number) || (p[0].number==p[1].number && p[3].number==p[4].number) ||
            (p[0].number==p[1].number && p[2].number==p[3].number))
        res[7]++;
    else if((p[0].number==p[1].number) || (p[1].number==p[2].number) || (p[2].number==p[3].number) || (p[3].number==p[4].number))
        res[8]++;
    else
        res[9]++;
}

int main()
{
    int a,b,a1,b1,a2,b2;
    scanf("%d%d",&a,&b);
    scanf("%d%d%d%d",&a1,&b1,&a2,&b2);


    for(int i1_=0;i1_<a;i1_++)
    {
        for(int j1_=0;j1_<b;j1_++)
        {
            if((i1_==a1 && j1_==b1) || (i1_==a2 && j1_==b2))
                continue;

            for(int i2_=0;i2_<a;i2_++)
            {
                for(int j2_=0;j2_<b;j2_++)
                {
                    if((i2_==a1 && j2_==b1) || (i2_==a2 && j2_==b2) || (i2_==i1_ && j2_==j1_))
                        continue;

                    for(int i3_=0;i3_<a;i3_++)
                    {
                        for(int j3_=0;j3_<b;j3_++)
                        {
                            if((i3_==a1 && j3_==b1) || (i3_==a2 && j3_==b2) || (i3_==i1_ && j3_==j1_) || (i3_==i2_ && j3_==j2_))
                                continue;
                            p[0].number=a1;p[0].color=b1;
                            p[1].number=a2;p[1].color=b2;
                            p[2].number=i1_;p[2].color=j1_;
                            p[3].number=i2_;p[3].color=j2_;
                            p[4].number=i3_;p[4].color=j3_;
                            solve();
                        }
                    }
                }
            }
        }
    }

    for(int i=1;i<=9;i++)
        printf("%d ",res[i]/6);
    return 0;
}