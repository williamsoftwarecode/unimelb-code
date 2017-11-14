/*
* Subject: COMP90041 Programming and Software Development
* Project B
* Author: William Ngeow
* Student Number: 596301
* Date: May 5, 2016
* Comment: TicTacToe class manages overall game system
*/

import java.util.Scanner; 
import java.util.StringTokenizer;

public class TicTacToe {
	
	public static Scanner keyboard = new Scanner(System.in);
	private String input = "";
	private final int MAXCOMMAND = 5;
	private final int FIRST = 0;
	private final int SECOND = 1;
	private final int THIRD = 2;
	private final int FORTH = 3;
	private final int OWON = 1; 
	private final int XWON = 2; 
	private final int DRAW = 3; 
	private String[] command = new String[MAXCOMMAND];

	private GameManager gameManager = new GameManager();
	private PlayerManager playerManager = new PlayerManager();
	
	public static void main(String[] args) {
		TicTacToe gameSystem = new TicTacToe();
		gameSystem.run();
	}
	
	public void run () {
		System.out.println("Welcome to Tic Tac Toe!");
		
		while(true) {
			
			boolean valid = false; 
			
			try {	
				command = new String[MAXCOMMAND];
				command[FIRST] = "";
				System.out.print("\n>"); 
				input = keyboard.nextLine(); 
			
				int i=0;
				StringTokenizer tokens = new StringTokenizer(input, " \n,");
				while(tokens.hasMoreTokens()) {
					command[i] = tokens.nextToken();
					i++;
				}
			
				// exit command
				if (command[FIRST].equals("exit")) {
					valid = true; 
					playerManager.writeFile();
					System.out.print("\n");
					System.exit(0);
				}
			
				// addplayer command
				if (command[FIRST].equals("addplayer")) {
					valid = true; 
					
					// Throw exception if there are less than 4 arguments (including command)
					if (command[FORTH] == null) {
						throw new InvalidNumberOfArgumentsException();
					}
				
				playerManager.addPlayer(command[SECOND],command[THIRD],command[FORTH]);
				}
			
				// removeplayer command				
				if (command[FIRST].equals("removeplayer")) {
					valid = true; 
					if (command[SECOND] != null) {
						playerManager.removePlayer(command[SECOND]);
					} else {
						playerManager.removePlayer();
					}
				}
			
				// editplayer command
				if (command[FIRST].equals("editplayer")) {
					valid = true; 
				
					// Throw exception if there are less than 4 arguments (including command)
					if (command[FORTH] == null) {
						throw new InvalidNumberOfArgumentsException();
					}
				
					playerManager.editPlayer(command[SECOND],command[THIRD],command[FORTH]);
				}
			
				// resetstats command
				if (command[FIRST].equals("resetstats")) {
					valid = true; 
					if (command[SECOND] != null) {
						playerManager.resetStats(command[SECOND]);
					} else {
						playerManager.resetStats();
					}
				}
			
				// displayplayer command				
				if (command[FIRST].equals("displayplayer")) {
					valid = true; 
					if (command[SECOND] != null) {
						playerManager.displayPlayer(command[SECOND]);
					} else {
						playerManager.displayPlayer();
					}
				}
			
				// rankings command
				if (command[FIRST].equals("rankings")) {
					valid = true; 
					playerManager.displayRanking();
				}
			
				// playgame command
				if (command[FIRST].equals("playgame")) {
					valid = true; 
				
					// Throw exception if there are less than 2 players
					if (command[THIRD] == null) {
						throw new InvalidNumberOfArgumentsException();
					}
				
					boolean playerAValid = playerManager.checkUsernameEqual(command[SECOND]);
					boolean playerBValid = playerManager.checkUsernameEqual(command[THIRD]);
				
					Player playerA = playerManager.getPlayer(command[SECOND]); 
					Player playerB = playerManager.getPlayer(command[THIRD]); 
				
					if (playerAValid && playerBValid) {
						gameManager.playGame(playerA, playerB);
					} else {
						System.out.println("Player does not exist.");
					}
				}
			
				// addaiplayer command
				if (command[FIRST].equals("addaiplayer")) {
					valid = true; 
				
					// Throw exception if there are less than 4 arguments (including command)
					if (command[FORTH] == null) {
						throw new InvalidNumberOfArgumentsException();
					}
				
					playerManager.addAIPlayer(command[SECOND],command[THIRD],command[FORTH]);
				}
			
				// Throw exception if input command is invalid
				if (valid == false) {
					String errorMessage = "'"+command[FIRST]+"' is not a valid command.";
					throw new InvalidCommandException(errorMessage);
				}
			}
			
			catch (InvalidCommandException e) {
				System.out.println(e.getMessage());
			}
			
			catch (InvalidNumberOfArgumentsException e) {
				System.out.println(e.getMessage());
			}
		}
	}
}