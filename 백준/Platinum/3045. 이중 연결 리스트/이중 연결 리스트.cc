#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    int num;
    node* lNode;
    node* rNode;
    node(int num) {
        this->num = num;
        lNode = rNode = nullptr;
    }
};

node* linklist[500002];
int slist[500002];
bool visited[500002];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    char c;
    int a,b;
    int k;
    cin >> n >> m;
    linklist[0] = new node(0);
    for (int i = 1; i <= n+1; i++) {
        node* curNode = linklist[i - 1];
        node* newNode = new node(i);
        curNode->rNode = newNode;
        newNode->lNode = curNode;
        linklist[i] = newNode;
    }
    for (int i = 0; i < m; i++) {
        cin >> c;
        cin >> a >> b;
        if (c == 'A') {
            node* moveNode = linklist[a];
            node* curNode = linklist[b];

            moveNode->lNode->rNode = moveNode->rNode;
            moveNode->rNode->lNode = moveNode->lNode;

            curNode->lNode->rNode = moveNode;
            moveNode->lNode = curNode->lNode;
            moveNode->rNode = curNode;
            curNode->lNode = moveNode;
        }
        else {
            node* moveNode = linklist[a];
            node* curNode = linklist[b];

            moveNode->lNode->rNode = moveNode->rNode;
            moveNode->rNode->lNode = moveNode->lNode;

            curNode->rNode->lNode = moveNode;
            moveNode->rNode = curNode->rNode;
            moveNode->lNode = curNode;
            curNode->rNode = moveNode;
        }
    }
    vector<int>vec;
    node* curNode = linklist[0];
    vec.push_back(-1);
    for (int i = 1; i <= n; i++) {
        curNode = curNode->rNode;
        k = curNode->num;
        // cout << k << '\n';
        if (!vec.empty() && vec.back() >= k) {
            int idx = lower_bound(vec.begin(), vec.end(), k) - vec.begin();
            vec[idx] = k;
            slist[i] = idx;
            //cout << idx << '\n';
        }
        else {
            vec.push_back(k);
            slist[i] = vec.size()-1;
        }
    }

    int ans = vec.size()-1;
    vector<int> llList;

    curNode = linklist[n + 1];
    int idx = n;
    int K = 0;
    while (ans > 0) {
        curNode = curNode->lNode;
        if (ans == slist[idx]) {
            llList.push_back(curNode->num);
            visited[curNode->num] = true;
            K++;
            ans--;
        }
        idx--;
    }

    /*for (int i = llList.size()-1; i >= 0; i--) {
        cout << llList[i] << " ";
    }*/
    cout << n-K << '\n';
    int curIdx = llList.back();

    for (int i = curIdx; i >= 2; i--) {
        cout << 'A' << " " << i - 1 << " " << i << '\n';
    }

    for (int i = curIdx+1; i <= n; i++) {
        if (!visited[i]) {
            cout << 'B' << " " << i << " " << i - 1 << '\n';
        }
    }

    return 0;
}