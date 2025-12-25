#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
int main(){
    int n;
    int k;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>k;
        if(!vec.empty() && vec.back() >= k){
            int idx = lower_bound(vec.begin(),vec.end(),k)-vec.begin();
            vec[idx]=k;
        }
        else{
            vec.push_back(k);
        }
    }
    cout<<vec.size();
    return 0;
}