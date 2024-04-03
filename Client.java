import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        try {
            // Connect to the server on localhost and port 12345
            Socket socket = new Socket("localhost", 12345);

            // Create input and output streams for communication with the server
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

            // Send a message to the server
            out.println("Hello from primeDevansh!");

            // Receive and print the server's response
            String response = in.readLine();
            System.out.println("Server response: " + response);

            // Close streams and socket
            in.close();
            out.close();
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
