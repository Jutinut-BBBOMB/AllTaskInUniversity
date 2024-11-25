///StudentID:6609650228    Name:Jutinut Ratanamongkonkul
import java.util.Scanner;
public class Vendingmachine {
	public static void Machine(int price) {
		if(price>=5 && price<=50) {
			int twozero = (50-price)/20;
			int twozeroR = (50-price)%20;
			int ten =(twozeroR/10);
			int tenR=(twozeroR%10);
			int five=(tenR/5);
		System.out.println("20 bath note: "+twozero);
		System.out.println("10 bath coin: "+ten+ " and");
		System.out.println("5 bath coin: "+five);
		}
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter price of item(from 5 baths to 50 baths): ");
		int price = scan.nextInt();
		System.out.println("You bought an item for "+price+ " baths and gave me 50 baths.");
		System.out.println("So your change is ");
		Vendingmachine.Machine(price);
		
	}

}
