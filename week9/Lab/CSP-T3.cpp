#include <bits/stdc++.h>
using namespace std;

#define MAX (32767)
#define MIN (-32768)

int pre[200100],num[200100];
#define offset 100000
vector<pair<int,int>> ans;

int main() {

    string s;
    int cnt=0;
    while(getline(cin,s)) {
        cnt++;
        if(s[2]=='>') {
            int a=0,b=0;
            int i=5;
            int neg1=0,neg2=0;
            if(s[i]=='-') { // deal with '-'
                i++;
                neg1=1;
            }
            while(i<s.size() && s[i]!=' ') {
                a=a*10 + s[i]-'0';
                i++;
            }
            if(neg1)
                a=a*(-1);
            if(i==s.size() || s[i+1]=='|') { // x >= a
                pre[a+offset]++;
            }
            else {  //s[i]=='&' have <=
                i+=9;
                if(s[i]=='-') {
                    i++;
                    neg2=1;
                }
                while(i<s.size() && s[i]!=' ') {
                    b=b*10 + s[i]-'0';
                    i++;
                }
                if(neg2)
                    b=b*(-1);
                if(a<=b) {
                    pre[a+offset]++; pre[b+offset+1]--; //x >= a && x <= b
                }
            }
        }
        else    //s[2]=='<'
        {
            int b=0;
            int i=5;
            int neg=0;
            if(s[i]=='-') {
                neg=1;
                i++;
            }
            while(i<s.size() && s[i]!=' ') {
                b=b*10 + s[i]-'0';
                i++;
            }
            if(neg)
                b=b*(-1);
            pre[0]++; pre[b+offset+1]--;    // x <= b
        }
    }

    num[0]=pre[0];
    for(int i=1;i<=200000;i++) {
        num[i]=num[i-1]+pre[i];
    }

    int t1=0,t2=0;
    for(int i=MIN;i<=MAX;i++) {
        if(num[i+offset]) t1++;
        else t2++;
    }
    if(t1==MAX-MIN+1) {
        cout<<"true"<<"\n";
        return 0;
    }
    if(t2==MAX-MIN+1) {
        cout<<"false"<<"\n";
        return 0;
    }
    // 1 0 2 3 0 0 5 4 0 0
    // 1 1 1 0 0 0
    // 0 1 1 0 1 0
    // 0 0 0 1 1 1
    int l=MIN,r=MIN;
    while(l<=MAX && r<=MAX) {
        if(num[l+offset]==0 && num[r+offset]==0) {
            l++;
            r++;
        }
        else if(num[l+offset] && num[r+offset]==0) {
            ans.push_back(make_pair(l,r-1));
            l=r;
        }
        else if(num[l+offset] && num[r+offset]){
            r++;
        }
    }

    if(num[l+offset]!=0 && num[r-1+offset]!=0)
    {
        ans.push_back(make_pair(l,r-1));
    }

    for(int i=0;i<ans.size();i++) {
        if(ans[i].first==MIN)
            cout<<"x <= "<<ans[i].second;
        else if(ans[i].second==MAX)
            cout<<"x >= "<<ans[i].first;
        else
            cout<<"x >= "<<ans[i].first<<" && "<<"x <= "<<ans[i].second;
        if(i!=ans.size()-1)
            cout<<" ||"<<"\n";
    }

    return 0;
}