#include<bits/stdc++.h>
using namespace std;
 #define debug(x) cerr<<#x<<":"<<x<<endl
const int M=5e6;
char sd[20];
char s[M],t[M];
int nt[M];
void make_nt(char t[])
{
    int i=0,k=-1;
    nt[0]=-1;
    while(t[i])
    {
        if(k==-1||t[i]==t[k])
        {
            i++,k++;
            nt[i]=k;
        }
        else
            k=nt[k];
    }
    i=0;while(t[i])debug(nt[i++]);
}
 
bool match(char s[],char t[])
{
    int lt=strlen(t);
    int i=0,j=0;
    while(s[i])
    {
        if(j==-1||s[i]==t[j])
        {
            i++,j++;
        }
        else
            j=nt[j];
        if(j>=lt)
            return true;
    }
    return false;
}
 
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",t);
    make_nt(t);
    for(int i=0;i<10;i++)
        sd[i]=i+'0';
    for(int i=10;i<16;i++)
        sd[i]='A'+i-10;
    for(int k=2;k<=16;k++)
    {
        int ls=0;
        for(int i=1;i<=n;i++)
        {
            int tmp=i;
            char ss[20];
            int lss=0;
            while(tmp)
            {
                ss[lss++]=sd[tmp%k];
                tmp/=k;
            }
            for(int j=lss-1;j>=0;j--)
                s[ls++]=ss[j];
        }
        s[ls]='\0';
        if(match(s,t))
        {
            puts("yes");
            exit(0);
        }
    }
    puts("no");
    return 0;
}