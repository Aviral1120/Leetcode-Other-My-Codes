/*
// correct but time n space exploitation
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> v;
        for(int i=nums.size()-k;i<nums.size();i++)
            v.push_back(nums[i]);

        for(int i=0;i<nums.size()-k;i++)
            v.push_back(nums[i]);

        nums.clear();

        for(int i=0;i<v.size();i++)
            nums.push_back(v[i]);

    }
};

*/

/*
// space problem solved still it is a little time taking for this platform
class Solution {
public:


    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int g = n - __gcd(n,k);
        int a,i,j,temp;
        for(i=0;i<g;i++)
        {
            j = i;
            temp = nums[i];
            while(1)
            {
                a = (j+k)%n;
                if(a==i)
                    break;
                nums[j] = nums[a];
                j = a;
            }
            nums[j] = temp;
        }

    }
};
*/

class Solution {
public:

    void rev(vector<int>&v, int s, int e)
    {
        while(s<e)
        {
            swap(v[s],v[e]);
            s++;
            e--;
        }
    }
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        // this step below is for conditions when the value of k goes past n you know
        k %= n;
    /*as we call the reverse function below........it could have been done either way
     i.e we can reverse the two parts indivisually and at last revrse the whole vector/array
      or we can reverse the array first and then reverse those two parts */
        rev(nums,0,n-k-1);
        rev(nums,n-k,n-1);
        rev(nums,0,n-1);

    }
};
