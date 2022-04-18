
//first approach (brute force) : we just sort the array and check for which element (arr[i) the adjacent element (arr[i+1]) is the same
//time complexity : O(nlogn) + O(n)  or O(NlogN + N)
//space complexity : O(1)
//nlogn is the time complexity used by the sort function
//code
int findDuplicate(vector < int > & arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      return arr[i];
    }
  }
}

//second approach (better) : we could take the account of the frequencies of the elements and check if any elements frequency is >1
//time complexity : O(n)
//space complexity :
//code
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>m;

        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int ans;
        for(auto i : m)
        {
            if(i.second > 1)
                 ans = i.first;
        }

        return ans;
    }
};

//third approach (best) : Linked List Cycle Method
//time complexity : O(n)
//space complexity : O(1)
//code
