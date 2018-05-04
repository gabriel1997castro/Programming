
#include <stdio.h>

int main(){
    int compra, dinheiro, net, i, cndtn;
    int bill[15] = {7, 12, 22, 52, 102, 15, 25, 55, 105, 30, 60, 110, 70, 120, 150};
    while(1){
        scanf("%d%d", &compra, &dinheiro);
        if(compra==0 && dinheiro==0) break;
        net = dinheiro - compra;
        for(i=0, cndtn = 0; i<15; i++){
            if(bill[i] == net){
                cndtn = 1;
                break;
            }
        }
        if(cndtn) printf("possible\n");
        else printf("impossible\n");
    }
    return 0;
}
