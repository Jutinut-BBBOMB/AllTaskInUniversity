///StudentID:6609650228    Name:Jutinut Ratanamongkonkul
package HomeworkNo3;
import java.util.Scanner;
public class Account { 
    private double balance; 
    private int accountNumber; 
    private static int lastAccountNumber = 0; 
    public Account(double intialBalance){ 
        balance = intialBalance; 
        accountNumber = lastAccountNumber + 1; 
        lastAccountNumber = accountNumber; 
    } 
    
    public void deposit(double depositAmount){ 
        balance += depositAmount; 
    } 
    public boolean withdraw(double withdrawAmount){ 
        if (withdrawAmount > balance){     
            System.out.println("Insufficient Funds!!!"); 
            return false; 
        } 
        else { 
            balance -= withdrawAmount; 
            return true; 
        } 
    } 
    public double getBalance() {
        return balance;
    }
    public int getaccountNuber() {
        return accountNumber;
    }
    public int getlastAccountNumber() {
        return lastAccountNumber;
    }
}