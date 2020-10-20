#include <stdio.h>
int main (){
    double v[3][3];
    for (int i=0; i<3;i++){
        for (int j=0; j<3; j++){
            scanf("%lf", &v[i][j]);
        }
    }
    if (v[0][0]*v[1][1]*v[2][2]+
        v[0][1]*v[1][2]*v[2][0]+
        v[0][2]*v[1][0]*v[2][1]-
        
        v[0][0]*v[1][2]*v[2][1]-
        v[0][1]*v[1][0]*v[2][2]-
        v[0][2]*v[1][1]*v[2][1]==0){
            printf("Векторы компланарны\n");
        }else{
            printf("Векторы некомпланарны\n");
        }
   
   
   for (int i = 0; i<3;i++){
       for (int j = i+1; j<3; j++){
            if (v[i][0]==0 && v[i][1]==0 && v[i][2]==0){
                printf("%d %d колл\n", i+1, j+1);
                break;
            }
            double ratio = 0;
            for (int coord = 0; coord<3; coord++){
               if (v[i][coord]!=0){
                   ratio = v[j][coord]/v[i][coord];
               }
            }
            if (v[i][0]*ratio==v[j][0] && 
                v[i][1]*ratio==v[j][1] &&
                v[i][2]*ratio==v[j][2]){
                    printf("%d %d коллинеарны \n", i+1, j+1);
                } else{
                    printf("%d %d не коллинеарны \n", i+1, j+1);
                }
            
       }
   }
    
    
    return 0;
}
