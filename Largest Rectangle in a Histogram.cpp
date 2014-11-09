#include <iostream>
#include <string.h>
#define MAXN 100000
using namespace std;

typedef long long ll;

ll val[MAXN], rightSmaller[MAXN], leftSmaller[MAXN];

int main()
{
    int n;

    while(cin >> n && n){

        memset(val, 0, sizeof(val));
        ll ans = 0;
        for(int i=0; i < n; i++)
            cin >> val[i];

        leftSmaller[0] = -1;
        for(int i=1; i < n; ++i){
            leftSmaller[i] = i-1;
            while(val[leftSmaller[i]] >= val[i])
            {
                leftSmaller[i] = leftSmaller[leftSmaller[i]];
                if(leftSmaller[i] == -1) break;
            }
        }

        rightSmaller[n-1] = -1;
        for(int i=n-2; i >= 0; --i){
            rightSmaller[i] = i + 1;
            while(val[rightSmaller[i]] >= val[i] ){
                rightSmaller[i] = rightSmaller[rightSmaller[i]];
                if(rightSmaller[i] == -1) break;
            }
        }

        for(int i=0; i < n; ++i){
            if(rightSmaller[i] == -1) rightSmaller[i] = n-1;
            else rightSmaller[i]--;
            if(leftSmaller[i] == -1) leftSmaller[i] = 0;
            else leftSmaller[i]++;

            ll currentArea = val[i] * (rightSmaller[i] - leftSmaller[i] + 1 );
            ans = max(ans, currentArea);
        }
        cout << ans << endl;
    }
    return 0;
}
