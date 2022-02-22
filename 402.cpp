#include <string>
#include <stack>
using namespace std;
class Solution {
    

public:
    string removeKdigits(string num, int k) {
        string ret;
        ret.reserve(num.size() - k + 1);

        size_t num_size = num.size();
        int i = 0;
        while(k != 0 && i < num_size)
        {
            auto candidate = num[i];
            while (k !=0 && !ret.empty())
            {
                char back = ret.back();
                if (back > candidate)
                {
                    ret.pop_back();
                    k--;
                }
                else
                {
                    break;
                }
            }
            ret.push_back(candidate);
            i++;
        }

        // case : k == 0 && i <num_size
        if (i < num_size)
            ret.insert(ret.end(), num.begin() + i, num.end());
        // case : k !=0 && i == num_size
        while (k != 0)
        {
            ret.pop_back();
            k--;
        }

        auto iter = ret.begin();
        for (; iter != ret.end(); iter++)
        {
            if (*iter != '0')
            {
                break;
            }
        }
        ret.assign(iter, ret.end());
        
        if (!ret.compare(""))
            return "0";
        return ret;
    }
};

int main()
{
    Solution solution;
    string ret;
    ret = solution.removeKdigits("100", 1);
    printf("%s\n", ret.c_str());
    ret = solution.removeKdigits("10001", 1);
    printf("%s\n", ret.c_str());
    ret = solution.removeKdigits("10", 2);
    printf("%s\n", ret.c_str());
    ret = solution.removeKdigits("14329759", 7);
    printf("%s\n", ret.c_str());
    ret = solution.removeKdigits("1432219", 3);
    printf("%s\n", ret.c_str());
    ret = solution.removeKdigits("10200", 1);
    printf("%s\n", ret.c_str());
}