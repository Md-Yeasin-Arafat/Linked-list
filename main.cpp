#include<bits/stdc++.h>
using namespace std;

typedef struct student{
    int id;
    char name[50];
    struct student *prev;
    struct student *next;
}student;

void create(student *head);
void insert(student *head,student *item,student *locafter);
student *del(student *head,student *prev);
//void fcreate(student *head, FILE *in);
student *fcreate(student *head,FILE *in);
void display(student *head);
void traverse(student *head);
void dll_reverse(student *last);
student *search(student *head,int id);
student *search_prev(student *head, int id);


int main()
{
    FILE *in;
    int id;
    student *first,*loc,*last,*item;
    in=fopen("/Users/Dell/Desktop/success.txt","r");
    first=(student*) malloc(sizeof(student));

    first->prev=NULL;
    first->next=NULL;
    last=first;

    //create(first);
    last=fcreate(first,in);
    //traverse(first);
     //fcreate(first,in);
     fclose(in);
     traverse (first);

    //display(first);
    cout<<"Reverse List"<<endl;
    dll_reverse(last);


    cout<<"enter an id to search : ";
    cin>>id;
    loc=search(first,id);
    cout<<"Data found at "<<loc<<endl;
    //traverse(first);
    // cout<<loc;

    cout<<"enter an id and name to insert : ";
    item=(student*) malloc(sizeof(student));
    cin>>item->id>>item->name;


    insert(first,item,loc);
    traverse(first);
    cout<<"Reverse List"<<endl;
    dll_reverse (last);


    //cout<<"enter an id to find its previous location : ";
    // search_prev=(student*)malloc(sizeof(student));
    cout<<"Enter an id to remove from the list : ";
    cin>>id;
    loc=search(first,id);
    first=del(first,loc);


    traverse(first);
    cout<<"Reverse List"<<endl;
    dll_reverse(last);
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

student *fcreate(student *head, FILE *in){
    student *block,*prev;
    int id;
    char name[50];
    block=head;

     if(fscanf(in,"%d%s",&id,name)==2){

        block->id=id;

        strcpy(block->name,name);

    }


    while(fscanf(in,"%d %s",&id,name)==2){
        prev=block;
        block->next=(student *) malloc(sizeof(student));

        block=block->next;
        block->prev=prev;
        block->id=id;

        strcpy(block->name,name);

    }

    block->next=NULL;
    return block;

}

// \Users\Dell\OneDrive\one drive\OneDrive\Desktop

void insert(student *head,student *item, student *locafter){
    item->next=locafter->next;
    locafter->next->prev=item;

    locafter->next=item;
    item->prev=locafter;
}

student *del(student *head,student *loc){
    student *prev,*first;

    if(loc->prev==NULL){
        loc->next->prev==NULL;
        first=loc->next;
        delete loc;
        return first;
    }
    prev=loc->prev;
    prev->next=prev->next->next;
    delete loc;
    return head;
}

void traverse(student *head){
    if(head==NULL)return;
    cout<<head->id<<"\t"<<head->name<<endl;
    traverse(head->next);
}


void dll_reverse(student *last){
    if(last==NULL)return;
    cout<<last->id<<"\t"<<last->name<<endl;
    dll_reverse(last->prev);
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
