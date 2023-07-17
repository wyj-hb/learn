function[R,P] = fun_spearman(X,kind);
%X是矩阵 kind是阿尔法
[row,line] = size(X);%line是X的列数
[Y,Z] = sort(A,1,'ascend')
for j = 1:line
    qishi = 1;
    zhongzhi = 1;
    for i = 2:row
       if G(i,j) == G(i-1,j)
           zhongzhi = zhongzhi+1;
       else
           %此时不相等
           G(qishi:zhongzhi,j) = sum(qishi:zhongzhi)/(zhongzhi-qishi+1);
           qishi = i;
           zhongzhi = i;
       end
    end
end
for i=1:row
    for j = 1:line
        A(Z(i,j),j) = G(i,j);
    end
end
R = zeros(line,line);
for i = 1:line
    for j = 1:line
        %分别对每行每列数据进行处理
        if i == j
            R(i,j) = 1;
        else
            z = (A(:,i) - A(:,j)).*(A(:,i) - A(:,j));
            R(i,j) = 1 - (line*sum(z)) / (row*(row^2 -1));
        end
    end
end




    