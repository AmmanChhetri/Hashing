

// Problem Link - https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1




#include <bits/stdc++.h>
using namespace std;



// Brute Force
// we will make a count array for a1 ...and traverse through a2...if we found the element in the array...so we decrease the 
// count and move forward...if we didn't find the element we return "No"

// If all the elements would have been unique then we wouldn't have to use count array...but as there can be duplicate 
// elements...


// It's easy you can do it :)







// Better
string isSubset_Better(vector<int> &a1, vector<int> &a2, int n, int m) {
    
    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());
    
    int i = 0;  // for a1
    int j = 0;  // for a2
    
    while(i < n && j < m) {
        if(a1[i] == a2[j]) {
            i++;
            j++;
        }else if(a1[i] < a2[j]) {
            i++;
        }else{
            return "No";
        }
    }
    
    if(i == n && j < m) return "No";
    
    return "Yes";
    
    // Time Complexity is O(nlogn) + O(mlogm) + O(n+m)...
    // Space Complexity is O(1)...
}








// Optimal - Using unordered_maps
// suppose a1 = {1,2,3} ...and a2={1,1} ...we know a2 is not a subset of a1 ..as in a2 we have two 1's ...and in a1 we only have 
// one 1's ...so we see we can also calculate if a2 is a subset of a1 or not using frequency..so...

// Logic - Our logic is simple we will traverse in the smaller array(a2)...and check for each element do we have a element 
// present in the map(for a1)....
string isSubset_Optimal(vector<int> &a1, vector<int> &a2, int n, int m) {
    
    // n = a1.size();
    // m = a2.size();
    

    unordered_map<int,int> mpp;
    
    // Adding a1 elements to the map...
    for(int i = 0;i<n;i++) {
        mpp[a1[i]]++;
    }

    // Traversing in the smaller array and checking if we have corrosponding element in a1..
    for(int j = 0;j<m;j++) {
        if(mpp.find(a2[j]) == mpp.end()) {
            return "No";
        }else{
            if(mpp[a2[j]] > 0) {
                mpp[a2[j]]--;
                continue;
            }else{
                return "No";
            }
        }
    }


    return "Yes";


    // Time Complexity is O(n) + O(m)....O(n) for storing values in map...and O(m) for the loop..
    // Space Complexity is O(n)...

}





int main() {

    vector<int> a1 = {589,5847,595,959,258};
    vector<int> a2 = {258,25};
    
    int n = a1.size();
    int m = a2.size();

    cout<<isSubset_Better(a1,a2,n,m)<<endl;
    cout<<isSubset_Optimal(a1,a2,n,m)<<endl;
    return 0;
}