/*
* Subject: COMP90041 Programming and Software Development
* Project B
* Author: William Ngeow
* Student Number: 596301
* Date: May 5, 2016
* Comment: PlayerManager class manages current players in game system
*/

import java.util.Scanner; 
import java.io.FileInputStream;
import java.io.PrintWriter; 
import java.io.FileOutputStream; 
import java.io.FileNotFoundException;

public class PlayerManager {
	
	private final int INITIAL = 0;
	private final int NUMBER_TOP_PLAYERS = 10;
	private final int MAXPLAYERS = 100;
	private final int PERCENT = 100;
	private final double ONE = 1.0;
	private final int A_MORE_B = 1;
	private final int B_MORE_A = -1;
	private final int EQUAL = 0;
	private final int A_THEN_B = -1;
	private final int B_THEN_A = 1;
	private final String FILE_NAME = "player.dat";
	
	// Current number of Players
	private int numberPlayers = INITIAL;
	private Player[] players = new Player[MAXPLAYERS];
	PrintWriter outputStream = null;
	Scanner inputStream = null;	
	
	public PlayerManager () {

		try {
			// Reads file contents as file input stream
			inputStream = new Scanner(new FileInputStream(FILE_NAME));
		
			// Reads player data from file input stream 
			while (inputStream.hasNext() != false) {
				
				String playerType = inputStream.next();
				if (playerType.equals("Human")) {
					players[numberPlayers] = new HumanPlayer(); 
					inputStream.nextLine();
				} else if (playerType.equals("AI")) {
					players[numberPlayers] = new AIPlayer(); 
					inputStream.nextLine();
				}
				
				players[numberPlayers].setUsername(inputStream.next());
				inputStream.nextLine();			
				players[numberPlayers].setFamilyName(inputStream.next());
				inputStream.nextLine();		
				players[numberPlayers].setGivenName(inputStream.next());
				inputStream.nextLine();		
				players[numberPlayers].setNumberGamesPlayed(inputStream.nextInt());
				inputStream.nextLine();		
				players[numberPlayers].setNumberGamesWon(inputStream.nextInt());
				inputStream.nextLine();		
				players[numberPlayers].setNumberGamesDrawn(inputStream.nextInt());
				inputStream.nextLine();		
				numberPlayers = numberPlayers + 1; 
			}
		}
		
		catch (FileNotFoundException e) {
			try {
				// Creates new file
				outputStream = new PrintWriter(new FileOutputStream(FILE_NAME));
			}
			catch (FileNotFoundException e1) {
				System.out.println("NOT FOUND.");
				System.exit(0);
			}
		}
	}
	

	// Adds Human player to the array
	public void addPlayer (String newUsername, String newFamilyName, String newGivenName) {
		if (checkUsernameEqual(newUsername) == false) {
			players[numberPlayers] = new HumanPlayer(); 
			players[numberPlayers].setUsername(newUsername);
			players[numberPlayers].setFamilyName(newFamilyName);
			players[numberPlayers].setGivenName(newGivenName);
			numberPlayers = numberPlayers + 1; 
		} else {
			System.out.println("The username has been used already.");
			return;
		}
		
	}
	
	
	
	// Adds AI player to the array
	public void addAIPlayer (String newUsername, String newFamilyName, String newGivenName) {
		if (checkUsernameEqual(newUsername) == false) {
			players[numberPlayers] = new AIPlayer(); 
			players[numberPlayers].setUsername(newUsername);
			players[numberPlayers].setFamilyName(newFamilyName);
			players[numberPlayers].setGivenName(newGivenName);
			numberPlayers = numberPlayers + 1; 
		} else {
			System.out.println("The username has been used already.");
			return;
		}
		
	}
	
	
	
