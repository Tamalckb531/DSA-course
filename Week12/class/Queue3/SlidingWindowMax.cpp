class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        vector<int> ans;
        deque<int> dq;

        //* First window

        for (int i = 0; i < k; i++)
        {
            int element = nums[i];
            while (!dq.empty() && nums[dq.back()] < element)
            {
                dq.pop_back(); //? popping from back as front element are already used by prev window but back element is unchecked
            }
            dq.push_back(i);
        }

        int element = nums[dq.front()];
        ans.push_back(element);

        //* Rest window
        for (int i = k; i < nums.size(); i++)
        {

            //? Removal
            while (!dq.empty() && dq.front() < i - k + 1)
            {
                dq.pop_front();
            }

            //? Addition
            int element = nums[i];
            while (!dq.empty() && nums[dq.back()] < element)
            {
                dq.pop_back();
            }
            dq.push_back(i);

            //? Ans store
            int elem = nums[dq.front()];
            ans.push_back(elem);
        }

        return ans;
    }
};