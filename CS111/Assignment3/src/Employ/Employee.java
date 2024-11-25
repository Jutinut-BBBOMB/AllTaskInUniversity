///StudentID:6609650228    Name:Jutinut Ratanamongkonkul

package Employ;
public abstract class Employee {
    protected String fullName;
    protected int age;
    protected String department;
    protected int performanceScore;

    public Employee(String fullName, int age, String department, int performanceScore) {
        this.fullName = fullName;
        this.age = age;
        this.department = department;
        this.performanceScore = performanceScore;
    }

    public String getName() {
        return fullName.split("-")[0];
    }

    public String getLastName() {
        return fullName.split("-")[1];
    }
    
    public String getFullName()
    {
        return fullName;
    }
    
    public int getAge() {
        return age;
    }

    public String getDepartment() {
        return department;
    }

    public int getPerformanceScore() {
        return performanceScore;
    }

    public void setFullName(String fullName) {
        this.fullName = fullName;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public void setPerformanceScore(int performanceScore) {
        this.performanceScore = performanceScore;
    }

    public abstract double getMonthlyPayment();
}