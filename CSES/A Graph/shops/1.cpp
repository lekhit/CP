#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// accepted solution

const int MOD = 1000000007;
const int UNCOLOURED_NODE = -1;
 
int main() {
    int numberOfNodes, numberOfEdges, numberOfShops;
    cin >> numberOfNodes >> numberOfEdges >> numberOfShops;
 
    vector<int> cityColour(numberOfNodes + 1, UNCOLOURED_NODE); // setting all nodes to UNCOLOURED_NODE
    vector<int> cityDistanceFromClosestShop(numberOfNodes + 1, MOD); // for each shop this will be set to 0
    vector<int> shopMinDistance(numberOfNodes + 1, MOD); // stores min distances between shops; does not store distance for other cities without shops
    vector<int> isShop(numberOfNodes + 1, 0);
    queue<int> q;
 
    for (int i = 0; i < numberOfShops; i++) {
        int shopId;
        cin >> shopId;
        cityColour[shopId] = shopId; // each shop will have same colour code as its id; All cities who has this shop as it's closest shop will also store this color code (shopID)
        cityDistanceFromClosestShop[shopId] = 0; // for each shop closest shop will be itself; calculating min distances between shops seperately
        isShop[shopId] = true; // used to check if the present node is shop
        q.push(shopId); // multisource BFS will start from each shop; will go on colouring each layer one by one; ie each coloured node will have responsibilty of finding other Shop for its origin Shop[shopID stored as colour code]
    }

    // --- Building Graph
 
    vector<vector<int> > graph(numberOfNodes + 1);
    for (int i = 0; i < numberOfEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    // --- BFS to find the shortest distance to each shop
    while (!q.empty()) {
        int currentCityId = q.front();
        q.pop();
        for (int neighbourCityId : graph[currentCityId]) {
            if (cityColour[currentCityId] == cityColour[neighbourCityId]) continue; // avoiding same coloured neighbour city; because it already knows the closest Shop will be same as colour code (this is ensured by coloring with layered logic[BFS] )
            if (cityColour[neighbourCityId] == UNCOLOURED_NODE) { //new node which is yet to be coloured
                cityColour[neighbourCityId] = cityColour[currentCityId]; //colouring 
                cityDistanceFromClosestShop[neighbourCityId] = cityDistanceFromClosestShop[currentCityId] + 1; //updating distance
                q.push(neighbourCityId); // since it was uncoloured its neighbours were never explored; so adding to queue
            } else { //Node is already coloured; meaning this can act as connecting path between two Shops; since both current and neighbour know its closest shop ID(colour code)
                int newDistanceBetweenShops = cityDistanceFromClosestShop[currentCityId] + cityDistanceFromClosestShop[neighbourCityId] + 1; // 1 is the connection between the current and neighbour
                int sourceShopColour = cityColour[currentCityId];
                int neighbourShopColour = cityColour[neighbourCityId];
                // we only update if newDistanceBetweenShops is lower than the present value; there is always a possibility that Shop has already found better path, however that may not be true for other.
                shopMinDistance[sourceShopColour] = min(newDistanceBetweenShops, shopMinDistance[sourceShopColour]);
                shopMinDistance[neighbourShopColour] = min(newDistanceBetweenShops, shopMinDistance[neighbourShopColour]);
            }
        }
    }
 
    for (int i = 1; i <= numberOfNodes; i++) {
        int dist;
        if (isShop[i]) {
            dist = (shopMinDistance[i] == MOD) ? -1 : shopMinDistance[i]; // MOD represents city was not reachable 
        } else {
            dist = (cityDistanceFromClosestShop[i] == MOD) ? -1 : cityDistanceFromClosestShop[i]; // MOD represents city was not reachable 
        }
        cout << dist << " ";
    }
    cout << endl;
    return 0;
}