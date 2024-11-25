///StudentID:6609650228    Name:Jutinut Ratanamongkonkul
package HomeworkNo2;
import java.util.Scanner;
public class MobileServiceCosts{
	public static void main(String[] args) {
		Double time = 0.0;
		Scanner scan = new Scanner(System.in);
		while(true){
		System.out.println("Enterminutes(Q= Quit): ");
		String Answer = scan.next();
		if (Answer == ("Q")){
		break;
		}
		else {
			time = Double.parseDouble(Answer);
		}
		System.out.println("Youhavetopay "+minutes(time));
		}
	}
	public static Double minutes(Double x) {
			 x = Math.ceil(x);
		     if(x < 0) {
		        return 0.0;
		     }
		     if(x < 10) {
		        return x*3.5;
		        }
		     if(x < 60) {
		        return twentyminute(x);
		        }
		     else {
		        return x*1.5;
		        }
		    }
	public static Double twentyminute(Double x) {
			if(x<1) {
				return 0.0;
			}
			if(x<21) {
				return 3+twentyminute(x-1);
			}
			else {
				return 1+twentyminute(x-1);
			}
		
	}
}