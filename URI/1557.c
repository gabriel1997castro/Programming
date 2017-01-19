#include <stdio.h>

int main(){
	int n,i,j;

do{	
	scanf("%d", &n);
	if(n!=0){
	if(n<0||n>15)
		scanf("%d", &n);
	int m[n][n];
	m[0][0]=1;
	for(i=1;i<n;i++){
		m[i][0]=2*m[i-1][0];
	}
	for(i=0;i<n;i++){
		for(j=1;j<n;j++){
			m[i][j]=2*m[i][j-1];	
		}
	}
	
	int T = 0, valor=m[n-1][n-1];

 	if (valor == 0)
 		T = 1;
    else
        while (valor != 0)
        {
       		T = T + 1;
            valor = valor / 10;
        }

    for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
    		if(j!=n-1){
    			if(T==1)
    			printf("%2d",m[i][j]);
    		    if(T==2)
    			printf("%3d",m[i][j]);
    		    if(T==3)
    			printf("%4d",m[i][j]);
    		    if(T==4)
    			printf("%5d",m[i][j]);
    		    if(T==5)
    			printf("%6d",m[i][j]);
    		    if(T==6)
    			printf("%7d",m[i][j]);
    		    if(T==7)
    			printf("%8d",m[i][j]);
    			if(T==8)
    			printf("%9d",m[i][j]);
    		    if(T==9)
    			printf("%10d",m[i][j]);
    		    if(T==10)
    			printf("%11d",m[i][j]);
    		    if(T==11)
    			printf("%12d",m[i][j]);
    		    if(T==12)
    			printf("%13d",m[i][j]);
    			if(T==13)
    			printf("%14d",m[i][j]);
    		    if(T==14)
    			printf("%15d",m[i][j]);
    		    if(T==15)
    			printf("%16d",m[i][j]);
    		    if(T==16)
    			printf("%17d",m[i][j]);
    		    if(T==17)
    			printf("%18d",m[i][j]);
    		}
    		else{
    			if(T==1)
    			printf("%2d\n",m[i][j]);
    		    if(T==2)
    			printf("%3d\n",m[i][j]);
    		    if(T==3)
    			printf("%4d\n",m[i][j]);
    		    if(T==4)
    			printf("%5d\n",m[i][j]);
    		    if(T==5)
    			printf("%6d\n",m[i][j]);
    		    if(T==6)
    			printf("%7d\n",m[i][j]);
    		    if(T==7)
    			printf("%8d\n",m[i][j]);
    			if(T==8)
    			printf("%9d\n",m[i][j]);
    		    if(T==9)
    			printf("%10d\n",m[i][j]);
    		    if(T==10)
    			printf("%11d\n",m[i][j]);
    		    if(T==11)
    			printf("%12d\n",m[i][j]);
    		    if(T==12)
    			printf("%13d\n",m[i][j]);
    		    if(T==13)
    			printf("%14d\n",m[i][j]);
    		    if(T==14)
    			printf("%15d\n",m[i][j]);
    			if(T==15)
    			printf("%16d\n",m[i][j]);
    		    if(T==16)
    			printf("%17d\n",m[i][j]);
    		    
    		   
    		}
    	}
    }
}
    printf("\n");

}while(n!=0);
	return 0;
}