#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define db 0
#define all(x)(x).begin(),(x).end()
#define x first
#define y second
using namespace std;

int N;
vector<int>p,pp;

int main(){
    freopen("Input/SampleSize.1.in","r",stdin);
    scanf("%d",&N);
    for(int i = 0,j = 0;i < N;i++){
        scanf("%d",&j);
        p.push_back(j);
    }
    for(int i = 1;i <= 100;i++){
        for(int j = 0; j <= i;j++)
            pp.push_back((int)round(j*100.0/i));
        for(int j = 0;j < N;j++){
            if(!binary_search(all(pp),p[j]))
                break;
            if(j == N-1){
               printf("%d\n",i);
               goto end;
            }
        }
        pp.clear();
    }
    end:return 0;
    return 0;
}
