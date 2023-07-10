#include "judge.h"
#include <malloc.h>
#include <iostream>

class NAD : public INAD {
    int *subset;
	int min;
   public:
    long long getMinimumCost(int n, int k, long long c[15][8]) {
        min=INT32_MAX;
		subset = (int*)malloc(sizeof(int)* n);
		iterate(n,k,c,subset,0);
		return min;
    }
	void iterate(int n, int k, long long c[15][8], int* data, int size){
		if(k==size){
			int sum = 0;
			for(int i = 0 ;i<k;i++){
				sum+=c[i][data[i]];
			}
		}
		for(int i = 0; i<n; i++){
			auto new_c = (long long *)malloc(sizeof(long long) * n-1);
			
		}

	}
};

NAD solution;
int main() {
    Judge::run(&solution);
    return 0;
}
