///StudentID:6609650228    Name:Jutinut Ratanamongkonkul
import java.util.ArrayList;
public class Toaster {
	private ArrayList<Toastable>items;
	
	//สร้าง toaster
	public Toaster() {
		items = new ArrayList<>();
	}
	
	public void add(Toastable item) {
		items.add(item);
	}
	
	public void print() {
		for(Toastable toast : items) {
			System.out.println(toast.toString());
		}
		
	}
	

}
