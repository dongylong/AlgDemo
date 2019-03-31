//
//  queue.c
//  AlgDemo
//
//  Created by dongyuanlong on 11/21/17.
//  Copyright © 2017 dongyuanlong. All rights reserved.
//

#include "queue.h"
#include <string.h>

struct queueStruct{
    int data[1000];
    int head;
    int tail;
};
struct stackStruct{
    int data[10];
    int top;
};
void queue1(){
    int q[102] = {0, 6, 3, 1, 7, 5, 8, 9, 2, 4};
    int head = 0;
    int tail = 10;
    while (head < tail) {
        printf("%d",q[head]);
        head++;
        q[tail]=q[head];
        head++;
        tail++;
    }
    getchar();
    getchar();
}
void queue2(){
    struct queueStruct q;
    int i;
    q.head=1;
    q.tail=1;
    for (i=1; i<10; i++) {
        scanf("%d",&q.data[q.tail]);
        q.tail++;
    }
    while (q.head<q.tail) {
        printf("%d",q.data[q.head]);
        q.head++;
        q.data[q.tail]=q.data[q.head];
        q.head++;
        q.tail++;
    }
}
void palindrome(){
    char a[101]="ahaha" ;
    char s[101];
    long next;
    int top=0;
    long i ;
    long mid,len;
    len = strlen(a);
    mid=len/2-1;
    for(i = 0 ; i<=mid;i++){
        s[++top] = a[i];
    }
    if(len%2 ==0){
        next = mid +1;
    }else{
        next = mid+2;
    }
    for(i=next;i<=len-1;i++){
        if(a[i]!=s[top]){
            break;
        }
        top--;
    }
    if (top==0) {
        printf("YES");
    }else{
        printf("NO");
    }
}
void queue3(){
    struct queueStruct q1,q2;
    struct stackStruct s;
    int book[10];
    int i,t;
    q1.head=1;q1.tail=1;
    q2.head=1;q2.tail=1;
    s.top=0;
    int data[1000] = {2,4,1,2,5,6,3,1,3,5,6,4};
    for(i =1;i<9;i++){
        book[i] = 0;
    }
    for (i =0; i<6; i++) {
        //        scanf("%d",&q1.data[q1.tail]);
        q1.data[q1.tail] = data[i];
        q1.tail++;
    }
    for (i =6; i<12; i++) {
        //        scanf("%d",&q2.data[q2.tail]);
        q2.data[q2.tail]=data[i];
        q2.tail++;
    }
    while(q1.head<q1.tail&&q2.head<q2.tail){
        t=q1.data[q1.head];
        if(book[t]==0){
            q1.head++;
            s.top++;
            s.data[s.top]=t;
            book[t]=1;
        }else{
            q1.head++;
            q1.data[q1.tail]=t;
            q1.tail++;
            while (s.data[s.top]!=t) {
                book[s.data[s.top]]=0;
                q1.data[q1.tail] = s.data[s.top];
                q1.tail++;
                s.top--;
            }
        }
        
        t=q2.data[q2.head];
        if(book[t]==0){
            q2.head++;
            s.top++;
            s.data[s.top]=t;
            book[t]=1;
        }else{
            q2.head++;
            q2.data[q2.tail]=t;
            q2.tail++;
            while (s.data[s.top]!=t) {
                book[s.data[s.top]]=0;
                q2.data[q2.tail] = s.data[s.top];
                q2.tail++;
                s.top--;
            }
        }
    }
    if(q2.head==q2.tail){
        printf("q1 wins\n");
        printf("q1:data:\n");
        for(i=q1.head;i<q1.tail-1;i++){
            printf(" %d",q1.data[i]);
        }
        if(s.top>0){
            printf("\ns.data is:\n");
            for(i=0;i<s.top+1;i++){
                printf(" %d",s.data[i]);
            }
        }else{
            printf("s.data is empty");
        }
    }else{
        printf("q2 wins\n");
        printf("q2:data:\n");
        for(i=q2.head;i<q2.tail-1;i++){
            printf(" %d",q2.data[i]);
        }
        if(s.top>0){
            printf("\ns.data is:\n");
            for(i=0;i<s.top+1;i++){
                printf("%d",s.data[i]);
            }
        }else{
            printf("s.data is empty");
        }
    }
}
