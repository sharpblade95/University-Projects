
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;


class Greedy {

	
	
	
	PriorityQueue<NodeInfo> frontier = new PriorityQueue<NodeInfo>(1,new Compare() {
        @Override
        public int compare(NodeInfo o1, NodeInfo o2) {
        return Double.valueOf(o1.g).compareTo(o2.g);
        }
    });
	
	
	LinkedList<String> explored;
	Node child;
	List<Node> childList;
	NodeInfo childData;
	NodeInfo endTour;
	NodeInfo node;
	

	private void addChildren(List<Node> children, boolean last) {
		int i = 0;

		if (last == false) {
			while (i < children.size()) {
				double gcost = 0.0;
				
				child = children.get(i);

				if (!(explored.contains(child.name))) {
					gcost = child.sld + node.g;
					childData = new NodeInfo(child.name, node.path, gcost);
					childData.path.add(node.nodeName);
					childData.f = childData.g + childData.h;
					frontier.add(childData);
				}
				i++;
			}
		} else {

			int j = 0;
			while (j < children.size()) {
				double gcost = 0.0;
				child = children.get(j);
				if (child.name.equals(tsp.initialState)) {
					gcost = child.sld + node.g;
					endTour = new NodeInfo(child.name, node.path, gcost);
					endTour.path.add(node.nodeName);
					endTour.path.add(child.name);
					endTour.f = endTour.g + endTour.h;
					break;
				}
				j++;
			}
		}
	}

	
	public void search() {

		LOWriter.init();

		System.out.println("Greedy Search with Straight Line Distance Heuristics \n");

		
		explored = new LinkedList<String>();

		node = new NodeInfo(tsp.initialState);

		frontier.add(node);

		while (true) {

			if (frontier.peek() == null) {
				addChildren(childList, true);
				LOWriter.output(endTour);
				return;
			}

			node = frontier.remove();
			explored.add(node.nodeName);
			frontier.clear();

			if (!node.nodeName.equals(tsp.initialState)) {
				LOWriter.log(node);
			}

			childList = tsp.graph.get(node.nodeName);
			addChildren(childList, false);

		
		}
	}
}