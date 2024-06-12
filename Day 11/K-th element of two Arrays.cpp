// K-th element of two Arrays
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0, j=0;
        int elm = -1; 
        while(i<n && j<m && k--){
            if(arr1[i] <= arr2[j]) {
                elm = arr1[i];
                i++;
            }
            else {
                elm = arr2[j];
                j++;
            }
        }
        while(i<n && k>0){
            elm = arr1[i++];
            k--;
        }
        while(j<m && k>0){
            elm = arr2[j++];
            k--;
        }
        
        return elm;
    }
};