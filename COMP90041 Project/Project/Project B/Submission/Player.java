/*
* Subject: COMP90041 Programming and Software Development
* Project B
* Author: William Ngeow
* Student Number: 596301
* Date: May 5, 2016
* Comment: Player class represents a single player in game
*/

import java.util.Scanner; 

public class Player {
	
	private String username = "";
	private String familyName = ""; 
	private String givenName = "";
	private int numberGamesPlayed = 0;
	private int numberGamesWon = 0;
	private int numberGamesDrawn = 0;
	
	// No-argument constructor
	public Player () {

	}
	
	
	
	// Constructor with username, family name, and given name
	public Player (String newUsername, String newFamilyName, String newGivenName) {
		username = newUsername; 
		familyName = newFamilyName;
		givenName = newGivenName;
	}

	
	
	// Accessors and mutators 
	public String getUsername () {
		return username;
	}
	
	public void setUsername (String newUsername) {
		username = newUsername;
	}
	
	public String getFamilyName () {
		return familyName;
	}
	
	public void setFamilyName (String newFamilyName) {
		familyName = newFamilyName;
	}
	
	public String getGivenName () {
		return givenName;
	}
	
	public void setGivenName (String newGivenName) {
		givenName = newGivenName;
	}
	
	public int getNumberGamesPlayed () {
		return numberGamesPlayed; 
	}
	
	public void setNumberGamesPlayed (int newNumberGamesPlayed) {
		numberGamesPlayed = newNumberGamesPlayed;
	} 
	
	public int getNumberGamesWon () {
		return numberGamesWon; 
	}
	
	public void setNumberGamesWon (int newNumberGamesWon) {
		numberGamesWon = newNumberGamesWon;
	} 
	
	public int getNumberGamesDrawn () {
		return numberGamesDrawn; 
	}
	
	public void setNumberGamesDrawn (int newNumberGamesDrawn) {
		numberGamesDrawn = newNumberGamesDrawn;
	} 
}