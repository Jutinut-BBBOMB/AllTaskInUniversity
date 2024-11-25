///Name: Jutinut Ratanamongkonkul
///SID:6609650228

package assign2_6609650228;

public class FourWords {
	private String word1;
    private String word2;
    private String word3;
    private String word4;
    private int count = 0;
  public void add(String words4) {
	  if (count >= 4) {
		  System.out.println("Can't add a new word something!");
			  return;
	  } count++;
	  switch (count) {
	  case 1: word1 = words4;
	  break;
	  case 2: word2 = words4;
	  break;
	  case 3: word3 = words4;
	  break;
	  case 4: word4 = words4;
	  break;
	  }
  }
  
  public String getMin() {
      String min = null;
      if (word1 != null && (min == null || word1.compareTo(min) < 0)) {
          min = word1;
      }
      if (word2 != null && (min == null || word2.compareTo(min) < 0)) {
          min = word2;
      }
      if (word3 != null && (min == null || word3.compareTo(min) < 0)) {
          min = word3;
      }
      if (word4 != null && (min == null || word4.compareTo(min) < 0)) {
          min = word4;
      }
      return min;
  }

  public String getMax() {
      String max = null;
      if (word1 != null && (max == null || word1.compareTo(max) > 0)) {
          max = word1;
      }
      if (word2 != null && (max == null || word2.compareTo(max) > 0)) {
          max = word2;
      }
      if (word3 != null && (max == null || word3.compareTo(max) > 0)) {
          max = word3;
      }
      if (word4 != null && (max == null || word4.compareTo(max) > 0)) {
          max = word4;
      }
      return max;
  }

  public void printWords() {
      System.out.println(" List of words:");
      if (word1 != null) System.out.println("\t" + word1);
      if (word2 != null) System.out.println("\t" + word2);
      if (word3 != null) System.out.println("\t" + word3);
      if (word4 != null) System.out.println("\t" + word4);
      if (word1 == null) System.out.printf("\n"); 

      String min = getMin();
      String max = getMax();
      
      System.out.println("The lexicographic minimum is: " + min);
      System.out.println("The lexicographic maximum is: " + max);

      int totalLength = 0;
      if (word1 != null) totalLength += word1.length();
      if (word2 != null) totalLength += word2.length();
      if (word3 != null) totalLength += word3.length();
      if (word4 != null) totalLength += word4.length();
      
      double averageLength;
      if (count == 0) {
          averageLength = 0;
      } else {
          averageLength = totalLength / (double) count;
      }

      System.out.println("Total length " + totalLength);
      System.out.printf("Average length %.6f",averageLength);
      System.out.printf("\n");
  }
}
