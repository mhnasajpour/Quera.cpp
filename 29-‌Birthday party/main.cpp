#include <iostream>
#include <vector>
using namespace std;

bool is_in_a_area(pair<int, int> &a, pair<int, int> &b, vector<pair<double, double>> &lines)
{
    if(b.first == a.first)
    {
        for (int i = 0; i < lines.size(); i++){
            double y = a.first * lines[i].first + lines[i].second;
            if (y > min(a.second, b.second) && y < max(a.second, b.second))
                return false;
        }
        
        return true;
    }

    pair<double, double> lineAB;
    lineAB.first = (double)(b.second - a.second) / (b.first - a.first);
    lineAB.second = a.second - (lineAB.first * a.first);

    for (int i = 0; i < lines.size(); i++)
    {
        double x = (double)(lines[i].second - lineAB.second) / (lineAB.first - lines[i].first);

        if (x > min(a.first, b.first) && x < max(a.first, b.first))
            return false;
    }

    return true;
}

int main()
{
    int r, m, n;
    cin >> n >> m >> r;

    vector<pair<int, int>> points;
    vector<pair<double, double>> lines;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p;
        cin >> p.first >> p.second; // point (x, y)
        points.push_back(p);
    }

    for (int i = 0; i < m; i++)
    {
        double a, b, c; // ax + by + c = 0
        cin >> a >> b >> c;
        lines.push_back(pair<double, double>((-a / b), (-c / b))); // y = (-a/b)x - (c/b)   =>      y = (first)x + (second)
    }

    bool isExist = false;
    vector<pair<int, int>>::iterator it1 = points.begin();
    vector<pair<int, int>>::iterator it2 = points.begin();
    while (it1 != points.end())
    {
        it2 = it1;
        while (it2 != points.end())
        {
            if (it1 == it2)
                it2++;
            
            if (it2 != points.end())
            {
                if (is_in_a_area(*it1, *it2, lines))
                {
                    points.erase(it2);
                    isExist = true;
                    continue;
                }
                it2++;
            }
        }
        it1++;
    }

    if (isExist)
        cout << "Yes" << endl;

    else
        cout << "NO" << endl;

    cout << points.size() << endl;
}