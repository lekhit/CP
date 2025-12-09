#include <bits/stdc++.h>
using namespace std;
// ref: https://usaco.guide/gold/dsu?lang=cpp

class DSU
{
public:
    int N;
    vector<int> parent, size;
    // using zero based indexing 
    DSU(int n)
    {
        n = N; // will be sticking to exact N
        // if N is to be included in queries then give n+1 as input

        parent.resize(N);
        for(int i=0;i<N;i++) parent[i]=i; 
        size.assign(N, 1);
    }
    DSU(int n, int defaultParent)
    {
       
    }

    int findParent(int a)
    {
        if (a == parent[a])
            return a;
        return parent[a] = findParent(a); // path compression
    }

    int combine(int a, int b)
    { // 1--> successful 0--> already connected
        int parentA = findParent(a);
        int parentB = findParent(b);

        if (parentA == parentB)
            return 0;
        if (size[parentA] < size[parentB])
            swap(parentA, parentB);

        size[parentA] += size[parentB];
        parent[parentB] = parentA;
        return 1;
    }

    bool isConnected(int a, int b)
    {
        return (findParent(a) == findParent(b));
    }
};