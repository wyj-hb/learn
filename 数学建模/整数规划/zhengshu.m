%例题1
f = [30 25 18 32 27 19 22 26;29 31 19 18 21 20 30 19;28 29 30 19 19 22 23 26;
    29 30 19 24 25 19 18 21;21 20 18 17 16 14 16 18];
f = f(:);
%A*x<=b;
A = zeros(8,40);
b = ones(8,1);
for i=1:8
    A(i,(i-1)*5+1:(i-1)*5+5)=1;
end
Aeq = zeros(5,40);
beq = ones(5,1);
for i=1:5
    Aeq(i,i:5:40) = 1;
end
lb = zeros(40,1);
ub = ones(40,1);
intcon = 1:40;
x = intlinprog(f,intcon,A,b,Aeq,beq,lb,ub);
x = reshape(x,[5,8]);