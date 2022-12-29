#pragma once

#include <iostream>
#include "../graph.h"

using namespace std;

void test_top()
{
    Graph a;
    vector<pair<int, int>> a1;
    a1.push_back(pair(1, 1));
    a1.push_back(pair(2, 2));
    Vertex v1(a1);
    Vertex v2;
    Vertex v3;
    a.points.push_back(v1);
    a.points.push_back(v2);
    a.points.push_back(v3);
    stack<int> sort;
    a.top_sort(a.points[0], sort);
    cout << sort.top();
    sort.pop();
    cout << sort.top();
    sort.pop();
    cout << sort.top();
    sort.pop();
}
