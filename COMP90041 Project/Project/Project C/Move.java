/*
* Subject: COMP90041 Programming and Software Development
* Project B
* Author: William Ngeow
* Student Number: 596301
* Date: May 24, 2016
* Comment: Move class represents a single move made by a player
*/

import java.util.Scanner; 

public class Move {
	
	private int rowNumber = 0;
	private int columnNumber = 0;
	
	// No-argument constructor
	public Move () {

	}
	
	// Constructor with row input and column input
	public Move (int rowInput, int columnInput) {
		rowNumber = rowInput; 
		columnNumber = columnInput;
	}

	// Accessors and mutators 
	public int getRow () {
		return rowNumber; 
	}
	
	public void setRow (int newRow) {
		rowNumber = newRow;
	} 
	
	public int getColumn () {
		return columnNumber; 
	}
	
	public void setColumn (int newColumn) {
		columnNumber = newColumn;
	} 
}