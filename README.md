# 42_minitalk
Minitalk is a simple communication system that allows two programs to communicate via signals. The project involves creating a client-server communication system where the client sends messages to the server using Unix signals (specifically SIGUSR1 and SIGUSR2). The server receives the signals and decodes them into meaningful messages. The aim is to explore inter-process communication (IPC) using signals and implement a basic message transfer system.

##  How It Works
The server listens for incoming signals from the client. When a signal is received, it decodes the data and reconstructs the message.
The client sends a message to the server by encoding each character of the message into binary format, and then sending it bit by bit using the signals.
Each bit of a character is sent as a signal:

SIGUSR1 represents a 0 bit.

SIGUSR2 represents a 1 bit.

## How to Run the Project
### 1- Clone the repository:
```
git clone https://github.com/your-username/minitalk_42.git
cd minitalk_42
```
### 2- Compile the project:
```
make
```
### 3- Run the server:
```
./server
```
The server will display its process ID (PID) when it starts. You’ll need this PID to send messages from the client.

### 4- Run the client:
```
./client [server_pid] [message]
```
<b>server_pid</b>: The PID of the running server.
<b>message</b>: The message you want to send to the server.
## Example
### Start the server:
```
./server
```
The server will output its PID:
```
Server is running, PID: 12345
```
### Send a message from the client:
```
./client 12345 "Hello"
```
This sends the message "Hello" to the server with PID 12345.

## Clean up:
To remove object files and the binary, run:
```
make fclean
```
