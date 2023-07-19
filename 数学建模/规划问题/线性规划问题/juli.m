function len = juli(x1,x2)
%返回x1 x2之间的距离 假设x1 x2均为行向量
len = ((x1(1)-x2(1))^2+(x1(2)-x2(2))^2)^0.5;