/*
* Subject: COMP90041 Programming and Software Development
* Project B
* Author: William Ngeow
* Student Number: 596301
* Date: May 24, 2016
* Comment: AIPlayer class represents a single player in game
*/

import java.util.Scanner; 

public class AIPlayer extends Player {
	private final char O = 'O';
	private final char X = 'X';
	private final char E = ' ';
	private final int MAXROWS = 3;
	private final int MAXCOLUMNS = 3;
	
	// No-argument constructor
	public AIPlayer () {
		super();
		setPlayerType("AI"); 
	}
	
	
	
	// Constructor with username, family name, and given name
	public AIPlayer (String newUsername, String newFamilyName, String newGivenName) {
		super();
		setUsername(newUsername); 
		setFamilyName(newFamilyName);
		setGivenName(newGivenName);
		setPlayerType("AI");
	}

	
	
	// Abstract method that returns an object of the Move class
	public Move makeMove(char[][] gameBoard) {
		Move move = new Move();
		
		for (int i=0; i<MAXROWS; i++) {
			for (int j=0; j<MAXCOLUMNS; j++) {
				if (gameBoard[i][j] == E) {
					move.setRow(i);
					move.setColumn(j);
					return move;
				}
			}
		}
		
		return move;
	}

}