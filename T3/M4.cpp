#include <bits/stdc++.h>
using namespace std;


long long T,n,opid;
long long flag=-1;
string op;

deque<pair<long long,long long>> Q;
map<string,long long> mp
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

void Add()
{
    long long u;
    scanf("%lld", &u);
    for(auto it=Q.begin();it!=Q.end();it++)
        if(it->first==u)
        {
            printf("OpId #%lld: same likeness.\n", opid);
            return ;
        }
    Q.push_back(make_pair(u,0));
    printf("OpId #%lld: success.\n", opid);
}

void Close()
{
    long long u;
    scanf("%lld",&u);
    for(auto it=Q.begin();it!=Q.end();it++)
        if(it->first==u)
        {
            if(flag==u) flag=-1;
            printf("OpId #%lld: close %lld with %lld.\n",opid,u,it->second);
            Q.erase(it);
            return ;
        }
    printf("OpId #%lld: invalid likeness.\n",opid);
}

void Chat()
{
    long long w;
    scanf("%lld",&w);
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
        printf("OpId #%lld: success.\n",opid);
    }
    else
        printf("OpId #%lld: empty.\n", opid);
}

void Rotate()
{
    long long x;
    scanf("%lld",&x);
    if(x>Q.size() || x<1)
        printf("OpId #%lld: out of range.\n",opid);
    else
    {
        pair<long long,long long> temp=Q[x-1];
        Q.erase(Q.begin()+x-1);
        Q.push_front(temp);
        printf("OpId #%lld: success.\n",opid);
    }
}

void Prior()
{
    if(Q.empty())   printf("OpId #%lld: empty.\n",opid);
    else
    {
        pair<long long,long long> maxPair=Q[0];
        auto maxIt=Q.begin();
        for(auto it=Q.begin()+1;it!=Q.end();it++)
            if((*it).first>maxPair.first)  {maxPair=(*it);  maxIt=it;}
        Q.erase(maxIt);
        Q.push_front(maxPair);
        printf("OpId #%lld: success.\n",opid);
    }
}

void Choose()
{
    long long u;
    scanf("%lld",&u);
    for(auto it=Q.begin();it!=Q.end();it++)
        if((*it).first==u)
        {
            pair<long long,long long> temp=(*it);
            Q.erase(it);
            Q.push_front(temp);
            printf("OpId #%lld: success.\n",opid);
            return ;
        }
    printf("OpId #%lld: invalid likeness.\n",opid);
}

void Top()
{
    long long u;
    scanf("%lld",&u);
    for(auto it=Q.begin();it!=Q.end();it++)
        if((*it).first==u)
        {
            flag=u;
            printf("OpId #%lld: success.\n",opid);
            return ;
        }
    printf("OpId #%lld: invalid likeness.\n",opid);
}

void Untop()
{
    for(auto it=Q.begin();it!=Q.end();it++)
        if((*it).first==flag)
        {
            flag=-1;
            printf("OpId #%lld: success.\n",opid);
            return ;
        }
    printf("OpId #%lld: no such person.\n",opid);
}



int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    scanf("%lld",&T);
    while(T--)
    {
        opid=0;
        Q.clear();
        flag=-1;
        scanf("%lld",&n);
        while(n--)
        {
            cin>>op;
            opid++;
            switch(mp[op])
            {
                case 1:
                    Add();
                    break;
                case 2:
                    Close();
                    break;
                case 3:
                    Chat();
                    break;
                case 4:
                    Rotate();
                    break;
                case 5:
                    Prior();
                    break;
                case 6:
                    Choose();
                    break;
                case 7:
                    Top();
                    break;
                case 8:
                    Untop();
                    break;
            }

            /*
            //debug
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
                            printf("OpId #%lld: Bye %lld: %lld.\n",opid,it->first,it->second);
                        }
                        Q.erase(it);
                        break;
                    }

                while(!Q.empty())
                {
                    pair<long long,long long> temp=Q.front();
                    Q.pop_front();
                    if(temp.second!=0)
                    {
                        opid++;
                        printf("OpId #%lld: Bye %lld: %lld.\n",opid,temp.first,temp.second);
                    }
                }
            }
            else
            {
                while(!Q.empty())
                {
                    pair<long long,long long> temp=Q.front();
                    Q.pop_front();
                    if(temp.second!=0)
                    {
                        opid++;
                        printf("OpId #%lld: Bye %lld: %lld.\n",opid,temp.first,temp.second);
                    }
                }
            }
        }

    }   //while(T--)


    return 0;
}