///StudentID:6609650228    Name:Jutinut Ratanamongkonkul
package HomeworkNo3;
import java.util.ArrayList;
	public class Bank {
	ArrayList<Account> accountList = new ArrayList<Account>();
    public void addAccount(Account act) {
        accountList.add(act);
    }
    public Account getAccount(int index) {
        return accountList.get(index);
    }
    public ArrayList<Account> findAccounts(double account){
        ArrayList<Account> find = new ArrayList<>();
        for(Account x:accountList) {
            if(x.getBalance() >= account) {
                find.add(x);
            }
        }
        return find.isEmpty() ? null:find;
    }
    public Account findMin() {
        if(accountList.isEmpty()) {
            return null;
        }
        Account min = accountList.get(0);
        for(Account x:accountList) {
            if(x.getBalance() < min.getBalance()) {
                min = x;
            }
        }
        return min;
    }
    public Account findMax() {
        if(accountList.isEmpty()) {
            return null;
        }
        Account max = accountList.get(0);
        for(Account x:accountList) {
            if(x.getBalance() > max.getBalance()) {
                max = x;
            }
        }
        return max;
    }
    public void addInterest() {
        for(Account x:accountList) {
            double interest = x.getBalance()*0.03;
            x.deposit(interest);
        }
    }
    public double getTotal() {
        double sum = 0.0;
        for(Account x:accountList) {
            sum+=x.getBalance();
        }
        return sum;
    }
    public double getAverage() {
        double average = getTotal()/accountList.size();
        return average;
    }
}

