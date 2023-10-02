

// Problem statement: Given an array, we have found the number of occurrences of each element in the array.


#include <bits/stdc++.h>
using namespace std;


// Brute Force -
// Our logic is to use two for loops ...outer for loop will tell us which element we are counting..and inner for loop will 
// traverse and count the value if we found ...We can have duplicates so ...consider the case....{10,15,10,15,10,5,8}...so our 
// outer loop starts from index i=0...and inner for loop starts from index i+1...suppose if we found an element we increase the
// count...so in the above case when we have counted 10 and 15..our i will be at index 3(number = 10)...so our for loop will 
// again count it...so to avoid this we need to do something to tell our code....that we have counted this element earlier...
// so we create a visited array...so whenever we count an element(which means while traversing using j , if we found a 
// element such that nums[i] == nums[j]...which means...this element will be considered in that particular element's count
// so we mark our visited array at index j as true...implying this element has been counted ..so next time when we come to this
// index j...we know this element has been counted...)...indicating we have visited this index alrerady in past calculations...
void countFrequency_Brute(vector<int> &nums) {
    
    int n = nums.size();
    vector<int> visited(n,false);

    for(int i = 0;i<n;i++) {

        if(visited[i] == true) {
            continue;
        }

        int count = 1;
        for(int j = i+1;j<n;j++) {

            if(nums[j] == nums[i]) {
                count++;
                visited[j] = true;
            }

        }
        cout<<nums[i]<<" Count is : "<<count<<endl;
    }

    // Time Complexity is O(n^2)
    // Space Complexity is O(n)
}







// Optimal - (Using Maps)
// ! We can also use Arrays to hash ...if the value of the maximum element of the array is not that much higher....
// We will use unordered_map to pair the element with its frequency...here we won't use ordered map(map)...as it will take logn
// time in all 3 cases to store the values in map....whereas the unordered_map will only take O(1) to store the elements (as 
// the element are not sorted in unordered_map )... in average and best cases..and the worst case is very rare that takes O(n)
// time to store...

// Logic - We iterate through the array...and will update the frequency of the element if it is present in the array...if the
//         element is not present in the map (meaning this number appearing for the first time..) then we assign the frequency
//         of this element as 1...
void countFrequency_Optimal(vector<int> &nums) {

    unordered_map<int,int> mpp;
    int n = nums.size();

    for(int i = 0;i<n;i++) {
        mpp[nums[i]]++;
    }

    for(auto it : mpp) {
        cout<<it.first<<"->"<<it.second<<endl;
    }

    // Time Complexity is  O(n)
    // Space Complexity is O(n)..at worst case all elements are different..so we end up taking space for all elements..
}

int main() {

    vector<int> nums = {1,3,4,3,4,1};
    int n = nums.size();
    int x = 4;

    countFrequency_Brute(nums);
    countFrequency_Optimal(nums);

    
    return 0;
}