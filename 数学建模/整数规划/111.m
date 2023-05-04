%例题一
c = [3 8 2 10 3;8 7 2 9 7;6 4 2 7 5;8 4 2 3 5;9 10 6 9 10];%指派矩阵,每一个元素的含义的第i个人做第j项工作
c = c(:);%按照列顺序形成25*1的列向量
a = zeros(10,25);
intcon = 1:25;
for i=1:5
    a(i,(i-1)*5+1:5*i) = 1;%每项工作只能有1个人做
    a(5+i,i:5:25) = 1;%每个人只能做一项工作
end
b = ones(10,1);
lb = zeros(25,1);
ub = ones(25,1);%每一个x要么为0要么为1
x = intlinprog(c,intcon,[],[],a,b,lb,ub);
x = reshape(x,[5,5])
%例题2
intcon = 3;%3代表我们的决策变量是x3
f = [-3;-2;-1];
A = [1,1,1];
b = 7;
Aeq = [4,2,1];
beq = 12;
lb = zeros(3,1);
ub = [inf;inf;1];
x = intlinprog(f,intcon,A,b,Aeq,beq,lb,ub);%inf是无穷大的意思
x = reshape(x,[1,3]);



