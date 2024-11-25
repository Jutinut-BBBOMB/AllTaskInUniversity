///StudentID:6609650228    Name:Jutinut Ratanamongkonkul

public class Bread implements Toastable {
	public static final String BURNT = "Burn";
	public static final String CRISP = "Crisp";
	public static final String SOFT = "Soft";
	private String state;
	
	
	//สร้างขนมปัง
	public Bread() {
		state = SOFT;
	}
	
	public void setState(String state) {
		this.state = state;
	}
	
	public String getState() {
		return state;
	}
	
	public String toString() {
		return "Bread is now: "+ state;
	}


	@Override
	public void Toast() {
		// TODO Auto-generated method stub

	}

	@Override
	public void getToaststate() {
		// TODO Auto-generated method stub

	}

}
