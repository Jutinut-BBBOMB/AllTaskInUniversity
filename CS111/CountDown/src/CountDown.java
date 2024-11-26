import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class CountDown implements ActionListener{
	private int count;
	
	public CountDown(int initialCount){
		count = initialCount;
	}
	
	public void actionPerformed(ActionEvent event) {
		if (count > 0) 
			System.out.println(count);
		else if (count == 0)
			System.out.println("Happy New Year!");
		count--;
	}
}
