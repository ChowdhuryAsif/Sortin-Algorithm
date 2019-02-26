#include <bits/stdc++.h>
using namespace std;

#define mx 105

class Age
{
public:
    int year;
    int month;
    int day;
    int pos;
};

Age human[mx];

bool younger(Age X, Age Y)
{
    if(X.year == Y.year && X.month == Y.month)
        return X.day < Y.day;
    else if(X.year == Y.year)
        return X.month < Y.month;
    else
        return X.year < Y.year;
}

void marge(int st, int mid, int en)
{
    int i = st, j = mid+1, k = 1;
    Age temp[mx];

    while(i<=mid || j<=en){
        if(i > mid)
            temp[k++] = human[j++];
        else if(j > en)
            temp[k++] = human[i++];
        else if(younger(human[i], human[j]))
            temp[k++] = human[i++];
        else
            temp[k++] = human[j++];
    }

    for(i=st, k=1; i<=en; i++, k++)
        human[i] = temp[k];
}

void divide(int st, int en)
{
    if(st < en){
        int mid = (st+en) >> 1;

        divide(st, mid);
        divide(mid+1, en);

        marge(st, mid, en);
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, y, m, d; cin >> n;

    for(int i=1; i<=n; i++){
        cin >> y >> m >> d;

        human[i].year = y;
        human[i].month = m;
        human[i].day = d;
        human[i].pos = i;
    }

    divide(1, n);

    for(int i=1; i<=n; i++)
        cout << human[i].year << " " << human[i].month << " " << human[i].day << " Human: " << human[i].pos << endl;

    return 0;
}
