import java.util.Scanner; 

public class ttt {
	
	Scanner keyboard = new Scanner(System.in);
	
	public static void main(String[] args) {
		TicTacToe game = new TicTacToe();
    game.setNamePlayerO("WOOHOOOO");
		String name1 = game.getNamePlayerO(); 
    game.setNamePlayerX("WOOHOOOO222");
		String name2 = game.getNamePlayerX(); 
    System.out.println(name1 + " " + name2);
	}
	
}