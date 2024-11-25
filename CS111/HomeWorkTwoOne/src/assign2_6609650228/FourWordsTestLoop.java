///Name: Jutinut Ratanamongkonkul
///SID:6609650228


package assign2_6609650228;
import java.util.Scanner;

public class FourWordsTestLoop {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FourWords words4 = new FourWords();
        Scanner scanner = new Scanner(System.in);
        int round = 0;

        System.out.println("No words set up yet!");
        words4.printWords();
        System.out.printf("\n");
        
        while (round < 5) {
            System.out.print("Enter your word: ");
            String word = scanner.nextLine();
            round++;

            words4.add(word);
            System.out.printf("Round " + round + ":");
            words4.printWords();
            System.out.printf("\n");
        }
        }
	}

