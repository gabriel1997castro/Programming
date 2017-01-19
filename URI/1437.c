#include <stdio.h>

int main(){
	int i=1,b,j; 
	char s;
	while(i){
		b=4001;
		scanf("%d",&i);
		getchar();
		if(i==0)
			return 0;
			for(j=0;j<i;j++){
				scanf("%c",&s);
				if(s=='D')
					b++;
				else if(s=='E')
					b--;
			}
			if(b%4==1)
				printf("N\n");
			else if(b%4==2)
				printf("L\n");
			else if(b%4==3)
				printf("S\n");
			else if(b%4==0)
				printf("O\n");
		
	}

	return 0;
}