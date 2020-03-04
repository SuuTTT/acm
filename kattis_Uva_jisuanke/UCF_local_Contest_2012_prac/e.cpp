#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define debug(x) cerr<<#x<<": "<<x<<endl
const int inf=0x3f3f3f3f;
int t;
int n;
vector<string>ve[100];
int pos[109],len[109],can[109][19],h[109];
int main(){
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d",&n);
        getchar();
        for(int i=0;i<n;i++){
            char c;
            string s="";
            string line;
            getline(cin,line);
            debug(line);
            ve[i].clear();
            len[i]=0;
            while(auto c:s){
                if(c=='#'){
                    ve[i].push_back(s);
//                    debug(i);debug(s);debug(s.size());
                    len[i]=max(len[i],(int)s.size());
                    s="";
                }
                else {
                    s+=c;
                }
            }
            ve[i].push_back(s);
//            debug(i);debug(s);debug(s.size());
            len[i]=max(len[i],(int)s.size());
            s="";
            while(ve[i].size()<6){
                ve[i].push_back(" ");
                if(ve[i].size()<6)ve[i].insert(ve[i].begin()," ");
            }
        }
//        for(int i=0;i<n;i++)debug(len[i]);
        can[0][0]=0;
        int cnt=0;h[0]=0;pos[0]=0;
        for(int i=1;i<n;i++){
            int f=0;
            for(int j=0;j<=cnt;j++){
                if(len[i]<len[can[j][h[j]]]){
                    f=1;
                    can[j][++h[j]]=i;
                    pos[i]=pos[can[j][h[j]-1]]+(len[can[j][h[j]-1]]-len[i])/2;
                    break;
                }
            }
            if(f==0){
                can[++cnt][0]=i;
                h[cnt]=0;
                pos[i]=pos[can[cnt-1][0]]+len[can[cnt-1][0]]+3;
            }
        }
//        for(int i=0;i<=cnt;i++){
//            for(int j=0;j<=h[i];j++)printf("%d ",can[i][j]);printf("\n");
//        }

        printf("Can Stack #%d: \n",cas);
        printf("         1         2         3         4         5         6 \n");
        printf("123456789012345678901234567890123456789012345678901234567890 \n");
        for(int i=10;i>=0;i--){
            for(int j=0;j<8;j++){
                int now=0;
                for(int k=0;k<=cnt;k++){
                    if(i>h[k])continue;
                    int id=can[k][i];
                    while(now<pos[id]){
                        printf(" ");
                        now++;
                    }
                    int to=now+2+len[id];
                    printf("#");now++;
                    if(j==0||j==7){
                        while(now+1<to)printf("#"),now++;
                    }
                    else{
                        for(int g=0;g<(len[id]-ve[id][j-1].size())/2;g++)printf(" "),now++;
                        for(int g=0;g<ve[id][j-1].size();g++)printf("%c",ve[id][j-1][g]),now++;
                        while(now+1<to)printf(" "),now++;
                    }
                    printf("#");now++;
                }
                if(now>0)printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
/*
1
2
Coaches8#Ali88
Geeks of#UCFdorms#Soup

2
2
Coaches8#Ali88
Geeks of#UCFdorms#Soup
6
Pork and#Beans
Cream of#Mushroom#Soup
Baby#Carrots
Snow#Peas
Grape#Jelly
Aunt Helens#Down Home#Country#Goodness
*/
