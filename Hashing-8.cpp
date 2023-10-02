



// Problem Link - https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include <bits/stdc++.h>
using namespace std;






 // Brute Force
 // We find the sum of all possible subarrays...and whenever we encounter a sum as 0..we find the length of the subarray...and 
 // update max length of the required subarray..
 int maxLength_Brute(vector<int> &nums, int n) {
    
    // to store the maximum sum..
    int maxi = 0;

    for(int i = 0;i<n;i++) {
        int sum = 0;
        for(int j = i;j<n;j++) {
            sum += nums[j];

            if(sum == 0) {
                maxi = max(maxi,j-i+1);
            }
        }
    }

    return maxi;

    // Time Complexity is O(n^2)...
    // Space Complexity is O(1)...
 }








// Optimal 
// we know ...if we have sum of subarray..that has already been seen earlier...which means...we have added 0 to it...or simply
// ...all the elements from that point to this point has sum as 0...that's why we are getting the same sum again..so what we 
// going to do is we create a map...and store the sum and the index where it has occured for the first time...after this 
// whenver we get the sum again...we just calculate the distance of the subarray...

// Suppose arr = {1,2,3,4-7} ..therefore sum array will be {1,3,6,10,3}...so we see 3 is coming again...it was first came at
// index 1..now it is coming again at index 4..which means...when we have added elements at index 2,3 ...as soon as we added 
// element at index 4..our sum became 3...so which means...sum of the subarray is 0...[ as sum+0 = sum]...

// And as we need to find the largest subarray...so we just update the sum with the index where it occurred for the first time...
int maxLength_Optimal(vector<int> &nums, int n) {

    int maxi = 0;
    unordered_map<int,int> mpp;
    int sum = 0;
    
    // this step is necessary because consider case arr = {1,-1,1,-1}...so here we see sums are {1,0,1,0}...so we are getting 
    // maximum length as 2 only...but this is wrong right...as we can see the sum of all the elements of the subarray is also 
    // 0..so longest subarray will be of length of 4...(ie. array itself...)...so to handle such cases we initialzie the map 
    // with mpp[0]=-1...now why -1...becasue we know suppose the whole array is givig sum as 0...so to find length from the 
    // method we use in below code ...we do...j-mpp[0]..where j=n-1...which means we have n-1-(-1)..which means...n..so to 
    // handle the cases where sum becomes 0 ..while traversing we need to initialize this....
    mpp[0] = -1;

    for(int i = 0;i<n;i++) {
        sum += nums[i];
        
        if(mpp.find(sum) == mpp.end()) {
            // if sum appearing for the first time..
            mpp[sum] = i;
        }else{
            // we seen this sum before...
            maxi = max(maxi,i-mpp[sum]);
        }
    }


    return maxi;

    // Time Complexity is O(n)...
    // Space Complexity is O(n)...
}





int main() {

    vector<int> nums = {15,-2,2,-8,1,7,10,23};
    int n = nums.size();

    cout<<maxLength_Brute(nums,n)<<endl;
    cout<<maxLength_Optimal(nums,n)<<endl;

    return 0;
}