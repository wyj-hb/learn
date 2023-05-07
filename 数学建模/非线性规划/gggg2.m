% options = optimset('GradObj','on');%设置所有参数及其值，未设置的为默认值,该句含义为该参数为
%用户定义的目标函数的梯度。
[x,y] = fminunc('fun3',rand(1,2));
%使用二阶导数
options = optimset('GradObj','on','Hessian','on');
[x,y] = fminunc('fun4',rand(1,2),options);