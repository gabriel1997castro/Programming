#include <stdio.h>
#include <string.h>

int main(){
	char str[20]="mmmmmmmmmmmmmmmmmm";
	int h=0,soma=0;

	while(h<3){

		gets(str);
		if(str[0]=='c'){
			h+=1;
			printf("%d\n", soma);
			soma=0;
		}
		if(str[0]=='-'&&str[1]=='-')
			if(str[2]=='*')
				soma+=1;
		if(str[0]=='-'&&str[1]=='*'){
			if(str[2]=='-')
				soma+=2;
			if(str[2]=='*')
				soma+=3;
		}
		if(str[0]=='*'){
			if(str[1]=='-'){
				if(str[2]=='-')
					soma+=4;
				if(str[2]=='*')
					soma+=5;
			}
			if(str[1]=='*'){
				if(str[2]=='-')
					soma+=6;
				if(str[2]=='*')
					soma+=7;
			}
		}
	}
			



	return 0;
}