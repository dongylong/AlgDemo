//
//  quickSort.c
//  AlgDemo
//
//  Created by dongyuanlong on 11/6/18.
//  Copyright © 2018 dongyuanlong. All rights reserved.
//

#include "quickSort.h"
int a[101],n;
void quickSort(int left ,int right){
    int i,j,t,tmp;
    if(left>right){
        return;
    }
    tmp = a[left];
    i=left;
    j=right;
    while (i!=j) {
        while (a[j]>=tmp&&i<j) {
            j--;
        }
        while (a[j]<=tmp&&i<j) {
            i++;
        }
        if(i<j){
            t = a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[left]=a[i];
    a[i]=tmp;
    quickSort(left, i-1);
    quickSort(j+1, right);
}
int main(){
    int i,j,t;
    scanf("%d",&n);
    for (i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    quickSort(1, n);
    for (i=1; i<=n; i++) {
        printf("%d",a[i]);
        getchar();getchar();
        return 0;
    }
}
