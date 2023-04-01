#include<iostream>
using namespace std;
#include<vector>
//1.给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
//不占用额外内存空间能否做到？
// 思想:顺时针先旋转对角线，再旋转各行的元素，逆时针相反
//class Solution {
//public:
//    void rotate(vector<vector<int>>& matrix) {
//        int n = matrix.size();
//        for (int i = 0;i < n;i++)
//        {
//            for (int j = i + 1;j < n;j++)
//            {
//                swap(matrix[i][j], matrix[j][i]);
//            }
//        }
//        for (auto& y : matrix)
//        {
//            reverse(y.begin(), y.end());
//        }
//    }
//};
//2.编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
//void setZeroes(vector<vector<int>>& matrix) {
//    int arr1[10];
//    int arr2[10];
//    for (int i = 0;i < matrix.size();i++)
//    {
//        for (int j = 0;j < matrix.size();j++)
//        {
//            if (matrix[i][j] == 0)
//            {
//                arr1[i] = 1;
//                arr2[j] = 1;
//            }
//        }
//    }
//    for (int i = 0;i < matrix.size();i++)
//    {
//        if (arr1[i] == 1)
//        {
//            for (int j = 0;j < matrix.size();j++)
//            {
//                matrix[i][j] = 0;
//            }
//        }
//        if (arr2[i] == 1)
//        {
//            for (int j = 0;j < matrix.size();j++)
//            {
//                matrix[j][i] = 0;
//            }
//        }
//    }
//}
//int main()
//{
//    vector<vector<int>> v1;
//    vector<int> v2{ 0,1,2,0 };
//    vector<int> v3{ 3,4,5,2 };
//    vector<int> v4{ 1,3,1,5 };
//    int arr[3][4] = { 0,1,2,0 ,3,4,5,2,1,3,1,5 };
//    v1.push_back(v2);
//    v1.push_back(v3);
//    v1.push_back(v4);
//    setZeroes(v1);
//}
//3.给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
//class Solution
//{
//public:
//    vector<int> findDiagonalOrder(vector<vector<int>>& mat)
//    {
//        int row = mat.size();
//        vector<int> v1;
//        int col = mat[0].size();
//        int x = 1;//遍历次数
//        for (int i = 0;i < row + col - 1;i++)
//        {
//            if (i % 2)
//            {
//                int c = (i < col) ? i : col - 1;
//                int r = i - c;
//                while (c >= 0 && r < row)
//                    v1.push_back(mat[r++][c--]);
//            }
//            else
//            {
//                int r = (i < row) ? i : row - 1;
//                int c = i - r;
//                while (c < col && r >= 0)
//                    v1.push_back(mat[r--][c++]);
//            }
//        }
//        return v1;
//    }
//};
//1）先得出遍历的次数，也就是对角线的条数为i = n + m - 1，所以数组遍历条件也就是i < n + m - 1。
//    （2）在看图，对角线上的每个元素坐标之和为i, 也就是元素的坐标xy与i的关系为：x + y = i
//    （3）如何遍历？看图中，偶数对应的对角线上的元素是从下往上遍历，而奇数对应的对角线上的元素是从上往下遍历，那么只要确定遍历的起始点和结束点就好啦！我们先看偶数对角线的起点和终点，因为奇数对角线和它相反，知道了偶数的，也不难得出奇数的的。
//    当i < n - 1时，起始点坐标x = i，如1的x坐标为0，i也为0, 结束点的横坐标x = 0
//    当i >= n - 1时，起始点坐标x = n - 1, 如2的x坐标为2，i也为2, 结束点的纵坐标y = m - 1, 根据（2）中的关系式, 所以得出横坐标x = i - (m - 1)
//    所以偶数对角线遍历时起始点的x的坐标为min(i, n - 1)，结束点的x坐标为max(0, i - (m - 1)), 而坐标y就是i - x