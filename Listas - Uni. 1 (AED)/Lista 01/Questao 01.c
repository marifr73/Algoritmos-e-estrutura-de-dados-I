#include<stdio.h>

int main(){
    int x, y, *p;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;
    return 0;
}

//Portanto a responta de (X = 3), (Y = 4) e (P = &Y = 4).