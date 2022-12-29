#ifndef LAB3_SEM3_TEST_D_H
#define LAB3_SEM3_TEST_D_H

#include "../graph.h"

using namespace std;

void test_d()
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
    a.dijkst_alg(a.points[1]);
}

#endif //LAB3_SEM3_TEST_D_H
