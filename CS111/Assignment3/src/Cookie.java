///StudentID:6609650228    Name:Jutinut Ratanamongkonkul

public class Cookie implements Toastable {
	private String state;
	
	public Cookie() {
		state = "SOFT";
	}
	
	public void toast() {
		state = "Burn";
	}
	
	public void getToastState() {
        System.out.println(toString());
    }
    
    public String toString() { 
        return "Cookie is now: " + state; 
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
