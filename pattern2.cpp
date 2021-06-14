/*

pattern 2

    *
   **
  ***
 ****
*****

*/
#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    k = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j < k && j > 0)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        k--;
        cout << "\n";
    }
    return 0;
}

/*
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j<n-i)
            {
                cout<<" ";
            }
            else:
            {
                cout<<"*";
            }
            cout<<"\n";
        }
    }
    return 0;
}
*/