# Minitalk

The "minitalk" repository contains the C implementation of two executables: "server" and "client". This project focuses on signal communication using Unix signals and implements the compilation of these two files. The "server" executable, when started, prints the PID of its own process. The "client" executable should be launched with two arguments: the PID of the server and the message string to send.

Through the use of Unix signals, a communication channel is established between the server and the client. By using SIGUSR1 and SIGUSR2 signals (handled by sigaction) and binary calculations, a string is sent between the processes.

This project is part of the curriculum at 42School and emphasizes the use of Unix signals, the implementation of sigaction, and the utilization of bitwise operators. It has achieved a score of 125 out of 100.

## Requirements

- Compatible C compiler (e.g., GCC)
- UNIX or Linux operating system

## Usage

1. Clone the repository to your local system:

   ```shell
   git clone https://github.com/stenterello/minitalk.git

2. Navigate to the main directory of the repository:  

   ```shell
   cd minitalk

3. Compile the programs by running the command:  

   ```shell
   make

4. Start the server by running the command:

   ```shell
   ./server
   
   The server will print its PID.

5. Start the client by running the command:

   ```shell
   ./client <server_pid> <message>

   Replace <server_pid> with the PID of the server process and <message> with the message you want to send.


## Description

The "minitalk" project implements a communication system between the server and the client using Unix signals. The server process prints its own PID upon startup, allowing the client to specify the destination server.

The client sends a string message to the server using a combination of SIGUSR1 and SIGUSR2 signals. Each character of the message is encoded into a binary representation, and the client sends the signal corresponding to each bit to the server. The server, upon receiving the signals, decodes the binary representation and reconstructs the original string.

The project extensively utilizes sigaction for signal handling and bitwise operators for encoding and decoding the messages.