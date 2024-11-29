public class Main {
    public static void main(String[] args) {
        Tesla myTesla = new Tesla();

        // Calling methods from the Car abstract class
        myTesla.start();    // Output: Tesla is starting.
        myTesla.honk();     // Output: The car is honking.

        // Calling methods from the Vehicle interface
        myTesla.stop();     // Output: Tesla has stopped.
        myTesla.fuelType(); // Output: This Tesla uses electricity.

        // Calling methods from the ElectricVehicle interface
        myTesla.charge();   // Output: Tesla is charging.
        myTesla.batteryStatus();  // Output: Tesla battery is at 80%.
    }
}
