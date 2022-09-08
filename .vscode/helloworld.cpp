#include<stdio.h>
#include<string.h> // lay compare

typedef struct NgayThangNam
{
	int ngay;
	int thang;
	int nam;
}Date;

typedef struct Nguoi
{
	int thehe;
	char hoten[40];
	char ba[40];
	char me[40];
	char vc[40];
	Date ngaysinh;
	int socon;
}N;

typedef struct Node
{
	Nguoi data;
	struct Node *next;
}node;

//tao LinkedList
typedef struct LinkedList
{
	Node *head;
	Node *tail;
}LL;

//tao ra 1 node
Node* CreateNode(N data)
{
	Node *newNode = new Node();
	newNode->data= data; 
	newNode->next = NULL;
	return newNode;
}

bool IsEmpty(LinkedList lst)
{
	if(lst.head==NULL && lst.tail==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void CreateList(LinkedList &lst)
{
	lst.head = NULL;
	lst.tail = NULL;
}

void XuatGiaPha(LinkedList lst)
{
	if(IsEmpty(lst)==true)
	{
		return;
	}
	else
	{
		Node *newNode = new Node();
		newNode = lst.head;
		printf("\n-------Danh Sach Nguoi Trong Gia Pha--------\n");
		printf("%5s %10s %10s %10s %10s %10s %5s","The He","Ho Ten","Ba","Me","Vo/Chong","Nam Sinh","So Con");
		while(newNode !=NULL)
		{
			printf("\n%5d %10s %10s %10s %10s %d/%d/%d %5d",newNode->data.thehe,newNode->data.hoten,newNode->data.ba,newNode->data.me,newNode->data.vc,newNode->data.ngaysinh.ngay,newNode->data.ngaysinh.thang,newNode->data.ngaysinh.nam,newNode->data.socon);
			newNode = newNode->next;
		}	
	}
	
}


int count(LinkedList lst)
{
	int dem =0;
	while(lst.head!=NULL)
	{
		++dem;
		lst.head = lst.head->next;
	}
	return dem;
}

void InsertNodeFirst(LinkedList &lst,Nguoi &x)
{
	Node *newNode = CreateNode(x);
	if(IsEmpty(lst)==true)
	{
		lst.head  = newNode;
		lst.tail = newNode;
	}
	else
	{
		newNode->next = lst.head;
		lst.head = newNode;
	}	
}

void Nhap1nguoi(N &a)
{	
        printf("\nNhap the he: \n");
        scanf("%d",&a.thehe);
        printf("Nhap ba: \n");
        fflush(stdin);
        gets(a.ba);
		printf("Nhap me: \n");
        fflush(stdin);
        gets(a.me);
		printf("Nhap ho ten: \n");
        fflush(stdin);
        gets(a.hoten);
		printf("Nhap ten vo hoac chong: \n");
        fflush(stdin);
        gets(a.vc);
		printf("Nhap ngay sinh: \n");
        scanf("%d",&a.ngaysinh.ngay);
        printf("Nhap thang sinh: \n");
        scanf("%d",&a.ngaysinh.thang);
        printf("Nhap nam sinh: \n");
        scanf("%d",&a.ngaysinh.nam);
        printf("Nhap so con: \n");
        scanf("%d",&a.socon);
        
}

void NhapDuLlieu(LinkedList &lst)
{
	int n;
	printf("Nhap so luong nguoi trong gia pha: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		N x;
		printf("Nhap thong tin Nguoi can them:");
		Nhap1nguoi(x);
		InsertNodeFirst(lst,x);
	}
}

int Kiemtra(LinkedList &lst,int t,char ten[])
{
	if(IsEmpty(lst)==true)
	{
		return -1;
	}
	else
	{
		Node *newNode = new Node();
		newNode = lst.head;
		while(newNode !=NULL)
		{
			if(strcmp(newNode->data.hoten,ten)==0 && newNode->data.ngaysinh.nam==t)
			{
				return 1;
			}
			newNode = newNode->next;
		}	
		return -1;
	}
}

void XuatConChauTH(LinkedList &lst,int t)
{
	if(IsEmpty(lst)==true)
	{
		return;
	}
	else
	{
		Node *newNode = new Node();
		newNode = lst.head;
		printf("\n-------------Danh Sach Nguoi Trong Gia Pha--------------\n");
		printf("%5s %10s %10s %10s %10s %10s %5s","The He","Ho Ten","Ba","Me","Vo/Chong","Nam Sinh","So Con");
		while(newNode !=NULL)
		{
			if(newNode->data.thehe>=t)
			printf("\n%5d %10s %10s %10s %10s %d/%d/%d %5d",newNode->data.thehe,newNode->data.hoten,newNode->data.ba,newNode->data.me,newNode->data.vc,newNode->data.ngaysinh.ngay,newNode->data.ngaysinh.thang,newNode->data.ngaysinh.nam,newNode->data.socon);
			newNode = newNode->next;
		}	
	}
}

int main()
{
	LinkedList lst;
	CreateList(lst);	
	NhapDuLlieu(lst);
	int soluong = count(lst);
	printf("\nSo luong nguoi trong List: %d",soluong);
	XuatGiaPha(lst);
	char x[40];
	printf("\nNhap vao ten 1 nguoi: ");
	fflush(stdin);
	gets(x);
	int namsinh;
	printf("\nNhap nam sinh: ");
	scanf("%d",&namsinh);
	int th;
	printf("\nNhap vao the he: ");
	scanf("%d",&th);
	if(Kiemtra(lst,namsinh,x) == -1)
		printf("\nKhong co nguoi ay trong gia pha !");
	else
	{
		XuatConChauTH(lst,th);
	}
	
	
}