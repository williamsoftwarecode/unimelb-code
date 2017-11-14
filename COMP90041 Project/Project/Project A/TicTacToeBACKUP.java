import java.util.Scanner; 

public class TicTacToe {
	
	Scanner keyboard = new Scanner(System.in);
	final int OWON = 1; 
	final int XWON = 2; 
	final int DRAW = 3; 
	final int CONT = 4;
	final char E = ' ';
	final int TURN = 2;

	public static void main(String[] args) {
		TicTacToe game = new TicTacToe();
		game.run();
	}
	
	public void run () {
		int state = CONT;

		System.out.println("Welcome to Tic Tac Toe!\n");
		System.out.println("Enter Player O's name:"); 
		String playerO = keyboard.next(); 
		System.out.println("Enter Player X's name:"); 
		String playerX = keyboard.next(); 
		keyboard.nextLine(); // remove \n for next nextLine()
		
		// Initialise grid
		char[][] gridValues = { {E, E, E}, {E, E, E}, {E, E, E} };
		printGrid(gridValues);
		
		int turn = TURN;		
		while (state == CONT) {
			
			if (turn%2 == 0) { 		// turn is for alternating between player O and X
				System.out.println(playerO + "'s move:"); 
				String oMove = keyboard.nextLine(); 
				updateGrid(gridValues, oMove, 'O');
				printGrid(gridValues);
				state = getGameState(gridValues);
			} else { 
				System.out.println(playerX + "'s move:"); 
				String xMove = keyboard.nextLine(); 
				updateGrid(gridValues, xMove, 'X');
				printGrid(gridValues);
				state = getGameState(gridValues);
			}
			turn++;
		}

		if (state == OWON) { 
			System.out.println("Game over. " + playerO + " won!"); 
		} else if (state == XWON) {
			System.out.println("Game over. " + playerX + " won!"); 
		} else if (state == DRAW) { 
			System.out.println("Game over. It was a draw!"); 
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
	
	public int getGameState (char[][] grid) { 
		int gameState = CONT;
		int numberFullSquares = 0;
		
		for (int i = 0; i < 3; i++) {
			// Check rows for win
			if (checkAllEqual(grid[i][0], grid[i][1], grid[i][2])) {
				gameState = checkWinner(grid[i][0]);	
			}				
			// Check columns for win
			if (checkAllEqual(grid[0][i], grid[1][i], grid[2][i])) {
				gameState = checkWinner(grid[0][i]);
			}
		}
			
		// Check Diagonals
		if (checkAllEqual(grid[0][0], grid[1][1], grid[2][2])) { 
			gameState = checkWinner(grid[0][0]); 
		}
			
		if (checkAllEqual(grid[2][0], grid[1][1], grid[0][2])) {
			gameState = checkWinner(grid[2][0]);
		}
			
		// Check Draw 
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) { 
				if (grid[j][k] != E) {
					numberFullSquares++; 
				}
			}
		}
		
		if (numberFullSquares == 9) { 
			gameState = DRAW;
		}
	return gameState; 
	} 
	
	public boolean checkAllEqual (char First, char Second, char Third) {
		boolean equal = false; 
		
		// Dismiss equal empty squares
		if ((First == E) || (Second == E) || (Third == E)) { 
			equal = true;
		}
		
		// Check for three equal squares
		if (First == Second) {
			if (Second == Third) {
				equal = true; 
			} else {
				equal = false;
			}
		} else { 
			equal = false; 
		}
		
		return equal;
	}
	
	public int checkWinner (char player) {		
		int winState = CONT; 
		
		if (player == 'O') { 
			winState = OWON;
		}
		
		if (player == 'X') { 
			winState = XWON;
		}
		
	return winState;
	} 
}