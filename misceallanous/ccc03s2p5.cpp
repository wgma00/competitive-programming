#include<bits/stdc++.h>
using namespace std;

int N,lo,hi,LO,HI;
int arr[65536];

int main() 
{
    ifstream in("//dev//stdin");
    memset(arr,-1,sizeof(arr));
    lo = LO = hi = HI = 0;
    for(int i = 0;in >> N && N!= 0;i++)
    {
        if(arr[N] == -1)
        {
           arr[N] = i;
           HI = i;
           if(HI-LO > hi-lo)
              lo = LO, hi = HI;
        }
        else
        {
            LO = arr[N]+1;
            HI = i-1;
            arr[N] = i;
            if(HI-LO > hi-lo)
                lo = LO, hi = HI;
        }
  }
  in.clear();
  in.seekg(0, ios::beg);
  rewind(stdin);
  for(int i = 0;in >> N && N != 0;i++)
  {
      cout << N << endl;
      if(i >= lo && i <= hi)
      {
         cout << N << endl;
      }
  }
  cout << N << endl;
  in >> N;
  cout << N << endl;
  return 0;
}
