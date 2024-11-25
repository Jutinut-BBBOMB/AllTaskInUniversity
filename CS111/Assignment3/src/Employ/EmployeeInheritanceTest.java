//StudentID:6609650228    Name:Jutinut Ratanamongkonkul


package Employ;
import java.util.ArrayList;
import java.util.List;


public class EmployeeInheritanceTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List<Employee> employees = new ArrayList<>();
		   employees.add(new PermanentEmployee("Somchai-Hankla", 25, "IT", 8, 20000));
		   employees.add(new PermanentEmployee("Somsong-Bunthum", 22, "IT", 4, 12000));
		   employees.add(new HourlyEmployee("Manee-Dumkum", 21, "Production", 25, 6));
		   employees.add(new HourlyEmployee("Piti-Rukthai", 25, "Production", 30, 5));
		   employees.add(new HourlyEmployee("Veera-Rukdee", 30, "Production", 20, 8));

		   printMonthlyPaymentSlip(employees);
	}
		 
	public static void printMonthlyPaymentSlip(List<Employee> employees) {
		       for (Employee emp : employees) {
		           System.out.println("*************************************************\n");
		           System.out.println("         Payment Slip of " + emp.getFullName() + "\n");
		           System.out.println("*************************************************");
		           System.out.printf("First Name : %-19s Last Name : %s\n", emp.getName(), emp.getLastName());
		           System.out.printf("Department is %-19s AGE %d \n", emp.getDepartment(), emp.getAge());
		           System.out.printf("Monthly Payment: %.2f baht", emp.getMonthlyPayment());
		           if (emp instanceof PermanentEmployee) {
		           PermanentEmployee permEmp = (PermanentEmployee) emp;
		               double socialSecurity = Math.min(750, permEmp.getSalary() * 0.05);
		               System.out.printf("   Social Security: %.2f baht\n", socialSecurity);
		           }
		           System.out.println("\n");
		       }

	}

}
