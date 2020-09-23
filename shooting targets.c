#include <stdio.h>
struct p{
    int xy,c;
};
int f(int a,struct p *k,int l){
    for(int i=0;i<l;i++){
        if(k[i].xy==a)
        return i;
    }
    return -1;
}
void r(struct p *a,int x,int p[][2],int k,int l,int n){
    for(int i=0;i<n;i++){
        if(p[i][k]==x){
            int h=f(p[i][k^1],a,l);
            a[h].c--;
        }
    }
}
struct p * m(struct p *k,int l){
    struct p *m=k;
    for(int i=1;i<l;i++){
        if(m->c<k[i].c)
        m=k+i;
    }
    return m;
}
int main(){
    int n;
    scanf("%d",&n);
    int p[n][2],xc=0,yc=0,k,t=0,c=0;
    struct p x1[n],y1[n],*tempx,*tempy;
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i][0],&p[i][1]);
        k=f(p[i][0],x1,xc);
        if(k==-1){
            x1[xc].xy=p[i][0];
            x1[xc++].c=1;
        }
        else
        x1[k].c++;
        k=f(p[i][1],y1,yc);
        if(k==-1){
            y1[yc].xy=p[i][1];
            y1[yc++].c=1;
        }
        else
        y1[k].c++;
    }
    tempy=m(y1,yc);
    tempx=m(x1,xc);
    while(t!=n){
        if(tempx->c>tempy->c){
            t+=tempx->c;
            tempx->c=0;
            r(y1,tempx->xy,p,0,yc,n);
            tempx=m(x1,xc);
        }
        else{
            t+=tempy->c;
            tempy->c=0;
            r(x1,tempy->xy,p,1,xc,n);
            tempy=m(y1,yc);
        }
        c++;
    }
    printf("%d",c);
}
