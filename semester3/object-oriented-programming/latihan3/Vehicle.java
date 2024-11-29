public interface Vehicle {
    // Abstract method (no body)
    void start();

    // Abstract method (no body)
    void stop();

    // A default method with a body
    default void fuelType() {
        System.out.println("This vehicle uses gasoline.");
    }
}
