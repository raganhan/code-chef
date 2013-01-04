
#include <stdio.h>

int SALARIES[100];

bool all_eq(int nworkers) {
	int previous = SALARIES[0];
	
	for(int i = 1; i < nworkers; i++){

		if(previous != SALARIES[i]) {
			return false;
		}

		previous = SALARIES[i];
	}

	return true;
}

int index_of_max_value(int nworkers){
	int max = SALARIES[0];
	int max_index = 0;
	
	for(int i = 1; i < nworkers; i++){
		if(max < SALARIES[i]) {
			max = SALARIES[i];
			max_index = i;
		}
	}

	return max_index;
}

int main() {

	int test_cases;
	int nworkers;
	int max_index;
	int i,j;
	int noperations;

	// first line is the number of test_cases
	scanf("%d\n", &test_cases);

	// each test case
	for(i = 0; i < test_cases; i++){

		// reading initial salaries
		scanf("%d\n", &nworkers);
		for(j = 0; j < nworkers; j++){
			scanf("%d ", &SALARIES[j]);			
		}

		noperations = 0;
		while(!all_eq(nworkers)){
			noperations++;
			max_index = index_of_max_value(nworkers);
			for(j = 0; j < nworkers; j++){
				SALARIES[j]++;
			}
			SALARIES[max_index]--;
		}

		printf("%d\n", noperations);
	}
}

