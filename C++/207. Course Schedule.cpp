#include <bits/stdc++.h>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses, vector<int>()); // Adjacency List
    vector<int> remaining(numCourses, 0);

    for (int i = 0; i < prerequisites.size(); i++)
    {
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        remaining[prerequisites[i][0]]++;
    }

    queue<int> que;

    for (int i = 0; i < numCourses; i++)
    {
        if (remaining[i] == 0)
            que.push(i);
    }

    int course;

    while (!que.empty())
    {
        course = que.front();
        que.pop();

        for (int higher_course : graph[course])
        {
            remaining[higher_course]--;
            if (remaining[higher_course] == 0)
                que.push(higher_course);
        }
    }

    for (int i = 0; i < numCourses; i++)
    {
        if (remaining[i])
            return false;
    }

    return true;
}
