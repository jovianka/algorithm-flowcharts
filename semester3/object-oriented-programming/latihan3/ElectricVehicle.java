public interface ElectricVehicle {
    // Abstract method to charge the vehicle
    void charge();

    // Default method for electric vehicles (optional implementation)
    default void batteryStatus() {
        System.out.println("Battery is fully charged.");
    }
}
