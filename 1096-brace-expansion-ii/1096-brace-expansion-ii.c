/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **a;
    int n;
} List;

List solve(char *s, int *i);

void add(List *l, char *x){
    for(int j=0;j<l->n;j++)
        if(!strcmp(l->a[j],x)) return;

    l->a = realloc(l->a,(l->n+1)*sizeof(char*));
    l->a[l->n] = malloc(strlen(x)+1);
    strcpy(l->a[l->n++],x);
}

List merge(List a,List b){
    for(int i=0;i<b.n;i++)
        add(&a,b.a[i]);

    return a;
}

List join(List a,List b){
    List r={NULL,0};
    char x[200];

    for(int i=0;i<a.n;i++)
        for(int j=0;j<b.n;j++){
            strcpy(x,a.a[i]);
            strcat(x,b.a[j]);
            add(&r,x);
        }

    return r;
}

List solve(char *s,int *i){
    List ans={NULL,0}, cur={NULL,0};

    while(s[*i] && s[*i]!='}'){
        if(s[*i]==','){
            ans=merge(ans,cur);
            cur=(List){NULL,0};
            (*i)++;
        }else{
            List x={NULL,0};

            if(s[*i]=='{'){
                (*i)++;
                x=solve(s,i);
                (*i)++;
            }else{
                char c[2]={s[*i],'\0'};
                add(&x,c);
                (*i)++;
            }

            if(cur.n==0)
                cur=x;
            else
                cur=join(cur,x);
        }
    }

    ans=merge(ans,cur);
    return ans;
}

char** braceExpansionII(char* expression,int* returnSize){
    int i=0;
    List r=solve(expression,&i);

    for(int i=0;i<r.n;i++)
        for(int j=i+1;j<r.n;j++)
            if(strcmp(r.a[i],r.a[j])>0){
                char *t=r.a[i];
                r.a[i]=r.a[j];
                r.a[j]=t;
            }

    *returnSize=r.n;
    return r.a;
}