#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000005;
int phi[MAX + 5];
// TC: O(NlogN)
int MyPhi[MAX+5];
void generateMyPhi(int n){
    for(int i=1;i<=n;i++)
        MyPhi[i] = i;
    for(int i = 2; i<=n;i++){
        if(MyPhi[i] == i){
            for(int j = i; j<=n; j+=i){
                MyPhi[j] -= MyPhi[j]/i;
            }
        }
    }
}

int main(){
    generateMyPhi(MAX);
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        int a;
        scanf("%d",&a);
        printf("%d\n",MyPhi[a]);
    }
    return 0;
}
