mass = 1;
b = 3;
k = 1;


% LQR section
Q  = [1 0; 0 1]*1;
Qf = [1 0; 0 1];
R  = eye(1)*1e-2;

Ac = [0 1;...
     -k/mass -b/mass];
Bc = [0;1];


% Fooooooorza Iris!