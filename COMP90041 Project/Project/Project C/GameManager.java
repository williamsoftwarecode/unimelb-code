/*
* Subject: COMP90041 Programming and Software Development
* Project B
* Author: William Ngeow
* Student Number: 596301
* Date: May 5, 2016
* Comment: GameManager handles a two-player TicTacToe game
*/

import java.util.Scanner; 

public class GameManager {
	
	private final int OWON = 1; 
	private final int XWON = 2; 
	private final int DRAW = 3; 
	private final int CONT = 4;
	private final char O = 'O';
	private final char X = 'X';
	private final char E = ' ';
	private final int TURN = 2;
	private final int START = 0;
	private final int MAXROWS = 3;
	private final int MAXCOLUMNS = 3;
	private final int MAXSQUARES = 9;
	private final int INBOUNDARY = 0;
	private final int OUTBOUNDARY = 1;
	private final int LOWBOUNDARY = 0;
	private final int HIGHBOUNDARY = 2;
	private final int OCCUPIED = 1;
	private final int NOTOCCUPIED = 0;
	private final int ERROR = 1;
	private final int NOERROR = 0;
	private final int INITIAL = 0;
	private char[][] grid = { {E, E, E}, {E, E, E}, {E, E, E} }; // initialise grid
	private String namePlayerO = "";
	private String namePlayerX = "";
	private Move move = new Move();
	
	// Returns 1 if O wins, 2 if X wins, 3 if draw
	public void playGame (Player playerA, Player playerB) {
		int state = CONT;
		int turn = TURN;
		int moveRow = START;
		int moveColumn = START; 
		char currentPlayer = E;
		namePlayerO = playerA.getGivenName(); 
		namePlayerX = playerB.getGivenName();
		
		initialiseGrid();	// initialise empty grid
		printGrid();		// print empty grid
		
		while (state == CONT) {
			if (turn%TURN == 0) {	// "turn" to alternate between player O and X
				System.out.println(namePlayerO + "'s move:"); 
				move = playerA.makeMove(grid);
				moveRow = move.getRow();
				moveColumn = move.getColumn();
				
				while (determineError(moveRow, moveColumn) == ERROR) {
					
					if (checkOutOfCellBoundary(moveRow,moveColumn) == OUTBOUNDARY) {
						System.out.print("Invalid move. "); 
						System.out.println("You must place at a cell within {0,1,2} {0,1,2}.");
					} else if (checkCellOccupied(moveRow,moveColumn) == OCCUPIED) {
						System.out.print("Invalid move. "); 
						System.out.println("The cell has been occupied.");
					}
					
					System.out.println(namePlayerO + "'s move:");
					move = playerA.makeMove(grid);
					moveRow = move.getRow();
					moveColumn = move.getColumn();
				}				
				
				currentPlayer = O;
				updateGrid(moveRow, moveColumn, currentPlayer);
				printGrid();
				state = getGameState();
			} else { 
				System.out.println(namePlayerX + "'s move:"); 
				move = playerB.makeMove(grid);
				moveRow = move.getRow();
				moveColumn = move.getColumn();
				
				while (determineError(moveRow, moveColumn) == ERROR) {
					
					if (checkOutOfCellBoundary(moveRow,moveColumn) == OUTBOUNDARY) {
						System.out.print("Invalid move. "); 
						System.out.println("You must place at a cell within {0,1,2} {0,1,2}.");
					} else if (checkCellOccupied(moveRow,moveColumn) == OCCUPIED) {
						System.out.print("Invalid move. "); 
						System.out.println("The cell has been occupied.");
					}
					
					System.out.println(namePlayerX + "'s move:");
					move = playerB.makeMove(grid);
					moveRow = move.getRow();
					moveColumn = move.getColumn();
				}		
				
				currentPlayer = X;
				updateGrid(moveRow, moveColumn, currentPlayer);
				printGrid();
				state = getGameState();
			}
			turn++;					// next turn
		}
		
		// Print game over message
		if (state == OWON) { 
			updateStatsWin(playerA);
			updateStatsLose(playerB);
			System.out.println("Game over. " + namePlayerO + " won!"); 
		} else if (state == XWON) {
			updateStatsLose(playerA);
			updateStatsWin(playerB);
			System.out.println("Game over. " + namePlayerX + " won!"); 
		} else if (state == DRAW) { 
			updateStatsDraw(playerA);
			updateStatsDraw(playerB);
			System.out.println("Game over. It was a draw!"); 
		}
	}
	
	private void initialiseGrid () {
		for (int i=0; i<MAXROWS; i++) {
			for (int j=0; j<MAXCOLUMNS; j++) {
				grid[i][j] = E; 				
			}
		}
	}
	
	private void printGrid () { 
		System.out.println(grid[0][0] + "|" + grid[0][1] + "|" + grid[0][2]);
		System.out.println("-----"); 
		System.out.println(grid[1][0] + "|" + grid[1][1] + "|" + grid[1][2]); 
		System.out.println("-----"); 
		System.out.println(grid[2][0] + "|" + grid[2][1] + "|" + grid[2][2]);
	}
	
	private void updateGrid (int moveRowNew, int moveColumnNew, char player) { 	
		if (player == O) {
			grid[moveRowNew][moveColumnNew] = O;
		} else if (player == X) {
			grid[moveRowNew][moveColumnNew] = X;
		}
	}
	
