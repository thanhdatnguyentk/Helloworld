#include <iostream>
#include <vector>
#include <algorithm>

struct DATA
{
    long long x, y;
};

bool compare(const DATA& a, const DATA& b)
{
    if (a.x != b.x)
        return a.x < b.x;
    return a.y > b.y;
}

int Partition(std::vector<DATA>& v, int low, int high)
{
    DATA pivot = v[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (compare(v[j], pivot))
        {
            i++;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[high]);
    return i + 1;
}
void QuickSort(std::vector<DATA>& v, int low, int high)
{
    if (low < high)
    {
        int pivot = Partition(v, low, high);
        QuickSort(v, low, pivot - 1);
        QuickSort(v, pivot + 1, high);
    }
}


void SapXep(std::vector<DATA>& v)
{
    int n = v.size();
    QuickSort(v, 0, n - 1);
}

int main()
{
    std::vector<DATA> v;
    DATA data;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> data.x >> data.y ;
        v.push_back(data);
    }
    SapXep(v);
    for (int i = 0; i < n; i++)
    {
        std::cout << v[i].x << " " << v[i].y << std::endl;
    }
    return 0;
}
