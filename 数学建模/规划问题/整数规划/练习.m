% %例1
% clc;clear;
% c = [-20 -10];
% intcon = [1 2];
% A = [5 4;2 5];
% b =[24 13]';
% lb = [0 0]';
% [a,b] = intlinprog(c,intcon,A,b,[],[],lb)
% %例2
% c = [18 23 5];
% intcon = 3;
% A=[107,500,0;
%       72,121,65;
%       -107,-500,0;
%       -72,-121,-65];
% b=[50000;2250;-500;-2000];
% lb = [0 0 0]';
% [a,b] = intlinprog(c,intcon,A,b,[],[],lb)
% %例3
% c = [-3 -2 -1];
% intcon = 3;
% A = [1 1 1]
% b =7;
% Aeq = [4 2 1];
% beq = 12;
% lb = [0 0 0]';
% ub = [inf inf 1]';
% [a,b] = intlinprog(c,intcon,A,b,Aeq,beq,lb,ub);

%背包问题
% c = [-540 -200 -180 -350 -60 -150 -280 -450 -320 -120];
% A = [6 3 4 5 1 2 3 5 4 2];
% b = 30;
% intcon = [1:1:10];
% lb = zeros(10,1);
% ub =ones(10,1);
% [a,b] = intlinprog(c,intcon,A,b,[],[],lb,ub)

%指派问题
% 5*4个未知量 xij = 1表示第i个人参加第j项运动
% clear;
% c = [66.8 75.6 87 58.6 57.2 66 66.4 53 78 67.8 84.6 59.4 70 74.2 69.6 57.2 67.4 71 83.8 62.4]
% intcon = (1:1:20);
% A = zeros(5,20);
% b = [1 1 1 1 1]';
% a = 0;
% for i=1:5
%     A(i,a*4+1:(a+1)*4) = 1;
%     a = a+1;
% end
% Aeq = zeros(4,20);
% beq =[1 1 1 1]';
% for i=1:4
%     Aeq(i,i:4:20) = 1;
% end
% lb = zeros(20,1);
% ub = ones(20,1);
% [a,b] = intlinprog(c,intcon,A,b,Aeq,beq,lb,ub);
 
%钢管切割问题
c = [1 1 1 1 1 1 1];
intcon = [1:1:7];
A = [-1 -2 0 0 0 -1 0;0  0 -3 -2 -1 -1 0;-4 -1 0 -2 -4 -1 -6];
b = [-100 -100 -100]';
lb = [0 0 0 0 0 0 0]';
[x,y] = intlinprog(c,intcon,A,b,[],[],lb)





