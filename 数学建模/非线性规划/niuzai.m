%例题1
xishu = [1,-1,2,-3];
x0 = roots(xishu);
%使用符号法
syms x
epn = x^3 - x^2 + 2*x==0;
x0 = solve(epn,x);
x0 = vpa(x0,5)%其中5设置的是有效位数是5
%使用fsolve函数
y = @ (x) x^3-x^2+2*x-3;
x = fsolve(y,rand(1))%求得的是给定初始值附近的一个零点


