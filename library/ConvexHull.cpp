#include <map>
#include <cmath>
#include <cfloat>
#include <vector>
#include <algorithm>
using namespace std;

template<class T> class Point {
public:
  T x, y;

  Point(T x, T y) {
    this->x = x;
    this->y = y;
  }

  Point<T> operator +(const Point &p) const {
    return Point<T>(this->x + p.x, this->y + p.y);
  }

  Point<T> operator -(const Point &p) const {
    return Point<T>(this->x - p.x, this->y - p.y);
  }

  bool operator <(const Point &p) const {
    if (this->x != p.x)
      return this->x < p.x;
    else
      return this->y < p.y;
  }

  bool operator >(const Point &p) const {
    return p < *this;
  }

  bool operator <=(const Point &p) const {
    return !(*this > p);
  }

  bool operator >=(const Point &p) const {
    return !(*this < p);
  }

  bool operator ==(const Point &p) const {
    return this->x == p.x && this->y == p.y;
  }
};

template<class T> double inner_product(Point<T> a, Point<T> b) {
  return a.x * b.x + a.y * b.y;
}

template<class T> double cross_product(Point<T> a, Point<T> b) {
  return a.x * b.y - a.y * b.x;
}

// return: list of points counterclockwise that compose convex hull
template<class T> vector<Point<T>> convex_hull(vector<Point<T>> &points) {
  Point<T> p0 = points[0];
  for (Point<T> p: points) {
    if (p.y < p0.y)
      p0 = p;
    else if (p.y == p0.y && p.x < p0.x)
      p0 = p;
  }

  // pair<pair<angle, distance>, point>
  typedef pair<pair<double, double>, Point<T>> Ppp;
  vector<Ppp> v;
  for (Point<T> p: points) {
    if (p == p0)
      continue;
    double angle = atan2(p.y - p0.y, p.x - p0.x);
    double dist = sqrt(pow(p.x - p0.x, 2) + pow(p.y - p0.y, 2));
    v.push_back(make_pair(make_pair(angle, dist), p));
  }

  sort(v.begin(), v.end());
  auto it = v.end(); it--;
  while (fabs(it->first.first - v.back().first.first) <= DBL_EPSILON) it--;
  it++;
  reverse(it, v.end());

  vector<Point<T>> res;
  res.push_back(p0);
  res.push_back(v[0].second);
  for (uint i = 1; i < v.size(); i++) {
    Point<T> p = v[i].second;
    while (res.size() >= 2) {
      Point<T> p2 = *(res.end() - 2), p1 = res.back();
      Point<T> v1 = p2 - p, v2 = p1 - p;
      T c = cross_product(v1, v2);
      if (c >= 0)
        break;
      res.erase(res.end() - 1);
    }
    res.push_back(p);
  }

  return res;
}
