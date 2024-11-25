///StudentID:6609650228    Name:Jutinut Ratanamongkonkul


package Employ;

public class HourlyEmployee extends Employee {
	
	private static final int MIN_HOURLY_WAGE_RATE = 50;
    private int workingSessionsPerMonth;

    public HourlyEmployee(String fullName, int age, String department, int workingSessionsPerMonth , int performanceScore) {
        super(fullName, age, department, performanceScore);
        this.workingSessionsPerMonth = workingSessionsPerMonth;
    }

    public double calculatePersonalHourlyWage() {
        if (performanceScore <= 5) {
            return MIN_HOURLY_WAGE_RATE;
        } else {
            return MIN_HOURLY_WAGE_RATE * (1 + 0.1 * (performanceScore - 5));
        }
    }

    @Override
    public double getMonthlyPayment() {
        return calculatePersonalHourlyWage() * 8 * workingSessionsPerMonth;
    }

}
