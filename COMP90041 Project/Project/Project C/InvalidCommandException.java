/*
* Subject: COMP90041 Programming and Software Development
* Project C
* Author: William Ngeow
* Student Number: 596301
* Date: May 21, 2016
* Comment: InvalidCommandException class handles invalid input command.
*/

public class InvalidCommandException extends Exception{
	
	// Must have these two constructors
	public InvalidCommandException() {
		super("Invalid command.");
	}
	
	public InvalidCommandException(String message) {
		super(message);
	}
}
