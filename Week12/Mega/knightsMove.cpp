class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.

    //? take the src and dist in 0-based -> make a visited vector and mark all visited -> Do BFS and count step (increase step in nullptr and insert another if the queue is not empty -> explore the point if not null ptr and return true if dist found) -> return step from BFS

    bool explore(pair<int, int> &point, pair<int, int> &dist, int N, vector<vector<bool>> &visited, queue<pair<int, int>> &q)
    {

        int moveY[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int moveX[] = {1, -1, 1, -1, 2, -2, 2, -2};

        for (int i = 0; i < 8; i++)
        {
            int newX = point.first + moveX[i];
            int newY = point.second + moveY[i];

            //? bound check
            if (newX < 0 || newY < 0 || newX >= N || newY >= N || visited[newX][newY])
                continue; //? can't take this but should check the next

            if (make_pair(newX, newY) == dist)
                return true; //? found the destination

            q.push(make_pair(newX, newY)); //? a new possible move
            visited[newX][newY] = true;
        }
        return false; //? didn't reach the dist yet
    }

    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        //? Step1: take the src and dist in 0-based index
        pair<int, int> src = {KnightPos[0] - 1, KnightPos[1] - 1};
        pair<int, int> dist = {TargetPos[0] - 1, TargetPos[1] - 1};

        //? Step2: Visited array
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        visited[src.first][src.second] = true;

        //? Step3: Do BFS and count step
        int step = 1;
        queue<pair<int, int>> q;
        q.push(src);
        q.push({-1, -1}); //? first nullptr

        if (src == dist)
            return 0;

        while (!q.empty())
        {

            pair<int, int> frontPoint = q.front();
            q.pop();

            if (frontPoint == make_pair(-1, -1))
            {
                //? nullptr -> start of a new step
                step++;
                if (!q.empty())
                {
                    q.push(make_pair(-1, -1)); //? insert new nullptr of the new steps
                }
            }
            else
            {
                //? a potential move which can have more moves further
                if (explore(frontPoint, dist, N, visited, q))
                {
                    return step; //? it found the dist
                }
            }
        }

        return -1; //? no dist found
    }
};
