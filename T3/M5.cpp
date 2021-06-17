#include <bits/stdc++.h>
using namespace std;

class NOTEPAD {
private:
    vector<string> data;            //文本内容
    pair<int,int> cursor;           //光标位置
    pair<int,int> checkPoint;       //记录点的位置
    pair<int,int> start,end;        //选中字段光标的开始和结尾
    vector<string> clipboard;       //粘贴板
    bool shiftState;                //标记粘滞功能的启动和关闭
    bool selected;                  //标记选中状态
    bool fromShift;                 //标记粘贴板来源
    void moveToEnd();               //将光标移动到当前行的末尾
    bool haveEnter(int x);          //判断当前行有没有换行符
    bool isEnd();                   //判断光标是否在该行的末尾
    bool emptyLine(int x);          //判断当前行是否为空
    void setBound();                //设置选中字段的开始和结束光标位置
    void eraseSelect();             //删除选中字段

public:
    NOTEPAD();
    ~NOTEPAD();
    void move(string &s);
    void insert(char c);
    void insert(string &s);
    void remove(string &s);
    void shift();
    int find(string &s);
    int count();
    void copy();
    void print();
};

NOTEPAD::NOTEPAD() {
    data.clear();
    clipboard.clear();
    data.emplace_back(string());
    cursor.first=0,cursor.second=0;
    checkPoint.first=checkPoint.second=0;
    shiftState=false;
    selected=false;
}

NOTEPAD::~NOTEPAD() {}

void NOTEPAD::moveToEnd() {
    if(data[cursor.first].empty()) {
        cursor.second=0;
    }
    else {
        if(data[cursor.first][data[cursor.first].size()-1]=='\n') //当前行有换行符
            cursor.second=data[cursor.first].size()-1;
        else    //当前行没有换行符
            cursor.second=data[cursor.first].size();
    }
}

bool NOTEPAD::haveEnter(int x) {
    if(data[x].empty())
        return false;
    else {
        if(data[x][data[x].size()-1]=='\n')
            return true;
        else
            return false;
    }
}

bool NOTEPAD::isEnd() {
    if(data[cursor.first].empty() && cursor.second==0)
        return true;

    if(haveEnter(cursor.first)) { //当前行有换行符
        if(cursor.second==data[cursor.first].size()-1)
            return true;
        else
            return false;
    }
    else { //当前行没有换行符
        if(cursor.second==data[cursor.first].size())
            return true;
        else
            return false;
    }
}

bool NOTEPAD::emptyLine(int x) {
    if(data[x].empty())
        return true;
    if(data[x].size()==1 && data[x][0]=='\n')
        return true;
    return false;
}

void NOTEPAD::setBound() {
    if(checkPoint.first<cursor.first || (checkPoint.first==cursor.first && checkPoint.second<cursor.second)) {
        start=checkPoint;
        end=cursor;
    }
    else {
        start=cursor;
        end=checkPoint;
    }
}

void NOTEPAD::eraseSelect() {
    if(start.first==end.first) { //选中内容位于一行内
        data[start.first].erase(data[start.first].begin()+start.second,data[start.first].begin()+end.second);
        cursor=start;
    }
    else { //选中内容位于多行
        //保存end所在行的右侧剩余内容
        string tmp;
        for(int i=end.second;i<data[end.first].size();i++)
            tmp.push_back(data[end.first][i]);
        //删除start所在行的右侧内容
        data[start.first].erase(data[start.first].begin()+start.second,data[start.first].end());
        //删除start+1到end行
        data.erase(data.begin()+start.first+1,data.begin()+end.first+1);
        //将end行右侧剩余内容补到start行
        data[start.first]+=tmp;
        cursor=start;
    }
}

