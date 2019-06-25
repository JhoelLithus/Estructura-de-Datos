#include <iostream>
#include <map>
#include <vector>
#include<fstream>

# define N 100
using namespace std;

int gradalc[N]; //Grado de Alcohol
map<int, int>tomad; //tomado
vector<int> depend[N]; //Dependencia
vector<int>orden; //ordenado

int main()
{
	//ifstream in("Uva 929.txt");
    map<string, int> mp;
    map<int, string> mp2;
    string s, p, q;
    int n, ques, cas = 0;
    
    while(scanf("%d", &n)!=EOF) //n-> Cantidad
    {
        int k = 0;
        for(int i=0; i<n; i++) 
		{
            cin>>s; //Bebidas Disponibles
            mp2[k] = s;
            mp[s] = k++;
        }
        scanf("%d", &ques); //Casos
        
        while(ques--)
        {
            cin>>p>>q; //bebidas tomadas en orden
            gradalc[mp[q]]++;
            depend[mp[p]].push_back(mp[q]);
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
			{
                if(!gradalc[j] && !tomad[j]) 
				{
                    tomad[j] = 1;
                orden.push_back(j);
                
                for(int k=0; k<depend[j].size(); k++)
                    gradalc[depend[j][k]]--;
                break;
            }
        }
    }
    printf("Case #%d: ", ++cas);
    cout<<"Dilbert should drink beverages in this order:";

        for(int i=0; i<orden.size(); i++)
            cout<<" "<<mp2[orden[i]];
        printf(".\n\n");
        tomad.clear();
        orden.clear();
        for(int i=0; i<n; i++)
            depend[i].clear();
    }
    return 0;
}
