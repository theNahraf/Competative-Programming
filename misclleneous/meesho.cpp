#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
#include<algorithm>

using namespace std;

set<pair<pair<int, int>, int>> dataset;
unordered_map<int,pair<pair<int, int>, int>> datamap;

class Order{
int id;
int x;
int y;
int priority;
int k;
public:
 Order(){
    cout<<"cart is created"<<endl;
}

void addorder(int id, int x, int y, int priority){
int dist = abs(x) +abs(y);
pair<pair<int, int>, int> orderinfo = {{priority, dist},  id};
dataset.insert(orderinfo);
datamap[id] =  orderinfo;
cout<<"order Placed with id - : "<<id<<endl;
}

void cancel(int id){
	dataset.erase(datamap[id]);
    datamap.erase(id);
	cout<<"order id - " <<id<<" Cancelled Succesful"<<endl;
}

void get(int k){
	for(auto ord: dataset){
	if(k ==0) return ;
	int orderid = ord.second;
    int dist =  ord.first.second;
    int priority =  ord.first.first;
    string st = priority == 1 ? "Express" : "Standard";
    cout<<orderid<<", "<< st << " "<< dist <<endl;
	k = k - 1;
	}
    cout<<endl;
}
};

int main(){
Order* mycart =  new Order();
mycart->addorder(101, 2, 3, 1);
mycart->addorder(102, -1, 4, 2);
mycart->addorder(103, 0, 1, 1);
mycart->get(2);
mycart->addorder(105, 1, 1, 1);
mycart->cancel(101);
mycart->get(2);
return 0;
}

	



/*

Delivery Route Optimizer
Problem Statement:
Meesho’s delivery team has N orders to ship from a warehouse. Each order has:
order_id
destination (x, y coordinates)
priority (1=express, 2=standard)
A delivery van can carry K orders at once. The van must choose orders to maximize:
Number of express (priority=1) orders delivered.
Minimize total Manhattan distance (|x1 - x2| + |y1 - y2|) traveled (warehouse at (0,0)).
Task:
add_order(order_id, x, y, priority): Insert a new order.
cancel_order(order_id): Cancel an order.
get_best_K_orders(K): Fetch optimal K orders on-demand.
Constraints:
1 ≤ K ≤ N ≤ 2·10⁵
-10⁶ ≤ x, y ≤ 10⁶
priority ∈ {1, 2}
Sample test cases
add 101 2 3 1
add 102 -1 4 2
add 103 0 1 1
get 2
add 105 1 1 1
cancel 101
get 2

output 
103 101
103 105

Explanation:
add 101 2 3 1: Express order, distance = 5.
add 102 -1 4 2: Standard order, distance = 5.
add 103 0 1 1: Express order, distance = 1.
get 2: The available express orders are 101 (dist 5) and 103 (dist 1). To maximize express orders, we must pick both.
 Output: 103 101
add 105 1 1 1: A new express order is added, distance = 2.
cancel 101: Order 101 is removed.
get 2: The available orders are now 103 (express, dist 1), 105 (express, dist 2), and 102 (standard, dist 5).
 The optimal set of 2 is the two express orders.
 Output: 103 105





*/