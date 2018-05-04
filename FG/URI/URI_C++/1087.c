#include <stdio.h>

int main(){
	int x1=1,x2,y1,y2,h,x,y;

	while(x1!=0||x2!=0||y1!=0||y2!=0){
		h=0;
		x=0;
		y=0;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if(x1>x2)
			x=x1-x2;
		if(x2>x1)
			x=x2-x1;
		if(y1>y2)
			y=y1-y2;
		if(y1<y2)
			y=y2-y1;
		if(x==y&&(x1!=0||x2!=0||y1!=0||y2!=0)&&x!=0)
			h=1;
		if(x!=y)
			h=2;
		if(x1==x2)
			h--;
		if(y1==y2)
			h--;
		if(h<0){
			h=0;
		}
		if(x1!=0||x2!=0||y1!=0||y2!=0){
			printf("%d\n", h);
		}
	}



	return 0;
}