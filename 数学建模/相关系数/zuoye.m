% clear;clc
% A = xlsread("八年级男生体测数据.xls");
% %第一步 描述性统计
% %min max mean median skewness(偏度) kurtosis(峰度) 
% [a,b] = size(A);
% c = zeros(6,b);%第i列，6想描述性统计
% c(1,:) = min(A);
% c(2,:) = max(A);
% c(3,:) = mean(A);
% c(4,:) = median(A);
% c(5,:) = skewness(A);
% c(6,:) = kurtosis(A);
% %第二步 做线性相关图
% %测试：身高与体重两行数据做相关图
% x = A(:,1);
% y = A(:,2);
% plot(x,y,"ro");
% %第三步 线性无关因此选择斯皮尔曼系数
% %检验正态性
% %h 与 p
% a = size(A,2);%A的列数
% g1 = zeros(1,a);
% g2 = zeros(1,a);
% for i=1:a
%     [h,p] = jbtest(A(:,i),0.05);
%     %h为相关系数，p为比较值
%     g1(i) = h;
%     g2(i) = p;
% end
% disp(g1);
% disp(g2);
% %因此选择斯皮尔曼系数
% [Y1,Y2] = corrcoef(A)
% [R,P] = corr(A,"type","Spearman")
% [a,b] = size(R);
% c = zeros(a,b);
% for i=1:a
%     for j = 1:b
%         if i~=b
%             if 1-normcdf((R(i,j)*sqrt(a-1))*2) <P(i,j)
%                 c(i,j) = 0;%表示符合
%             else
%                 c(i,j) = 1;
%             end
%         end
%     end
% end
A = xlsread("八年级男生体测数据.xls");
[R,P] = corr(A,"type","Spearman");
[R,P] = fun_spearman(A);  


    