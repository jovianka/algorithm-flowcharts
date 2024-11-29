package com.companylatihan;

class MyCircle {
    public double radius;

    public MyCircle(double radius) {
        this.radius = radius;
    }

    public double calculatePerimeter() {
        double perimeter = 2 * Math.PI * radius;
        return perimeter;
    }

}

public class App {
    public static void main(String[] args) {
        MyCircle circleOne = new MyCircle(32);
        double perimeter = circleOne.calculatePerimeter();
        System.out.println(
                "Keliling dari lingkaran dengan radius "
                + circleOne.radius
                + " = "
                + String.format("%.2f", perimeter));
    }
}