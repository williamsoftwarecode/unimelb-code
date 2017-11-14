/*
* Subject: COMP90041 Programming and Software Development
* Assignment 1: TicTacToe
* Author: William Ngeow
* Student Number: 596301
* Date: Mar 10, 2016
* Comment: Simple two-player TicTacToe game
*/

import java.util.Scanner; 

public class TicTacToe {
	
	Scanner keyboard = new Scanner(System.in);
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
	private char[][] grid = { {E, E, E}, {E, E, E}, {E, E, E} }; // initialise grid
	String namePlayerO = "";
	String namePlayerX = "";
	
	public static void main(String[] args) {
		TicTacToe game = new TicTacToe();
		game.run();
	}
	
	public void run () {
		int state = CONT;
		int turn = TURN;
		int moveRow = START;
		int moveColumn = START; 
		char currentPlayer = E;
		
		System.out.println("Welcome to Tic Tac Toe!\n");
		System.out.println("Enter Player O's name:"); 
		namePlayerO = keyboard.next(); 
		System.out.println("Enter Player X's name:"); 
		namePlayerX = keyboard.next(); 
		keyboard.nextLine();		// remove \n for next nextLine()
		printGrid();				// print empty grid
		
		while (state == CONT) {
			if (turn%TURN == 0) {	// "turn" to alternate between player O and X
				System.out.println(namePlayerO + "'s move:"); 
				moveRow = keyboard.nextInt();
				moveColumn = keyboard.nextInt();
				currentPlayer = O;
				updateGrid(moveRow, moveColumn, currentPlayer);
				printGrid();
				state = getGameState();
			} else { 
				System.out.println(namePlayerX + "'s move:"); 
				moveRow = keyboard.nextInt();
				moveColumn = keyboard.nextInt();
				currentPlayer = X;
				updateGrid(moveRow, moveColumn, currentPlayer);
				printGrid();
				state = getGameState();
			}
			turn++;					// next turn
		}
		
		// Print game over message
		if (state == OWON) { 
			System.out.println("Game over. " + namePlayerO + " won!"); 
		} else if (state == XWON) {
			System.out.println("Game over. " + namePlayerX + " won!"); 
		} else if (state == DRAW) { 
			System.out.println("Game over. It was a draw!"); 
		}
	}
	
	public void printGrid () { 
		System.out.println(grid[0][0] + "|" + grid[0][1] + "|" + grid[0][2]);
		System.out.println("-----"); 
		System.out.println(grid[1][0] + "|" + grid[1][1] + "|" + grid[1][2]); 
		System.out.println("-----"); 
		System.out.println(grid[2][0] + "|" + grid[2][1] + "|" + grid[2][2]);
	}
	
	public void updateGrid (int moveRowNew, int moveColumnNew, char player) { 	
		if (player == O) {
			grid[moveRowNew][moveColumnNew] = O;
		} else if (player == X) {
			grid[moveRowNew][moveColumnNew] = X;
		}
	}
	
	public int getGameState () { 
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
			} else if (checkAllEqual(grid[0][i], grid[1][i], grid[2][i])) {
				gameState = checkWinner(grid[0][i]);	// column win
			}
		}
			
		// Check diagonals for win
		if (checkAllEqual(grid[0][0], grid[1][1], grid[2][2])) { 	
			gameState = checkWinner(grid[0][0]); 	// diagonal win
		} else if (checkAllEqual(grid[2][0], grid[1][1], grid[0][2])) {    
			gameState = checkWinner(grid[2][0]);	// antidiagonal win
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
}