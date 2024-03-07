import java.applet.*;
import java.awt.*;
import java.awt.event.*;

public static void main(String[] args) {
public class AnimatedApplet extends Applet implements Runnable, ActionListener {
    private Thread animatorThread;
    private int x, y;
    private int dx, dy;
    private int delay = 50; // milliseconds
    private boolean running = false;
    private Button startButton, stopButton, fasterButton, slowerButton;

    public void init() {
        // Initialize object position and velocity
        x = 100;
        y = 100;
        dx = 2;
        dy = 2;

        // Create buttons for controlling the animation
        startButton = new Button("Start");
        stopButton = new Button("Stop");
        fasterButton = new Button("Faster");
        slowerButton = new Button("Slower");

        // Add action listeners to buttons
        startButton.addActionListener(this);
        stopButton.addActionListener(this);
        fasterButton.addActionListener(this);
        slowerButton.addActionListener(this);

        // Add buttons to the applet
        add(startButton);
        add(stopButton);
        add(fasterButton);
        add(slowerButton);
    }

    public void start() {
        // Start the animation thread
        if (animatorThread == null) {
            running = true;
            animatorThread = new Thread(this);
            animatorThread.start();
        }
    }

    public void stop() {
        // Stop the animation thread
        running = false;
        animatorThread = null;
    }

    public void run() {
        while (running) {
            // Update object position
            x += dx;
            y += dy;

            // Bounce off walls
            if (x <= 0 || x >= getWidth()) {
                dx = -dx;
            }
            if (y <= 0 || y >= getHeight()) {
                dy = -dy;
            }

            // Repaint the applet
            repaint();

            // Delay for smooth animation
            try {
                Thread.sleep(delay);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void paint(Graphics g) {
        // Draw a moving object
        g.setColor(Color.RED);
        g.fillOval(x - 10, y - 10, 20, 20);
    }

    public void actionPerformed(ActionEvent e) {
        // Handle button clicks
        if (e.getSource() == startButton) {
            start();
        } else if (e.getSource() == stopButton) {
            stop();
        } else if (e.getSource() == fasterButton) {
            delay -= 5; // Decrease delay for faster animation
        } else if (e.getSource() == slowerButton) {
            delay += 5; // Increase delay for slower animation
        }
    }
}
}
