%例题1
%已知（1,0)为极小值点,(-3,2)为极大值点
syms x y;
f = x^3-y^3+3*x^2+3*y^2-9*x;
df = jacobian(f);%[3*x^2 + 6*x - 9, - 3*y^2 + 6*y]
d2f = jacobian(df);%求二阶偏导
[xx,yy] = solve(df,[x,y]);%求驻点
xx=double(xx);
yy = double(yy);
for i=1:length(xx)
    a = subs(d2f,{x,y},{xx(i),yy(i)});
    b=eig(a);%求a的特征值
    z = subs(f,{x,y},{xx(i),yy(i)});%计算极值
    if all(b>0)
        fprintf('(%f,%f)是极小值点，对应的极小值为%f\n',xx(i),yy(i),z);
    elseif all(b<0)
        fprintf('(%f,%f)是极大值点，对应的极大值为%f\n',xx(i),yy(i),z);
    elseif any(b>0) & any(b<0)
        fprintf('(%f,%f)不是极值点%f\n',xx(i),yy(i),z);
    else
        fprintf('(%f,%f)无法判断\n',xx(i),yy(i));
    end
end
%例题2
f = @(x) x(1)^3-x(2)^3+3*x(1)^2+3*x(2)^2-9*x(1);
g = @(x) -f(x);
[xy1,z1] = fminunc(f,rand(2,1));
[xy2,z2] = fminunc(g,rand(2,1));
z2 = -z2;
%例题3
[x,y] = fminunc('fun5',2);

         
        
    
