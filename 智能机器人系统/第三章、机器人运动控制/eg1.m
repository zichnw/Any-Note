% 四个控制点
C = [0 1 2 3
     0 1 1 0];

% 归一化路程
s = 0:0.01:1; 

% 样条函数
f1s = (1-s).^3 / 6;
f2s = (3*s.^3 - 6*s.^2 + 4) / 6;
f3s = (-3*s.^3 + 3*s.^2 + 3*s + 1) / 6;
f4s = s.^3 / 6;

% 四个控制点的B样条曲线
Ps = C(:,1)*f1s + C(:,2)*f2s + C(:,3)*f3s + C(:,4)*f4s;

figure(1)
plot(C(1,:), C(2,:), 'r*', Ps(1,:), Ps(2,:), 'b');
legend('Control Points', 'B-Spline Curve');
title('B-Spline Curve with 4 Control Points');

%% 有多个控制点的B样条曲线
Cn = [0 1   2   -2  -1   0
      0 0.3 2.5 2.5 4.7  5];

% 归一化路程
s = 0:0.01:1; 

% 样条函数
f1s = (1-s).^3 / 6;
f2s = (3*s.^3 - 6*s.^2 + 4) / 6;
f3s = (-3*s.^3 + 3*s.^2 + 3*s + 1) / 6;
f4s = s.^3 / 6;

% N个控制点
N = length(Cn);

figure(2)
mycolor = 'mbc';
plot(Cn(1,:), Cn(2,:), 'r*');
hold on;
for i = 1 : N-3
    Ps = Cn(:,i)*f1s + Cn(:,i+1)*f2s + Cn(:,i+2)*f3s + Cn(:,i+3)*f4s;
    plot(Ps(1,:), Ps(2,:), mycolor(mod(i,3)+1));
end
legend('Control Points', 'B-Spline Curve');
title('B-Spline Curve with Multiple Control Points');
