%例题一
x = unifrnd(0,12,[1,10000000]);%0-12产生10000000个点
y = unifrnd(0,9,[1,10000000]);
pinshu = sum(y < x.^2 & x<=3) + sum(y<12-x & x>=3);
area = 12 * 9 * pinshu/10.^7;
%例题2
rand('state',sum(clock*100));
p0 = 0;
tic;%开始计时
for i=1:10^6
    x = randi([0,99],1,5);%生成一个由0-99数字组成的1*5矩阵
    [f,g] = mengte(x);
    if all(g <= 0)%满足条件的
        if p0<f
            x0 = x;
            p0 = f;
        end
    end
end
toc      