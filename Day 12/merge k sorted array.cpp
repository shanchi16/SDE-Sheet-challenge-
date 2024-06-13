#include <bits/stdc++.h> 
#define pp pair<int,pair<int,int>> 
vector<int> mergeKSortedArrays(vector<vector<int>>& mat, int k)
{   int n= mat.size();
    priority_queue<pp, vector<pp>, greater<pp> > pq;
    for(int i=0; i<n; i++){
      pq.push({mat[i][0], {i,0}});
    }

    vector<int>  ans;
    while(!pq.empty()){
      auto top = pq.top();
      pq.pop();
      ans.push_back(top.first);
      int i=top.second.first, j=top.second.second;
      if(j+1 < mat[i].size()) pq.push({mat[i][j+1], {i,j+1}});
    }
    return ans;
}
