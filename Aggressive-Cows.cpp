#########################################################################################################################################  Question  ###########################################################################################################################

You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples :

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.
Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.
Constraints:
2 <= stalls.size() <= 106
0 <= stalls[i] <= 108
1 <= k <= stalls.size()

#########################################################################################################################################  Solution  ###########################################################################################################################

  //{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

   bool canPlaceCows(vector<int> &arr,int k,int dist){
        int n = arr.size();
        int cntCow = 1;
        int lastPos = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i] - lastPos >= dist){
                cntCow++; //place cow
                lastPos = arr[i];
            }
            if(cntCow == k){
                return true;
            }
        }
        return false;
        
    }
     
    int aggressiveCows(vector<int> &arr, int k) {

        // Write your code here
        //Binary Search
        //Pattern type -> min(of max)
        
        // Instead of storing answer variable use polarity principle
        
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int s = 1,e = arr[n-1] - arr[0];
        while(s<=e){
            int mid = s + ((e-s)/2);
            if(canPlaceCows(arr,k,mid))
            {
                s = mid+1;
            }
            else{
                e = mid - 1;
            }
        }
        return e;
        
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