	// Removes player with specified username
	public void removePlayer (String newUsername) {
		int usernamePosition = INITIAL;
		
		if (checkUsernameEqual(newUsername) == true) {
			usernamePosition = checkUsernamePosition(newUsername);
			
			// Shift player position one step back (overwrites removed player)
			for (int i=usernamePosition; i<(numberPlayers-1); i++) {
				players[i] = players[i+1];
			}
			
			// Remove the final player from the array
			players[numberPlayers-1] = null;  
			
			// Update number of players
			numberPlayers--;
			
		} else {
			
			// When removing a non-existent user
			System.out.println("The player does not exist.");
			return;
		}
	}
	
	
	
	// Removes all players
	public void removePlayer () {
		String input = "";
		
		System.out.println("Are you sure you want to remove all players? (y/n)");
		input = TicTacToe.keyboard.next(); 
		TicTacToe.keyboard.nextLine(); 	// remove \n for the next input
		
		if (input.equals("y")) {
			
			// Remove all players in the array
			for (int i=0; i<numberPlayers; i++) {
				players[i] = null;  // OR NULL
			}
			
			// Reinitialise number of players
			numberPlayers = INITIAL;
			
		} else {
			return;
		}
	}
	
	
	
	// Edit family name and given name of specified username
	public void editPlayer (String newUsername, String newFamilyName, String newGivenName) {
		int usernamePosition = INITIAL;
		
		if (checkUsernameEqual(newUsername) == true) {
			usernamePosition = checkUsernamePosition(newUsername);
			
			// Edit names
			players[usernamePosition].setFamilyName(newFamilyName);
			players[usernamePosition].setGivenName(newGivenName);
			
		} else {
			
			// When editing a non-existent user
			System.out.println("The player does not exist.");
			return;
		}
	}
	
	
	
	// Reset player statistics with specified username
	public void resetStats (String newUsername) {
		int usernamePosition = INITIAL;
		
		if (checkUsernameEqual(newUsername) == true) {
			usernamePosition = checkUsernamePosition(newUsername);
			
			// Reset statistics
			players[usernamePosition].setNumberGamesPlayed(INITIAL);
			players[usernamePosition].setNumberGamesWon(INITIAL);
			players[usernamePosition].setNumberGamesDrawn(INITIAL);
			
		} else {
			
			// When removing a non-existent user
			System.out.println("The player does not exist.");
			return;
		}
	}
	
	
	
	// Reset all players statistics
	public void resetStats () {
		String input = "";
		
		System.out.println("Are you sure you want to reset all player statistics? (y/n)");
		input = TicTacToe.keyboard.next(); 
		TicTacToe.keyboard.nextLine(); 	// remove \n for the next input
		
		if (input.equals("y")) {
			
			// Reset all player statistics in the array
			for (int i=0; i<numberPlayers; i++) {
				players[i].setNumberGamesPlayed(INITIAL);
				players[i].setNumberGamesWon(INITIAL);
				players[i].setNumberGamesDrawn(INITIAL);
			}
			
		} else {
			return;
		}
	}
	
	
	
	// Display player information with specified username
	public void displayPlayer (String newUsername) {
		int usernamePosition = INITIAL;
		
		if (checkUsernameEqual(newUsername) == true) {
			usernamePosition = checkUsernamePosition(newUsername);
			
			// Display player information
			printPlayers(usernamePosition);
			
		} else {
			
			// When removing a non-existent user
			System.out.println("The player does not exist.");
			return;
		}
	}
	
	
	
	// Display all player information
	public void displayPlayer () {
		sortAlphabetical();
		for (int i=0; i<numberPlayers; i++) {
			printPlayers(i);
		}
	}
	
	
	
