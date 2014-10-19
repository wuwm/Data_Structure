//
//  main.c
//  Data_Structure
//
//  Created by 吴未名 on 14-10-16.
//  Copyright (c) 2014年 吴未名. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 20
#define LISTINCREMENT 10
#define OVERFLOW 111
#define True 1
#define False 0
#define Error -1
#define Ok 11
#define Fail -2
typedef int Status;
typedef int ElemType;
typedef Status (*Compare_p)(ElemType,ElemType);
typedef struct {
    ElemType *a;
    int length;
    int listsize;
}SqList;
Status Compare(ElemType a,ElemType b){
    if(a==b)    return True;
    else    return False;
}
Status InitList_Sq(SqList *L){
    L->a=(SqList *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    if(!L->a)
        return Error;
    L->length=0;
    L->listsize=LIST_INIT_SIZE;
    return Ok;
    
}
Status DestoryList(SqList *L){
    
    if(!L->a)  return Error;
    free(L->a);
    L->length=0;
    L->listsize=0;
    return Ok;
}
Status ClearList(SqList *L){
    if(!L)  return Error;
    L->length=0;
    return Ok;
}
Status ListEmpty(SqList *L){
    if(!L)  return Error;
    if(L->length==0)    return True;
    else return False;
}
Status GetElem(SqList *L,int i,ElemType *e){
    SqList *p=L;
    if(i>L->length)  return Error;
    *e=*((p->a)+i);
    return Ok;
}
int LocateElem(SqList *L,ElemType e){
    if(!L)  return Error;
    int i;
    for(i=0;i<L->length;i++){
        if(e==*((L->a)+i))  return i+1;
    }
    return Fail;
}
Status PriorElem(SqList *L,ElemType cur_e,ElemType *pre_e){
    if(!L)  return Error;
    if(!L->a)   return Error;
    int i=LocateElem(L, cur_e);
    if(i==Error||i==Fail||i==1)   return Fail;
    *pre_e=*(L->a+i-1);
    return Ok;
}
Status NextElem_Sq(SqList *L,ElemType cur_e,ElemType *next_e){
    if(!L)  return Error;
    if(!L->a)   return Error;
    int i=LocateElem(L, cur_e);
    if(i==Error||i==Fail||i==L->length-1)   return Fail;
    *next_e=*((L->a)+i);
    return Ok;
}
Status ListInsert(SqList *L,int i,ElemType e){
    int j;
    ElemType *p,*q;
    if(!L)  return Error;
    if(i<1||i>L->length)    return Error;
    if(i==L->length){ //开辟新空间
        ElemType *q=(ElemType *)malloc((L->listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!q)  return Error;
        for(j=0;j<L->length;j++){
            *(q+i)=*(L->a+i);
        }
        free(L->a);
        L->a=q;
        L->listsize+=LISTINCREMENT;
    }
    q=L->a+i-1;
    for(p=L->a+L->length;p>=q;p++){
        *p=*(p-1);
    }
    *q=e;
    L->length++;
    return Ok;
}
Status ListDelete_Sq(SqList *L,int i,ElemType *e){
    int j;
    if(!L)  return Error;
    if(!L->a)   return Error;
    *e=*(L->a+i-1);
    for(j=i-1;j<L->length-1;j++){
        *(L->a+j)=*(L->a+j+1);
    }
    L->length--;
    return Ok;
}

int main(){
    return 0;
}