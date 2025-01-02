package com.myjava.threads;

// Class extending Thread to create a thread
class MySmpThread extends Thread {
    public static int myCount = 0;

    public void run() {
        while (MySmpThread.myCount <= 10) {
            try {
                System.out.println("Expt Thread: " + (++MySmpThread.myCount));
                Thread.sleep(100); // Pause for 100 milliseconds
            } catch (InterruptedException iex) {
                System.out.println("Exception in thread: " + iex.getMessage());
            }
        }
    }
}

// Main class to execute threads
public class RunThread {
    public static void main(String a[]) {
        System.out.println("Starting Main Thread...");

        // Create an instance of the thread
        MySmpThread mst = new MySmpThread();
        mst.start(); // Start the secondary thread

        // Logic for the main thread
        while (MySmpThread.myCount <= 10) {
            try {
                System.out.println("Main Thread: " + (++MySmpThread.myCount));
                Thread.sleep(100); // Pause for 100 milliseconds
            } catch (InterruptedException iex) {
                System.out.println("Exception in main thread: " + iex.getMessage());
            }
        }

        System.out.println("End of Main Thread...");
    }
}