	// Outputs the top-10 players ranked based on winning ration from highest to lowest
	public void displayRanking () {
		int winRatio = INITIAL;
		int drawRatio = INITIAL;
		int numberGamesPlayed = INITIAL;
		String username = "";
		
		sortWinDrawAlphabetical(); 
		System.out.println(" WIN  | DRAW | GAME | USERNAME"); 
		
		if (numberPlayers <= NUMBER_TOP_PLAYERS) {
			
			// Fewer than 10 players
			for (int i=0; i<numberPlayers; i++) {
				winRatio = (int) Math.round(computeWinRatio(players[i])*PERCENT); 
				drawRatio = (int) Math.round(computeDrawRatio(players[i])*PERCENT);
				numberGamesPlayed = players[i].getNumberGamesPlayed();
				username = players[i].getUsername();
				printFormat(winRatio, drawRatio, numberGamesPlayed, username);
			}
		} else {
			
			// More than 10 players
			for (int i=0; i<NUMBER_TOP_PLAYERS; i++) {
				winRatio = (int) Math.round(computeWinRatio(players[i])*PERCENT); 
				drawRatio = (int) Math.round(computeDrawRatio(players[i])*PERCENT);
				numberGamesPlayed = players[i].getNumberGamesPlayed();
				username = players[i].getUsername();
				printFormat(winRatio, drawRatio, numberGamesPlayed, username);
			}
		}
	}
	
	
	
	// Prints player ranking statistics in desired format
	private void printFormat (int win, int draw, int game, String username) {
		System.out.printf(" %3d%% | %3d%% | %2d   | %s\n", win, draw, game, username); 
	}
	
	
	
	// Checks if username is already in the array
	public boolean checkUsernameEqual (String newUsername) {
		boolean isEqual = false;
		String oldUsername = "";
		
		for (int i=0; i<numberPlayers; i++) {
			oldUsername = players[i].getUsername();
			if (oldUsername.equals(newUsername)) {
				isEqual = true; 
				break;
			} else {
				isEqual = false;
			}
		}
		return isEqual;
	} 
	
	
	
	// Checks username position in the array
	private int checkUsernamePosition (String newUsername) {
		int position = INITIAL;
		String oldUsername = "";
		
		for (int i=0; i<numberPlayers; i++) {
			oldUsername = players[i].getUsername();
			if (oldUsername.equals(newUsername)) {
				position = i; 
			}
		}
		return position;
	} 

	
	
	// Rearranges the array in alphabetical order of username
	private void sortAlphabetical () {
		
		// Uses insertion sort
		for (int i=0; i<numberPlayers; i++) {
			for (int j=i; j<numberPlayers; j++) {
				
				// If alphabetically higher, swap
				if (players[i].getUsername().compareTo(players[j].getUsername()) > 0) {
					Player temp = players[i]; 
					players[i] = players[j];
					players[j] = temp;
				}
			
			}
		}	

	}

	
	
	// Rearranges the array based on winning ratio
	// Ties are broken by drawing ratio, then username alphabetically
	// Sort in order of highest to lowest
	// Uses insertion sort
	private void sortWinDrawAlphabetical () {
		
		// If winRatio of the second is higher, swap
		for (int i=0; i<numberPlayers; i++) {
			for (int j=i; j<numberPlayers; j++) {
				if (compareWinRatio(players[i], players[j]) < 0) {
					Player temp = players[i]; 
					players[i] = players[j];
					players[j] = temp;
				} 
			}
		}	
		
		// If winRatio is equal, compare draw ratio
		for (int i=0; i<numberPlayers; i++) {
			for (int j=i; j<numberPlayers; j++) {
				if (compareWinRatio(players[i], players[j]) == 0) {
					if (compareDrawRatio(players[i], players[j]) < 0) {
						Player temp = players[i]; 
						players[i] = players[j];
						players[j] = temp;
					} 
				}
			}
		}	
		
		// If winRatio and drawRatio is equal, compare alphabetical order of username
		for (int i=0; i<numberPlayers; i++) {
			for (int j=i; j<numberPlayers; j++) {
				if (compareWinRatio(players[i], players[j]) == 0) {
					if (compareDrawRatio(players[i], players[j]) == 0) {
						if (compareUsernameAlphabetical(players[i], players[j]) > 0) {
							Player temp = players[i]; 
							players[i] = players[j];
							players[j] = temp;
						}
					}
				}
			}
		}	
	}
	
	
	
