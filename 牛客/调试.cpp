//#include<iostream>
//#include<vector>
//#include<stdio.h>
//using namespace std;
//int length = 0;
//int main()
//{
//    int n;
//    cin >> n;
//    int x;
//    vector<int> v(n + 1, 0);
//    for (int i = n;i >= 0;i--)
//    {
//        cin >> x;
//        v[i] = x;
//    }
//    for (int i = n;i >= 0;i--)
//    {
//        if (i == n)
//        {
//            if (v[i] < 0)
//            {
//                if (v[i] == -1)
//                {
//                    printf("-x^%d", i);
//                    length++;
//                    continue;
//                }
//                printf("%dx^%d", v[i], i);
//                length++;
//            }
//            else if (v[i] == 0)
//            {
//                continue;
//            }
//            else if (v[i] == 1)
//            {
//                printf("x^%d", i);
//                length++;
//            }
//            else
//            {
//                printf("%dx^%d", v[i], i);
//                length++;
//            }
//        }
//        else
//        {
//            if (i > 1)
//            {
//                if (v[i] < 0)
//                {
//                    if (v[i] == -1)
//                    {
//                        printf("-x^%d", i);
//                        length++;
//                        continue;
//                    }
//                    printf("%dx^%d", v[i], i);
//                    length++;
//                }
//                else if (v[i] == 0)
//                {
//                    continue;
//                }
//                else if (v[i] == 1 && length == 0)
//                {
//                    printf("x^%d", i);
//                    length++;
//                }
//                else if (v[i] == 1 && length != 0)
//                {
//                    printf("+x^%d", i);
//                    length++;
//                }
//                else if (v[i] != 1 && length != 0)
//                {
//                    printf("+%dx^%d", v[i], i);
//                    length++;
//                }
//                else if (v[i] != 1 && length == 0)
//                {
//                    printf("%dx^%d", v[i], i);
//                    length++;
//                }
//            }
//            else if (i == 0)
//            {
//                if (v[i] == 0)
//                {
//                    continue;
//                }
//                else
//                {
//                    if (v[i] > 0 && length == 0)
//                    {
//                        printf("%d", v[i]);
//                    }
//                    if (v[i] > 0 && length != 0)
//                    {
//                        printf("+%d", v[i]);
//                    }
//                    if (v[i] < 0)
//                    {
//                        printf("%d", v[i]);
//                    }
//                }
//            }
//            else if (i == 1)
//            {
//                if (v[i] == 0)
//                {
//                    continue;
//                }
//                else
//                {
//                    if (v[i] == 1 && length == 0)
//                    {
//                        printf("x");
//                        length++;
//                    }
//                    else if (v[i] == 1 && length != 0)
//                    {
//                        printf("+x");
//                        length++;
//                    }
//                    else if (v[i] > 0 && length == 0)
//                    {
//                        printf("%dx", v[i]);
//                        length++;
//                    }
//                    else if (v[i] > 0 && length != 0)
//                    {
//                        printf("+%dx", v[i]);
//                        length++;
//                    }
//                    else if (v[i] < 0)
//                    {
//                        if (v[i] == -1)
//                        {
//                            printf("-x");
//                            length++;
//                            continue;
//                        }
//                        printf("%dx", v[i]);
//                        length++;
//                    }
//                }
//            }
//        }
//    }
//}
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//vector<int> v1(3, 0);
//bool cmp(vector<int> v1, vector<int> v2)
//{
//    if (v1.front() == v2.front() && v1.back() != v2.back())
//    {
//        return v1.back() > v2.back();
//    }
//    else if (v1.front() == v2.front() && v1.back() == v2.back())
//    {
//        return v1[1] < v2[1];
//    }
//    return v1.front() > v2.front();
//}
//int main()
//{
//    int n, x;
//    cin >> n;
//    vector<vector<int>> v(n, v1);
//    int arr[n][3];
//    for (int i = 0;i < n;i++)
//    {
//        for (int j = 0;j < 3;j++)
//        {
//            cin >> x;
//            arr[i][j] = x;
//        }
//    }
//    int sum = 0;
//    for (int i = 0;i < n;i++)
//    {
//        for (int j = 0;j < 3;j++)
//        {
//            sum += arr[i][j];
//        }
//        v[i][0] = sum;
//        v[i][2] = arr[i][0];
//        v[i][1] = i + 1;
//        sum = 0;
//    }
//    sort(v.begin(), v.end(), cmp);
//    for (int i = 0;i < 5;i++)
//    {
//        cout << v[i][1] << " " << v[i][0] << endl;
//    }
//}
//#include<iostream>
//#define int long long
//using namespace std;
//bool panduan(int x, int y)
//{
//    int size = min(x, y);
//    //判断两个数是否互质
//    for (int i = 2;i <= size;i++)
//    {
//        if (x % i == 0 && y % i == 0)
//        {
//            return 0;
//        }
//    }
//    return 1;
//}
//int ans = 0;
//int bns = 0;
//signed main()
//{
//    //使用枚举法
//    int A, B, L;
//    cin >> A >> B >> L;
//    for (int i = L;i >= 1;i--)
//    {
//        for (int j = 1;j <= L;j++)
//        {
//            if (!panduan(i, j))
//            {
//                continue;
//            }
//            if (i * 1.0 / j >= A * 1.0 / B)
//            {
//                if (ans == 0)
//                {
//                    ans = i;
//                    bns = j;
//                }
//                else
//                {
//                    //现在已经存在
//                    if (i * 1.0 / j < ans * 1.0 / bns)
//                    {
//                        ans = i;
//                        bns = j;
//                    }
//                }
//            }
//            else
//            {
//                break;
//            }
//        }
//    }
//    cout << ans << " " << bns << endl;
//}