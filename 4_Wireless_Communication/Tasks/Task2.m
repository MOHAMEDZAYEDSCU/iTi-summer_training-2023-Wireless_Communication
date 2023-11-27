% Define parameters
M = [4, 16]; % Modulation orders (4-QAM and 16-QAM)
snr_dB = 0:20; % SNR range in dB
snr_lin = 10.^(snr_dB / 10); % Convert SNR to linear scale

% Initialize arrays to store bit error rates
ber_4qam = zeros(length(snr_lin), 1);
ber_16qam = zeros(length(snr_lin), 1);

% Loop over SNR values
for i = 1:length(snr_lin)
    % Generate random data symbols
    data = randi([0 M(1)-1], 10000, 1); % 4-QAM
    data_16qam = randi([0 M(2)-1], 10000, 1); % 16-QAM
    
    % Modulate the data symbols
    modulated_signal = qammod(data, M(1));
    modulated_signal_16qam = qammod(data_16qam, M(2));
    
    % Pass the modulated signals through AWGN channel
    noisy_signal = awgn(modulated_signal, snr_dB(i));
    noisy_signal_16qam = awgn(modulated_signal_16qam, snr_dB(i));
    
    % Demodulate the received signals
    demodulated_signal = qamdemod(noisy_signal, M(1));
    demodulated_signal_16qam = qamdemod(noisy_signal_16qam, M(2));
    
    % Calculate bit error rates
    ber_4qam(i) = sum(data ~= demodulated_signal) / numel(data);
    ber_16qam(i) = sum(data_16qam ~= demodulated_signal_16qam) / numel(data_16qam);
end

% Plot BER curves using semilogy
figure;
semilogy(snr_dB, ber_4qam, 'b-*', 'DisplayName', '4-QAM');
hold on;
semilogy(snr_dB, ber_16qam, 'r-*', 'DisplayName', '16-QAM');
hold off;
grid on;
xlabel('SNR (dB)');
ylabel('Bit Error Rate');
title('Bit Error Rate (BER) Curve for 4-QAM and 16-QAM Modulation');
legend('Location', 'best');
