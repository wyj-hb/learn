function [compress_A] = mysvd(A, ratio)
    % 函数作用：使用奇异值分解将矩阵A压缩到指定的特征比例
    % 输入变量
    %     A：要压缩的m*n维的矩阵
    %     ratio：要保留原矩阵的特征比例（100%表示不压缩）
    % 输出变量 
    %     compress_A: 压缩后的矩阵
    [U,S,V] = svd(A);   % U:m*m         S：m*n      V ： n*n
    eigs = diag(S);  % 得到S的主对角线元素，即矩阵A的奇异值，并将其保存到列向量中
    SUM = sum(eigs);  % 计算所有奇异值的总和
    temp = 0;   % 新建临时变量，用于下面的循环
    for  i = 1: length(eigs)  % 循环
        temp =temp + eigs(i);  % 每循环一次，就更新temp的值为原来的temp值+接下来的一个奇异值
        if (temp/SUM) > ratio  % 如果现在的比例超过了ratio,就退出循环
            break
        end
    end
    disp(['压缩后保留原矩阵的比例特征为：',num2str(roundn(100*temp/SUM,-2)),'%'])  %roundn(x,-2)可将x四舍五入到小数点后两位
    compress_A= U(:,1:i)*S(1:i,1:i)*V(:,1:i)';
end