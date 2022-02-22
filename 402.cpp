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

        // 예를 들어 "24635"에서 2개를 지운다고 가정해보자.
        
        // 스택에 맨 앞의 자리부터 하나씩 넣어서 3자리 문자열을 만든다고 하자. 
        
        // 처음 스택에 "2"를 넣는다.
        // 그 다음 4를 스택에 넣는다.
        // 이 때 2가지 선택 중 하나를 해야한다.
        // 1. 2를 지우고 4를 넣는다. 4XX
        // 2. 4를 쌓는다. 24X
        // 맨 앞의 자리 수가 4보다 2인 것이 더 작으므로, 2번 선택을 한다.
        // 다음 6을 스택에 넣는다.
        // 이 때 2가지 선택 중 하나를 해야한다.
        // 1. 4를 지우고 6을 넣는다. 26X
        // 2. 6을 쌓는다. 246
        // 두번째 자리 수가 6보다 4인 것이 더 작으므로, 2번 선택을 한다.
        // 스택에 3을 넣는다.
        // 이 때 2가지 선택 중 하나를 해야한다.
        // 1. 6을 지우고 3을 넣는다. 243
        // 2. 3을 지운다. 246
        // 세번째 자리 수가 6보다 3인 것이 더 작으므로, 1번 선택을 한다.
        // 이를 계속해서 반복해서, 가장 높은 자리의 수는 가장 작은 수. 
        // 가장 낮은 자리의 수는 가장 높은 수가 되도록 스택을 쌓으면 된다.

        // 만약에 필요한 높은 자리의 수를 전부 지웠는데 스택에 넣을 것이 더 남아있다면
        // 아랫자리수는 그대로 전부 채우면 되고
        // 스택에 넣은 것이 남지 않았는데 지워야할 수들이 남아있다면
        // 현재 스택에 들어있는 수는 모두 오름차순으로 정렬이 되어있는 것이기 때문에
        // 가장 낮은 자리 수부터 날리면 된다.
        

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