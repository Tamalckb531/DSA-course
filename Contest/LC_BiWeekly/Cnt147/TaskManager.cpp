#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;
class TaskManager
{
public:
    map<int, pair<int, int>> mp; //? taskId -> {userId, priority} mapping
    set<pair<int, int>> st;      //? {priority, taskId} stack store
    TaskManager(vector<vector<int>> &tasks)
    {
        for (auto it : tasks)
        {
            st.insert({it[2], it[1]});
            mp[it[1]] = {it[0], it[2]};
        }
    }

    void add(int userId, int taskId, int priority)
    {
        st.insert({priority, taskId});
        mp[taskId] = {userId, priority};
    }

    void edit(int taskId, int newPriority)
    {
        pair<int, int> p = mp[taskId]; //? have {userId, priority}

        //? set new in map
        mp[taskId] = {p.first, newPriority};

        //? delete old and set new in stack
        pair<int, int> oldPair = {p.second, taskId};
        auto it = st.find(oldPair);
        st.erase(it);
        st.insert({newPriority, taskId});
    }

    void rmv(int taskId)
    {
        pair<int, int> p = mp[taskId];

        //? remove in map
        mp.erase(taskId);

        //? remove in stack
        pair<int, int> oldPair = {p.second, taskId};
        auto it = st.find(oldPair);
        st.erase(it);
    }

    int execTop()
    {
        //? safety check
        if (mp.size() == 0)
            return -1;

        //? get the userId of task with the highest priority
        auto it = st.end();
        it--;
        pair<int, int> p = *it;
        int ans = mp[p.second].first; //? userId

        //? remove the taskId form both set and map
        mp.erase(p.second);
        st.erase(it);

        //? return the userId
        return ans;
    }
};

class TaskManager
{
public:
    map<int, pair<int, int>> mp;
    set<pair<int, int>> st;
    TaskManager(vector<vector<int>> &tasks)
    {
        for (auto it : tasks)
        {
            st.insert({it[2], it[1]});
            mp[it[1]] = {it[0], it[2]};
        }
    }

    void add(int userId, int taskId, int priority)
    {
        st.insert({priority, taskId});
        mp[taskId] = {userId, priority};
    }

    void edit(int taskId, int newPriority)
    {
        pair<int, int> p = mp[taskId];

        mp[taskId] = {p.first, newPriority};

        pair<int, int> oldPair = {p.second, taskId};
        auto it = st.find(oldPair);
        st.erase(it);
        st.insert({newPriority, taskId});
    }

    void rmv(int taskId)
    {
        pair<int, int> p = mp[taskId];
        mp.erase(taskId);

        pair<int, int> oldPair = {p.second, taskId};
        auto it = st.find(oldPair);
        st.erase(it);
    }

    int execTop()
    {
        if (mp.size() == 0)
            return -1;

        auto it = st.end();
        it--;
        pair<int, int> p = *it;
        int ans = mp[p.second].first;

        mp.erase(p.second);
        st.erase(it);

        return ans;
    }
};