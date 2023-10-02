

// Problem Link - https://practice.geeksforgeeks.org/problems/remove-minimum-number-of-elements4032/1

#include <bits/stdc++.h>
using namespace std;



// As we need to find the minimum number of operations to make both the arrays unique(no common element) ...now we know if both
// the arrays has no element common...then the minimum operation 0...but as soon as we get a common element in 2 arrays...
// we need to delete this ..suppose a = {2,2,3,1,5,2} ...and b = {2,2,4} ...now if we see in these arrays except 2 all are unique
// so to make both arrays completely unique we need to delete 2 from one of the array...(point to be noted...we can only delete
// from one array at a time...)...now to make the arrays in minimum operations we will delete from the array having the minimum
// frequency of that element...also to make the arrays unique....if duplicates are there ....we need to completely delete it 
// from any of the arrays...
// so this gives us the hint of counting elements...and we think of using hash map

int minRemove(vector<int> &a, vector<int> &b, int n, int m) {

    int count = 0;
    unordered_map<int,int> mpp;


    // counting elements in array a...
    for(int i = 0;i<n;i++) {
        mpp[a[i]]++;
    }


    // traversing in array b...and checking if we have the element in a or not..
    for(int j = 0;j<m;j++) {
        if(mpp.find(b[j]) == mpp.end()) {
            // we didn't find this element(b[j]) ...in the map...so we don't need to delete it...
            continue;
        }else{
            // if found in the map...we check if we have any occurence of this element left
            if(mpp[b[j]] > 0){
                // if present
                count++;
                mpp[b[j]]--;
            }else{
                // if the occurence of the element in map is 0...which means this element is no-more present..
                continue;
            }
        }
    }



    return count;

    // Time Complexity is O(n) + O(m)

    // Space Complexity is O(n)    


}




int main() {
    vector<int> a = { 4, 2, 4, 4};
    vector<int> b = { 4, 3};

    int n = a.size();
    int m = b.size();


    cout<<minRemove(a,b,n,m)<<endl;

    return 0;
}