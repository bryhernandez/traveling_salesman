#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int dist(int pointA, int pointB, vector<pair<double, double>> v) {
    double xdist, ydist;
    xdist = v[pointA].first - v[pointB].first;
    ydist = v[pointA].second - v[pointB].second;

    double d = sqrt(pow(xdist, 2) + pow(ydist, 2));
    return round(d);
}

int main() {
  vector<pair<double, double>> num;

  double n;
  cin >> n;

  for(int i = 0; i < n; i ++){
    double x, y;
    cin >> x;
    cin >> y;

    num.push_back({x, y});
  }

  vector<int> travel;
  vector<bool> pass;

  travel.resize(n, -1);
  pass.resize(n, false);

  travel[0] = 0;
  pass[0] = true;

  for(int i = 1; i < n; i++){
    int opt = -1;
    for(int j = 0; j < n; j++){
      if(!pass[j] && (opt == -1 || dist(travel[i-1], j, num) < dist(travel[i-1], opt, num)))
        opt = j;
    }
    travel[i] = opt;
    pass[opt] = true;
  }

  for(auto i : travel)
    cout << i << endl;
}
