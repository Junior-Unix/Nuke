package main

import (
    "bufio"
    "fmt"
    "net"
    "os"
)

func main() {
    // The host and port to be connected.
    host := "127.0.0.1"
    port := "8080"
    // Create a TCP socket and connect to the host:port.
    conn, err := net.Dial("tcp", host+":"+port)
    if err != nil {
        fmt.Println("Error connecting:", err.Error())
        os.Exit(1)
    }
    // Create the input and output streams for the network socket.
    in := bufio.NewReader(conn)
    out := bufio.NewWriter(conn)
    // Send request to the HTTP server.
    fmt.Fprintf(out, "GET /index.html HTTP/1.0\r\n\r\n")
    out.Flush()
    // Read the response and display on console.
    for {
        line, err := in.ReadString('\n')
        if err != nil {
            break
        }
        fmt.Print(line)
    }
    // Close the I/O streams.
    in.Reset(nil)
    out.Reset(nil)
    conn.Close()
}
