clear all;
close all;
clc;

Fc = 1;
M1 = 4;
M2 = 16;

stream_size = 10000;
SNR = 1 : 1 : 20;
bits_per_symbol1 = log2(M1);
bits_per_symbol2 = log2(M2);

BER1 = [];
BER2 = [];
data = randi([0, 1], stream_size, 1);

stream_symbols1 = reshape(data, stream_size / bits_per_symbol1, bits_per_symbol1);
stream_symbols1 = bi2de(stream_symbols1);
stream_symbols1 = qammod(stream_symbols1, M1);
stream_symbols2 = reshape(data, stream_size / bits_per_symbol2, bits_per_symbol2);
stream_symbols2 = bi2de(stream_symbols2);
stream_symbols2 = qammod(stream_symbols2, M2);

for snr = SNR
    noisy_signal1 = awgn(stream_symbols1, snr);
    noisy_signal2 = awgn(stream_symbols2, snr);
    
    received_symbols1 = qamdemod(noisy_signal1, M1);
    received_symbols2 = qamdemod(noisy_signal2, M2);
    received_bits1 = de2bi(received_symbols1);
    received_bits2 = de2bi(received_symbols2);
    
    received_bits1 = received_bits1(:);
    received_bits2 = received_bits2(:);
    
    [errors1, ber1] = biterr(data, received_bits1);
    [errors2, ber2] = biterr(data, received_bits2);
    
    BER1 = [BER1, ber1];
    BER2 = [BER2, ber2];
end

% Plotting
figure;
semilogy(SNR, BER1, 'r', 'LineWidth', 2);
hold on;
semilogy(SNR, BER2, 'b', 'LineWidth', 2);
grid on;
xlabel('SNR (dB)');
ylabel('Bit Error Rate');
legend('Q4', 'Q16');
