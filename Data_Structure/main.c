//
//  main.c
//  Data_Structure
//
//  Created by 吴未名 on 14-10-16.
//  Copyright (c) 2014年 吴未名. All rights reserved.
//

#include <stdio.h>
#define LIST_INIT_SIZE 10
typedef struct {
    int *a;
    int length;
    int listsize;
}SqList;
int InitList_Sq(SqList *L){
    L->a=(int *)malloc(sizeof(int)*LIST_INIT_SIZE);
    if(!L->a) exit(1);
    L->length=0;
    L->listsize=LIST_INIT_SIZE;
    return 1;
    
}
int main(){
    return 0;
}