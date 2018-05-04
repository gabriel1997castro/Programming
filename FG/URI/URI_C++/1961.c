#include <stdio.h>
#include <stdlib.h>

int main(){
	int h, c, i, j=0;
	
	scanf("%d %d", &h, &c);
	int h1[c];
	
	for(i=0;i<c;i++){
		scanf("%d", &h1[i]);
	}
	for(i=0; i<c-1; i++){
		if(h1[i+1]>h1[i]){
			if((h1[i+1]-h1[i])>h)
				j++;
		}
		else{
			if((h1[i]-h1[i+1])>h)
				j++;
		}	
	}
	if(j>0)
		printf("GAME OVER\n");
	else
		printf("YOU WIN\n");




	return 0;
}