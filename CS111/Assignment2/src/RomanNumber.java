///StudentID:6609650228    Name:Jutinut Ratanamongkonkul
import java.util.Scanner;
public class RomanNumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner (System.in);
		System.out.println("Input the roman number: ");
		String roman = getroman(scanner);
		Change(roman);
	}
	public static String getroman(Scanner T) {
		return T.next();
	}
	public static void Change(String Y) {
		switch(Y) {
		case "I" :
			System.out.println("It is One.");
			break;
		case "II" :
			System.out.println("It is Two.");
			break;
		case "III" :
			System.out.println("It is Three.");
			break;
		case "IV" :
			System.out.println("It is Four.");
			break;
		case "V" :
			System.out.println("It is Five.");
			break;
		case "VI" : 
			System.out.println("It is Six.");
		default: 
			System.out.println("UnknownNumber.");

		}
	}
	
		
		
	}

