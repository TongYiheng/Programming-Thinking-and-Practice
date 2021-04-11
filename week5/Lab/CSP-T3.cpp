#include <bits/stdc++.h>
using namespace std;

stack<pair<string,string>> opStack;
stack<map<int,int>> numStack;//cishu, xishu

int stringToInt(string s)
{
    int num=0;
    for(int i=0;i<s.size();i++)
    {
        num+=(s[i]-'0')*pow(10,s.size()-i-1);
    }
    return num;
}

void mapAdd(map<int,int>& m1, map<int,int>& m2)
{//m1 add m2, and push into stack
    for(auto im=m2.begin();im!=m2.end();im++)
        m1[im->first]+=im->second;
    opStack.push(make_pair("OP","0"));
    numStack.push(m1);
}

void mapMul(map<int,int>& m, int n)
{//m mul n, and push into stack
    if(n>=0)
    {
        for(auto im=m.begin();im!=m.end();im++)
            m[im->first]=im->second*n;
        opStack.push(make_pair("OP","0"));
        numStack.push(m);
    }
    else
    {
        map<int,int> mm;
        for(auto im=m.begin();im!=m.end();im++)
            mm[im->first+1]=im->second;
        opStack.push(make_pair("OP","0"));
        numStack.push(mm);
    }
}

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    //int cccc=0;
    int loopTimes=0,endTimes=0;
    string str;
    while(cin>>str)
    {
        //cccc++;
        if(str=="BEGIN")
        {
            continue;
        }
        else if(str=="LOOP")
        {
            loopTimes++;
            string n;
            cin>>n;
            opStack.push(make_pair(str,n));
        }
        else if(str=="OP")
        {
            string n;
            cin>>n;
            map<int,int> m;
            m[0]=stringToInt(n);
            numStack.push(m);
            opStack.push(make_pair("OP","0"));
        }
        else    // str=="END"
        {
            endTimes++;
            if(endTimes==loopTimes+1)   // BEGIN--END
                break;
            map<int,int> m1;
            while(opStack.top().first!="LOOP")
            {
                m1=numStack.top();
                numStack.pop();
                opStack.pop();
                if(opStack.top().first=="LOOP")
                {
                    break;
                }
                else
                {
                    map<int,int> m2=numStack.top();
                    numStack.pop();
                    opStack.pop();
                    mapAdd(m1,m2);
                }
            }

            if(isdigit(opStack.top().second[0]))
            {//loop num
                int loopTimes=stringToInt(opStack.top().second);
                opStack.pop(); // pop loop
                mapMul(m1,loopTimes);
            }
            else    //loop n
            {
                opStack.pop(); // pop loop
                mapMul(m1,-1);
            }
        }
        //cout<<cccc<<endl;
    }

    // Ensure numStack has only one map, which is the final answer.
    while(!opStack.empty() && opStack.top().first=="OP")
    {
        map<int,int> m1=numStack.top();
        numStack.pop();
        opStack.pop();
        if(opStack.empty() || opStack.top().first!="OP")
        {
            numStack.push(m1);
            opStack.push(make_pair("OP","0"));
            break;
        }
        map<int,int> m2=numStack.top();
        numStack.pop();
        opStack.pop();
        mapAdd(m1,m2);
    }

    map<int,int> mp=numStack.top();
    int cnt=0;
    map<int,int>::reverse_iterator flag;    // the symbol of the last output
    for(auto it=mp.rbegin();it!=mp.rend();it++)
    {
        if(it->second==0)
            cnt++;
        if(it->second!=0)
            flag=it;
    }

    if(cnt==mp.size())
    {
        printf("Runtime = 0\n");
    }
    else
    {
        printf("Runtime = ");
        for(auto it=mp.rbegin();it!=mp.rend();it++)
        {
            if(it->first==0)
            {
                if(it->second==0)
                    continue;
                else
                {
                    if(it==flag)
                        printf("%d",it->second);
                    else
                        printf("%d+",it->second);
                }
            }
            else if(it->first==1)
            {
                if(it->second==0)
                {
                    continue;
                }
                else if(it->second==1)
                {
                    if(it==flag)
                        printf("n",it->first);
                    else
                        printf("n+",it->first);
                }
                else
                {
                    if(it==flag)
                        printf("%d*n",it->second,it->first);
                    else
                        printf("%d*n+",it->second,it->first);
                }
            }
            else
            {
                if(it->second==0)
                {
                    continue;
                }
                else if(it->second==1)
                {
                    if(it==flag)
                        printf("n^%d",it->first);
                    else
                        printf("n^%d+",it->first);
                }
                else
                {
                    if(it==flag)
                        printf("%d*n^%d",it->second,it->first);
                    else
                        printf("%d*n^%d+",it->second,it->first);
                }
            }
        }
    }

    return 0;
}