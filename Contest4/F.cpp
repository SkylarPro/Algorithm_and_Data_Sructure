#include <iostream>
#include <cstdio>
#include <vector>
// Garland using the binary search method (dichotomy method)


double B(std::vector<double>& h, int n)
{
    double l = 0, r = h[0];
    bool Up;
    while (r - l > 0.0000000001) {
        h[1] = (l + r) / 2;
        Up = true;
        for (int i = 2; i < n; i++) {
            h[i] = 2 * h[i - 1] - h[i - 2] + 2;
            if (h[i] < 0) {
                Up = false;
                break;
            }
        }
        if (Up) {
            r = h[1];
        }
        else {
            l = h[1];
        }
    }
    return h[n - 1];

}
int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);

    std::vector<double> h;
    int n;
    std::cin >> n;
    h.resize(n);

    std::cin >> h[0];
    double a = B(h,n);
    std::cout.precision(2);
    std::cout<<fixed << a;
    return 0;
}