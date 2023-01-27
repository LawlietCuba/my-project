#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int matrix[n][n-1]; 

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n-1; j++)
            {
                cin >> matrix[i][j];
            }
        }

        vi ans(n);
        vi cont(n+1,0);

        for(int i=0; i<n; i++)
        {
            cont[matrix[i][0]]++;
        }

        for(int i=0; i<=n; i++)
            if(cont[i] == n-1)
                ans[0] = i;

        for(int i=0; i<n; i++)
        {
            if(matrix[i][0] != ans[0])
            {
                for(int j=0; j<n-1; j++)
                {
                    ans[j+1] = matrix[i][j];
                }
                break;
            }
        }

        for(int i=0; i<n; i++) cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;
}