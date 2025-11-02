#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string a;
    int p,num;
    int cnt=0;
    string c[10000];
    
    cin>>a>>p;
    c[0]=a;
    
    while(1){
        
        num=0;
        for(int i=0;i<c[cnt].size();i++){
            num+=pow((c[cnt][i]-'0'),p);
        }
        cnt++;
        c[cnt]=to_string(num);
        for(int i=0;i<cnt;i++){
            if(c[i]==c[cnt]){
                cout<<i;
                return 0;
            }
        }

    }
    
    return 0;
}
