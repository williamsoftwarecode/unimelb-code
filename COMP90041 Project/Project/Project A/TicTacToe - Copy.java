import java.util.Scanner; 

public class TicTacToe {
	
	Scanner keyboard = new Scanner(System.in);
	
	public static void main(String[] args) {
		TicTacToe game = new TicTacToe();
		game.run();
	}
	
	public void run () {
		
		System.out.println("Welcome to Tic Tac Toe!");
		System.out.println("\nEnter Player O's name:"); 
		String playerO = keyboard.next(); 
		System.out.println("\nEnter Player X's name:"); 
		String playerX = keyboard.next(); 
		keyboard.nextLine(); // remove \n for next nextLine()

		final char E = ' ';
		char[][] gridValues = { {E, E, E}, {E, E, E}, {E, E, E} };
		
		printGrid(gridValues);  
		
		int j = 0;
		while (j < 3) {
			System.out.println("\n" + playerO + "'s move:"); 
			String oMove = keyboard.nextLine(); 
			updateGrid(gridValues, oMove, 'O');
			printGrid(gridValues);
			
			System.out.println("\n" + playerX + "'s move:"); 
			String xMove = keyboard.nextLine(); 
			updateGrid(gridValues, xMove, 'X');
			printGrid(gridValues);
			
			j++;
		}	
	}
	
	public void printGrid (char[][] grid) { 
		System.out.println(grid[0][0] + "|" + grid[0][1] + "|" + grid[0][2]);
		System.out.println("-----"); 
		System.out.println(grid[1][0] + "|" + grid[1][1] + "|" + grid[1][2]); 
		System.out.println("-----"); 
		System.out.println(grid[2][0] + "|" + grid[2][1] + "|" + grid[2][2]);
	}
	
	public void updateGrid (char[][] grid, String moveNew, char type) { 
		
		final int ROW = 0;
		final int COLUMN = 1;
		
		String[] parts = moveNew.split(" ");
		int moveRow = Integer.parseInt(parts[ROW]);
		int moveColumn = Integer.parseInt(parts[COLUMN]);		
		
		if (type == 'O') {
			grid[moveRow][moveColumn] = 'O';
		}
		
		if (type == 'X') {
			grid[moveRow][moveColumn] = 'X';
		}
	}
}