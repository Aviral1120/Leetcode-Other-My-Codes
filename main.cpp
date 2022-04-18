
//first approach (Brute force) : simply sort the array/vector with the help of any sorting algo
//time complexity : based on the algo
//space complexity : O(1)


//second approach (better) : counting the occurrences of the elements and making a customized array
//time complexity : O(n) + O(n)
//space complexity : O(1)
//code

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int a=0,b=0,c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                a++;
            else if(nums[i]==1)
                b++;
            else
                c++;
        }
        nums.clear();
        for(int i=0;i<n;i++)
        {
            if(i<(a))
                nums.push_back(0);
            else if(i>=(a-1) && i<(a+b))
                nums.push_back(1);
            else
                nums.push_back(2);

        }


    }
};


//third approach (best) : 3 pointer approach
//time complexity : O(n)
//space complexity : O(1)
//this problem is a variant of famous " DUTCH NATIONAL FLAG ALGORITHM "
//code
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;

        while (mid <= high) {
            switch (nums[mid]) {

            // If the element is 0
            case 0:
                swap(nums[low++], nums[mid++]);
                break;
             /* case 0:
                swap(nums[low], nums[mid]);
                low++;
                mid++;
                break;
            */
            // If the element is 1 .
            case 1:
                mid++;
                break;

            // If the element is 2
            case 2:
                swap(nums[mid], nums[high--]);
                break;
            }
        }

    }
};
