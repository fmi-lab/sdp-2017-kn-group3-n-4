#include "graph.cpp"
#include "llist.cpp"

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

void deleteLast(LList<int>& lst)
{
    lst.IterStart();
    elem_link1<int>* p;
    while ((p = lst.Iter())) {
        if (p->link == NULL)
            break;
    }
    int x;
    lst.DeleteElem(p, x);
}

bool dfs(const int& a, const int& b, graph<int>& g, LList<int>& l)
{
    l.ToEnd(a);
    if (a == b)
        return true;
    elem_link1<int>* p = g.point(a);
    p = p->link;
    while ((p)) {
        if (!member(p->inf, l)) {
            if (dfs(p->inf, b, g, l))
                return true;
            deleteLast(l);
        }
        p = p->link;
    }
    return false;
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
    LList<int> way;
    cout << dfs(2, 8, g, way) << endl;
    return 0;
}