void NOTEPAD::move(string &s) {
    if(selected) { //处于选中状态
        selected=false;
    }

    if(s=="Home") {
        cursor.second=0;
    }
    else if(s=="End") {
        moveToEnd();
    }
    else if(s=="Up") {
        if(cursor.first==0) //当前是第一行
            return;
        if(data[cursor.first-1].size()-1 < cursor.second) { //上一行的列数小于当前光标的列数
            cursor.first--;
            moveToEnd();
        }
        else
            cursor.first--;
    }
    else if(s=="Down") {
        if(cursor.first==data.size()-1)
            return;

        if(haveEnter(cursor.first+1)) { //下一行有换行符
            if(data[cursor.first+1].size()-1 < cursor.second) {
                cursor.first++;
                moveToEnd();
            }
            else
                cursor.first++;
        }
        else { //下一行没有换行符
            if(data[cursor.first+1].size() < cursor.second) {
                cursor.first++;
                moveToEnd();
            }
            else
                cursor.first++;
        }
    }
    else if(s=="Left") {
        if(cursor.first==0 && cursor.second==0)
            return ;
        if(cursor.second==0) {
            cursor.first--;
            moveToEnd();
        }
        else {
            cursor.second--;
        }
    }
    else if(s=="Right") {
        if(cursor.first==data.size()-1 && isEnd())
            return ;
        if(isEnd()) {
            cursor.first++;
            cursor.second=0;
        }
        else {
            cursor.second++;
        }
    }
}

void NOTEPAD::insert(char c) {
    if(selected) {
        setBound();
        eraseSelect();
        selected=false;
    }

    if(data[cursor.first].size()==cursor.second)
        data[cursor.first].push_back(c);
    else
        data[cursor.first].insert(data[cursor.first].begin()+cursor.second,c);
    cursor.second++;
}

void NOTEPAD::insert(string &s) {
    if(selected) {
        setBound();
        eraseSelect();
        selected=false;
    }

    if(s=="Enter") {
        if(cursor.first==data.size()-1 && cursor.second==data[cursor.first].size()) { //光标在无换行符的行末（最后一行）
            data[cursor.first].push_back('\n');
            data.insert(data.begin()+cursor.first+1,string());
        }
        else if(cursor.second==data[cursor.first].size()-1 && data[cursor.first][cursor.second]=='\n') { //光标在有换行符的在行末
            data.insert(data.begin()+cursor.first+1,string("\n"));
        }
        else { //光标不在行末
            string tmp;
            for(int i=cursor.second;i<data[cursor.first].size();i++)
                tmp.push_back(data[cursor.first][i]);
            data.insert(data.begin()+cursor.first+1,tmp);
            data[cursor.first].erase(data[cursor.first].begin()+cursor.second,data[cursor.first].end());
            data[cursor.first].push_back('\n');
        }
        cursor.first++;
        cursor.second=0;
    }
    else if(s=="Space") {
        if(data[cursor.first].size()==cursor.second)
            data[cursor.first].push_back(' ');
        else
            data[cursor.first].insert(data[cursor.first].begin()+cursor.second,' ');
        cursor.second++;
    }
    else if(s=="Paste") {
        if(clipboard.empty()) { //粘贴板为空
            return ;
        }
        else {
            if(!fromShift) { //粘贴板来自一行
                if(cursor.first==data.size()-1 && cursor.second==data[cursor.first].size()) { //光标在无换行符的行末
                    for(auto x:clipboard[0])
                        data[cursor.first].push_back(x);
                    moveToEnd();
                }
                else if(cursor.second==data[cursor.first].size()-1 && data[cursor.first][cursor.second]=='\n') { //光标在有换行符的行末
                    data[cursor.first].pop_back();
                    for(auto x:clipboard[0])
                        data[cursor.first].push_back(x);
                    data[cursor.first].push_back('\n');
                    moveToEnd();
                }
                else { //光标不在行末
                    string tmp;
                    for(int i=cursor.second;i<data[cursor.first].size();i++)
                        tmp.push_back(data[cursor.first][i]);
                    data[cursor.first].erase(data[cursor.first].begin()+cursor.second,data[cursor.first].end());
                    for(auto x:clipboard[0]) {
                        data[cursor.first].push_back(x);
                        cursor.second++;
                    }
                    for(auto x:tmp) {
                        data[cursor.first].push_back(x);
                    }
                }
            }
            else { //粘贴板来自选中字段
                if(clipboard.size()==1) { //粘贴板只有一行
                    if(cursor.first==data.size()-1 && cursor.second==data[cursor.first].size()) { //光标在无换行符的行末
                        for(auto x:clipboard[0])
                            data[cursor.first].push_back(x);
                        moveToEnd();
                    }
                    else if(cursor.second==data[cursor.first].size()-1 && data[cursor.first][cursor.second]=='\n') { //光标在有换行符的行末
                        data[cursor.first].pop_back();
                        for(auto x:clipboard[0])
                            data[cursor.first].push_back(x);
                        data[cursor.first].push_back('\n');
                        moveToEnd();
                    }
                    else { //光标不在行末
                        string tmp;
                        for(int i=cursor.second;i<data[cursor.first].size();i++)
                            tmp.push_back(data[cursor.first][i]);
                        data[cursor.first].erase(data[cursor.first].begin()+cursor.second,data[cursor.first].end());
                        for(auto x:clipboard[0]) {
                            data[cursor.first].push_back(x);
                            cursor.second++;
                        }
                        for(auto x:tmp) {
                            data[cursor.first].push_back(x);
                        }
                    }
                }
                else { //粘贴板有多行
                    string tmp;
                    for(int i=cursor.second;i<data[cursor.first].size();i++)
                        tmp.push_back(data[cursor.first][i]);
                    data[cursor.first].erase(data[cursor.first].begin()+cursor.second,data[cursor.first].end());
                    data[cursor.first]+=clipboard[0];

                    for(int i=1;i<clipboard.size();i++) {
                        cursor.first++;
                        data.insert(data.begin()+cursor.first,clipboard[i]);
                    }
                    moveToEnd();
                    data[cursor.first]+=tmp;
                }
            }
        }
    }
}

