#include<bits/stdc++.h>

using namespace std;

int mmq(float x[],float y[],int n){

    float sum_x, sum_y, sum_xy, sum_xx,zero=0;
    float c0,c1;
    float xy[n];
    float xx[n];
    
    transform(x, x + n, y, xy, multiplies<float>());
    transform(x, x + n, x, xx, multiplies<float>());

    sum_y = accumulate(y,y+n,zero);
    sum_x = accumulate(x,x+n,zero);
    sum_xy = accumulate(xy,xy+n,zero);
    sum_xx = accumulate(xx,xx+n,zero);

    c1 = ((n*sum_xy)-(sum_x*sum_y))/((n*sum_xx)-(sum_x*sum_x));
    c0 = (sum_y-(c1*sum_x)) / n;

    printf("Y = %.2f + %.2fx\n",c0,c1);

    return 0;
}

int main(){
    
    float x[] = {1,2,3,4.5,6,7.5,9,10,11};
    float y[] = {2,25,70,80,220,250,440,500,560}; 

    mmq(x,y,9);

    return 0;
}