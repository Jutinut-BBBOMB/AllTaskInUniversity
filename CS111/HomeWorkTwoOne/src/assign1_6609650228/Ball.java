///Name: Jutinut Ratanamongkonkul
///SID:6609650228
package assign1_6609650228;
public class Ball {
	private double radius;
	public void setRadius(double aRadius) {
		this.radius = aRadius;
	}
	public double getRadius() {
		return radius;
	}
	public double getSurface() {
		return 4.0 * Math.PI * Math.pow(radius, 2);
	}
	public double getVolume() {
		return (4.0/3.0)*Math.PI * Math.pow(radius, 3);
	}
}