void NOTEPAD::remove(string &s) {
    if(selected) { //处于选中状态
        setBound();
        eraseSelect();
        selected=false;
        return ;
    }

    if(s=="Del") {
        if(cursor.first==data.size()-1 && isEnd())
            return ;
        if(cursor.second==data[cursor.first].size()-1 && data[cursor.first][cursor.second]=='\n') { //该字符为换行符
            data[cursor.first].pop_back();  //删除换行符
            string nextLine(data[cursor.first+1]);
            data.erase(data.begin()+cursor.first+1);
            data[cursor.first]+=nextLine;
        }
        else {
            data[cursor.first].erase(data[cursor.first].begin()+cursor.second);
        }
    }
    else if(s=="Backspace") {
        if(cursor.first==0 && cursor.second==0)
            return ;
        if(cursor.second==0) {
            cursor.first--;
            moveToEnd();
            data[cursor.first].pop_back();  //删除换行符
            string nextLine(data[cursor.first+1]);
            data.erase(data.begin()+cursor.first+1);
            data[cursor.first]+=nextLine;
        }
        else {
            cursor.second--;
            data[cursor.first].erase(data[cursor.first].begin()+cursor.second);
        }
    }
}

void NOTEPAD::shift() {
    if(selected) { //处于选中状态
        selected=false;
        shiftState=true;
        return ;
    }

    if(!shiftState) {   //启动粘滞功能
        shiftState=true;
        checkPoint=cursor;
    }
    else { //关闭粘滞功能
        shiftState=false;
        if(cursor!=checkPoint) { //进入选中状态
            selected=true;
        }
    }
}

int NOTEPAD::find(string &s) {
    int ans=0;

    if(selected) { //当前处于选中状态
        setBound();
        if(start.first==end.first) { //选中内容位于一行内
            int index=0;
            string str;
            for(int i=start.second;i<end.second;i++) {
                str.push_back(data[start.first][i]);
            }
            while((index=str.find(s,index)) < str.length()){
                ans++;
                index++;
            }
        }
        else {
            for(int l=start.first;l<=end.first;l++) {
                int index=0;
                string str;
                if(l==start.first) {
                    for(int i=start.second;i<data[start.first].size();i++) {
                        str.push_back(data[start.first][i]);
                    }
                }
                else if(l==end.first) {
                    for(int i=0;i<end.second;i++) {
                        str.push_back(data[end.first][i]);
                    }
                }
                else {
                    str=data[l];
                }
                while((index=str.find(s,index)) < str.length()){
                    ans++;
                    index++;
                }
            }
        }
    }
    else { //当前未处于选中状态
        for(int l=0;l<data.size();l++) {
            int index=0;
            string str=data[l];
            while((index=str.find(s,index)) < str.length()){
                ans++;
                index++;
            }
        }
    }

    return ans;
}

