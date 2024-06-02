//  Find the duplicate in an array of N+1 integers
#include<bits/stdc++.h>

using namespace std;
int findDuplicate(vector<int> & nums) {
    int slow = nums[0];
    int fast = nums[0];

    while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];

        if (slow == fast) {
            break;
        }
    }
    int slow2 = nums[0];

    while (slow != slow2) {
        slow = nums[slow];
        slow2 = nums[slow2];
    }

    return slow;  
}
int main() {
  vector < int > arr;
  arr = {1,3,4,2,3};
  cout << "The duplicate element is " << findDuplicate(arr) << endl;
}