#include <bits/stdc++.h>
using namespace std;

map<string,int> mp
{
    {"Add",1},
    {"Close",2},
    {"Chat",3},
    {"Rotate",4},
    {"Prior",5},
    {"Choose",6},
    {"Top",7},
    {"Untop",8},
};

int main()
{
    int T,n,opid=0;
    int u,w,x;
    int flag=-1;
    string op;
    deque<pair<int,int>> Q;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        while(n--)
        {
            cin>>op;
            opid++;
            switch(mp[op])
            {
                case 1:
                {
                    scanf("%d", &u);
                    auto it=Q.begin();
                    for(;it!=Q.end();it++)
                        if(it->first==u)
                        {
                            printf("OpId #%d: same likeness.\n", opid);
                            break;
                        }
                    if(it==Q.end())
                    {
                        Q.push_back(make_pair(u,0));
                        printf("OpId #%d: success.\n", opid);
                    }
                    break;
                }
                case 2:
                {
                    scanf("%d",&u);
                    bool R=false;
                    for(auto it=Q.begin();it!=Q.end();it++)
                        if(it->first==u)
                        {
                            if(flag==u) flag=-1;
                            R=true;
                            Q.erase(it);
                            printf("OpId #%d: close %d with %d.\n",opid,u,it->second);
                            break;
                        }
                    if(!R)
                        printf("OpId #%d: invalid likeness.\n",opid);
                    break;
                }
                case 3:
                    scanf("%d",&w);
                    if(!Q.empty())
                    {
                        if(flag!=-1)
                        {
                            for(auto it=Q.begin();it!=Q.end();it++)
                                if(it->first==flag)
                                    it->second+=w;
                        }
                        else
                        {
                            Q[0].second+=w;
                        }
                        printf("OpId #%d: success.\n",opid);
                    }
                    else
                        printf("OpId #%d: empty.\n", opid);
                    break;
                case 4:
                    scanf("%d",&x);
                    if(x>Q.size() || x<1)   {printf("OpId #%d: out of range.\n",opid);}
                    else
                    {
                        pair<int,int> temp=Q[x-1];
                        Q.erase(Q.begin()+x-1);
                        Q.push_front(temp);
                        printf("OpId #%d: success.\n",opid);
                    }
                    break;
                case 5:
                    if(Q.empty())   printf("OpId #%d: empty.\n",opid);
                    else
                    {
                        pair<int,int> maxPair=Q[0];
                        auto maxIt=Q.begin();
                        for(auto it=Q.begin()+1;it!=Q.end();it++)
                            if((*it).first>maxPair.first)  {maxPair=(*it);  maxIt=it;}
                        Q.erase(maxIt);
                        Q.push_front(maxPair);
                        printf("OpId #%d: success.\n",opid);
                    }
                    break;
                case 6:
                {
                    scanf("%d",&u);
                    bool R=false;
                    for(auto it=Q.begin();it!=Q.end();it++)
                        if((*it).first==u)
                        {
                            R=true;
                            pair<int,int> temp=(*it);
                            Q.erase(it);
                            Q.push_front(temp);
                            printf("OpId #%d: success.\n",opid);
                            break;
                        }
                    if(!R)
                        printf("OpId #%d: invalid likeness.\n",opid);
                    break;
                }
                case 7:
                {
                    scanf("%d",&u);
                    auto it=Q.begin();
                    for(;it!=Q.end();it++)
                        if((*it).first==u)
                        {
                            flag=u;
                            printf("OpId #%d: success.\n",opid);
                            break;
                        }
                    if(it==Q.end())
                        printf("OpId #%d: invalid likeness.\n",opid);
                    break;
                }
                case 8:
                {
                    auto it=Q.begin();
                    for(;it!=Q.end();it++)
                        if((*it).first==flag)
                        {
                            flag=-1;
                            printf("OpId #%d: success.\n",opid);
                            break;
                        }
                    if(it==Q.end())
                        printf("OpId #%d: no such person.\n",opid);
                    break;
                }
            }

            /*debug
            printf("------------------\n");
            printf("第%d次操作后的队列：\n",opid);
            for(auto e:Q)
                printf("(%d,%d) ",e.first,e.second);
            printf("flag=%d",flag);
            printf("\n");
            */

        }   //while(n--)

        //byebye
        if(!Q.empty())
        {
            if(flag!=-1)
            {
                for(auto it=Q.begin();it!=Q.end();it++)
                    if((*it).first==flag)
                    {
                        if(it->second!=0)
                        {
                            opid++;
                            printf("OpId #%d: Bye %d: %d.\n",opid,it->first,it->second);
                        }
                        Q.erase(it);
                        break;
                    }

                while(!Q.empty())
                {
                    pair<int,int> temp=Q.front();
                    Q.pop_front();
                    if(temp.second!=0)
                    {
                        opid++;
                        printf("OpId #%d: Bye %d: %d.\n",opid,temp.first,temp.second);
                    }
                }
            }
            else
            {
                while(!Q.empty())
                {
                    pair<int,int> temp=Q.front();
                    Q.pop_front();
                    if(temp.second!=0)
                    {
                        opid++;
                        printf("OpId #%d: Bye %d: %d.\n",opid,temp.first,temp.second);
                    }
                }
            }
        }

    }   //while(T--)


    return 0;
}