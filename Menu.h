#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <windows.h>
using namespace std;

#define N 3
using namespace std;

//DLL======================================================

struct node{  
    int data;  
    node *previous;  
    node *next;  
};      
   
//Represent the head and curr of the doubly linked list  
node *head, *curr = NULL;  
//Ket Thuc DLL==============================================

//Khai Bao Ham==============================================
void Menu();			// Ham nay se xuat ra cac danh sach menu
int ChonMenu();			// Ham nay dung de chon 1 menu tuong ung
void XuLyMenu();		// Xu ly menu ung voi menu duoc chon
void Visit(int data); 	//Tao Trang Moi
//void Print ();			//In ra thong tin
void TrangTruoc(); 		//Ve lai trang truoc
void TrangSau();		//Sang trang ke tiep
void PrintHistory();	//In lich su

//int search(node** head_ref, int x);

//Ket Thuc Khai Bao Ham====================================

//Dieu Khien Menu=========================================
void Menu() {
	cout << "=================Home Page================\n";
	cout << "1. Tao Trang Moi\n";
	cout << "2. Trang Truoc\n";
	cout << "3. Trang sau\n";
	cout << "4. Lich Su\n";
	cout << "5. Thoat!!!\n";
	cout << "==========================================\n";
}
int ChonMenu()
{
	int n = 0;
	cout << "\n\nMoi chon menu: ";
	cin >> n;
	if (n > 0 || n < 5)
		return n;
	else
		return ChonMenu();
		
}
void XuLyMenu()
{
	int chon = ChonMenu();
	switch (chon)
	{
	case 1:
		cout << "1. Trang Moi Da Duoc Tao.\n";
		Visit(4);
		Visit(5);
		Visit(99);
		break;
	case 2:
		cout << "2. Trang Truoc\n";
		TrangTruoc();
		break;
	case 3:
		cout << "3. Trang Ke Tiep\n";
		TrangSau();
		break;
	case 4:
		cout << "4. Lich Su Cua Ban\n";
		PrintHistory();
		break;
	case 5:
		cout << "5. Dong Trinh Duyet\n";
		exit(1);
		break;
	}
}
//Ket Thuc Dieu Khien Menu==================================

//Ham xu ly==================================================
void Visit(int data)
{
	 
	node *newNode = new node;  
    newNode->data = data;  
      
    //If list is empty  
    if(head == NULL) {  
        //Both head and curr will point to newNode  
        head = curr = newNode;  
        //head's previous will point to NULL  
        head->previous = NULL;  
        //curr's next will point to NULL, as it is the last node of the list  
        curr->next = NULL;  
    }  
	else {  
        //newNode will be added after curr such that curr's next will point to newNode  
        curr->next = newNode;  
        //newNode's previous will point to curr  
        newNode->previous = curr;  
        //newNode will become new curr  
        curr = newNode;  
        //As it is last node, curr's next will point to NULL  
        curr->next = NULL;    
    }  
    curr = newNode;
}

/*void Print()
{
	node *current = head;  
    if(head == NULL) 
	{
        printf("List is empty\n");  
        return;  
    }  
    
    while(current != NULL) {  
        //Prints each node by incrementing pointer.  
        printf("%d ", current->data);  
        current = current->next;  
    }  

}*/

void TrangTruoc()
{
	 if(head == NULL) 
	{
        printf("\nList is empty");  
        return;  
    }  
	node* temp = head;
	while(temp->next != curr)
	{
		temp= temp->next;
	}
	curr=temp;
	cout<<"\nBan dang o trang: " << curr->data;
}
void TrangSau()
{
	if(head == NULL) 
	{
        printf("\nList is empty");  
        return;  
    }  
	if(curr->next != NULL)
		curr=curr->next;
	cout<<"\nBan dang o trang: " << curr->data;
}


void PrintHistory()
{
	cout<<"\nLich Su Duyet Cua Ban";
	if(head == NULL) 
	{
		cout<<"\n=================================";
        cout<<"\n		EMPTY";  
        cout<<"\n=================================";
        return;  
    }  
    node* temp = head;
    //in cac trang truoc
	while(temp != curr)
	{
		cout<<"\n-"<<temp->data;  
		temp= temp->next;		
	} 
	//in trang hien tai
	cout<<"\n> -"<<temp->data;  
	temp= temp->next;		
	//In trang ke tiep
	while(temp != NULL)
	{
		cout<<"\n-"<<temp->data;  
		temp= temp->next;		
	}
    
	
}
/*int search(node** head_ref, int x)
{
 
    // Stores head Node
    node* temp = *head_ref;
 
    // Stores position of the integer
    // in the doubly linked list
    int pos = 0;
 
    // Traverse the doubly linked list
    while (temp->data != x && temp->next != NULL) {
 
        // Update pos
        pos++;
 
        // Update temp
        temp = temp->next;
    }
 
    // If the integer not present
    // in the doubly linked list
    if (temp->data != x)
        return -1;
 
    // If the integer present in
    // the doubly linked list
    return (pos + 1);
}*/


//Ket thuc ham xu ly=========================================



