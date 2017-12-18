#include "graph.cpp"
#include "llist.cpp"

bool flag = false;
int minL = 1e9;
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

void dfs(const int& a, const int& b, graph<int>& g, LList<int>& l, LList<int>& minPath)
{
    l.ToEnd(a);
    if (a == b) {
        flag = true;
        int len = l.len();
        if (len < minL) {
            minL = len;
            minPath = l;
        }
    }
    elem_link1<int>* p = g.point(a);
    p = p->link;
    while ((p)) {
        if (!member(p->inf, l)) {
            dfs(p->inf, b, g, l, minPath);
            deleteLast(l);
        }
        p = p->link;
    }
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
    LList<int> tmp;
    LList<int> way;
    dfs(2, 4, g, tmp, way);
    if (way.empty()) {
        printf("None\n");
    } else {
        way.IterStart();
        for (elem_link1<int>* i = way.Iter(); i != NULL; i = way.Iter()) {
            printf("%d \n", i->inf);
        }
    }
    return 0;
}