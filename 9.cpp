class Solution {
public:
    bool isPalindrome(int x) {
        if (x <0)
            return false;
        
        int count = 0;
        char digit[10] = {0};
        while (x != 0)
        {
            int temp = x / 10;
            digit[count++] = x - temp * 10;
            x = temp;
        }
        
        int half_count = count / 2;
        for (int i=0;i<half_count; i++)
        {
            if (digit[i] != digit[count-i])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    bool ret = solution.isPalindrome(121);
    ret = solution.isPalindrome(-121);
    ret = solution.isPalindrome(10);
    return 0;
}