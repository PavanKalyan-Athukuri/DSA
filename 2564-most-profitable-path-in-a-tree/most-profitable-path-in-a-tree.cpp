class Solution {

private:
    vector<vector<int>> tree;
    vector<bool> visited;
    unordered_map<int,int> bobpath;
    queue<vector<int>> nodeQueue;
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        tree.resize(n);
        visited.assign(n,false);
        nodeQueue.push({0, 0, 0});
        int maxIncome = INT_MIN;
        for(vector<int> edge:edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        findBobPath(bob,0);
        visited.assign(n,false);
        while(!nodeQueue.empty()){
            int sourceNode = nodeQueue.front()[0],time=nodeQueue.front()[1],
            income = nodeQueue.front()[2];
            if(bobpath.find(sourceNode)==bobpath.end()||time<bobpath[sourceNode]){
                income += amount[sourceNode];
            }
            else if(time==bobpath[sourceNode]){
                income += amount[sourceNode]/2;
            }
            if (tree[sourceNode].size() == 1 && sourceNode != 0) {
                maxIncome = max(maxIncome, income);
            }
            for(int adjacentNode: tree[sourceNode]){
                if(!visited[adjacentNode]){
                    nodeQueue.push({adjacentNode,time+1,income});
                }
            }
            visited[sourceNode] = true;
            nodeQueue.pop();
        }
        return maxIncome;
    }
public:
    bool findBobPath(int bob,int time){
        bobpath[bob] = time;
        visited[bob] = true;
        if(bob==0){
            return true;
        }
        for(auto adjacentNode:tree[bob]){
            if(!visited[adjacentNode]){
                if(findBobPath(adjacentNode,time+1))
                    return true;
            }
        }
        bobpath.erase(bob);
        return false;
    }
};