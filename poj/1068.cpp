#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        int l[45] = {0};
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> k;
            l[k + i] = 1;
        }
        for (int i = 0; i < n * 2; i++) {
            if (l[i] == 1) {
                int ll = 0;
                for (int j = i - 1; j >= 0; j--) {
                    if (l[j] == -1) {
                        ll++;
                    }
                    if (l[j] == 0) {
                        cout << ll + 1 << " ";
                        l[j] = -1;
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
}