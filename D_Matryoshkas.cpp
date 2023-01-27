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

        vi v(n,0);
        for(int i=0; i<n; i++) cin >> v[i];

        sort(v.begin(), v.end());

        int dp = 0;
        int current_number = v[0];  
        int current_amount = 0;     // of matryotskas formed in hand

        for(int i = 0; i<n;)
        {
            if(current_number + 1 < v[i])
            {
                dp+=current_amount;
                current_amount = 0;
                current_number = v[i];
            }
            else
            {
                current_number = v[i];
                int temp_amount = 0;    // of i-th matryoskas found
                while(current_number == v[i] && i<n)    // quitas i<n y salen v[5] = 4 y v[6] = 49
                {
                    temp_amount++;
                    i++;
                }

                if(temp_amount < current_amount){
                    dp+=current_amount - temp_amount;
                    current_amount -= temp_amount;
                } 
                else current_amount = temp_amount;
            }
        }

        dp+=current_amount;

        cout << dp << "\n";
    }

    return 0;
}