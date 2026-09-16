load("data_u_y_tf1.mat")
t = simout.time;
u = simout.signals.values(:,1);
y = simout.signals.values(:,2);


idx_inicio = find(u > 0, 1, 'first');
t_inicio = t(idx_inicio);
t_fin = t_inicio + 30;

idx = t >= t_inicio & t <= t_fin;
t = t(idx) - t_inicio;
u = u(idx);
y = y(idx);

% Graficar
plot(t, y,t,u, 'LineWidth', 2)
xlabel('Time (s)')
ylabel('Amplitud')
legend("velocidad (RPM/s)", "PWM (%)")
title("Curva reaccion del motor dc")
grid on



%%
s = tf('s');

Gp = tf(tf1.Numerator, tf1.Denominator);
Gp_g=Gp*6;
%Sp=ss(Gp);

Ts = 0.01;


%Sp=(-13.46,26.07,1,0,Ts);
