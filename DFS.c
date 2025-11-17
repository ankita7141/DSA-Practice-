
#include<stdio.h>
void DFS(int a[20][20],int visited[20],int u,int n){
    visited[u]=1;
    printf("%d",u);
    for(int v=1;v<=n;v++){
        if(a[u][v]==1 && visited[v]==0){
            DFS(a,visited,v,n);
        }
    }
}

int main(){
    int a[20][20],visited[20],n;
    int i,j,source;
printf("enter num of vertices:");
scanf("%d",&n);
printf("enter adjacency matrix:");
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
scanf("%d",&a[i][j]);
    }
}
printf("enter source node:\n");
scanf("%d",&source);
printf("DFS:\n");
DFS(a,visited,source,n);
return 0;


}