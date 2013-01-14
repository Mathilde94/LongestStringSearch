#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int pstrcmp(const void *p, const void *q){
  return strcmp(*(char **)p,*(char **)q);
}

int comlen(char *p, char *q){
  int result(0);
  while (p && *p==*q){
    result++;
    p++;q++;
  }
  return result;
}

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define MAXN 1000000
char *a[MAXN];

int main(){

  string s("");
  string temporary("");
  while (getline(cin,temporary)){
    s+=temporary;
  }
 
  int n(s.size());
  cout << n <<endl;
  FOR(i,0,s.size()){
    a[i]=&s[i];
  } 
  qsort(a,n,sizeof(char *), pstrcmp);
 
 int maxlen=-1;
 int maxi=-1;
 FOR(i,0,s.size()-1){
    if (comlen(a[i],a[i+1])>maxlen){
     maxlen=comlen(a[i],a[i+1]);
     maxi=i;
   }
 }
 
 cout <<"String of max length: "<< maxlen<<endl;
 FOR(i,0,maxlen){
   cout << a[maxi][i];
 }
 cout <<endl;
 return 0;
}
