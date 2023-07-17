
figure(1);
plot(X,Y,'ro');
xlabel("X的值");
ylabel("Y的值");
[a,b]= xy(X,Y);
hold on;%表格位置不动
grid on;%产生网格线
xx = 2.5:0.1:7;
yy = a*xx+b;
plot(xx,yy,"b-");
f=@(x)a*x+b;
fplot(f,[2.5,7]);
legend('样本数据','拟合函数','location','SouthEast')
y_hat = a*x+b; % y的拟合值
SSR = sum((y_hat-mean(Y)).^2)  % 回归平方和
SSE = sum((y_hat-Y).^2) % 误差平方和
SST = sum((Y-mean(Y)).^2) % 总体平方和
SST-SSE-SSR   % 5.6843e-14  =   5.6843*10^-14   matlab浮点数计算的一个误差
R_2 = SSR / SST


clear;clc
year = 1790:10:2000;
population = [3.9,5.3,7.2,9.6,12.9,17.1,23.2,31.4,38.6,50.2,62.9,76.0,92.0,106.5,123.2,131.7,150.7,179.3,204.0,226.5,251.4,281.4];
plot(year,population,'o')
cftool  % 拟合工具箱