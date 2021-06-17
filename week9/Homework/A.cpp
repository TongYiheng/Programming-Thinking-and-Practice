#include <bits/stdc++.h>
using namespace std;

struct ele
{
    map<string,int> mp;

    bool operator == (const ele &e) const {
        return mp==e.mp;
    }
    void operator += (const ele &e) {
        for(auto &x:e.mp) mp[x.first] += x.second;
    }
    void operator *= (const int v) {
        for(auto &x:mp)  x.second *= v;
    }
};

vector<string> split(string &s,char c)
{
    vector<string> res;
    string tmp;
    for(auto x:s) {
        if(x==c) {
            if(!tmp.empty()) {
                res.emplace_back(tmp);
                tmp="";
            }
        }
        else {
            tmp+=x;
        }
    }
    if(!tmp.empty()) {
        res.emplace_back(tmp);
        tmp.clear();
    }
    return res;
}

int r_int(string &s,int &p) {
    int res=0;
    while(p<s.length() && isdigit(s[p]))
        res=res*10+s[p]-'0',p++;
    if(res==0) return 1;
    return res;
}

string r_el(string &s,int &p) {
    string res;
    if(isupper(s[p])) res+=s[p], p++;
    if(islower(s[p])) res+=s[p], p++;
    return res;
}

ele str2set(string &s,int &p) {
    ele res;
    int multi=r_int(s,p);
    while(p<s.length()) {
        if(s[p]=='(') {
            ++p;
            res += str2set(s,p);
        }
        else if(s[p]==')') {
            ++p;
            res *= r_int(s,p);
            return res;
        }
        else {
            string tmp=r_el(s,p);
            res.mp[tmp] += r_int(s,p);
        }
    }
    res *= multi;
    return res;
}

bool solve(string &s)
{
    vector<string> fms=split(s,'=');
    ele res[2];
    for(int i=0;i<2;i++) {
        vector<string> el=split(fms[i],'+');
        for(int j=0,p=0;j<el.size();j++,p=0) {
            res[i]+=str2set(el[j],p);
        }
    }
    return res[0]==res[1];
}


int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        if(solve(s))
            cout<<"Y"<<"\n";
        else
            cout<<"N"<<"\n";
    }
    return 0;
}