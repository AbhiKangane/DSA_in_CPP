/* 
Create a class Hotel with the below attributes:

hotelId - int
hotelName - String
dateOfBooking String (in the format dd-mon-yyyy)
noOfRoomsBooked - int
wifiFacility - String
totalBill- double

The above attributes should be private, write getters, setters and parameterized constructor as required.
Create class Solution with main method.
Implement two static methods noOfRoomsBookedInGivenMonth and searchHotelByWifiOption in Solution class.
1) noOfRoomsBookedInGivenMonth method:
This method will take two input parameter array of Hotel objects and a String parameter.
The method will return the total numbers of rooms booked from array of Hotel objects for the given month(String parameter passed).
If no rooms are booked for the given month in the Hotel objects, then the method should return 0.

2) searchHotelByWifiOption method:
This method will take two input parameter array of Hotel objects and a String parameter
The method will return Hotel object with second highest totalbill, from the array of Hotel objects where wifi Facility attribute matches with the given wifi facility(String parameter passed)
If no Hotel with the given wifi option is present in the array of Hotel objects, then the method should return null.

* Note:
1) No two Hotel object would have the same hotelld.
2) No two Hotel object would have the same totalbill
3) The Array either has at least two objects with specified wifi option OR no object with specified wifi option. 
4) All the searches should-be case insensitive. 5) dateOfBooking is stored in the format dd-mon-yyyy(eg. 01- Jan-2022)


The above mentioned static methods should be main method. 
For noOfRoomsBookedInGivenMonth method - The main method should print the total number of booked rooms as it is, if the returned value is greater than 0, else it should print "No rooms booked in the given month"
For searchHotelBy WifiOption method - The main method should print the hotelld from the returned Hotel object if the returned value is not null. If the returned value is null then it should print "No such option available".
Before calling these static methods in main, use Scanner object to read the values of four Hotel objects referring attributes in the above mentioned attribute sequence.
Next, read the value of two String parameters for capturing the month & WiFi option.
*/

import java.util.*; 

public class MyClass{ 
    private int id, rooms; 
    private String name, date, wifi; 
    private double bill; 

    public MyClass(int ID, String NAME, String DATE, int ROOMS, String WIFI, double BILL){
        id = ID; 
        name = NAME; 
        date = DATE; 
        rooms = ROOMS; 
        wifi = WIFI; 
        bill = BILL; 
    } 

    public int getId(){return id;} 
    public int getRooms(){return rooms;} 
    public String getName(){return name;} 
    public String getDate(){return date;} 
    public String getWifi(){return wifi;} 
    public double getBill(){return bill;} 

    public static void main(String[] args){ 
        Scanner sc = new Scanner(System.in); 
        MyClass[] hotels = new MyClass[4];
    
        for(int i=0; i<4; i++){
            int id = sc.nextInt(); sc.nextLine();
            String name = sc.nextLine();
            String date = sc.nextLine();
            int rooms = sc.nextInt(); sc.nextLine();
            String wifi = sc.nextLine();
            double bill = sc.nextDouble();
            
            hotels[i] = new MyClass(id,name,date,rooms,wifi,bill);
        } 
        sc.nextLine();
        String month = sc.nextLine();
        String Wifi = sc.nextLine();

        // for noOFRoomsBookedInGivenMonth
        int ans1 = fun1(hotels, month);
        if(ans1 > 0)
            System.out.println(ans1); 
        else 
            System.out.println("No rooms booked in the given month"); 
    
        // searchHotelByWifiOption : for finding 2nd largest totalBill hotel  
        MyClass ans2 = fun2(hotels, Wifi); 
        if(ans2 != null) 
            System.out.println(ans2.getId()); 
        else 
            System.out.println("No such option available"); 
        sc.close(); 
    } 

    public static int fun1(MyClass[] hotels, String month){ 
        int ans = 0; 
        for(MyClass h: hotels){ 
            String bookingMonth = h.getDate().split("-")[1]; 
            if(bookingMonth.equalsIgnoreCase(month)) 
                ans += h.getRooms(); 
        } 
        return ans; 
    } 

    public static MyClass fun2(MyClass[] hotels, String wifi){
        List ans = new ArrayList<>(); 
        for(MyClass h: hotels){
            if(h.getWifi().equalsIgnoreCase(wifi)) 
                ans.add(h); 
        }
        if(ans.size()<2) 
            return null; 

        ans.sort(Comparator.comparingDouble(MyClass::getBill).reversed()); 
        return ans.get(1); 
    } 
}