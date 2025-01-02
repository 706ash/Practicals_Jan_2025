package com.myjava.threads;

// Class implementing Runnable interface
class MyRunnableThread implements Runnable {
    public static int myCount = 0;

    public MyRunnableThread() {
    }

    public void run() {
        while (MyRunnableThread.myCount <= 10) {
            try {
                System.out.println("Expt Thread: " + (++MyRunnableThread.myCount));
                Thread.sleep(100); // Pause for 100 milliseconds
            } catch (InterruptedException iex) {
                System.out.println("Exception in thread: " + iex.getMessage());
            }
        }
    }
}

// Main class to execute threads
public class RunMyThread {
    public static void main(String a[]) {
        System.out.println("Starting Main Thread...");

        // Creating an instance of the Runnable class
        MyRunnableThread mrt = new MyRunnableThread();
        Thread t = new Thread(mrt); // Wrapping Runnable into a Thread
        t.start(); // Start the secondary thread

        // Logic for the main thread
        while (MyRunnableThread.myCount <= 10) {
            try {
                System.out.println("Main Thread: " + (++MyRunnableThread.myCount));
                Thread.sleep(100); // Pause for 100 milliseconds
            } catch (InterruptedException iex) {
                System.out.println("Exception in main thread: " + iex.getMessage());
            }
        }

        System.out.println("End of Main Thread...");
    }
}
