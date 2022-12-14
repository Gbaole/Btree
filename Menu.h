#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <windows.h>
#include <cstring>
#include <fstream>
using namespace std;

#define N 3
using namespace std;

//DLL======================================================

struct node{  
    string data;  
    node *previous;  
    node *next;  
};      
   
//Represent the head and curr of the doubly linked list  
node *head, *curr = NULL; 
node * record; 
//Ket Thuc DLL==============================================

//Khai Bao Ham==============================================
void Menu();			// Ham nay se xuat ra cac danh sach menu
int ChonMenu();			// Ham nay dung de chon 1 menu tuong ung
void XuLyMenu();		// Xu ly menu ung voi menu duoc chon
void Visit(string data); 	//Tao Trang Moi
//void Print ();		//In ra thong tin
void TrangTruoc(); 		//Ve lai trang truoc
void TrangSau();		//Sang trang ke tiep
void PrintHistory();	//In lich su
void XoaHet();
void MoFile();
void InFile();
node *Tim(struct node* head, string str);
void Xoa();
void XoaDau();
void XoaCuoi();
void XoaDongTrongFile();

//Ket Thuc Khai Bao Ham====================================

//Dieu Khien Menu=========================================
void Menu() {
	cout << "=================Home Page================\n";
	cout << "1. Tao Trang Moi\n";
	cout << "2. Trang Truoc\n";
	cout << "3. Trang sau\n";
	cout << "4. Lich Su\n";
	cout << "5. Xoa Toan Bo Lich Su\n";
	cout << "6. Danh Dau Trang Hien Tai\n";
	cout << "7. Cac Trang Yeu Thich\n";
	cout << "8. Xoa 1 Trang Lich Su\n";
	cout << "9. Xoa Danh Dau 1 Trang\n";
	cout << "99. Thoat!!!\n";
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
	string str;
	node* head= NULL;
	switch (chon)
	{
	case 1:
		cout << "1. Nhap Trang Ban Muon Tim Kiem.\n";
		cin>>str;
		Visit(str);
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
		cout << "5. Da Xoa Toan Bo Lich Su\n";
		XoaHet();
		break;
	case 6:
		cout << "6. Da Danh Dau Thanh Cong Trang Hien Tai\n";
		MoFile();
		break;
	case 7:
		cout << "7. Cac Trang Yeu Thich Cua Ban\n";
		InFile();
		break;	
	case 8:
		Xoa();
		break;	
	case 9:
		XoaDongTrongFile();
		cout<<"Da Xoa";
		break;	
	case 99:
		cout << "99. Dong Trinh Duyet\n";
		exit(1);
		break;
	}
}
//Ket Thuc Dieu Khien Menu==================================

//Ham xu ly==================================================
void Visit(string data)
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
    cout<<"Ban Dang O Trang " <<curr->data<<"\n";
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
        printf("\nEMPTY");  
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
        printf("\nEMPTY");  
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
	cout<<"\n>-"<<temp->data;   
	temp= temp->next;		
	
	//In trang ke tiep
	while(temp != NULL)
	{
		cout<<"\n-"<<temp->data;    
		temp= temp->next;		
	}
}
void XoaHet()
{
		node *temp;
		while(head != NULL)
		{
			temp = head;
			head = head -> next;
		}
    	cout<<"All nodes are deleted successfully.\n"; 
    	delete temp;
    	PrintHistory();
}
node *Tim(struct node* head, string str) 
{ 
    node* temp = head;   
    while (temp != NULL) 
    { 
        if (temp->data == str) 
            return temp; 
        temp = temp->next; 
    } 
    return temp;
} 
void Xoa()
{
	node *temp;
	string str;
	cout<<"\nNhap trang can xoa: ";
	cin>>str;
	temp = Tim(head,str);

	if(temp != NULL )
	{
		if(temp->previous==NULL)
		{
			XoaDau();
			PrintHistory();
		}
		if(temp->next==NULL)
		{
			XoaCuoi();
			PrintHistory();
		}
		else
		{
			//thay doi lai lien ket cua phan tu co khoa K can xoa
        	temp->previous->next = temp->next;
        	temp->next->previous = temp->previous;
        	//gan con tro prev va next cua phan tu co khoa K can xoa ve null
        	temp->previous = NULL; 
        	temp->next = NULL;
        	//xoa node p co phan tu la khoa k
        	delete temp;
        	PrintHistory();
    	}
	}
}
void XoaDau(){
    //gan p bang phan tu dau danh sach
    node *temp = head;
    //thuc hien gan lai phan tu dau danh sach
    head = head->next;
    head->previous = NULL;
    //neu khong ton tai phan tu dau danh sach
    if (head==NULL){
        curr = NULL;
    }
    else
    //thay doi con tro next ve NULL
    {
		temp->next = NULL;
		
	}
    //xoa node p duoc gan bang phan tu dau danh sach
   	delete temp;
   	
}
void XoaCuoi (){
    //tao node p va gan bang phan tu cuoi danh sach
    node *temp = curr;
    //thuc hien gan lai phan tu cuoi danh sach
    curr = curr->previous;
    curr->next = NULL;
    //kiem tra phan tu cuoi neu rong
    if (curr==NULL){
        head = NULL;
    }
    //thay doi con tro prev cua node p ve NULL
    else
	{
		temp->previous = NULL;
	}
    //xoa p duoc gan bang phan tu cuoi danh sach
    delete temp;
}

void MoFile()
{
	ofstream Bookmark("bm.txt", ios::app);
	if(head == NULL)
		cout<<"EMPTY";
  // Write to the file
	if(head != NULL)
  	{
		Bookmark << curr->data<<"\n";
  		Bookmark.close();
	
  	}
  	
  // Close the file
  	
}
void InFile()
{
	// Create a text string, which is used to output the text file
	string text;

	// Read from the text file
	ifstream Bookmark("bm.txt");

	if (Bookmark.fail()) 
	{
    	cout << "\nError opening file" << endl;
	}
	if (Bookmark.eof())
	{
		cout <<"EMPY LIST";
	}
	// Use a while loop together with the getline() function to read the file line by line
	else 
	{
	
		while (getline (Bookmark, text)) 
		{
			
 		 	// Output the text from the file
  			cout <<"\nAddress: "<< text;
		}
	}	
	// Close the file
	Bookmark.close();
}

void XoaDongTrongFile()
{
	string line;
	string del;
	cout<<"Nhap trang can xoa: ";
	cin>>del;
    // open input file
    ifstream bm("bm.txt");
    if( !bm.is_open())
    {
          cout << "Bookmark file failed to open\n";
    }
    // now open temp output file
    ofstream temp("temp.txt");
    // loop to read/write the file.  Note that you need to add code here to check
    // if you want to write the line
    while( getline(bm,line) )
    {
        if(line != del)
            temp << line << "\n";
    }
    bm.close();
    temp.close();    
    // delete the original file
    remove("bm.txt");
    // rename old to new
    rename("temp.txt","bm.txt");
}
    


//Ket thuc ham xu ly=========================================



