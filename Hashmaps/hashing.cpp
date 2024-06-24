#include <bits/stdc++.h>
using namespace std;
class Hashing
{
public:
    vector<list<int>> v;
    int size;

    Hashing(int size)
    {
        this->size = size;
        v.resize(size);
    }

    int hashValue(int x)
    {
        int num = x % size;
        return num;
    }

    void addKey(int key)
    {
        int idx = hashValue(key);
        v[idx].push_back(key);
    }

    list<int>::iterator searchKey(int key)
    {
        int idx = hashValue(key);
        return find(v[idx].begin(), v[idx].end(), key);
    }

    void deleteKey(int key)
    {
        int idx = hashValue(key);
        if (searchKey(key) != v[idx].end())
        {
            v[idx].erase(searchKey(key));
            cout << "is Deleted."
                 << " ";
        }
        else
        {
            cout << "Key is not in the hashtable" << endl;
        }
    }
};
int main()
{
    Hashing h(10);
    h.addKey(5);
    h.addKey(9);
    h.addKey(7);
    h.deleteKey(9);

    return 0;
}