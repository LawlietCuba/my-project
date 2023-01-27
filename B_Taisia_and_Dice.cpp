#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define pi 3.14159265358979323846  

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, s, r;
        cin >> n >> s >> r;

        vi answer(n);

        answer[n-1] = s-r;
        n--;
        s-=(s-r);

        for(int i=0; i<n; i++)
        {
            answer[i] = s/n;
        }

        int res = s%n;

        while(res>0)
        {
            for(int i=0; i<n; i++)
            {
                answer[i]++;
                res--;
                if(res == 0) break;
            }
        }

        for(int i=0; i<n+1; i++) cout << answer[i] << " ";
        cout << "\n";
    }

    return 0;
}