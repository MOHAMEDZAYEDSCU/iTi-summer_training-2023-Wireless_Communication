clc;
clear all;

Ts = 0.01;
fc = 1;
stream_size = 5;

bit_stream = randi([0,1], 1, stream_size);
t = 0 : Ts : length(bit_stream) - Ts;

carrier = cos(2 * pi * fc * t);

rep = repmat(bit_stream, 1 / Ts , 1);
sig = reshape(rep, 1, []);

modulation = carrier.*(sig);

figure;
subplot(211); stem(bit_stream);
title('Original Bit Stream');

subplot(212); plot(modulation);
title('Modulated Signal');
xlabel('Time');
ylabel('Amplitude');
