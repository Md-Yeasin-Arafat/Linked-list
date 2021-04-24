#include<bits/stdc++.h>
using namespace std;

typedef struct student{
    int id;
    char name[50];
    struct student *next;
}student;

void create(student *head);
void insert(student *head,student *item,student *locafter);
void del(student *head,student *prev);
void fcreate(student *head, FILE *in);
void display(student *head);
void traverse(student *head);
student *search(student *head,int id);
student *search_prev(student *head, int id);


int main()
{
    FILE *in;
    int id;
    student *first,*loc,*item;

    // in=fopen("\Users\Dell\OneDrive\one drive\OneDrive\Documents\dummy.txt","r");
    first=(student*) malloc(sizeof(student));
    create(first);
    traverse(first);

    // fcreate(first,in);
    // fclose(in);

    //display(first);
    
    cout<<"enter an id to search : ";
    cin>>id;
    loc=search(first,id);
    traverse(first);
    // cout<<loc;

    cout<<"enter an id and name to insert : ";
    item=(student*) malloc(sizeof(student));
    cin>>item->id>>item->name;
    insert(first,item,loc);
    traverse(first);

    //cout<<"enter an id to find its previous location : ";
    // search_prev=(student*)malloc(sizeof(student));
    cout<<"Enter an id to remove from the list : ";
    cin>>id;
    loc=search_prev(first,id);
    //cout<<loc<<endl;
    //traverse(first);

    cout<<"after deleting this particular id : "<<endl;
    if(first->id==id)first=first->next;
    else del(first,loc);
    traverse(first);

}



void create(student *head){
    char c;
    cout<<"Put your Id and Name to enlist : ";
    cin>>head->id>>head->name;
    cout<<"Put y or Y to continue else press any to stop : ";
    cin>>c;
    if(c=='y' || c=='Y'){
        head->next=(student*) malloc(sizeof(student));
        create(head->next);
    }
    else head->next=NULL;

}

void fcreate(student *head, FILE *in){
    student *block;
    int id;
    char name[50];
    block=head;

     if(fscanf(in,"%d %s",&id,name)==2){

        block->id=id;

        strcpy(block->name,name);

    }


    while(fscanf(in,"%d %s",&id,name)==2){

        block->next=(student *) malloc(sizeof(student));

        block=block->next;

        block->id=id;

        strcpy(block->name,name);

    }

    block->next=NULL;
    // while(fscanf(in,"%d%s",&id,name)==2){
    //     block->id=id;
    //     strcpy(block->name,name);
    //     block->next=block;
    // }
    // block->next=NULL;
}

// \Users\Dell\OneDrive\one drive\OneDrive\Desktop

void insert(student *head,student *item, student *locafter){
    item->next=locafter->next;
    locafter->next=item;
}

void del(student *head,student *prev){
    prev->next=prev->next->next;
}

void traverse(student *head){
    if(head==NULL)return;
    cout<<head->id<<"\t"<<head->name<<endl;
    traverse(head->next);
}



void display(student *head){
    if(head==NULL)return;
    cout<<head->id<<"\t"<<head->name<<endl;
    display(head->next);
}


student *search(student *head,int id){
    student *block;
    block=head;
    while(block!=NULL){
        if(block->id==id)return block;
        else block=block->next;
    }
    return NULL;
}

student *search_prev(student *head, int id){
    student *block;
    block=head;
    while(block->next!=NULL){
        if(block->next->id==id)return block;
        else block=block->next;
    }

}


// #include<bits/stdc++.h>
// using namespace std;

// typedef struct student{
//     int id;
//     char name[50];
//     struct student *next;
// }student;
// void create(student *head);
// void traverse(student *head);
// student *search(student *head, int id);

// int main()
// {
//     int id;
//     student *first,*loc;
//     first = (student*) malloc(sizeof(first));
//     create(first);

//     cout<<"Enter an id to search : ";
//     cin>>id;
//     loc= search(first,id);
//     cout<<loc;



//     return 0;
// }



// void create(student *head){
//         char c;
//         cout<<"Enter sopace separated id and name : ";
//         cin>>head->id>>head->name;
//         cout<<"press y or Y to continue or press other to terminate : ";
//         cin>>c;
//         if(c=='y' || c=='Y'){
//             head->next=(student*) malloc(sizeof(student));
//             create(head->next);
//         }
//         else head->next=NULL;
    
// }


// void traverse(student *head){
//     if(head==NULL)return;
//     cout<<head->id<<"\t"<<head->name<<endl;
//     traverse(head->next);
// }


//  student *search(student *head, int id){
//     student *block;
//     block=head;
//     while(block!=NULL){
//         if(block->id==id)return block;
//         else block=block->next;
//     }
//     return NULL;
// }