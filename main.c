#include <stdio.h>
#include <stdlib.h>


const int n = 6;

int matrix[6][6] = {
    {0,1,1,0,0,0},
    {0,0,0,1,1,1},
    {0,0,0,0,0,1},
    {1,0,0,0,0,0},
    {0,0,0,1,0,0},
    {0,0,0,0,1,0},
};

int vis[6] = {0};
int real_move[6] = {0};

typedef struct Node
{
    struct Node *next_move;
    int move;
}Node;

typedef struct
{
    Node* next_node;
    int size;
}stack;

void init_stack(stack * s)
{
 s->next_node = NULL;
 s->size = 0;
}

void print_array(int *arr)
{
    printf("\n");
    for(int i = 0; i < n ; i++)
        printf("%d   ",arr[i]);
}

void insert_in_stack(stack *s , int move)
{
    Node* temp = (Node*)malloc(sizeof (Node));
    if(temp == NULL){
        printf("Stack overflow \n");
        return;
    }
    temp->move=move;
    temp->next_move =s->next_node;
    s->next_node = temp;
    s->size++;
}

void del_in_stack(stack *s)
{
    Node* node =s->next_node;
    int temp=s->next_node->move;
    s->next_node = s->next_node->next_move;
    free(node);
    s->size--;
}

int next_move(int str_matrix)
{
    for(int i = 0;i<n;i++)
    {
        if(matrix[str_matrix][i] == 1 && !vis[i])
            return i;
    }
    return - 1;
}
//Задание 2
//Обход графа в глубина через стек
void depth_travers_stask(int st, stack* s)
{
    insert_in_stack(s,st);//инициализация начального узла стек
    vis[st] = 1;
    printf("%d  ",st);
    while(s->size)
    {
        int v = next_move(s->next_node->move);
        if(v == -1)
        {
            del_in_stack(s);
        }
        else
        {
            vis[v]=1;
            real_move[v] = v;
            printf("%d  ",v);
            insert_in_stack(s,v);
        }
    }
}
//Задание 2
int adjacent_vertices[6] = {0};

void adjacency_count () {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[j][i] == 1)
                if (i != j) adjacent_vertices[i]++;
        }
    }
}


int main()
{
    stack *s = (stack*)malloc(sizeof(stack));
    init_stack(s);
    depth_travers_stask(0,s);
    print_array(real_move);

    adjacency_count();
    print_array(adjacent_vertices);


    return 0;
}
