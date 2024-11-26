import javax.swing.JOptionPane;
import javax.swing.Timer;

public class TimeTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CountDown listener = new CountDown(10);
		
		final int DELAY = 1000;
		Timer t = new Timer(DELAY, listener);
		t.start();
		
		JOptionPane.showMessageDialog(null, "Quit?");
		System.exit(0);
	}

}
