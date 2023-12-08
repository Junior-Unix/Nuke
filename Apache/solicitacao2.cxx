#include <iostream>
#include <string>
#include <sstream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    // The host and port to be connected.
    std::string host = "127.0.0.1";
    int port = 8080;
    // Create a TCP socket and connect to the host:port.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, host.c_str(), &server_address.sin_addr);
    connect(sock, (sockaddr*)&server_address, sizeof(server_address));
    // Send request to the HTTP server.
    std::stringstream request;
    request << "GET /index.html HTTP/1.0\r\n\r\n";
    send(sock, request.str().c_str(), request.str().length(), 0);
    // Read the response and display on console.
    char buffer[1024] = {0};
    while (read(sock, buffer, sizeof(buffer)) > 0) {
        std::cout << buffer;
    }
    // Close the I/O streams.
    close(sock);
    return 0;
}
