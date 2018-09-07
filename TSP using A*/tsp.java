
import java.util.*;


class tsp{
	protected static int numNodes;
	protected static String initialState;
	protected static HashMap<String, List<Node>> graph = new HashMap<String, List<Node>>();
	protected static int option;
	protected static String outputPath,outputLog;
	public static void main(String[] args) {
		
		
		int i;
		

		if(args.length != 10 ){
			System.err.println("Invalid number of arguments");
			return;
		}
		
		
			for(i = 0;i < args.length;i++){
				
				if(args[i].equals("-t")){
					option = Integer.parseInt(args[i+1]);
				}else if(args[i].equals("-s")){
					tsp.initialState = args[i+1];	
					tsp.initialState = "a";	

				}else if(args[i].equals("-i")){
					
					
					Parser p = new Parser();
					if(!(p.parseFile(args[i+1]))){
						System.err.println("Give correct Input filename");
						return;
					}
					
					
				}else if(args[i].equals("-op")){
					tsp.outputPath = args[i+1];
					
					
				}else if(args[i].equals("-ol")){
					tsp.outputLog = args[i+1];

				}
			}
		
		if(option == 1){
			
			
			Greedy g = new Greedy();
			g.search();
			System.out.println("Completed Greedy Search on the input");
		}else if( option == 2){
			
			Astar a = new Astar();
			a.search();
			System.out.println("Completed A* Search with SLD heuristics on the input");

		
		}else if(option == 3){
		
			mAstar m = new mAstar();
			m.search();
			System.out.println("Completed A* Search with MST heuristics on the input");

		}
		
	}
}