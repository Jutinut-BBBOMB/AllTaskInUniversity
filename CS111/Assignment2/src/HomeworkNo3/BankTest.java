///StudentID:6609650228    Name:Jutinut Ratanamongkonkul

package HomeworkNo3;
import java.util.ArrayList;
import java.util.Scanner;

	public class BankTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Bank finance = new Bank();
		Scanner scanner = new Scanner(System.in);
		String answer;
		do {
			System.out.println("กด 1 เพื่อเพิ่มบัญชีใหม่");
			System.out.println("กด 2 พิมพ์แสดงรายละเอียดของบัญชี");
			System.out.println("กด 3 เพื่อค้นหาบัญชีที่มียอดมากกว่าหรือเท่ากับจำนวนที่ระบุ บัญชีที่น้อยที่สุด และบัญชีที่มียอดสูงสุด");
			System.out.println("กด 4 เพื่อเพิ่มดอกเบี้ยให้แก่ทุกบัญชีและแสดงยอดเงินทุกบัญชีหลังเพิ่มดอกเบี้ย");
			System.out.println("กด 5 เพื่อแสดงยอดเงินทั้งหมดรวมจากทุกบัญชีและแสดงยอดเงินเฉลี่ยจากทุกบัญชี");
			System.out.println("กด Q สิ้นสุดโปรแกรม");
		answer = scanner.next();
		switch(answer) {
		case "1":
			System.out.print("กรอกจำนวนเงินในบัญชี : ");
			double balance = scanner.nextDouble();
			Account sbalance = new Account(balance);
			finance.addAccount(sbalance);
			break;
		case "2":
			System.out.print("กรอกตำแหน่งของบัญชีที่ต้องการค้นหา : ");
			int index = scanner.nextInt();
			Account uindex = finance.getAccount(index);
			System.out.println("ยอดคงเหลือ : "+uindex.getBalance());
			System.out.println("หมายเลขบัญชี : "+uindex.getaccountNuber());
			break;
		case "3":
			System.out.print("กรุณากรอกขั้นต่ำของจำนวนเงินที่ต้องการค้นหา : ");
			double upper = scanner.nextDouble();
			ArrayList<Account> find = finance.findAccounts(upper);
			System.out.println("บัญชีที่มีจำนวนเงินมากกว่าหรือเท่ากับ :");
			for(Account x:find) {
				System.out.println("หมายเลขบัญชี่ที่ "+x.getaccountNuber()+" : "+x.getBalance());
				}
			Account max = finance.findMax();
			Account min = finance.findMin();
			System.out.println("บัญชีที่มีจำนวนเงินมากที่สุด : "+max.getBalance());
			System.out.println("บัญชีที่มีจำนวนเงินน้อยที่สุด : "+min.getBalance());
			break;
		case "4":
			finance.addInterest();
			for(Account x:finance.accountList) {
			System.out.println("จำนวนเงินหมายเลขบัญชีที่ "+x.getaccountNuber()+" : "+x.getBalance());
				}
			break;
		case "5":
			double total = finance.getTotal();
			double average = finance.getAverage();
			System.out.println("จำนวนเงินรวมทุกบัญชี : "+total);
			System.out.println("จำนวนเงินเฉลี่ยทุกบัญชี : "+average);
			break;
		case "Q":
			break;
			} 
			System.out.println("-----------------------------------------------------------------");
		} while(!answer.equals("Q"));
	}

}
