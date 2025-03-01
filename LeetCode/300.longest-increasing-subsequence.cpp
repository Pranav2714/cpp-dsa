/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
///// ***********************BS Solution***************//////

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v;
        v.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > v.back())
                v.push_back(nums[i]);
            else
            {
                int j = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                v[j] = nums[i];
            }
        }
        for (auto &i : v)
        {
            cout << i << " ";
        }
        cout << endl;
        return v.size();
    }
};
// @lc code=end