	// Compares username in alphabetical order
	private int compareUsernameAlphabetical (Player A, Player B) {
		int order = INITIAL;
		if (A.getUsername().compareTo(B.getUsername()) < 0) {
			order = A_THEN_B; 		// Player A comes before Player B 
		} else if (A.getUsername().compareTo(B.getUsername()) > 0) {
			order = B_THEN_A;		// Player B comes before Player A 
		} else {
			order = EQUAL; 			// Player A and Player B are equivalent
		}
		return order;
	}
	
	
	
	// Compares winRatio of player A and player B
	private int compareWinRatio (Player A, Player B) {
		int order = INITIAL;
		double winRatioA = computeWinRatio(A);
		double winRatioB = computeWinRatio(B);
		
		if (winRatioA > winRatioB) {
			order = A_MORE_B; 		// Player A is higher than Player B 
		} else if (winRatioA < winRatioB) {
			order = B_MORE_A;		// Player B is higher than Player A 
		} else {
			order = EQUAL; 			// Player A and Player B are equivalent
		}
		return order;
	}	
	
	
	
	// Compares drawRatio of player A and player B
	private int compareDrawRatio (Player A, Player B) {
		int order = INITIAL;
		double drawRatioA = computeDrawRatio(A);
		double drawRatioB = computeDrawRatio(B);
		
		if (drawRatioA > drawRatioB) {
			order = A_MORE_B; 		// Player A is higher than Player B 
		} else if (drawRatioA < drawRatioB) {
			order = B_MORE_A;		// Player B is higher than Player A 
		} else {
			order = EQUAL; 			// Player A and Player B are equivalent
		}
		return order;
	}	
	
	
	
	// Compute winRatio of player
	private double computeWinRatio (Player player) {
		double winRatio = INITIAL;
		
		if (player.getNumberGamesWon() > 0) {
			winRatio = ONE*(player.getNumberGamesWon()) / (player.getNumberGamesPlayed());
		} else {
			winRatio = INITIAL;
		}
		return winRatio;
	}
	
	
	
	// Compute drawRatio of player
	private double computeDrawRatio (Player player) {
		double drawRatio = INITIAL; 
		
		if (player.getNumberGamesDrawn() > 0) {
			drawRatio = ONE*(player.getNumberGamesDrawn())/(player.getNumberGamesPlayed());
		} else {
			drawRatio = INITIAL;
		}
		return drawRatio;
	}
	
	
	
	// Print player information
	private void printPlayers (int position) {
		System.out.print(players[position].getUsername() + ",");
		System.out.print(players[position].getFamilyName() + ",");
		System.out.print(players[position].getGivenName() + ",");		
		System.out.print(players[position].getNumberGamesPlayed() + " games,"); 
		System.out.print(players[position].getNumberGamesWon() + " wins,"); 
		System.out.print(players[position].getNumberGamesDrawn() + " draws");
		System.out.print("\n");
	}
	
	
	
	// Returns given name of player
	public String getPlayerGivenName (String playerUsername) {
		int position = checkUsernamePosition(playerUsername);
		String givenName = players[position].getGivenName();
		return givenName;
	}
	
	
	
	// Returns player object given the username
	public Player getPlayer (String newUsername) {
		int playerPosition = checkUsernamePosition(newUsername);
		return players[playerPosition]; 
	}
	
	
	
	// Write player information to file
	private void writePlayers (int position) {
		outputStream.println(players[position].getPlayerType());
		outputStream.println(players[position].getUsername());
		outputStream.println(players[position].getFamilyName());
		outputStream.println(players[position].getGivenName());		
		outputStream.println(players[position].getNumberGamesPlayed()); 
		outputStream.println(players[position].getNumberGamesWon()); 
		outputStream.println(players[position].getNumberGamesDrawn());
	}
	
	
	
	// Writes all player information to file
	public void writeFile () {
		sortAlphabetical();
		
		try {
			// Creates new file, overriding previous player.dat
			outputStream = new PrintWriter(new FileOutputStream(FILE_NAME));
		}
		catch (FileNotFoundException e2) {
			System.out.println("NOT FOUND.");
			System.exit(0);
		}		
		
		for (int i=0; i<numberPlayers; i++) {
			writePlayers(i);
		}
		outputStream.close();
	}

}