///Name: Jutinut Ratanamongkonkul
///SID:6609650228
package assign1_6609650228;
import java.util.Scanner;

public class BallTest {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		System.out.printf("Input the radius of the ball > ");
		double radius = scanner.nextDouble();
		Ball ball = new Ball();
		ball.setRadius(radius);
		
		System.out.printf("The ball radius'%.2f' has surfacearea = %.3f The ball\n",ball.getRadius(),ball.getSurface());
		System.out.printf("radius'%.2f' has volume = %.3f",ball.getRadius(),ball.getVolume());
		
	}

}
