function P = cal_P(s)
    % input  s: B样条曲线参数s
    % output P: [x(s) y(s) |V(s)| theat(s)]

    C = [0 2 2 -2 -2 0; 0 0.5 2.5 2.5 0.5 0];
    V1 = [1; 0];
    V2 = [1; 0];
    L = 0.254; % 起点终点速度方向
    NC = length(C);

    % 增加控制点，保证轨迹经过起点和终点
    RC = [C(:,1)-V1*L, C(:,1), C(:,1)+V1*L, C(:,2:NC-1), 
          C(:,NC)-V2*L, C(:,NC), C(:,NC)+V2*L];

    N = length(RC);
    Out = 0;

    if(s >= N-3)
        I = N-4;
        Out = 1;
        dt = s - (N-3);
        s = 1;
    else
        I = fix(s);
        s = mod(s, 1);
    end
end
