#ifndef LAB3_SEM3_GRAPH_H
#define LAB3_SEM3_GRAPH_H

#include <vector>
#include <stack>

using namespace std;

class Vertex
{
public:

    vector<pair<int, int>> adj_vert;
    bool is_visited{false};
    int label{100000};

    Vertex()
    {}

    Vertex(vector<pair<int, int>> adj)
    {
        adj_vert = adj;
    }
};

class Graph
{
public:

    vector<Vertex> points;

    void dijkst_alg(Vertex& beg)
    {
        beg.label = 0;
        Vertex* cur;

        while (1)
        {
            int min_label = 100000;

            for (int i = 0; i < points.size(); i++) {
                if (!points[i].is_visited) {
                    if (points[i].label < min_label) {
                        min_label = points[i].label;
                        cur = &points[i];
                    }
                }
            }

            if (min_label == 100000) return;

            cur->is_visited = true;

            for (int i = 0; i < cur->adj_vert.size(); i++) {
                int cur_ = cur->adj_vert[i].first;

                if (!points[cur_].is_visited) {
                    if (points[cur_].label != 100000) {
                        if (points[cur_].label > cur->label + cur->adj_vert[i].second) {
                            points[cur_].label = cur->label + cur->adj_vert[i].second;
                        }
                    } else {
                        points[cur_].label = cur->label + cur->adj_vert[i].second;
                    }
                }
            }
        }
    }

    void floyd_alg(Vertex& beg)
    {
        int** matrix = new int* [points.size()];
        for(int i = 0; i < points.size(); i++)
        {
            matrix[i] = new int [points.size()];
        }

        for(int i = 0; i < points.size(); i++)
        {
            for(int j = 0; j < points.size(); j++)
            {
                matrix[i][j] = 100000;
            }
        }

        for(int i = 0; i < points.size(); i++)
        {
            for(int j = 0; j < points[i].adj_vert.size(); j++)
            {
                matrix[i][points[i].adj_vert[j].first] = points[i].adj_vert[j].second;
            }
        }

        for(int k = 0; k < points.size(); k++)
        {
            for(int i = 0; i < points.size(); i++)
            {
                for(int j = 0; j < points.size(); j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        for(int i = 0; i < points.size(); i++)
        {
            for(int j = 0; j < points.size(); j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

    }

    void ford_alg(Vertex& beg)
    {
        beg.label = 0;
        for(int i = 0; i < points.size() - 1; i++)
        {
            for(int j = 0; j < points.size(); j++)
            {
                for(int k = 0; k < points[j].adj_vert.size(); k++)
                {
                    int ind = points[j].adj_vert[k].first;
                    int reb = points[j].adj_vert[k].second;
                    if(points[ind].label > points[j].label + reb)
                    {
                        points[ind].label = points[j].label + reb;
                    }
                    if(points[ind].label > points[j].label + reb)
                    {
                        cout << "negative cycle" << endl;
                    }
                }
            }
        }
    }

    void top_sort(Vertex& ver, stack<int>* stack)
    {
        Vertex* cur = &ver;
        cur->is_visited = true;

        for(int i = 0; i < cur->adj_vert.size(); i++)
        {
            int ind = cur->adj_vert[i].first;
            if(!points[ind].is_visited)
            {
                top_sort(points[ind], stack);
            }
        }
        int k = 0;
        while(&points[k] != cur)
        {
            k++;
        }

        stack->push(k);
    }
};

#endif //LAB3_SEM3_GRAPH_H
