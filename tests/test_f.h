#ifndef LAB3_SEM3_TEST_F_H
#define LAB3_SEM3_TEST_F_H

#include "../graph.h"

void test_f()
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
    a.floyd_alg(a.points[0]);
}

#endif //LAB3_SEM3_TEST_F_H
