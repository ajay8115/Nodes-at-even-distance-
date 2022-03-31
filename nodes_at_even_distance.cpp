// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

class Solution
{
public:
    int countOfNodes(vector<int> graph[], int n)
    {
        queue<int> q;
        vector<int> dist(n + 1, 0);
        vector<bool> visited(n + 1, false);

        q.push(1);
        visited[1] = true;

        while (!q.empty())
        {
            int node = q.front();

            int distance = dist[node];
            q.pop();

            for (int neighbour : graph[node])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    dist[neighbour] = distance + 1;
                    visited[neighbour] = true;
                }
            }
        }

        int even = 0, odd = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }

        return ((even * (even - 1)) / 2 + (odd * (odd - 1)) / 2);
    }
};