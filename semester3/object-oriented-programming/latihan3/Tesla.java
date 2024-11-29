public class Tesla extends Car implements Vehicle, ElectricVehicle {

    // Implementing the abstract method from the Car class
    @Override
    public void start() {
        System.out.println("Tesla is starting.");
    }

    // Implementing the abstract method from the Vehicle interface
    @Override
    public void stop() {
        System.out.println("Tesla has stopped.");
    }

    // Overriding the default method from the Vehicle interface
    @Override
    public void fuelType() {
        System.out.println("This Tesla uses electricity.");
    }

    // Implementing the abstract method from the ElectricVehicle interface
    @Override
    public void charge() {
        System.out.println("Tesla is charging.");
    }

    // Optionally, you can override the default method from ElectricVehicle interface
    @Override
    public void batteryStatus() {
        System.out.println("Tesla battery is at 80%.");
    }
}

