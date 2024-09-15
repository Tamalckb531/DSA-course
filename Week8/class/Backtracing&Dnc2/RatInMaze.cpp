#include <bits/stdc++.h>
using namespace std;
/*
        -? Rat can move 4 direction -> 4 recursive call for direction
        -? check co-ordinate safety
            -! Not out of bound
            -! Not blocked
            -! Not visited
        -? Before recursive call make visited true -> on recursive call store the move in a string -> after recursive call mark visited false for back-tracking
        -? When src reach dist, push the move string in ans
        -* 0,0 should be manually visited -> if 0,0 is blocked than return empty ans
    */

bool isSafe(int newx, int newy, vector<vector<int>> &mat, vector<vector<bool>> &visited, int size)
{

    //? Safe when -> mat not blocked || visited false || co-oridnates not out of bound

    if (newx < 0 || newy < 0 || newx >= size || newy >= size)
    {
        // out of bound
        return false;
    }
    if (mat[newx][newy] == 0)
    {
        // mat blocked
        return false;
    }
    if (visited[newx][newy])
    {
        // visited
        return false;
    }

    return true;
}

void solve(vector<vector<int>> &mat, int n, vector<vector<bool>> &visited, vector<string> &ans,
           string output, int srcx, int srcy, int destx, int desty)
{

    //* base case
    if (destx == srcx && desty == srcy)
    {
        ans.push_back(output);
        return;
    }

    //* movements UDLR

    //? UP ->
    int newx = srcx - 1;
    int newy = srcy;

    if (isSafe(newx, newy, mat, visited, n))
    {
        visited[newx][newy] = true;
        solve(mat, n, visited, ans, output + "U", newx, newy, destx, desty);
        visited[newx][newy] = false; //? back-tracking
    }

    //? DOWN ->
    newx = srcx + 1;
    newy = srcy;

    if (isSafe(newx, newy, mat, visited, n))
    {
        visited[newx][newy] = true;
        solve(mat, n, visited, ans, output + "D", newx, newy, destx, desty);
        visited[newx][newy] = false; //? back-tracking
    }

    //? LEFT ->
    newx = srcx;
    newy = srcy - 1;

    if (isSafe(newx, newy, mat, visited, n))
    {
        visited[newx][newy] = true;
        solve(mat, n, visited, ans, output + "L", newx, newy, destx, desty);
        visited[newx][newy] = false; //? back-tracking
    }

    //? RIGHT ->
    newx = srcx;
    newy = srcy + 1;

    if (isSafe(newx, newy, mat, visited, n))
    {
        visited[newx][newy] = true;
        solve(mat, n, visited, ans, output + "R", newx, newy, destx, desty);
        visited[newx][newy] = false; //? back-tracking
    }
}

vector<string> findPath(vector<vector<int>> &mat)
{
    vector<string> ans;
    int n = mat.size();
    vector<vector<bool>> visited(n, vector<bool>(n, 0));

    // co-ordinates
    int srcx = 0;
    int srcy = 0;
    int destx = n - 1;
    int desty = n - 1;

    //? src position always visited
    visited[0][0] = true;

    if (mat[srcx][srcy] == 0)
    {
        return ans;
    }

    string output = "";

    solve(mat, n, visited, ans, output, srcx, srcy, destx, desty);

    return ans;
}

int main()
{
    return 0;
}