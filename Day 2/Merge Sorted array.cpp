#include <bits/stdc++.h>
using namespace std;

void merge(long long nums1[], long long nums2[], int n, int m) {
    // len of the imaginary single array:
    int i=m-1, k=m+n-1;
    while(i>=0){
        nums1[k] = nums1[i];
        k--;
        i--;
    }
    i=k+1;
    int j=0;
    k=0;
    while(j<n && i<m+n){
        if(nums1[i] <= nums2[j]){
            nums1[k++] = nums1[i++]; 
        }
        else{
            nums1[k++] = nums2[j++];
        }
    }

    while(j<n){
        nums1[k++] = nums2[j++];
    }
    while(i<m+n){
        nums1[k++] = nums1[i++]; 
    }
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int m = 3, n = 4;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}

