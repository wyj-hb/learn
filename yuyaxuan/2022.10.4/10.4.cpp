//给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。
//如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。以长度为 2 的整数数组
//[index1, index2] 的形式返回这两个整数的下标 index1 和 index2。你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用
//相同的元素。你所设计的解决方案必须只使用常量级的额
//int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
//{
//    int x = 0;
//    int i = 0;
//    *returnSize = 2;
//    int len = 0;
//    int* arr = (int*)malloc(2 * sizeof(int));
//    int y = numbersSize - 1;
//    while (x < y)
//    {
//        while (numbers[x] + numbers[y] < target)
//        {
//            x++;
//        }
//        while (numbers[x] + numbers[y] > target)
//        {
//            y--;
//        }
//        if (numbers[x] + numbers[y] == target)
//        {
//            arr[0] = x + 1;
//            arr[1] = y + 1;
//            return arr;
//        }
//    }
//    return arr;
//    free(arr);
//}
#include <cstddef>
#include <string.h>
bool isPalindrome(char* s)
{
    if (s == NULL)
    {
        return true;
    }
    int len = strlen(s);
    int i = 0;
    int index = 0;
    for (i = 0;i < len;i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + ('a' - 'A');
        }
        else if (s[i] <= '9' && s[i] >= '1' && s[i] >= 'a' && s[i] <= 'z')
        {
            s[index++] = s[i];
        }
    }
    int j = 0;
    bool flag = true;
    int x = index - 1;
    for (j = 0;j < index;j++)
    {
        if (s[j] == s[x] || x == j)
        {
            x--;
            continue;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}
int main()
{
    char s[] = "race a car";
    bool isPalindrome(s);
}