/*
* Subject: COMP90041 Programming and Software Development
* Project C
* Author: William Ngeow
* Student Number: 596301
* Date: May 21, 2016
* Comment: This class handles invalid number of arguments.
*/

public class InvalidNumberOfArgumentsException extends Exception{
	
	// Must have these two constructors
	public InvalidNumberOfArgumentsException() {
		super("Incorrect number of arguments supplied to command.");
	}
	
	public InvalidNumberOfArgumentsException(String message) {
		super(message);
	}
}
