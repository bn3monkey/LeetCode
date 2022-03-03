#include <string>
#include <vector>
using namespace std;


class Solution {
private:
    
    string toString(int value)
    {
        if (value == -2147483648)
            return "-2147483648";
        
        string ret = "";
        if (value < 0)
        {
            value = -value;
            ret += "-";
        }
                
        // FACEBOOK ALGORITHM (INT TO STRING)
        static const char digits[201] = 
        "0001020304050607080910111213141516171819"
        "2021222324252627282930313233343536373839"
        "4041424344454647484950515253545556575859"
        "6061626364656667686970717273747576777879"
        "8081828384858687888990919293949596979899";
        
        char buffer[11] = {0,};
        int start = 9;
        while (value >= 100) {
            int idx = (value % 100) * 2;
            value /= 100;
            buffer[start] = digits[idx + 1];
            buffer[start - 1] = digits[idx];
            start -= 2;
        }
        
        if (value < 10) {
            buffer[start] = '0' + value;
        }
        else {
            int i = value * 2;
            buffer[start] = digits[i + 1];
            buffer[start -1] = digits[i];
            start = start - 1;
        }
        
        ret.insert(ret.end(), buffer + start, buffer + 10);
        return ret;
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> ret;
        if (nums.size() == 0)
            return ret;
        else
        {
            int start = nums[0];
            int end = nums[0];
            for (int i = 1;i<nums.size();i++)
            {
                // int 연산에서 조심해야함
                if (nums[i-1] + 1 == nums[i])
                {
                    end = nums[i];
                }
                else
                {
                    if (start == end)
                        ret.push_back(toString(start));
                    else
                    {
                        ret.push_back(toString(start)+"->"+toString(end));
                    }
                    start = nums[i];
                    end = nums[i];
                }
            }
            if (start == end)
                ret.push_back(toString(start));
            else
            {
                ret.push_back(toString(start)+"->"+toString(end));
            }
        }
        return ret;
    }
};

void main()
{

    Solution solution;
    vector<string> ret;
    int b = -2147483648;
    ret = solution.summaryRanges(vector<int>({ b, -2147483647, 2147483647})); 
    ret = solution.summaryRanges(vector<int>({0, 1, 2, 4, 5, 7}));
    int a = 2;
    ret = solution.summaryRanges(vector<int>({0, 2, 3, 4, 6, 8, 9}));
    a= 3;
    return;
}