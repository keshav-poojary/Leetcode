#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans;

        vector<int> leftProduct;
        vector<int> rightProduct;

        // left product
        int prod = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            leftProduct.push_back(prod);
            prod = prod * nums[i];
        }

        // right product
        prod = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            rightProduct.push_back(prod);
            prod = prod * nums[i];
        }

        reverse(rightProduct.begin(), rightProduct.end());

        for (int i = 0; i < nums.size(); i++)
        {
            int product = leftProduct[i] * rightProduct[i];
            ans.push_back(product);
        }

        return ans;
    }
};