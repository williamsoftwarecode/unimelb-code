/*
* Subject: COMP90041 Programming and Software Development
* Project B
* Author: William Ngeow
* Student Number: 596301
* Date: May 5, 2016
* Comment: TicTacToe class manages overall game system
*/

import java.util.Scanner; 

// Testing class
public class TTT {
	
	Scanner keyboard = new Scanner(System.in);
	String input = "";
	
	public static void main(String[] args) {
		TTT gameSystem = new TTT();
		gameSystem.run();
	}
	
	public void run () {
		
		System.out.println("Welcome to Tic Tac Toe!\n");
		System.out.print(">"); 
		
		PlayerManager manager = new PlayerManager(); 
		manager.addPlayer("playerone","family","given");
		manager.addPlayer("playertwo","family2","given2");
		manager.addPlayer("playerthree","family3","given3");
		manager.addPlayer("playerfour","family4","given4");
		manager.addPlayer("playerfive","family5","given5");
		manager.addPlayer("playersix","family6","given6");
		//manager.displayPlayer();
		
		//manager.removePlayer("playertwo");
		//manager.displayPlayer();
		
		//manager.removePlayer();
		//manager.displayPlayer();
		
		//manager.editPlayer("playerthree","stupid","username");
		//manager.displayPlayer();
		
		//manager.editPlayer("noexist","stupid","username");
		
		//manager.resetStats("playertwo");
		//manager.displayPlayer();
		
		//manager.resetStats("playertwo2");
		//manager.displayPlayer();
		
		//manager.resetStats();
		//manager.displayPlayer();
		
		//manager.displayPlayer("playerthree");
		//manager.displayPlayer("player3");
		//manager.displayPlayer();
		
		// manager.updateStatsWin("playertwo");
		// manager.updateStatsWin("playertwo");
		// manager.updateStatsDraw("playerfour");
		// manager.updateStatsDraw("playerfour");
		// manager.updateStatsWin("playerthree");
		// manager.updateStatsDraw("playerthree");
		// manager.updateStatsDraw("playerfive");
		// manager.updateStatsDraw("playersix");
		// manager.updateStatsLose("playersix");
		
		manager.displayPlayer();

		manager.displayRanking();
	}
	
	public void test () {
		Player playersss[] = new Player[100];
		playersss[1] = new Player("playerone","family","given");
		
		
		System.out.println(playersss[1].getUsername());
		System.out.println(playersss[1].getFamilyName());
		System.out.println(playersss[1].getGivenName());
		System.out.println(playersss[1].getNumberGamesPlayed()); 
		System.out.println(playersss[1].getNumberGamesWon()); 		
		System.out.println(playersss[1].getNumberGamesDrawn()); 

		playersss[1].setUsername("playertwo");
		playersss[1].setFamilyName("familytwo"); 
		playersss[1].setGivenName("givent123");
		playersss[1].setNumberGamesPlayed(1);
		playersss[1].setNumberGamesWon(2); 
		playersss[1].setNumberGamesDrawn(4);
		
		System.out.println(playersss[1].getUsername());
		System.out.println(playersss[1].getFamilyName());
		System.out.println(playersss[1].getGivenName());
		System.out.println(playersss[1].getNumberGamesPlayed()); 
		System.out.println(playersss[1].getNumberGamesWon()); 		
		System.out.println(playersss[1].getNumberGamesDrawn()); 
	}
}