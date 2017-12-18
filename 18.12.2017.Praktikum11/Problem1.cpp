#include "graph.cpp"
#include "llist.cpp"
#include "queue.cpp"

int dummy = 0;

bool member(const int& needle, LList<int>& haystack)
{
    elem_link1<int>* p;
    haystack.IterStart();
    while ((p = haystack.Iter())) {
        if (p->inf == needle)
            return true;
    }
    return false;
}

void bfs(const int& a, graph<int>& g, LList<int>& l)
{
    queue<int> q;
    q.push(a);
    l.ToEnd(a);
    while (!q.empty()) {
        int x;
        q.pop(x);
        elem_link1<int>* p = g.point(x);
        p = p->link;
        while (p) {
            if (!member(p->inf, l)) {
                q.push(p->inf);
                l.ToEnd(p->inf);
            }
            p = p->link;
        }
    }
}

void dfs(const int& a, graph<int>& g, LList<int>& l)
{
    l.ToEnd(a);
    elem_link1<int>* p = g.point(a);
    p = p->link;
    while ((p)) {
        if (!member(p->inf, l))
            dfs(p->inf, g, l);
        p = p->link;
    }
}

LList<int> diff(LList<int>& vert, LList<int>& l)
{
    LList<int> res;
    vert.IterStart();
    elem_link1<int>* p = vert.Iter();
    while ((p = vert.Iter())) {
        if (!member(p->inf, l))
            res.ToEnd(p->inf);
    }
    return res;
}

int fullBDfs(graph<int>& g, const bool& mau)
{
    LList<int> vert = g.vertexes(), l;
    int n = 0;
    while (!vert.empty()) {
        vert.IterStart();
        elem_link1<int>* p = vert.Iter();
        if (mau)
            dfs(p->inf, g, l);
        else
            bfs(p->inf, g, l);
        vert = diff(vert, l);
        n++;
    }
    return n;
}

int main()
{
    graph<int> g;
    g.addTop(1);
    g.addTop(2);
    g.addTop(3);
    g.addTop(4);
    g.addTop(5);
    g.addTop(6);
    g.addTop(8);

    g.addRib(1, 2);
    g.addRib(2, 1);
    g.addRib(1, 3);
    g.addRib(3, 1);
    g.addRib(2, 3);
    g.addRib(3, 2);
    g.addRib(2, 5);
    g.addRib(5, 2);
    g.addRib(2, 6);
    g.addRib(6, 2);
    g.addRib(3, 4);
    g.addRib(4, 3);
    g.addRib(3, 5);
    g.addRib(5, 3);
    g.addRib(4, 6);
    g.addRib(6, 4);
    cout << fullBDfs(g, 0) << endl;
    return 0;
}