int NOTEPAD::count() {
    int ans=0;

    if(selected) { //当前处于选中状态
        setBound();
        if(start.first==end.first) {
            for(int i=start.second;i<end.second;i++)
                if(data[start.first][i]!=' ' && data[start.first][i]!='\n') ans++;
        }
        else {
            for(int l=start.first;l<=end.first;l++) {
                if(l==start.first) {
                    for(int i=start.second;i<data[start.first].size();i++)
                        if(data[start.first][i]!=' ' && data[start.first][i]!='\n') ans++;
                }
                else if(l==end.first) {
                    for(int i=0;i<end.second;i++)
                        if(data[end.first][i]!=' '&& data[end.first][i]!='\n') ans++;
                }
                else {
                    for(auto x:data[l])
                        if(x!=' '&& x!='\n') ans++;
                }
            }
        }
    }
    else { //当前未处于选中状态
        for(int l=0;l<data.size();l++) {
            for(auto x:data[l])
                if(x!=' ' && x!='\n') ans++;
        }
    }

    return ans;
}

void NOTEPAD::copy() {
    if(selected) { //处于选中状态
        fromShift=true;
        clipboard.clear();
        setBound();
        if(start.first==end.first) { //选中内容位于一行内
            clipboard.emplace_back(string());
            for(int i=start.second;i<end.second;i++) {
                clipboard[0].push_back(data[start.first][i]);
            }
        }
        else { //选中内容位于多行
            for(int l=start.first;l<=end.first;l++) {
                if(l==start.first) {
                    clipboard.emplace_back(string());
                    for(int i=start.second;i<data[start.first].size();i++) {
                        clipboard[0].push_back(data[start.first][i]);
                    }
                }
                else if(l==end.first) {
                    clipboard.emplace_back(string());
                    for(int i=0;i<end.second;i++) {
                        clipboard[clipboard.size()-1].push_back(data[end.first][i]);
                    }
                }
                else {
                    clipboard.emplace_back(data[l]);
                }
            }
        }
    }
    else {
        if(emptyLine(cursor.first)) { //当前行为空
            return ;
        }
        else {
            clipboard.clear();
            clipboard.emplace_back(data[cursor.first]);
            if(haveEnter(cursor.first))//当前行有换行符，在粘贴板中删除换行符
                clipboard[0].pop_back();
            fromShift=false;
        }
    }
}

void NOTEPAD::print() {
    for(const auto& x:data) {
        cout<<x;
    }
    cout<<"\n";
}



int main() {
    NOTEPAD notepad;
    int n;
    cin>>n;
    string op,comd,word;
    for(int i=1;i<=n;i++) {
        cin>>op;
        //cout<<"op"<<i<<endl;
        if(op=="MOVE") {
            cin>>comd;
            notepad.move(comd);
        }
        else if(op=="INSERT") {
            cin>>comd;
            if(comd=="Char") {
                char c;
                cin>>c;
                notepad.insert(c);
            }
            else {
                notepad.insert(comd);
            }
        }
        else if(op=="REMOVE") {
            cin>>comd;
            notepad.remove(comd);
        }
        else if(op=="SHIFT") {
            notepad.shift();
        }
        else if(op=="FIND") {
            cin>>word;
            cout<<notepad.find(word)<<"\n";
        }
        else if(op=="COUNT") {
            cout<<notepad.count()<<"\n";
        }
        else if(op=="COPY") {
            notepad.copy();
        }
        else if(op=="PRINT") {
            notepad.print();
        }
    }
    return 0;
}