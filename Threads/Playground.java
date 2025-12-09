package Threads;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.concurrent.*;

public class Playground {
    
    public static void main(String args[]) throws InterruptedException, ExecutionException {
        
        ScheduledExecutorService executor = Executors.newScheduledThreadPool(5);
executor.scheduleAtFixedRate(() -> {
    System.out.println("Hello World");
}, 500, 100, TimeUnit.MILLISECONDS);

ThreadPoolExecutor executorService = (ThreadPoolExecutor) Executors.newScheduledThreadPool(3);
        Collection<Callable<String>> tasks = new ArrayList<>();

        // Create multiple Callable tasks
        for (int i = 0; i < 5; i++) {
            final int taskNumber = i;
            tasks.add(() -> {
                System.out.println("Executing task " + taskNumber + " in thread: " + Thread.currentThread().getName());
                Thread.sleep((long) (Math.random() * 20000));
                System.out.println("done task " + taskNumber + " in thread: " + Thread.currentThread().getName());
                
                return "Result from task " + taskNumber;
            });
        }

        // Invoke all tasks and get a list of Futures
        System.out.println("Invoking all tasks...");
        List<Future<String>> futures = executorService.invokeAll(tasks);

        // Retrieve the results
        System.out.println("Retrieving results...");
        for (Future<String> future : futures) {
            if (future.isDone()) {
                String result = future.get();
                System.out.println("Result: " + result);
            } else {
                System.out.println("Task was not completed.");
            }
        }

        executorService.shutdown();
    }
}