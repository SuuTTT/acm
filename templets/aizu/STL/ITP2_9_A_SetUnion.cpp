#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  set<int>a,b;
  cin>>n;
  while(n--){
    int x;
    cin>>x;
    a.insert(x);
  }
  cin>>n;
  while(n--){
    int x;
    cin>>x;
    b.insert(x);
  }
  vector<int>c;
  set_union(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c));
  //set_intersection(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c));
  //set_difference(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c));
  //set_symmetric_difference(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c));
  //对称差：只属于其中一个集合，而不属于另一个集合的元素组成的集合
  for(int i=0;i<c.size();i++)cout<<c[i]<<endl;
}
