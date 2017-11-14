/*
* Subject: COMP90041 Programming and Software Development
* Project B
* Author: William Ngeow
* Student Number: 596301
* Date: May 24, 2016
* Comment: HumanPlayer class represents a single player in game
*/

import java.util.Scanner; 

public class HumanPlayer extends Player {
	
	// No-argument constructor
	public HumanPlayer () {
		super();
		setPlayerType("Human"); 
	}
	
	
	
	// Constructor with username, family name, and given name
	public HumanPlayer (String newUsername, String newFamilyName, String newGivenName) {
		super();
		setUsername(newUsername); 
		setFamilyName(newFamilyName);
		setGivenName(newGivenName);
		setPlayerType("Human"); 
	}

	
	
	// Abstract method that returns an object of the Move class
	public Move makeMove(char[][] gameBoard) {
		Move move = new Move();

		move.setRow(TicTacToe.keyboard.nextInt());
		move.setColumn(TicTacToe.keyboard.nextInt());
		TicTacToe.keyboard.nextLine();		// remove \n for next nextLine() 
		return move;
	}

}