	private int getGameState () { 
		int gameState = CONT;
		int numberFullSquares = START;
		
		// Check for full grid 
		for (int j = 0; j < MAXROWS; j++) {
			for (int k = 0; k < MAXCOLUMNS; k++) { 
				if (grid[j][k] != E) {
					numberFullSquares++; 
				}
			}
		}
		
		// Check for draw
		// Note: If a player wins in the final turn, gameState is changed BELOW
		if (numberFullSquares == MAXSQUARES) { 
			gameState = DRAW;
		}
	
		// Check rows and columns for win
		for (int i = 0; i < MAXROWS; i++) {
			if (checkAllEqual(grid[i][0], grid[i][1], grid[i][2])) {
				gameState = checkWinner(grid[i][0]);	// row win
				return gameState; 
			} else if (checkAllEqual(grid[0][i], grid[1][i], grid[2][i])) {
				gameState = checkWinner(grid[0][i]);	// column win
				return gameState; 
			}
		}
			
		// Check diagonals for win
		if (checkAllEqual(grid[0][0], grid[1][1], grid[2][2])) { 	
			gameState = checkWinner(grid[0][0]); 	// diagonal win
			return gameState; 
		} else if (checkAllEqual(grid[2][0], grid[1][1], grid[0][2])) {    
			gameState = checkWinner(grid[2][0]);	// antidiagonal win
			return gameState; 
		}
	
		return gameState; 
	} 
	
	private boolean checkAllEqual (char First, char Second, char Third) {
		boolean equal = false; 
		
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
		
		// Dismiss equal empty squares
		if ((First == E) || (Second == E) || (Third == E)) { 
			equal = false;
		}
		
		return equal;
	}
	
	private int checkWinner (char player) {	
		int winState = CONT; 
		
		if (player == 'O') { 
			winState = OWON;
		}
		
		if (player == 'X') { 
			winState = XWON;
		}
		
		return winState;
	} 
	
	public String getNamePlayerO () {
		return namePlayerO;
	}
	
	public String getNamePlayerX () {
		return namePlayerX;
	}
	
	public void setNamePlayerO (String newNamePlayerO) {
		namePlayerO = newNamePlayerO;
	}
	
	public void setNamePlayerX (String newNamePlayerX) {
		namePlayerX = newNamePlayerX;
	}
	
	
	
	// Checks if input is within cell boundary
	// Returns 1 if out of boundary and 0 if within boundary
	private int checkOutOfCellBoundary (int row, int column) {
		int inBoundary = INBOUNDARY;
		boolean rowInBoundary = ((row >= LOWBOUNDARY) && (row <= HIGHBOUNDARY));
		boolean columnInBoundary = ((column >= LOWBOUNDARY) && (column <= HIGHBOUNDARY));
		
		if (rowInBoundary && columnInBoundary) {
			inBoundary = INBOUNDARY; 	// Move is in Boundary
		} else {
			inBoundary = OUTBOUNDARY;	// Move is not in Boundary
		}
		return inBoundary;
	}
	
	
	
	// Checks if cell has been occupied
	// Returns 1 if occupied and 0 if not occupied
	private int checkCellOccupied (int row, int column) {
		int cellOccupied = OCCUPIED;
		if (checkOutOfCellBoundary(row,column) == INBOUNDARY) {
			if (grid[row][column] == E) {
				cellOccupied = NOTOCCUPIED;
			}
		}
		return cellOccupied;
	}
	
	
	
	// Determines if an error has occured
	// Returns 1 if there is an error and 0 if there is no error
	private int determineError (int row, int column) {
		int error = NOERROR;
		
		if (checkOutOfCellBoundary(row,column) == OUTBOUNDARY) {
			error = ERROR;
		}
		
		if (checkCellOccupied(row,column) == OCCUPIED) {
			error = ERROR;
		}
		return error;
	}		
	
	
	
	// Update winner statistics after game
	private void updateStatsWin (Player player) {
		int oldNumberGamesPlayed = INITIAL;
		int oldNumberGamesWon = INITIAL;
		int newNumberGamesPlayed = INITIAL;
		int newNumberGamesWon = INITIAL;
		
		// Check old statistics
		oldNumberGamesPlayed = player.getNumberGamesPlayed();
		oldNumberGamesWon = player.getNumberGamesWon();
		
		newNumberGamesPlayed = oldNumberGamesPlayed + 1;
		newNumberGamesWon = oldNumberGamesWon + 1;
		
		// Update statistics
		player.setNumberGamesPlayed(newNumberGamesPlayed);
		player.setNumberGamesWon(newNumberGamesWon);
	}
	
	
	
	// Update draw statistics after game
	private void updateStatsDraw (Player player) {
		int oldNumberGamesPlayed = INITIAL;
		int oldNumberGamesDrawn = INITIAL;
		int newNumberGamesPlayed = INITIAL;
		int newNumberGamesDrawn = INITIAL;

		// Check old statistics
		oldNumberGamesPlayed = player.getNumberGamesPlayed();
		oldNumberGamesDrawn = player.getNumberGamesDrawn();
		
		newNumberGamesPlayed = oldNumberGamesPlayed + 1;
		newNumberGamesDrawn = oldNumberGamesDrawn + 1;
			
		// Update statistics
		player.setNumberGamesPlayed(newNumberGamesPlayed);
		player.setNumberGamesDrawn(newNumberGamesDrawn);
	}
	
	
	
	// Update loser statistics after game
	private void updateStatsLose (Player player) {
		int oldNumberGamesPlayed = INITIAL;
		int newNumberGamesPlayed = INITIAL;
		
		// Check old statistics
		oldNumberGamesPlayed = player.getNumberGamesPlayed();
		newNumberGamesPlayed = oldNumberGamesPlayed + 1;
		
		// Update statistics
		player.setNumberGamesPlayed(newNumberGamesPlayed);
	}	
}