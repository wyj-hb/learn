%例题一
f = [-2;-3;5];
A = [-2,5,-1;1,3,1];
b = [-10;12];
Aeq = [1,1,1];
beq = 7;
lb = [0,0,0];
[x,y] = linprog(f,A,b,Aeq,beq,lb)
x;
y = -y;
disp(y)
%例题2
f = [2;3;1];
a = [1,4,2;3,2,0];
b = [8;6];
[x,y] = linprog(f,-a,-b,[],[],zeros(3,1));
%例题3
f = [1;2;3;4;1;2;3;4];
a = [1,-1,-1,1;1,-1,1,-3;1,-1,-2,3];
a = [a,-a];
b = [-2;-1;-1/2];
[x,y] = linprog(f,a,b,[],[],zeros(8,1));
z = x(1:4)-x(5:end);
%作业1
f = [-3;1;1];
a = [1,-2,1;4,-1,-2];
b = [11;-3];
aeq = [-2,0,1];
beq = 1;
[x,y] = linprog(f,a,b,aeq,beq,zeros(3,1));
y = -y;
%作业2
f = [1;2;3;4;1;2;3;4];
a = [1,-1,-1,1;1,-1,1,-3;1,-1,-2,3];
a = [a,-a];
b =[0;1;-1/2];
[x,y] = linprog(f,[],[],a,b,zeros(8,1));
z = x(1:4)-x(5:end);
%例题4
%归一化
f = [-0.05,-0.27,-0.19,-0.185,-0.185];
a = 0;%假定的最大风险率
hold on;
%从0开始，步长为0.01
while a<0.05
    f = [-0.05,-0.27,-0.19,-0.185,-0.185];
    A = [zeros(4,1),diag([0.025,0.015,0.055,0.026])];%diag函数用来构造对角矩阵
    b = a*ones(4,1);%ones函数用来构造全是1的矩阵
    Aeq = [1,1.01,1.02,1.045,1.065];
    beq = 1;
    [x,y] = linprog(f,A,b,Aeq,beq,zeros(5,1));
    y = -y;
    plot(a,y,'*k');
    a = a+0.001;
end
xlabel('a');
ylabel('b');
    