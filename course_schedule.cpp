// Time Complexity: O(n)
// Space Complexity: O(n)
// Did this code successfully run on Leetcode : Yes

//Approach:
//1. We will create an adjacency list and an indegree array.
//2. We will iterate through the prerequisites and store the courses and their prerequisites in the adjacency list.
//3. We will also keep track of the indegree of each course.
//4. We will push the courses with indegree 0 into a queue.
//5. We will process the courses one by one and reduce the indegree of their neighbours.
//6. If the indegree of a neighbour becomes 0, we will push it into the queue.
//7. We will keep track of the number of courses processed and return true if all the courses are processed.
//8. Else, we will return false.

class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> adj(numCourses);
            vector<int> inDegree(numCourses, 0);
    
            for(auto& pre: prerequisites){
                int course = pre[0];
                int prereq = pre[1];
                adj[prereq].push_back(course);
                inDegree[course]++;
            }
    
            queue<int> q;
            for(int i = 0; i < numCourses; i++){
                if(inDegree[i] == 0){
                    q.push(i);
                }
            }
    
            int processed = 0; 
            while(!q.empty()){
                int course = q.front();
                q.pop();
                processed++;
    
                for(int neighbour : adj[course]){
                    inDegree[neighbour]--;
                    if(inDegree[neighbour] == 0){
                        q.push(neighbour);
                    }
                }
            }
            return processed == numCourses;
        }
    };