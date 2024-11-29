class Kendaraan {
    double panjang, lebar, tinggi;

    // konstruktor tanpa parameter
    Kendaraan() {
        panjang = lebar = tinggi = 3;
    }
    // konstruktor 1 parameter
    Kendaraan(double ukuran) {
        panjang = lebar = tinggi = ukuran;
    }
    // konstruktor banyak parameter
    Kendaraan(double p, double l, double t) {
        panjang = p;
        lebar = l;
        tinggi = t;
    }
    // konstruktor parameter objek
    Kendaraan(Kendaraan copy) {
        this.panjang = copy.panjang;
        this.lebar = copy.lebar;
        this.tinggi = copy.tinggi;
    }

    double size() {
        return panjang * lebar * tinggi;
    }
}

public class Main {
    public static void main(String args[]) {
        // membuat objek kendaraan dengan konstruktor
        Kendaraan truk_1 = new Kendaraan(3.8, 2.5, 1.3);
        Kendaraan truk_2 = new Kendaraan(4);
        Kendaraan truk_3 = new Kendaraan();
        Kendaraan salinan = new Kendaraan(truk_1);

        double size;

        size = truk_1.size();
        System.out.println("Volume truk pertama adalah " + size);

        size = truk_2.size();
        System.out.println("Volume truk kedua adalah " + size);

        size = truk_3.size();
        System.out.println("Volume truk ketiga adalah " + size);

        size = salinan.size();
        System.out.println("Volume truk salinan adalah " + size);
    }
}
