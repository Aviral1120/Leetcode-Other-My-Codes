
//first approach (naive approach) : just take two loops and try out all the possibilities till we get the required
//time complexity : O(n)
//space complexity : O(1)
//code
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    v.push_back(i);
                    v.push_back(j);
                    break;
                }
            }
        }
        return v;
    }
};


//second approach (better) : two pointer approach (just take a temp vector assign it with actual vector sort it)
//=>after sorting find the required elements via binary search and store them
//=>now compare those elements within the actual vector and get get the required index and store it
//time complexity : O(NlogN)
//space complexity : O(N)
//code
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        vector<int>temp ;
        temp = nums;
        sort(temp.begin(),temp.end());
        int s=0,n1,n2;
        int e=temp.size()-1;
        while(s<e)
        {
            if(temp[s]+temp[e]==target)
            {
                n1 = temp[s];
                n2 = temp[e];
                break;
            }
            else if(temp[s]+temp[e]>target)
                e--;
            else
                s++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==n1)
            {
                 v.push_back(i);
                 // if the vector is [3,3] and target 6 your output will become [0,0,1,1] instead of [0,1]
                 // unless we use the adjustment just below
                nums[i] = INT_MIN;
            }
            if(nums[i]==n2)
                v.push_back(i);
        }
        return v;
    }
};


//third approach (most efficient) : Hashing (first of all we declare a map, now we run a loop till the end of the given vector)
//=>inside the loop we check if the value(target-nums[i]) present in the map , if not we pair the I'th value with it index
//=>as soon as we pass the if statement we push the required indexes inside the vector and return , else we return an empty vector
//time complexity : O(N)
//space complexity : O(N)
//code
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i]) != m.end())
            {
                v.push_back(i);
                v.push_back(m[target-nums[i]]);
                return v;
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
