#include <bits/stdc++.h>
using namespace std;

int n,m;

struct dailyrun {
    string date;
    int p;
    string startTime,endTime;
    double length;
    string pauseTime;
    int s;
}dailyRun[150010];

struct stu {
    string level;
    int sum,dailyRunCnt;
    int p,s,f,c;
    string sex,physicalTest;
    string run;
    vector<dailyrun> v;
}student[5000];

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

void solveLongRun(int i) {
    vector<string> runTime=split(student[i].run,'\'');
    runTime[1].pop_back();
    int min=0,sec=0;
    for(int j=0;j<runTime[0].size();j++) {
        min=min*10+runTime[0][j]-'0';
    }
    for(int j=0;j<runTime[1].size();j++) {
        sec=sec*10+runTime[1][j]-'0';
    }

    if(student[i].sex=="M") {
        if(min<=11) student[i].sum+=20;
        else if(min==12) {
            if(sec<=30) student[i].sum+=20;
            else student[i].sum+=18;
        }
        else if(min==13) {
            if(sec==0) student[i].sum+=18;
            else if(sec>0 && sec<=30) student[i].sum+=16;
            else student[i].sum+=14;
        }
        else if(min==14) {
            if(sec==0) student[i].sum+=14;
            else if(sec>0 && sec<=30) student[i].sum+=12;
            else student[i].sum+=10;
        }
        else if(min==15) {
            if(sec<=10) student[i].sum+=10;
            else if(sec>10 && sec<=50) student[i].sum+=8;
            else student[i].sum+=6;
        }
        else if(min==16) {
            if(sec<=30) student[i].sum+=6;
            else student[i].sum+=4;
        }
        else if(min==17) {
            if(sec<=10) student[i].sum+=4;
            else student[i].sum+=2;
        }
        else if(min==18) {
            if(sec==0) student[i].sum+=2;
        }
    }
    else {
        if(min<=5) student[i].sum+=20;
        else if(min==6) {
            if(sec<=40) student[i].sum+=20;
            else if(sec>40 && sec<=57) student[i].sum+=18;
            else student[i].sum+=16;
        }
        else if(min==7) {
            if(sec<=14) student[i].sum+=16;
            else if(sec>14 && sec<=31) student[i].sum+=14;
            else if(sec>31 && sec<=50) student[i].sum+=12;
            else student[i].sum+=10;
        }
        else if(min==8) {
            if(sec<=5) student[i].sum+=10;
            else if(sec>5 && sec<=20) student[i].sum+=8;
            else if(sec>20 && sec<=35) student[i].sum+=6;
            else if(sec>35 && sec<=50) student[i].sum+=4;
            else student[i].sum+=2;
        }
        else if(min==9) {
            if(sec==0) student[i].sum+=2;
        }
    }
}

