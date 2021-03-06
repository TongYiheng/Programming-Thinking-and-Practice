#include <bits/stdc++.h>
using namespace std;
int main()
{
    char str[3];
    scanf("%s",str);
    if(str[0]==str[1] && str[1]==str[2])
        printf("Won\n");
    else
        printf("Lost\n");

    return 0;
}