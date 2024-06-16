import java.util.*;

public class MyClass
{
  private int playerId;
  private String playerName;
  private int runs;
  private String playerType;
  private  String matchType;

  MyClass(int playerId, String playerName, int runs, String playerType, String matchType){
    this.playerId = playerId;
    this.playerName = playerName;
    this.runs = runs;
    this.playerType = playerType;
    this.matchType = matchType;
  }	
  
	public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    MyClass[] players = new MyClass[4];	
  
    for(int i=0; i<players.length; i++){
      int playerId, runs;
      String playerName, playerType, matchType;
      
      playerName = sc.nextLine().toLowerCase();
      playerType = sc.nextLine().toLowerCase();
      matchType = sc.nextLine().toLowerCase();
      sc.nextLine();
      playerId = sc.nextInt();
      runs = sc.nextInt();
    
      players[i] = new MyClass(playerId,playerName,runs,playerType,matchType);
    }
      
    int leastRuns = findPlayerWithLowestRuns(players, sc.nextLine().toLowerCase());
    List<MyClass> filterPlayers = findPlayerByMatchType(players, sc.nextLine().toLowerCase());
  
    if(leastRuns > 0) 
      System.out.println(leastRuns);
    else 
      System.out.println("No such Player");
    
    if(filterPlayers.size()>0){
      for(int i=0;i<filterPlayers.size();i++){
        System.out.println(filterPlayers.get(i).getPlayerId());
      }
    }else{
      System.out.println("No Player with given matchType");
    }
  
    sc.close();
  }

	public static int findPlayerWithLowestRuns(MyClass[] players,String value){
    int minRuns = Integer.MAX_VALUE;
    
    for(int i=0;i<players.length;i++)
      if(players[i].getPlayerType().equals(value) && players[i].getRuns() < minRuns)
        minRuns = players[i].getRuns();
    
    if(minRuns==Integer.MAX_VALUE)return 0;
    return minRuns;
  }
	
	public static List<MyClass> findPlayerByMatchType(MyClass[] players,String value){
    List<MyClass> filterPlayers = new ArrayList();
    
    for(int i=0;i<players.length;i++){
      if(players[i].getMatchType().equals(value))
        filterPlayers.add(players[i]);
    }
    
    return filterPlayers;
  }
      
    public String getPlayerType(){
      return this.playerType;
    }

	public int getRuns(){
      return this.runs;
    }

	public String getMatchType(){
      return this.matchType;
    }

	public int getPlayerId(){
      return this.playerId;
    }
}