void solveDaily(int i) {
    int cnt=0;
    int lastEnd=0;
    string lastDate;
    for(int k=0;k<student[i].v.size();k++) {
        //长跑距离
        if(student[i].sex=="M" && student[i].v[k].length*1000<3000) continue;
        if(student[i].sex=="F" && student[i].v[k].length*1000<1500) continue;
        //平均速度
        vector<string> s=split(student[i].v[k].startTime,':');
        vector<string> e=split(student[i].v[k].endTime,':');
        int hh1=0,mm1=0,ss1=0,time1=0;
        int hh2=0,mm2=0,ss2=0,time2=0;
        for(int j=0;j<s[0].size();j++) hh1=hh1*10+s[0][j]-'0';
        for(int j=0;j<s[1].size();j++) mm1=mm1*10+s[1][j]-'0';
        for(int j=0;j<s[2].size();j++) ss1=ss1*10+s[2][j]-'0';
        time1=hh1*3600+mm1*60+ss1;
        for(int j=0;j<e[0].size();j++) hh2=hh2*10+e[0][j]-'0';
        for(int j=0;j<e[1].size();j++) mm2=mm2*10+e[1][j]-'0';
        for(int j=0;j<e[2].size();j++) ss2=ss2*10+e[2][j]-'0';
        time2=hh2*3600+mm2*60+ss2;
        if((student[i].v[k].length*1000/(time2-time1) < 2) || (student[i].v[k].length*1000/(time2-time1) > 5))
            continue;
        //暂停时间
        vector<string> pau=split(student[i].v[k].pauseTime,'\'');
        pau[1].pop_back();
        int pm=0,ps=0;
        for(int j=0;j<pau[0].size();j++) pm=pm*10+pau[0][j]-'0';
        for(int j=0;j<pau[1].size();j++) ps=ps*10+pau[1][j]-'0';
        if(pm==4 && ps>=31) continue;
        if(pm>=5) continue;
        //平均步幅
        if(student[i].v[k].length*1000/student[i].v[k].s > 1.5) continue;
        //间隔
        if(lastDate==student[i].v[k].date && time1-lastEnd < 3600*6)  continue;
        lastEnd=time2;
        lastDate=student[i].v[k].date;
        cnt++;
    }

    if(cnt>=21) student[i].sum+=10;
    else if(cnt>=19 && cnt<=20) student[i].sum+=9;
    else if(cnt>=17 && cnt<=18) student[i].sum+=8;
    else if(cnt>=14 && cnt<=16) student[i].sum+=7;
    else if(cnt>=11 && cnt<=13) student[i].sum+=6;
    else if(cnt>=7 && cnt<=10) student[i].sum+=4;
    else if(cnt>=3 && cnt<=6) student[i].sum+=2;
    student[i].dailyRunCnt=cnt;
}

void solve() {
    for(int i=1;i<=n;i++) {
        student[i].sum=0;
        //体育课专项
        student[i].sum+=student[i].s;
        //长跑测试
        solveLongRun(i);
        //日常长跑
        solveDaily(i);
        //体测
        if(student[i].physicalTest=="P") student[i].sum+=10;
        //平时
        int tt=student[i].dailyRunCnt+student[i].c;
        if(tt>=18) student[i].sum+=5;
        else if(tt>=15 && tt<=17) student[i].sum+=4;
        else if(tt>=12 && tt<=14) student[i].sum+=3;
        else if(tt>=9 && tt<=11) student[i].sum+=2;
        else if(tt>=6 && tt<=8) student[i].sum+=1;
        student[i].sum+=student[i].f;
        //level
        if(student[i].sum>=95) student[i].level="A";
        else if(student[i].sum>=90 && student[i].sum<95) student[i].level="A-";
        else if(student[i].sum>=85 && student[i].sum<90) student[i].level="B+";
        else if(student[i].sum>=80 && student[i].sum<85) student[i].level="B";
        else if(student[i].sum>=77 && student[i].sum<80) student[i].level="B-";
        else if(student[i].sum>=73 && student[i].sum<77) student[i].level="C+";
        else if(student[i].sum>=70 && student[i].sum<73) student[i].level="C";
        else if(student[i].sum>=67 && student[i].sum<70) student[i].level="C-";
        else if(student[i].sum>=63 && student[i].sum<67) student[i].level="D+";
        else if(student[i].sum>=60 && student[i].sum<63) student[i].level="D";
        else student[i].level="F";
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("test.txt","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>student[i].p;
        cin>>student[i].sex;
        cin>>student[i].s;
        cin>>student[i].run;
        cin>>student[i].physicalTest;
        cin>>student[i].f;
        cin>>student[i].c;
    }
    cin>>m;
    for(int i=1;i<=m;i++) {
        cin>>dailyRun[i].date;
        cin>>dailyRun[i].p;
        cin>>dailyRun[i].startTime>>dailyRun[i].endTime;
        cin>>dailyRun[i].length;
        cin>>dailyRun[i].pauseTime;
        cin>>dailyRun[i].s;
        for(int k=1;k<=n;k++) {
            if(student[k].p==dailyRun[i].p) {
                student[k].v.emplace_back(dailyRun[i]);
                break;
            }
        }
    }

    solve();
    for(int i=1;i<=n;i++) {
        cout<<student[i].p<<" "<<student[i].sum<<" "<<student[i].level<<"\n";
    }

    return 0;
}