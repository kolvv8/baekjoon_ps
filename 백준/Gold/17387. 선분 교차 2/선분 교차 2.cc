#include <iostream>
#define ll long long
using namespace std;

struct pos
{
    ll x = 0;
    ll y = 0;

    pos(int x, int y) {
        this->x = x;
        this->y = y;
    }

    bool operator<=(const pos& a) {
        if (x == a.x) {
            return y <= a.y;
        }
        return x < a.x;
    }
};

int ccw(pos a, pos b, pos c) {
    ll dir = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);

    if (dir > 0) {
        return 1;
    }
    else if (dir < 0) {
        return -1;
    }
    else {
        return 0;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int x1, x2, y1, y2;

    cin >> x1 >> y1 >> x2 >> y2;
    pos a1(x1, y1);
    pos a2(x2, y2);

    if (a2 <= a1) {
        swap(a1, a2);
    }

    cin >> x1 >> y1 >> x2 >> y2;

    pos b1(x1, y1);
    pos b2(x2, y2);

    if (b2 <= b1) {
        swap(b1, b2);
    }

    int cur1 = ccw(a1, a2, b1) * ccw(a1, a2, b2);
    int cur2 = ccw(b1, b2, a1) * ccw(b1, b2, a2);

    int sum = cur1 * cur2;

    if (cur1 == -1 && cur2 == -1) {
        cout << 1;
    }
    else if ((cur1 == -1 && cur2 == 0) || (cur1 == 0 && cur2 == -1)) {
        cout << 1;
    }
    else if (cur1 == 0 && cur2 == 0) {
        if (a1 <= b2 && b1 <= a2) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    else {
        cout << 0;
    }
    return 0;
}