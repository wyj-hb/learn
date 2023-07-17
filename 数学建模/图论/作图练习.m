% x = 0:pi/100:2*pi;
% y = sin(x);
% plot(x,y,'r-');
% xlabel("jay");
% ylabel("jolin");
% title("无与伦比");
% plot(y)
% 
% x = 0:pi/10:2*pi;
% y = sin(x);
% y1 = cos(x);
% plot(x,y,'g-',x,y1,'r-+');
% legend("sinx","cosx");%添加标签



x = 0:pi/10:2*pi;
y = sin(x);
plot(x,y,'g-');
hold on
y1 = cos(x);
plot(x,y1,'r-+');
