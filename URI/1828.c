#include <stdio.h>


int main(){
	int i,n;
	char string1[20], string2[20];

	scanf("%d", &n);

	for(i=0;i<n;i++){
		scanf("%s", string1);
		scanf("%s", string2);

		printf("Caso #%d: ", i+1);
		if(string1[2] == 's'&& string2[2] == 'p'){
			printf("Bazinga!\n");
		}
		if(string1[2] == 'p' && string2[2] == 'd'){
			printf("Bazinga!\n");
		}
		if(string1[2] == 'd' && string2[2] == 'g'){
			printf("Bazinga!\n");
		}
		if(string1[2] == 'g' && string2[2] == 'o'){
			printf("Bazinga!\n");
		}
		if(string1[2] == 'o' && string2[2] == 's'){
			printf("Bazinga!\n");
		}
		if(string1[2] == 's' && string2[2] == 'g'){
			printf("Bazinga!\n");
		}
		if(string1[2] == 'g' && string2[2] == 'p'){
			printf("Bazinga!\n");
		}
		if(string1[2] == 'p' && string2[2] == 'o'){
			printf("Bazinga!\n");
		}
		if(string1[2] == 'o' && string2[2] == 'd'){
			printf("Bazinga!\n");
		}
		if(string1[2] == 'd' && string2[2] == 's'){
			printf("Bazinga!\n");
		}



		if(string2[2] == 's'&& string1[2] == 'p'){
			printf("Raj trapaceou!\n");
		}
		if(string2[2] == 'p' && string1[2] == 'd'){
			printf("Raj trapaceou!\n");
		}
		if(string2[2] == 'd' && string1[2] == 'g'){
			printf("Raj trapaceou!\n");
		}
		if(string2[2] == 'g' && string1[2] == 'o'){
			printf("Raj trapaceou!\n");
		}
		if(string2[2] == 'o' && string1[2] == 's'){
			printf("Raj trapaceou!\n");
		}
		if(string2[2] == 's' && string1[2] == 'g'){
			printf("Raj trapaceou!\n");
		}
		if(string2[2] == 'g' && string1[2] == 'p'){
			printf("Raj trapaceou!\n");
		}
		if(string2[2] == 'p' && string1[2] == 'o'){
			printf("Raj trapaceou!\n");
		}
		if(string2[2] == 'o' && string1[2] == 'd'){
			printf("Raj trapaceou!\n");
		}
		if(string2[2] == 'd' && string1[2] == 's'){
			printf("Raj trapaceou!\n");
		}

		if(string1[2] == string2[2]){
			printf("De novo!\n");
		}

	}

	return 0;
}