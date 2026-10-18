#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> in_or, po_or;
map<int, int> left_view;
map<int, int> right_view;
int max_depth = 0; 

void work(int in_l, int in_r, int po_l, int po_r, int depth)
{
    if (in_l > in_r || po_l > po_r) return;

    int root = po_or[po_r];
    max_depth = max(max_depth, depth);

    right_view[depth] = root; 
    if (left_view.count(depth) == 0) {
        left_view[depth] = root;
    }

    int root_pos = in_l;
    while (root_pos <= in_r && in_or[root_pos] != root) {
        root_pos++;
    }

    int left_len = root_pos - in_l;

    work(in_l, root_pos - 1, po_l, po_l + left_len - 1, depth + 1);
    work(root_pos + 1, in_r, po_l + left_len, po_r - 1, depth + 1);
}

int main()
{
    int n;
    if (!(cin >> n)) return 0;

    in_or.resize(n);
    po_or.resize(n);

    for (int i = 0; i < n; i++) cin >> in_or[i];
    for (int i = 0; i < n; i++) cin >> po_or[i];

    work(0, n - 1, 0, n - 1, 1);

    cout << "R:";
    for (int i = 1; i <= max_depth; i++) {
        cout << " " << right_view[i];
    }
    cout << "\n";

    cout << "L:";
    for (int i = 1; i <= max_depth; i++) {
        cout << " " << left_view[i];
    }
    cout << "\n";

    return 0;
}