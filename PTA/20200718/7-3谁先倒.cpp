#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, n, An, Bn;
    int as, ah, bs, bh;
    An = 0, Bn = 0;
    cin >> A >> B;
    cin >> n;
    while (n--)
    {
        cin >> as >> ah >> bs >> bh;
        if (as + bs == ah && as + bs == bh)
        {
            continue;
        }
        else if (as + bs == ah)
        {
            A--;
            An++;
        }
        else if (as + bs == bh)
        {
            B--;
            Bn++;
        }
        if (A < 0)
        {
            cout << "A" << endl;
            cout << Bn;
            break;
        }
        if (B < 0)
        {
            cout << "B" << endl;
            cout << An;
            break;
        }
    }
    return 0;
}