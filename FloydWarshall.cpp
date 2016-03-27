/*
    @author Sukeesh
    Floyd-Warshall Algorithm
*/

#include "bits/stdc++.h"
using namespace std;

#define N 1001
#define INF 1000000

int graph[N][N];
int d[N][N];
int n;

inline void floyd_warshal(){
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			d[i][j] = graph[i][j];
		}
	}

	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(d[i][k] + d[k][j] < d[i][j]){
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

}

int main(){
	cin >> n;
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin >> graph[i][j];
		}
	}

    floyd_warshal();
    printf("All Pairs Shortest Paths \n");
    for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
    		if(d[i][j]==1000000){
    			cout<<"INF ";
    		}
    		else{
    			cout << d[i][j] << " ";
    		}
    	}
    	cout << "\n";
    }
}