
#include <stdio.h>

bool isSubSequence(char* small, char* big){

	while(*big != '\0'){
		if(*small == '\0'){
			return true;
		}

		if(*small == *big){
			*small++;
		}
		*big++;
	}

	return false;
}

bool eql(char* array1, char* array2){
	while(*array1 == *array2 && *array1 != '\0'){
		*array1++;
		*array2++;
	}

	return *array2 == '\0';
}

int main() {
	char manName[25001];
	int  manNameLength;

	char womanName[25001];
	int  womanNameLength;

	int npairs;
	char c;
	scanf("%2d\n", &npairs);

	// read
	for(int i = 0; i < npairs; i++){

		womanNameLength = manNameLength = 0;

		while( (c = getc(stdin)) != ' '){
			manName[manNameLength] = c;
			manNameLength += 1;
		}
		manName[manNameLength] = '\0';

		while( (c = getc(stdin)) != '\n'){
			womanName[womanNameLength] = c;
			womanNameLength += 1;
		}
		womanName[womanNameLength] = '\0';

		if(manNameLength < womanNameLength &&
				isSubSequence(manName, womanName)){
			printf("YES\n");
		}

		else if (manNameLength > womanNameLength &&
				isSubSequence(womanName, manName)){
			printf("YES\n");
		}

		else if (manNameLength == womanNameLength &&
				eql(manName, womanName)){
			printf("YES\n");
		}

		else {
			printf("NO\n");
		}

	}

	return 0;
}