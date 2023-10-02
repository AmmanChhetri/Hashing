

// Problem Link - https://practice.geeksforgeeks.org/problems/max-distance-between-same-elements/1


#include <bits/stdc++.h>
using namespace std;



// Brute 
int maxDistance_Brute(vector<int> &nums, int n) {
    
    // Here initializing the maxi with 0...because when we only have 1 element in the array ...then max distance is 0..
    int maxi = 0;

    for(int i = 0;i<n;i++) {
        for(int j = i+1;j<n;j++) {
            if(nums[i] == nums[j]) {
                maxi = max(maxi,j-i);
            }
        }
    }


    return maxi;

    // Time Complexity is O(n^2)...
    // Space Complexity is O(1)..
}








// Optimal
// Intuition - In the brute Force approach we are using 1st for loop for the first number ...and 2nd for loop for the second
//             number ...and we are checking if the first number is equal to second number...and if yes..then we are updating 
//             max distance..so if we want to optimiza it we think of O(n) solution...so what while traversing the array we
//             reached a element say 1 ...so if we just know if this element has occured previously or not...we can easily 
//             calculate the distance between them....that's why we think of hash maps...this time we store the number with its
//             index...now we only store the element when it occured for the first time ....and after that whenver it occurs we 
//             calculate distance...because we need to maximize the distance...


// We know whenver we store the element with index  in a map...the map stores the index of the most recent occurence...say
// nums = {4,5,2,4}...here when we add it in the map...we have initally as  4->0 , 5->1, 2->2 ...but as soon as we reached 4
// as 4 is already present in the map...it updates it index as 4->3, 5->1, 2->2...also map doesn't store duplicates...
int maxDistance_Better(vector<int> &nums, int n) {

    int maxi = 0;

    unordered_map<int,int> mpp;


    for(int i = 0;i<n;i++) {
        
        // element appearing for the first time ...then we add it to map...        
        if(mpp.find(nums[i]) == mpp.end()) {
            mpp[nums[i]] = i;
        }else{
            // if the element appearing after first time...we update maxi distance...
            maxi = max(maxi,i-mpp[nums[i]]);
        }
    }

    return maxi;

    // Time Complexity is O(1)..
    // Space Complexity is O(n)....
}






int main() {

    vector<int> nums = {1, 1, 2, 2, 2, 1};
    int n = nums.size();

    cout<<maxDistance_Brute(nums,n)<<endl;
    cout<<maxDistance_Better(nums,n)<<endl;

    return 0;
}