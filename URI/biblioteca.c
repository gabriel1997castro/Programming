biblioteca 


ordena
ordena(){
	for(i=0;i<4;i++){
		scanf("%d", &v[i]);
			y[i]=v[i];
	}

	for(i=0;i<4;i++){
		for(j=i;j<4;j++){
			if(v[j]<y[i]){
				a=y[i];
				y[i]=v[j];
				y[j]=a;
			}	
		}
		for(k=0;k<4;k++){
			v[k]=y[k];
		}

	}
}