#include <stdio.h>
int main(){
	int h1=1,m1=1,h2=1,m2=1,h,m;
while(h1!=0||h2!=0||m1!=0||m2!=0){
	scanf("%d %d %d %d", &h1,&m1,&h2,&m2);
		if(h1<h2){
			h=h2-h1;
			if(m1<=m2)
				m=m2-m1;
			else{
				m=(60-m1)+(m2);
				h=h2-h1-1;
			}
		}
		else if(h1>h2){
			h=(24-h1)+h2;
			if(m1<=m2){
				m=m2-m1;
			}
			else{
				m=(60-m1)+(m2);
				h=((24-h1)+h2-1);
			}
		}
		else if(h1==h2){
			if(m2>m1){
				h=0;
				m=m2-m1;
			}
			if(m2<=m1){
				h=23;
				m=(60-m1)+m2;
			}
		}
	if(h1!=0||h2!=0||m1!=0||m2!=0){
		printf("%d\n",(h*60)+m);
	}
}

	return 0;
}