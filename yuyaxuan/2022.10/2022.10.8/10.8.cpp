#include <stdio.h>
//编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
//void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
//{
//    int i, j;
//    int z = *matrixColSize;
//    int tmp = 0;
//    int cmp = 0;
//    int x[1000] = { 0 };//定义两个一维数组来记录等于0的i,j
//    int y[1000] = { 0 };
//    for (i = 0;i < matrixSize;i++)//遍历寻找
//    {
//        for (j = 0;j < z;j++)
//        {
//            if (matrix[i][j] == 0)
//            {
//                x[i] = i + 1;
//                y[j] = j + 1;
//                if (i > tmp)//通过比较得出最终长度
//                {
//                    tmp = i;
//                }
//                if (j > cmp)
//                {
//                    cmp = j;
//                }
//            }
//        }
//    }
//    for (i = 0;i <= tmp;i++)//根据i,j值进行行列填0操作
//    {
//        if (x[i] == i + 1)
//        {
//            for (j = 0;j < z;j++)
//            {
//                matrix[i][j] = 0;
//            }
//        }
//    }
//    for (j = 0;j <= cmp;j++)
//    {
//        if (y[j] == j + 1)
//        {
//            for (i = 0;i < matrixSize;i++)
//            {
//                matrix[i][j] = 0;
//            }
//        }
//    }
//}
//int main()
//{
//    int arr[3][3] = { {1,1,1},{1,0,1},{1,1,1} };//定义二维数组
//    int* b[3] = { arr[0],arr[1],arr[2] };//int*
//    int** p = &(*b);//int**
//    int  matrixColSize = 3;
////    int* x = &matrixColSize;
////    setZeroes(p,3,x);
//
//}
//给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
//int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize)
//{
//    if (matSize == 0)
//    {
//        //矩阵为空，返回0                                
//        *returnSize = 0;
//        return NULL;
//    }
//    int len = matSize * (*matColSize);
//    *returnSize = len;
//    int* returnNums = (int*)malloc(sizeof(int) * len);//无法带入变量为参数，所以动态开辟空间
//    int row = 0;
//    int col = 0;
//    int index = 0;
//
//    //循环遍历矩阵
//    while (index < len)
//    {
//        returnNums[index] = mat[row][col];
//        if ((row + col) % 2 == 0)
//        {                                                   //下标和为偶数，向右上遍历
//            if (col < (*matColSize) - 1)//未到边界
//            {
//                col++;
//                if (row > 0)
//                    row--;
//            }
//            else
//            {
//                row++;
//            }
//        }
//        else
//        {                                              //下标和为奇数，向左下遍历
//            if (row < matSize - 1)
//            {
//                row++;
//                if (col > 0)
//                    col--;
//            }
//            else
//                col++;
//        }
//        index++;
//    }
//    return returnNums;
//}
//编写一个函数来查找字符串数组中的最长公共前缀。
//如果不存在公共前缀，返回空字符串 ""。
//char* longestCommonPrefix(char** strs, int strsSize) {
//    int i = 1, j = 0, flag = 0;
//    if (strsSize < 2) {//字符串的长度为1/0，返回它本身
//        return strs[0];
//    }
//    for (;;j++) {//除非flag为1才能退出，总循环只改变j的值，因为i每次比较从1开始，而j比较完之后++比较后面的字符串
//        for (;i < strsSize;i++) {//改变比较的字符串，从第二个开始，本次比的是下标为j的位置各字符串是否相同
//            if (*(strs[i] + j) == '\0' || *(strs[i] + j) != *(strs[0] + j))//如果取到头，进入；如果取到的值与第一个所相应的不相等，进入
//            {
//                flag = 1;
//                break;
//            }
//        }
//        if (flag == 1) {
//            *(strs[0] + j) = '\0';//只要没比完或者比的字符串不相等就会进入，这是index=j的位置要么为NULL，要么该值不符合条件，加上/0形成字符串
//            break;
//        }
//        i = 1;
//    }
//    return strs[0];
//}
//给你一个字符串 s，找到 s 中最长的回文子串。回文:从左往右和从右往左读一样
char* longestPalindrome(char* s)
{
    int left = 0, right = strlen(s);
    int maxSize = 1;
    int t = 0;
    int start = 0;
    if (right <= 1)
        return s;
    for (left = 0;s[left] != '\0';left++)//定义开始比较的值，如果不满足回文，加1跳到下一个
    {
        t = 0;//判断是否有最大值替换；
        if (right - left + 1 <= maxSize)
        {
            break;//如果数组剩余字符数量少于maxSize,直接跳出循环；
        }
        for (right = right - 1;right > left;right--)//右边往前遍历数组；
        {
            if (s[left] == s[right])
            {
                for (int i = left, j = right;i <= j;i++, j--)
                {
                    if (i == j || (i == j - 1 && s[i] == s[j]))
                    {
                        if (maxSize < (right - left + 1))
                        {
                            maxSize = right - left + 1;
                            start = left;
                            t = 1;//maxSize修改值之后退出此外层循环；
                        }
                    }
                    if (s[i] != s[j])//判断是否是回文串
                    {
                        break;
                    }
                }
            }
            if (t == 1)
            {
                break;
            }
        }
        right = strlen(s);//一直从最右边开始
    }
    s[start + maxSize] = '\0';//把后面的截掉了
    return s + start;
}