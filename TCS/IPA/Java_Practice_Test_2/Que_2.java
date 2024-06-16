// Java IPA practice test 2 que 2 Sol

// import java.util.ArrayList;
// import java.util.Arrays;
// import java.util.Comparator;
// import java.util.List;
import java.util.*;

class MyClass {
    private int laptopId;
    private String brand;
    private double price;
    private int rating;
    private String osType;

    // Constructor
    public MyClass(int laptopId, String brand, String osType, double price, int rating) {
        this.laptopId = laptopId;
        this.brand = brand;
        this.osType = osType;
        this.price = price;
        this.rating = rating;
    }

    // Getters
    public int getLaptopId() {
        return laptopId;
    }

    public String getBrand() {
        return brand;
    }

    public double getPrice() {
        return price;
    }

    public int getRating() {
        return rating;
    }

    public String getOsType() {
        return osType;
    }

    // main method
    public static void main(String[] args) {
        // Create some Laptop objects
        MyClass[] laptops = new MyClass[4];
        Scanner sc = new Scanner(System.in);
        for(int i=0; i<4; i++){
            System.out.println("\nData of "+i+" Laptop: ");
            int id = sc.nextInt(); sc.nextLine();
            String b = sc.nextLine();
            String os = sc.nextLine();
            double p = sc.nextDouble(); sc.nextLine();
            int rating = sc.nextInt(); sc.nextLine();
            
            laptops[i] = new MyClass(id, b, os, p, rating);
        }

        // Example usage of countOfLaptopsByBrand
        
        System.out.println("Enter Brand name to count : ");  
        String brandToSearch = sc.nextLine();
        int count = countOfLaptopsByBrand(laptops, brandToSearch);
        if (count > 0) {
            System.out.println("countOfLaptopsByBrand "+brandToSearch+" = "+ count);
        } else {
            System.out.println("The given brand is not available");
        }

        // Example usage of searchLaptopByOsType
        System.out.println("Enter OS to search : ");  
        String osToSearch = sc.nextLine();
        MyClass[] searchResults = searchLaptopByOsType(laptops, osToSearch);
        System.out.println("\nsearchLaptopByOsType "+osToSearch+ " : ");
        if (searchResults != null) {
            for (MyClass laptop : searchResults) {
                System.out.println(laptop.getLaptopId() + " " + laptop.getRating());
            }
        } else {
            System.out.println("The given os is not available");
        }
    }

    public static int countOfLaptopsByBrand(MyClass[] laptops, String brand) {
        int count = 0;
        for (MyClass laptop : laptops) 
            if (laptop.getBrand().equalsIgnoreCase(brand) && laptop.getRating() > 3) 
                count++;

        return count;
    }

    public static MyClass[] searchLaptopByOsType(MyClass[] laptops, String osType) {
        List<MyClass> matchingLaptops = new ArrayList<>();
        for (MyClass laptop : laptops) {
            if (laptop.getOsType().equalsIgnoreCase(osType)) {
                matchingLaptops.add(laptop);
            }
        }
        if (matchingLaptops.isEmpty()) {
            return null;
        }
        matchingLaptops.sort(Comparator.comparingInt(MyClass::getLaptopId).reversed());
        return matchingLaptops.toArray(new MyClass[0]);
    }
}