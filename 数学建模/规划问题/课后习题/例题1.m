clear;clc
%整数规划
c = [1 1 1 1 1 1]
intcon = [1:1:6];
A = zeros(6,6);
for i=1:6
    if i>1
       A(i,i-1:1:i) = -1;
    else
        A(i,1) = -1;
    end
end
b = [60 70 60 50 20 30]';
b = b*-1;
lb = [0 0 0 0 0 0 0]';
[x,y] = intlinprog(c,intcon,A,b,[],[],lb)        

   
