#include <string.h>
//给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
//元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。
//思路:先去点空格，空格的ASCLL值一定小于32,接着暴力比较就行
char* reverseVowels(char* s)
{
    int len = strlen(s);
    int y = len;
    int k = 0;
    for (k = 0;k < len;k++)
    {
        if (s[k] < 32)
        {
            len--;
        }
    }
    int i = 0;
    int x = 0;
    int j = 0;
    for (i = 0;i < len;i++)
    {
        if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') || (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'))
        {
            for (j = len - 1 - x;j > i;j--)
            {
                if ((s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') || (s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U'))
                {
                    int tmp = 0;
                    tmp = s[i];
                    s[i] = s[j];
                    s[j] = tmp;
                    x++;
                    break;
                }
                x++;
            }
        }
    }
    return s;
}
int main()
{
    char s[] = { "hello" };
    reverseVowels(s);

}