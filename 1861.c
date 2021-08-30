#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct TreeNode
{
    char Nome[11];
    int Matou;
    struct TreeNode* Lchild;
    struct TreeNode* Rchild;
} Tree;
void Lexi(Tree* node);
void adiciona(Tree** t, char * nome);
void retira(Tree** t, char * nome);
int main()
{
    char matou[11], morreu[11];
    Tree* t = NULL;
    while (scanf("%s %s", matou, morreu)!= EOF)
    {
        adiciona(&t, matou);
        retira(&t, morreu);
    }
    printf("HALL OF MURDERERS\n");
    Lexi(t);
    free(t);
    return 0;
}
void adiciona(Tree** t, char * nome)
{
    if(*t == NULL)
    {
        *t = (Tree*)malloc(sizeof(Tree)); 
        (*t)->Lchild = NULL; 
        (*t)->Rchild = NULL;
        (*t)->Matou = 1;
        strcpy((*t)->Nome, nome);
    } 
    else 
    {
        if (strcmp(nome, (*t)->Nome)==0)
        {
            if ((*t)->Matou!=0)
            {
                (*t)->Matou = (*t)->Matou+1;
            }
        }
        else
        {
            if(strcmp(nome, (*t)->Nome)<0)
            {
                adiciona(&(*t)->Lchild, nome);
            }
            else
            {
                if(strcmp(nome, (*t)->Nome)>0)
                {
                    adiciona(&(*t)->Rchild, nome);
                }
            }
        }
    }
}
void retira(Tree** t, char * nome)
{
    if(*t == NULL)
    {
        *t = (Tree*)malloc(sizeof(Tree)); 
        (*t)->Lchild = NULL; 
        (*t)->Rchild = NULL;
        (*t)->Matou = 0;  
        strcpy((*t)->Nome, nome);
    }
    else
    {
        if (strcmp(nome, (*t)->Nome)==0)
            (*t)->Matou = 0;
        else
        {
            if(strcmp(nome, (*t)->Nome)<0)
            {
                retira(&(*t)->Lchild, nome);
            }
            else
            {
                if(strcmp(nome, (*t)->Nome)>0)
                {
                    retira(&(*t)->Rchild, nome);
                }
            }
        }
    }
}
void Lexi(Tree* node)
{
    if (node == NULL)
    {
        return;
    }
    Lexi(node->Lchild);
    if (node->Matou>0)
        printf("%s %d\n", node->Nome, node->Matou);
    Lexi(node->Rchild);
}