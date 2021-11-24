#include <bits/stdc++.h>
using namespace std;

struct Point { double x, y; };

struct ObservationPoint { Point p; double r; };
ObservationPoint p0 = {{0, 0}, 0}, p1 = {{0, 0}, 0}, p2 = {{0, 0}, 0};

template <class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }

int main(){
    // r0, x1, r1, x2, y2, r2;
    cin >> p0.r >> p1.p.x >> p1.r >> p2.p.x >> p2.p.y >> p2.r;
    Point g = {(p1.p.x + p2.p.x) / 3, p2.p.y / 3};
    vector<pair<double, Point>> v;
    for(double X = g.x - 5000.0; X <= g.x + 5000.0; X += 10.0){
        for(double Y = g.y - 5000.0; Y <= g.y + 5000.0; Y += 10.0){
            double sum = 0.0;
            sum += abs(X * X + Y * Y - p0.r * p0.r);
            sum += abs((X - p1.p.x) * (X - p1.p.x) + Y * Y - p1.r * p1.r);
            sum += abs(((X - p2.p.x) * (X - p2.p.x) + (Y - p2.p.y) * (Y - p2.p.y)) - p2.r * p2.r);
            v.push_back({sum, {X, Y}});
        }
    }
    double min = 999999999.999;
    Point ans;
    for(int i = 0; i < v.size(); i++) if(chmin(min, v[i].first)) ans = v[i].second;
    cout << ans.x << " " << ans.y << endl;
}