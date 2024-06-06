#include<bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
      double ans = 1.0;
      for (int i = 0; i < n; i++) {
        ans = ans * x;
      }
      return ans;
}
int main()
{   
    int x=2, n=10;

    // iterative method
    long long m = n;
    if(m < 0) m = -1* m;
    double ans = 1.0;
    while(m>0){
        if(m%2 == 0){
            x = (x*x);
            m = m/2;
        }
        else{
            ans*=x;
            m--;
        }
    }
    if(n < 0) ans = (double)1.0/(double) ans;
    cout<< ans << endl;

    // using recursion    
    cout<<myPow(2,10)<<endl;
}