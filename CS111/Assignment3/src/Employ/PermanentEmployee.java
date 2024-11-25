///StudentID:6609650228    Name:Jutinut Ratanamongkonkul


package Employ;

public class PermanentEmployee extends Employee {
	
	private double salary;

    public PermanentEmployee(String fullName, int age, String department, int performanceScore, double salary) {
        super(fullName, age, department, performanceScore);
        this.salary = salary;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    @Override
    public double getMonthlyPayment() {
        double socialSecurityRemittance = Math.min(750, salary * 0.05);
        double diligentBonus = performanceScore >= 8 ? salary * 0.03 : 0;
        return salary - socialSecurityRemittance + diligentBonus;
    }
}
