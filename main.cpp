#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <iomanip>

using namespace std;
using std::vector;

struct mokinys
{
    string vardas;
    string pavarde;
    vector<int> nd;
    double vidurkis=0;
    double mediana=0;
};

int main()
{
    vector<mokinys> m;
    int x, c, pv=7, vard=6;
    cout << "Kiek mokiniu?" << endl;
    cin >> x;
    m.resize(x);
    for(int i=0;i<x;i++)
    {
        cout << "Iveskite " << i+1 << " mokinio varda ir pavarde" << endl;
        cin >> m[i].vardas >> m[i].pavarde;
        if(m[i].vardas.length()>vard)
            vard=m[i].vardas.length();
        if(m[i].pavarde.length()>pv)
            pv=m[i].pavarde.length();
    }
    for(int i=0;i<x;i++)
    {
        cout << "Ar generuoti pazymius atsitiktinai " << i+1 << " mokiniui?" << endl << "1-Taip" << endl << "0-Ne" <<endl;
        cin >> c;
        if(c==0)
            {
                cout << "Iveskite " << i+1 << " mokinio egzamino pazimi"<<endl;
                m[i].nd.push_back(1);
                cin >> m[i].nd[0];
                int n=1;
                while(1==1)
                {
                    cout << "Iveskite " << i+1 << " mokinio " << n <<" pazimi (-1 jei baigete su mokiniu)"<<endl;
                    m[i].nd.push_back(n);
                    cin >> m[i].nd[n];
                if(m[i].nd[n]==-1)
                {
                    break;
                }
                n++;
            }
        }
        else if(c==1)
        {
            int nr;
            cout << "Kiek namu darbu sugeneruoti?" << endl;
            cin >> nr;
            srand(time(NULL));
            for(int j=0;j<nr;j++)
            {
                m[i].nd.push_back(j);
                m[i].nd[j]=rand()%10+1;
            }
            m[i].nd.push_back(nr);
            m[i].nd[nr]=-1;
        }
    }
    for(int i=0;i<x;i++)
    {

        int n=0;
        while(m[i].nd[n]!=-1)
        {
            m[i].vidurkis+=m[i].nd[n];
            n++;
        }
        m[i].vidurkis=m[i].vidurkis*1.0/n;
        n--;
        m[i].nd.resize(n);
        vector<int> laikinas=m[i].nd;
        sort(laikinas.begin(), laikinas.end());
        c=n/2;
        if(n%2!=0)
        {
            m[i].mediana=(laikinas[c]+laikinas[c-1])*1.0/2;
        }
        else if(n%2==0)
        {
            m[i].mediana=laikinas[c-1];
        }

    }
    int sk;
    char t=' ';
    cout << "Isvesti mediana(0) ar vidurki(1)" << endl;
    cin >> sk;
    cout << "Pavarde" << string(pv-6, t) << "Vardas" << string(vard-5, t);
    if(sk==1)
        cout << "Vidurkis" << endl;
    if(sk==0)
        cout << "Mediana" << endl;
    cout << string(pv+vard+3+7, '-') << endl;
    for(int i=0;i<x;i++)
    {
        int z=m[i].pavarde.length();
        z=pv-z;
        cout << m[i].pavarde << string(z+1, t);
        z=m[i].vardas.length();
        z=vard-z;
        cout << m[i].vardas << string(z+1, t);
        if(sk==1)
            cout << setprecision(3) << m[i].vidurkis << endl;
        if(sk==0)
            cout << setprecision(3) << m[i].mediana << endl;
    }
    return 0;
}
