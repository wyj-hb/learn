%例题1
f = ones(6,1);
intcon = 1:6;
A = zeros(7,6);
A(1,1:3) = -1;
A(2,2) = -1;
A(2,4) = -1;
A(3,3) = -1;
A(3,5) = -1;
A(4,4) = -1;
A(4,6) = -1;
A(5,5) = -1;
A(5,6) = -1;
A(6,1) = -1;
A(7,2)= -1;A(7,4)= -1;A(7,6) = -1;
b = ones(7,1);
lb = zeros(6,1);
ub = ones(6,1);
x = intlinprog(f,intcon,A,-b,[],[],lb,ub);
%例题2
intcon = 1:6;
c = [4 2 3 4;6 4 5 5;7 6 7 6;7 8 8 6;7 9 8 6;7 10 8 6];
c = c(:);%获得第一台、第二台....可以创造的利润
A = zeros(4,24);
for i=1:6
    A(i,i:6:24) = -1;
end
b = ones(6,1);
Aeq = zeros(4,24);
beq = ones(4,1);
for i=1:4
    Aeq(i,(i-1)*6+1:(i-1)*6+6) = -1;
end
lb = zeros(24,1);
ub = ones(24,1);
x = intlinprog(-c,intcon,Aeq,-beq,A,-b,lb,ub);
x = reshape(x,[6,4]);
x
%例题3
s = [];
for i=0:2%最大为2
    for j=0:3%最大为3
        for k=0:6%最大为6
            if 2.9*i + 2.1*j + k>5.9 & 2.9*i +2.1*j + k<=6.9
                s = [s;[i,j,k,6.9-(2.9*i+2.1*j+k)]];
            end
        end
    end
end
%找出所有可用方案
[sy,lnd]=sort(s(:,4));
s = s(lnd,:);
%保证100套钢架且原料最省
f = [1;1;1;1;1;1;1];
intcon = 1:7;
Aeq = [1,2,0,0,0,0,1;0,0,3,2,1,0,1;4,1,0,2,4,6,1];%3*7
beq = [100;100;100];
lb = [0;0;0;0;0;0;0];
ub = [inf;inf;inf;inf;inf;inf;inf];
[x,y] = intlinprog(f,intcon,[],[],-Aeq,-beq,lb,ub);
