%非线性规划问题
clear;clc
A = [-1 -2 0];
b = -1;
lb = [0 -inf -inf];
ub = [inf inf inf];
[a,b] = fmincon(@myfun,[2.3275    0.1829   -3.4175],A,b,[],[],lb,ub,@nonfun11)
%使用蒙特卡洛模拟
n = 100000;
a = unifrnd(0,3,n,1);
b = unifrnd(-2,2,n,1);
c = (repmat(2,n,1)-a.*a);
fmin = -inf;
for i=1:n
    x = [a(i), b(i), c(i)];  %构造x向量, 这里千万别写成了：x =[x1, x2, x3]
    if (x(1)+2*x(1)^2+x(2)+2*x(2)^2+x(3)-10<=0) & (x(1)+x(1)^2+x(2)+x(2)^2-x(3)-50<=0) & (2*x(1)+x(1)^2+2*x(2)+x(3)-40<=0) & (x(1)+2*x(2)>=1)   % 判断是否满足条件
        result =2*x(1)+3*x(1)^2+3*x(2)+x(2)^2+x(3) ;  % 如果满足条件就计算函数值
        if  result  > fmin  % 如果这个函数值大于我们之前计算出来的最大值
            fmin = result;  % 那么就更新这个函数值为新的最大值
            x0 = x;  % 并且将此时的x1 x2 x3更新为初始值
        end
    end
end

