


#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long sum=0, sqSum = 0;
    long long n=A.size();
    long long expSum=(long long) n*(n+1)/2;
    long long expSqsum = (long long)n*(n+1)*(2*n+1)/6;
    for(int it:A){
        sum += it;
        sqSum += (long long) it*it;
    }
    
    long long diffSum = expSum - sum, diffSqsum = expSqsum-sqSum; 
    long long div = diffSqsum/diffSum;
    int missing = (diffSum+div)/2;
    int repeatedNumber = (div - missing);
    
    return {repeatedNumber, missing};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}

