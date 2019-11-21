
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <iomanip>
#define true 1
#define false 0
#include "menu.h"
#define MAX 500



using namespace std;

enum Colors{
	black,          //  0 text color - multiply by 16, for background colors
	dark_blue,      //  1
	dark_green,     //  2
	dark_cyan,      //  3
	dark_red,       //  4
	dark_magenta,   //  5
	dark_yellow,    //  6
	light_gray,     //  7
	dark_gray,      //  8
	light_blue,     //  9
	light_green,    // 10
	light_cyan,     // 11
	light_red,      // 12
	light_magenta,  // 13
	light_yellow,   // 14
	white           // 15
};
		 
void color_set(){
	 HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int k=0;k<=255;k++) {
        SetConsoleTextAttribute(hConsoleColor, 245);
       // cout << k << " - Change color!  ";
        if (k%3==0) cout << endl;
    }
}
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
bool Check_ASCII_words(char word) {
	return(word >= 32 && word <= 127);
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//							CAU TRUC DU LIEU NHAN VIEN, HOA DON, CHI TIET HOA DON     			///
	struct position {
		int x,y;	
	};

//
	struct ngaylap{
	int ngay,thang,nam;
	};



// thong tin cua 1 node danh sach tuyen tinh chi tiet hoa don
struct CT_HD_INFO{
	string MAVT;
	float DonGia;
	int SoLuong; 
	float VAT ;
};

// cau truc danh sach tuyen tinh chi tiet hoa don
struct List_CT_HOADON {
 	struct	CT_HD_INFO INFO[21];
	int sizeHD = 20 ;
		
};


// du lieu cua 1 node danh sach lien ket HOA DON
struct 	DATA_HOADON {
	string SoHD,loai;
	float TriGia;
	struct ngaylap ngaylap;
    struct List_CT_HOADON* CT_HD;	
}; 
// cau truc  node danh sach lien ket HOA DON
struct HOADON {
	struct DATA_HOADON DATA_HD;
	struct HOADON *pNext;
};
// du lieu 1 node mang tuyen tinh NHAN VIEN
struct DATA_NHANVIEN {
	string MANV,HO,TEN,PHAI;
	struct HOADON *HD = NULL; 
};
// cau truc mang tuyen tinh NHAN VIEN
struct NHANVIEN {
	struct DATA_NHANVIEN *NV[MAX];
	int size_NV = 500; 
	};
// du lieu bien dung de chua du lieu case9
struct 	DATA_VT_CASE9{
	string MAVT;
	long long DoanhThu = 0;
};
struct List_VT_case9{
	struct DATA_VT_CASE9 DATA[100];
	int size = 100;
};
//////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////           CAC HAM SU LY DU LIEU NHAP VAO 			///////////////////
string Cut_Space(string &s){
	int i,n,j;
	int dem = 0;
	
	n=s.size();
	
		for(i=0;i<n;i++)
		{
			if((s[i]==' ')&&(s[i+1]==' '))
			{
				dem++;
				for(j=i;j<n;j++)
				{
					s[j]=s[j+1];
				}
				n--;	//so ki tu cua chuoi giam xuong
				i--;	//sau buoc nay thi i se tang (vong for) nen giam no xuong
			}
		}
		
	for (i=0;i<dem;i++){
		s.pop_back();
	}
	if (s.back() == ' ')
	s.pop_back();
	if (s.front() == ' ')
	s = s.erase(0,1);
	return s;
	
}
string Cut_enter(string &s){
	
	if (s.back() == '\n')
	s.pop_back();
	if (s.front() == '\n')
	s = s.erase(0,1);
	return s;
	
}
bool Check_Number(string a ){
	for(int i=0;i< a.size();i++)
		{
			if((a[i] > '9') || (a[i] < '0') || a.empty() == true)
			{
				return false;
			}
		}
	return true;	
}
void Print_Number_With_point (int s){
	char Num[50];
	itoa(s,Num,10);
	string xuoi = string(Num);
	Cut_Space(xuoi);
	string nguoc;
	int dem = 0;
	for (int i = Cut_Space(xuoi).size(); i >= 0; i-- ){
		
	//	cout << xuoi[i];
		nguoc += xuoi[i];
		if(dem % 3 == 0 && dem != xuoi.size() && dem != 0){
	//	cout << ",";
		nguoc += ",";	
		}
		
		dem++;
	}
	 
	for (int i = nguoc.size(); i >= 0 ; i--  ){
		cout << nguoc[i];	
	}
	cout << "VND";
}
//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////					CAU TRUC DU LIEU CAY NHI PHAN VA HAM LIEN QUAN 				//////

struct DaTa_Tree{
	
	string  MaVT;
	string TenVatTu;
	string DonViTinh;
	int SoLuongTon;
		
};
struct Node_Tree{
	
	struct DaTa_Tree DATA;
	struct Node_Tree *pLeft;
	struct Node_Tree *pRight;
	
};
typedef Node_Tree* Tree;
void Creat_Tree(Tree &T){
	
	T = NULL;
	
}
int Count_Node_Tree( Tree root){
	int count = 0;
	Node_Tree *p;
	while( root ){
		if( root->pLeft == NULL ){
			count = count + 1;
			root = root->pRight;
		}
		else{
			p = root->pLeft;
			while(p->pRight && p->pRight != root ){
				p = p->pRight;
			}
			if( p->pRight == NULL ){
				p->pRight = root;
				count = count + 1;
				root = root->pLeft;
			}
			else{
				p->pRight = NULL;
			//	cout<< root->data << " ";
				root = root->pRight;
			}
		}
	}
	
	
	 return count;
}
int Fix_VT_Xuat(Tree &root,string s,int i)
{
	if (root == NULL)
	 {
	 	
		return 0;
	}
	else {

     
     if (Cut_enter(root->DATA.MaVT ) > s) {

		if (Fix_VT_Xuat(root->pLeft,s,i) == 1) 
		return 1;
     	else return 0;
	 }
     else if (Cut_enter(root->DATA.MaVT ) < s){
		if (Fix_VT_Xuat(root->pRight,s,i) == 1) 
		return 1;
     	else return 0;      	

	 }
	
	 else{
	  
	//	cout << T->DATA.TenVatTu <<"\n";
	//	cout << T->DATA.TenVatTu <<"\n";
	//	cout << T->DATA.SoLuongTon <<"\n";
	//	cout << i <<"\n";
		root->DATA.SoLuongTon = root->DATA.SoLuongTon + i;
	//	cout << T->DATA.SoLuongTon <<"\n";
     	return 1;
	 }
	
      	
	}
}
int Fix_VT_Nhap(Tree &root,string s,int i)
{
	if (root == NULL)
	 {
	 	
		return 0;
	}
	else {

     
     if (Cut_enter(root->DATA.MaVT ) > s) {

		if (Fix_VT_Nhap(root->pLeft,s,i) == 1) 
		return 1;
     	else return 0;
	 }
     else if (Cut_enter(root->DATA.MaVT ) < s){
		if (Fix_VT_Nhap(root->pRight,s,i) == 1) 
		return 1;
     	else return 0;      	

	 }
	
	 else{
	  
	//	cout << T->DATA.TenVatTu <<"\n";
	//	cout << i;
		root->DATA.SoLuongTon = root->DATA.SoLuongTon - i;
     	return 1;
	 }
	
      	
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////	

////////////khai bao cac bien toan cuc //

	position vitricase5 = {0,0};
	position vitricase3 = {0,0};
//	struct DATA_NHANVIEN Data_NV;
	struct NHANVIEN NhanVien;
	Tree T;
//	struct NHANVIEN NhanVien1;
//	struct 	DATA_HOADON DATA_HD;
//	struct CT_HD_INFO CTHD_IF;

	//struct CT_HD_INFO INFO;
	int lcnhapxuat ;
	int SoVatTu_Auto;
	int SoHoaDon_Auto;
	string Tenvattu_fix ;
	string Donvitinh_VT_Fix;
	ifstream filein;
	ifstream filein1;
	ofstream fileout;
	ofstream fileout1;
	


/////////////////////////////////////////////////////////////
void Creat_Data_Tree(struct DaTa_Tree &Data){

	
	
	gotoxy(103,6);
	
	Data.MaVT = to_string(SoVatTu_Auto);
	cout << Data.MaVT;
	while (Data.TenVatTu.empty()){
	gotoxy(103,9);
	cout << "                   ";
	gotoxy(103,9);
//	cin.ignore();
	getline(cin,Data.TenVatTu);
	Data.TenVatTu = Cut_Space(Data.TenVatTu);
	}
	while (Data.DonViTinh.empty()){
	gotoxy(103,12);
	cout << "                   ";
	
	gotoxy(103,12);
//	cin.ignore();
	getline(cin,Data.DonViTinh);
	Data.DonViTinh = Cut_Space(Data.DonViTinh);
	}
	while ( true){
		gotoxy(103,15);
		cout <<"        ";
		gotoxy(103,15);
		string s ;
		cin >> s;
		if (Check_Number(s ) == true){
		Data.SoLuongTon = atoi(s.c_str());
		break;
		}
	}

	
}
void Add_Node_Tree(Tree &T,struct DaTa_Tree Data){
	
	
	if (T == NULL){
			Node_Tree *p = new Node_Tree;
			p->DATA = Data;
			p->pLeft = NULL;
			p->pRight = NULL;
			T = p;
	}
	else {
		
		if (T->DATA.MaVT > Data.MaVT) {
			
			Add_Node_Tree(T->pLeft,Data);
		}
		else if ( T->DATA.MaVT < Data.MaVT){
			
			Add_Node_Tree(T->pRight,Data);
		}
		
	}
}

void Add_Node_Tree_case2(Tree &T,struct DaTa_Tree Data){
	
	
	if (T == NULL){
			Node_Tree *p = new Node_Tree;
			p->DATA = Data;
			p->pLeft = NULL;
			p->pRight = NULL;
			T = p;
	}
	else {
		
		if (strcmp(T->DATA.TenVatTu.c_str(),Data.TenVatTu.c_str()) > 0 ) {
			
			Add_Node_Tree_case2(T->pLeft,Data);
		}
		else if (  strcmp(T->DATA.TenVatTu.c_str(),Data.TenVatTu.c_str()) < 0 ){
			
			Add_Node_Tree_case2(T->pRight,Data);
		}
		
	}
}
void Free_Memory(struct NHANVIEN &NhanVien){
	for (int i = 0 ; i < NhanVien.size_NV;i ++){
		delete NhanVien.NV[i];
	}
}	
void Traverse_Tree_case_6 (Tree root,string s,int i){

	Node_Tree *p;
	while( root ){
		if( root->pLeft == NULL ){
			if(atoi(root->DATA.MaVT.c_str()) == atoi(s.c_str())){
			cout <<root->DATA.TenVatTu;
			gotoxy(85,10+i);
			cout << "/" << root->DATA.DonViTinh;
			
			}			
			root = root->pRight;
		}
		else{
			p = root->pLeft;
			while(p->pRight && p->pRight != root ){
				p = p->pRight;
			}
			if( p->pRight == NULL ){
				p->pRight = root;
			if(atoi(root->DATA.MaVT.c_str()) == atoi(s.c_str())){
			cout <<root->DATA.TenVatTu;
			gotoxy(85,10+i);
			cout << "/" << root->DATA.DonViTinh;
			}
			root = root->pLeft;
			}
			else{
				p->pRight = NULL;
			//	cout<< root->data << " ";
				root = root->pRight;
			}
		}
	}
}
void Trasever_case_2(Tree root){
	
	int j = 0;
	int i = 0;
	////

	Node_Tree *p;
	while( root ){
		if( root->pLeft == NULL ){
				if(i<20){
				
				gotoxy(30,5+j);
				cout << atoi(root->DATA.MaVT.c_str());
				gotoxy(47,5+j);
				cout << root->DATA.TenVatTu;
				gotoxy(85,5+j);
				cout << root->DATA.DonViTinh ;
				gotoxy(97,5+j);
				cout << root->DATA.SoLuongTon;
				j++;
				}
				i++;
			root = root->pRight;
		}
		else{
			p = root->pLeft;
			while(p->pRight && p->pRight != root ){
				p = p->pRight;
			}
			if( p->pRight == NULL ){
				p->pRight = root;
			//	cout<< root->data << " ";
				root = root->pLeft;
			}
			else{
				p->pRight = NULL;
				if(i<20){
				
				gotoxy(30,5+j);
				cout << atoi(root->DATA.MaVT.c_str());
				gotoxy(47,5+j);
				cout << root->DATA.TenVatTu;
				gotoxy(85,5+j);
				cout << root->DATA.DonViTinh ;
				gotoxy(97,5+j);
				cout << root->DATA.SoLuongTon;
				j++;
				}
				i++;
				root = root->pRight;
			}
		}
	}
//	cout<< endl;

	////

	
}

void Trasever_List_Case_2(Tree root, int i){
	for (int i=0;i < 20;i++){
	
	gotoxy(30,5+i);
	cout << "     "; 
	gotoxy(47,5+i);
	cout << "               ";
	gotoxy(85,5+i);
	cout << "       ";
	gotoxy(97,5+i);
	cout << "         ";
		}
	int j = 0;
	int n = 0;
	//////
		Node_Tree *p;
	while( root ){
		if( root->pLeft == NULL ){
				if(n<i && n >= i - 20){
				
				gotoxy(30,5+j);
				cout << atoi(root->DATA.MaVT.c_str());
				gotoxy(47,5+j);
				cout << root->DATA.TenVatTu;
				gotoxy(85,5+j);
				cout << root->DATA.DonViTinh ;
				gotoxy(97,5+j);
				cout << root->DATA.SoLuongTon;
				j++;
				}
				n++;
			root = root->pRight;
		}
		else{
			p = root->pLeft;
			while(p->pRight && p->pRight != root ){
				p = p->pRight;
			}
			if( p->pRight == NULL ){
				p->pRight = root;
			//	cout<< root->data << " ";
				root = root->pLeft;
			}
			else{
				p->pRight = NULL;
				if(n<i && n >= i - 20){
				
				gotoxy(30,5+j);
				cout << atoi(root->DATA.MaVT.c_str());
				gotoxy(47,5+j);
				cout << root->DATA.TenVatTu;
				gotoxy(85,5+j);
				cout << root->DATA.DonViTinh ;
				gotoxy(97,5+j);
				cout << root->DATA.SoLuongTon;
				j++;
				}
				n++;
				root = root->pRight;
			}
		}
	}
	/////
	
}
int Find_Print_VT_case5(Tree root,string s,int i){
	if (T == NULL)
	 {
	 	
		return 0;
		}
     
     if (Cut_enter(root->DATA.MaVT ) > s) {
        if(Find_Print_VT_case5(root->pLeft,s,i) == 1)
			return 1;
		else return 0;	
	 }
     else if (Cut_enter(root->DATA.MaVT ) < s){
        if(Find_Print_VT_case5(root->pRight,s,i) == 1)
			return 1;
		else return 0;
      	
	 }
	
	 else{
	  
			gotoxy(85,10+vitricase5.y);
	  		cout << "/" << root->DATA.DonViTinh;
			if( lcnhapxuat == 1){
				if(root->DATA.SoLuongTon < i){
				gotoxy(90,6);
				cout << root->DATA.TenVatTu << " con " << root->DATA.SoLuongTon << " " << root->DATA.DonViTinh;
				
				getch();
				
				gotoxy(90,6);
				cout << "                       ";
			//	cin.ignore();
				return 0;					
				}
				else {
					root->DATA.SoLuongTon = root->DATA.SoLuongTon - i;
					return 1;
				}
		
     			return 1;
			}
			else if( lcnhapxuat == 0){
				root->DATA.SoLuongTon = root->DATA.SoLuongTon + i;
				return 1;
			}
     	
	 }
	
      
     
     }

int Find_Print_Deleta_case5(Tree root,string s,int i){
	if (root == NULL)
	 {
	 	cout << "ccc";
		return 0;
		}
     
     if (Cut_enter(root->DATA.MaVT ) > s) {
     	Find_Print_Deleta_case5(root->pLeft,s,i);
	 }
     else if (Cut_enter(root->DATA.MaVT ) < s){
      	Find_Print_Deleta_case5(root->pRight,s,i);
      	
	 }
	
	 else{
	  		gotoxy(30,10+i);
			cout <<root->DATA.TenVatTu;
			gotoxy(85,10+i);
			cout << "/" << root->DATA.DonViTinh;			
			return 1;
	 }
	
      
     return 0;
	
	
}
int  Find_Node_Case1(Tree root,string s){
	
	if (root == NULL)
	 {
		return 0;
		}
     
     if (Cut_enter(root->DATA.MaVT ) > s) {
     	if (Find_Node_Case1(root->pLeft,s) == 1)
	 		return 1;
	 	else return 0;	
	 }
     else if (Cut_enter(root->DATA.MaVT ) < s){
     	if (Find_Node_Case1(root->pRight,s) == 1)
	 		return 1;
	 	else return 0;
      	
	 }
	
	 else{
	 		gotoxy(103,6);
	 		cout << root->DATA.MaVT;
			gotoxy(103,9);
			cout << root->DATA.TenVatTu;
			gotoxy(103,12);
			cout << root->DATA.DonViTinh;
			Tenvattu_fix = root->DATA.TenVatTu;
			Donvitinh_VT_Fix = root->DATA.DonViTinh; 	  				
			return 1;
	 }

	
	
}
int  Fix_Node_Case1(Tree &root,string s){
	
	if (root == NULL)
	 {
		return 0;
		}
     
     if (Cut_enter(root->DATA.MaVT ) > s) {
     	if (Fix_Node_Case1(root->pLeft,s) == 1)
	 		return 1;
	 	else return 0;	
	 }
     else if (Cut_enter(root->DATA.MaVT ) < s){
     	if (Fix_Node_Case1(root->pRight,s) == 1)
	 		return 1;
	 	else return 0;
      	
	 }
	
	 else{

			root->DATA.TenVatTu =  Cut_Space(Tenvattu_fix);
			root->DATA.DonViTinh = Cut_Space(Donvitinh_VT_Fix); 	  				
			return 1;
	 }

	
	
}
void Trasever_List_Case_1(Tree root, int i){
	for (int j = 0 ; j < 20;j++){
						
	gotoxy(10,5+j);
	cout << "      " ;
	gotoxy(30,5+j);
	cout << "                        ";
	gotoxy(60,5+j);
	cout << "        ";
	gotoxy(77,5+j);
	cout << "      ";
	}
	int j = 0;
	int n = 0;
	Node_Tree *p;
	while( root ){
		if( root->pLeft == NULL ){
				if(n<i && n >= i - 20){
				
				gotoxy(10,5+j);
				cout << atoi(root->DATA.MaVT.c_str());
				gotoxy(30,5+j);
				cout << root->DATA.TenVatTu;
				gotoxy(60,5+j);
				cout << root->DATA.DonViTinh ;
				gotoxy(77,5+j);
				cout << root->DATA.SoLuongTon;
				j++;
				}
				n++;
				root = root->pRight;
				
		}
		else{
			p = root->pLeft;
			while(p->pRight && p->pRight != root ){
				p = p->pRight;
			}
			if( p->pRight == NULL ){
				p->pRight = root;
				if(n<i && n >= i - 20){
				
				gotoxy(10,5+j);
				cout << atoi(root->DATA.MaVT.c_str());
				gotoxy(30,5+j);
				cout << root->DATA.TenVatTu;
				gotoxy(60,5+j);
				cout << root->DATA.DonViTinh ;
				gotoxy(77,5+j);
				cout << root->DATA.SoLuongTon;
				j++;
				}
				n++;
				root = root->pLeft;
				
			}
			else{
				p->pRight = NULL;
			//	cout<< root->data << " ";
				root = root->pRight;
			}
		}
	}
	
}	

void Find_Node_Delete(Tree &X, Tree &Y){
	
	if (Y->pLeft != NULL){
		Find_Node_Delete(X,Y->pLeft);
	}
	else {
		X->DATA = Y->DATA;
		X = Y;
		Y = Y->pRight;
		
	}
}
int Delete_Node_Tree(Tree &root, string s ){
	
	if ( root == NULL){
		
		return 0;
	}
	else {
		if ( s < root->DATA.MaVT){
			 if (Delete_Node_Tree(root->pLeft,s ) == 1)
			 return 1;
			 else return 0;
		}
		else if ( s > root->DATA.MaVT){
			 if (Delete_Node_Tree(root->pRight,s ) == 1)
			 return 1;
			 else return 0;
		
		}
		else {
			
			Node_Tree *X = new Node_Tree ;
			X = root;
			if ( root->pLeft == NULL){
				root = root->pRight;
			}
			else if ( root->pRight == NULL){
				root = root->pLeft;
			}
			else {
				Node_Tree *Y = new Node_Tree;
				Y = root->pRight;
				Find_Node_Delete(X,Y);
			}
			delete X;	
			return 1;
		}
		 		 
	}
	
} 	
int Is_SLT_Eq_0(Tree T,string s)
{
	if (T == NULL)
	 {
	 	
		return 0;
	}
	else {

     
     if (Cut_enter(T->DATA.MaVT ) > s) {

		if (Is_SLT_Eq_0(T->pLeft,s) == 1) 
		return 1;
     	else return 0;
	 }
     else if (Cut_enter(T->DATA.MaVT ) < s){
		if (Is_SLT_Eq_0(T->pRight,s) == 1) 
		return 1;
     	else return 0;      	

	 }
	
	 else{
	  
		if (T->DATA.SoLuongTon == 0)
     	return 1;
     	else return 0;
	 }
	
      	
	}
}

void Read_Tree(ifstream &filein,Tree &T){
	
	
	filein.open("Tree.TXT",ios_base::in);
	if (filein.fail()== true)
	{	
		cout << "FILE D TON TAI";
		
	}
	else {
		
		struct DaTa_Tree Data;
		int sovattu;
		filein >>  sovattu;
		filein >>  SoVatTu_Auto;
		string s;
		getline(filein,s);
		for ( int i = 0; i < sovattu; i++ ){
		
			getline(filein ,Data.MaVT,'	');
			getline(filein , Data.TenVatTu,'	');
			getline(filein , Data.DonViTinh,'	');
			filein >> Data.SoLuongTon;
			getline(filein,s);
		//	getline(cin,s);
			Add_Node_Tree(T,Data);
		}
	}
	filein.close();	
}
void Read_Tree_case2(ifstream &filein,Tree &T){
	
	
	filein.open("Tree.TXT",ios_base::in);
	if (filein.fail()== true)
	{	
		cout << "FILE D TON TAI";
		
	}
	else {
		
		struct DaTa_Tree Data;
		int sovattu;
		filein >>  sovattu;
		string s;
		getline(filein,s);
		for ( int i = 0; i < sovattu; i++ ){
		
			getline(filein ,Data.MaVT,'	');
			getline(filein , Data.TenVatTu,'	');
			getline(filein , Data.DonViTinh,'	');
			filein >> Data.SoLuongTon;
		//	getline(cin,s);
			Add_Node_Tree_case2(T,Data);
		}
	}
	filein.close();	
}
void Write_Tree (ofstream &fileout,Tree root){
	
	fileout.open("Tree.TXT",ios::out|ios::trunc);
	fileout << Count_Node_Tree(root) << " \t";
	fileout << SoVatTu_Auto << "\n";
	Node_Tree *p;
	while( root ){
		if( root->pLeft == NULL ){
			fileout << root->DATA.MaVT << "	";
			fileout << root->DATA.TenVatTu << "	";
			fileout << root->DATA.DonViTinh << "	";		
			fileout << root->DATA.SoLuongTon << "\n";
			root = root->pRight;
		}
		else{
			p = root->pLeft;
			while(p->pRight && p->pRight != root ){
				p = p->pRight;
			}
			if( p->pRight == NULL ){
				p->pRight = root;
				fileout << root->DATA.MaVT << "	";
				fileout << root->DATA.TenVatTu << "	";
				fileout << root->DATA.DonViTinh << "	";		
				fileout << root->DATA.SoLuongTon << "\n";
				root = root->pLeft;
			}
			else{
				p->pRight = NULL;
			//	cout<< root->data << " ";
				root = root->pRight;
			}
		}
	}
	fileout.close();
}


///////////////các hàm danh sách nhân vien///////////////////	
int Pos_Empty_NV(struct NHANVIEN &NhanVien){
	int vitri ;
	for (vitri = 0; vitri < NhanVien.size_NV; vitri++)
	{
		if ((NhanVien.NV[vitri]->MANV).empty())
		return vitri;
		
	}
}
void Creat_Node_NV_MNV(struct DATA_NHANVIEN &Data_NV){
	//gotoxy(103,15);
	cin >> Data_NV.MANV;
}

int Add_Input_MaNV(struct NHANVIEN NhanVien){
	int Max[500];
	int Output = 0;
	string fix;
	for (int i = 0 ; i < Pos_Empty_NV(NhanVien) ;i ++){
		fix = NhanVien.NV[i]->MANV;
		fix = fix.erase(0,2);
		Max[i] = atoi(fix.c_str());
	}
	for (int j = 0; j < Pos_Empty_NV(NhanVien) ; j++){
		if (Max[j] > Output)
		Output = Max[j];
	}
	return Output;
}
void DeLete_Node_NV(struct DATA_NHANVIEN &Data_NV){
	Data_NV.MANV.clear();
	Data_NV.HO.clear();
	Data_NV.PHAI.clear();
	Data_NV.TEN.clear();
}
void Creat_Node_NV(struct DATA_NHANVIEN &Data_NV){
	DeLete_Node_NV(Data_NV); 
	string Manv ="nv";
	gotoxy(103,6);
	Data_NV.MANV = Manv += to_string(Add_Input_MaNV(NhanVien)+1);
	cout << Data_NV.MANV;
	while ((Data_NV.HO.empty()) || (Data_NV.TEN.empty())){
	
	gotoxy(103,9);
	cout << "                ";
	gotoxy(120,9);
	cout << "       ";
	gotoxy(103,9);
//	cin.ignore();
	getline(cin, Data_NV.HO);
	
	Cut_Space(Data_NV.HO);
	gotoxy(120,9);
	
	getline(cin, Data_NV.TEN);
	
	Cut_Space(Data_NV.TEN);
}
	gotoxy(103,12);
	//cin.ignore();
	getline(cin,Data_NV.PHAI);
	while(true){
	if (Data_NV.PHAI == "NAM" || Data_NV.PHAI == "NU" || Data_NV.PHAI == "Nam" || Data_NV.PHAI == "Nu" || Data_NV.PHAI == "nam" ||Data_NV.PHAI == "nu"){
	break;
	}
	else 
	gotoxy(103,12);
	cout <<"                     ";
	gotoxy(103,12);
	cin.ignore();
	cin >> Data_NV.PHAI;
}
}

void Empty_List_NV(struct NHANVIEN &NhanVien){
	for (int i = 0 ; i < Pos_Empty_NV(NhanVien);i++){
		
		NhanVien.NV[i]->HO.clear(); 
		NhanVien.NV[i]->MANV.clear();
		NhanVien.NV[i]->PHAI.clear();
		NhanVien.NV[i]->TEN.clear();
		delete NhanVien.NV[i]->HD;
		NhanVien.NV[i]->HD->DATA_HD.loai.clear();
		NhanVien.NV[i]->HD->DATA_HD.ngaylap.ngay = 0;
		NhanVien.NV[i]->HD->DATA_HD.ngaylap.thang = 0;
		NhanVien.NV[i]->HD->DATA_HD.ngaylap.nam = 0;
		delete NhanVien.NV[i]->HD->DATA_HD.CT_HD;
	}
		
}
int Insert_list_NHANVIEN (struct NHANVIEN &NhanVien ,int i , struct DATA_NHANVIEN Data_NV){
	
	
	if ( i<0 || i > NhanVien.size_NV || NhanVien.size_NV == 0)
	return 0;
	//if (i == 0) i=1;
	for (int j = NhanVien.size_NV ; j >=i; j--)
	
	 NhanVien.NV[j+1] = NhanVien.NV[j];
	 NhanVien.NV[i] = new DATA_NHANVIEN;
	 NhanVien.NV[i]->HO = Data_NV.HO;
	 NhanVien.NV[i]->MANV = Data_NV.MANV;
	 NhanVien.NV[i]->PHAI = Data_NV.PHAI;
	 NhanVien.NV[i]->TEN = Data_NV.TEN;
	 //list_CTHD.sizeHD ++;
	 
	return 1;
}
void cap_phat(struct NHANVIEN &NhanVien){
	for (int i = 0 ; i < NhanVien.size_NV;i++){
		NhanVien.NV[i] = new DATA_NHANVIEN;
	}
	
}
int DEL_ITEM_NHANVIEN(NHANVIEN &NhanVien, int i){
	
	int j;
	if (i < 0 || i > NhanVien.size_NV || NhanVien.size_NV == 0 )
	return 0;
	if (i == 0) i=1;
	for ( j = i; j < NhanVien.size_NV; j++)
	NhanVien.NV[j-1] = NhanVien.NV [j];
	NhanVien.size_NV --;
	return 1;
		
}
int Search_list_NV (struct NHANVIEN NhanVien , struct DATA_NHANVIEN Data_NV){
	for (int vitri =0; vitri < NhanVien.size_NV; vitri ++)
	if (NhanVien.NV[vitri]->MANV == Data_NV.MANV )
	return vitri;
	return -3;
		
}
int Is_NhanVien_Have_HD(struct NHANVIEN NhanVien,struct DATA_NHANVIEN Data_NV){
	for ( int i = 0; i < Pos_Empty_NV(NhanVien);i++){
		if (NhanVien.NV[i]->MANV == Data_NV.MANV ){
			if (NhanVien.NV[i]->HD != NULL){
				return 1;
			}
		}
	}
	return 0;
}
int Search_Manv(struct NHANVIEN NhanVien,string Manv){
	for (int vitri =0; vitri < NhanVien.size_NV; vitri ++){
	
	if (NhanVien.NV[vitri]->MANV == Manv )
	return vitri;}
	return -1;
}
void Traverse_list_NV_case3(struct NHANVIEN NhanVien,int n){
	for (int j = 0 ; j < 20;j++){
						
	gotoxy(10,5+j);
	cout << "          " ;
	gotoxy(30,5+j);
	cout << "                            ";
	gotoxy(60,5+j);
	cout << "          ";}
	int i = 0;
	
	if (NhanVien.size_NV == 0 )
	cout << " danh sach rong ";
	gotoxy(10,5);
	if (n<=20){
	
	for ( i = 0; i < Pos_Empty_NV(NhanVien); i++){
	
	gotoxy(10,5+i);
	cout << NhanVien.NV[i]->MANV; 
	gotoxy(30,5+i);
	cout << NhanVien.NV[i]->HO <<" ";
	cout << NhanVien.NV[i]->TEN;
	gotoxy(60,5+i);
	cout << NhanVien.NV[i]->PHAI;
	}	
	}
	else {
	
	
	for (i = 0 ; i < 20;i++ ){
	
	gotoxy(10,5+i);
	cout << NhanVien.NV[n-20]->MANV; 
	gotoxy(30,5+i);
	cout << NhanVien.NV[n-20]->HO << " ";
	cout << NhanVien.NV[n-20]->TEN;
	gotoxy(60,5+i);
	cout << NhanVien.NV[n-20]->PHAI;
	n++;
	
	}	
		
	}
}

void Page_Traverse_list_NV_case3(struct NHANVIEN NhanVien,int n){
	for (int j = 0 ; j < 20;j++){
						
	gotoxy(10,5+j);
	cout << "          " ;
	gotoxy(30,5+j);
	cout << "                            ";
	gotoxy(60,5+j);
	cout << "          ";}
	int i = 0;
	
	int j = n-20;
	if (NhanVien.size_NV == 0 )
	cout << " danh sach rong ";
	gotoxy(10,5);
	
	
	
	
	for (j ; j < n;j++ ){
	
	gotoxy(10,5+i);
	cout << NhanVien.NV[j]->MANV; 
	gotoxy(30,5+i);
	cout << NhanVien.NV[j]->HO << " ";
	cout << NhanVien.NV[j]->TEN;
	gotoxy(60,5+i);
	cout << NhanVien.NV[j]->PHAI;
	i++;
	
	}	
		
	
}
void Traverse_list_NV_case4(struct NHANVIEN NhanVien,int n){
	
	for (int i=0;i < 20;i++){
	
	gotoxy(30,5+i);
	cout << "          "; 
	gotoxy(47,5+i);
	cout << "                               ";
	gotoxy(85,5+i);
	cout << "         ";
		}
	struct DATA_NHANVIEN DaTa;
	
	for ( int i = 0 ; i < Pos_Empty_NV(NhanVien);i++){
		for (int j = 0; j < Pos_Empty_NV(NhanVien)+1;j++){
			if (strcmp(NhanVien.NV[i]->TEN.c_str(),NhanVien.NV[j]->TEN.c_str() )< 0 ){
				DaTa.HO = NhanVien.NV[j]->HO;
				DaTa.MANV = NhanVien.NV[j]->MANV;
				DaTa.PHAI = NhanVien.NV[j]->PHAI;
				DaTa.TEN = NhanVien.NV[j]->TEN;
				
				NhanVien.NV[j]->HO = NhanVien.NV[i]->HO;
				NhanVien.NV[j]->TEN = NhanVien.NV[i]->TEN;
				NhanVien.NV[j]->PHAI = NhanVien.NV[i]->PHAI;
				NhanVien.NV[j]->MANV = NhanVien.NV[i]->MANV;
				NhanVien.NV[i]->HO = DaTa.HO;
				NhanVien.NV[i]->TEN = DaTa.TEN;
				NhanVien.NV[i]->PHAI = DaTa.PHAI;
				NhanVien.NV[i]->MANV = DaTa.MANV;
			}
			else if (strcmp(NhanVien.NV[i]->TEN.c_str(),NhanVien.NV[j]->TEN.c_str()) == 0 ){
				if (strcmp(NhanVien.NV[i]->HO.c_str(),NhanVien.NV[j]->HO.c_str()) < 0 ){
				DaTa.HO = NhanVien.NV[j]->HO;
				DaTa.MANV = NhanVien.NV[j]->MANV;
				DaTa.PHAI = NhanVien.NV[j]->PHAI;
				DaTa.TEN = NhanVien.NV[j]->TEN;
			
				NhanVien.NV[j]->HO = NhanVien.NV[i]->HO;
				NhanVien.NV[j]->TEN = NhanVien.NV[i]->TEN;
				NhanVien.NV[j]->PHAI = NhanVien.NV[i]->PHAI;
				NhanVien.NV[j]->MANV = NhanVien.NV[i]->MANV;
				NhanVien.NV[i]->HO = DaTa.HO;
				NhanVien.NV[i]->TEN = DaTa.TEN;
				NhanVien.NV[i]->PHAI = DaTa.PHAI;
				NhanVien.NV[i]->MANV = DaTa.MANV;
				}
			}
			
		}
		
	}	
	int i=0;
	int j = n-20;
	if (NhanVien.size_NV == 0 )
	cout << " danh sach rong ";
	gotoxy(10,5);
	for (j; j < n ; j++){
	
	gotoxy(30,5+i);
	cout << NhanVien.NV[j]->MANV; 
	gotoxy(47,5+i);
	cout << NhanVien.NV[j]->HO <<" ";
	cout << NhanVien.NV[j]->TEN;
	gotoxy(85,5+i);
	cout << NhanVien.NV[j]->PHAI;
	i++;
}
}


////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
/////        các hàm ve danh dach  chi tiet hoa don /////	





int Empty_CTHD (struct List_CT_HOADON list_CTHD){
	
	return (list_CTHD.sizeHD == 0);
		
}	

int Full(List_CT_HOADON list_CTHD){
	
	return (list_CTHD.sizeHD == 20 ? 1 : 0); // tra ve danh sach hoa don co day hay ko ? (20 phan tu )\
	
}	// ham tao 1 node cau truc hoa don

int Find_Node_Tree(Tree T,string s)
{

		 if (T == NULL)
	 {
	 	
		return 0;
		}
     
     if (Cut_enter(T->DATA.MaVT ) > s) {
     	if (Find_Node_Tree(T->pLeft,s) == 1)
     		return 1;
     	else return 0;	
     	
	 }
     else if (Cut_enter(T->DATA.MaVT ) < s){
    	if (Find_Node_Tree(T->pRight,s) == 1)
     		return 1;
     	else return 0;      	
	 }
	
	 else{
	  
		gotoxy(30,10+vitricase5.y);
    	cout << T->DATA.TenVatTu;
     	return 1;
	 }
	
     
      
    
}
int Find_Node_Tree_case1(Tree T,string s)
{

		 if (T == NULL)
	 {
	 	
		return 0;
		}
     
     if (Cut_enter(T->DATA.MaVT ) > s) {
     	if (Find_Node_Tree_case1(T->pLeft,s) == 1)
     		return 1;
     	else return 0;	
     	
	 }
     else if (Cut_enter(T->DATA.MaVT ) < s){
    	if (Find_Node_Tree_case1(T->pRight,s) == 1)
     		return 1;
     	else return 0;      	
	 }
	
	 else{
	  

     	return 1;
	 }
	
     
      
    
}

void Creat_node_CTHD(struct CT_HD_INFO &INFO ){
		
//		while(Find_Node_Tree(T,INFO.MAVT) == 0){
		do {
				
			gotoxy(30,10+vitricase5.y);
			cout << "                   ";
			gotoxy(52,10+vitricase5.y);
			cout << "       ";
					
			//vi tri So Luong vat tu
			gotoxy(68,10+vitricase5.y);
			cout << "        ";
			// vi tri don gia vat tu
			gotoxy(78,10+vitricase5.y);
			cout << "            ";	
			while ( true){
				gotoxy(52,10+vitricase5.y);
				cout <<"         ";
				gotoxy(52,10+vitricase5.y);
				string s ;
				cin >> s;
				if (Check_Number(s ) == true){
					INFO.MAVT = s;
					break;
				}
			}
		}
		while (Find_Node_Tree(T,INFO.MAVT) != 1);
			
		//vi tri So Luong vat tu
		do {
		
			while ( true){
				gotoxy(68,10+vitricase5.y);
				cout <<"         ";
				gotoxy(68,10+vitricase5.y);
				string s ;
				cin >> s;
				if (Check_Number(s ) == true){
					INFO.SoLuong = atoi(s.c_str());
					break;
				}
			}		
		}
		while (Find_Print_VT_case5(T,INFO.MAVT,INFO.SoLuong) != 1);	
			
		
			// vi tri don gia vat tu
	//	Find_Print_VT_case5(T,INFO.MAVT,INFO.SoLuong);
			while ( true){
				gotoxy(78,10+vitricase5.y);
				cout <<"       ";
				gotoxy(78,10+vitricase5.y);
				string s ;
				cin >> s;
				if (Check_Number(s ) == true){
					INFO.DonGia = atoi(s.c_str());
					break;
				}
			}	

	
}
int Pos_Empty_CTHD(struct List_CT_HOADON list_CTHD){
	
		for ( int i = 0; i < list_CTHD.sizeHD; i++){
			if (list_CTHD.INFO[i].MAVT.empty())
			return i;
		}
		return 0;
	
}
	long long tong ;
void Output_Case5(struct List_CT_HOADON &list_CTHD){
//	tong = 0;
	gotoxy(95,10+vitricase5.y-1);
//	cout << fixed << setprecision(0) <<(list_CTHD.INFO[vitricase5.y-1].SoLuong)*(list_CTHD.INFO[vitricase5.y-1].DonGia); 
	Print_Number_With_point ((list_CTHD.INFO[vitricase5.y-1].SoLuong)*(list_CTHD.INFO[vitricase5.y-1].DonGia));
	
	tong += (list_CTHD.INFO[vitricase5.y-1].SoLuong)*(list_CTHD.INFO[vitricase5.y-1].DonGia);
	
	gotoxy(95,28);
//	cout << fixed << setprecision(0) << tong << "   VND";
 	Print_Number_With_point (tong);
}



// i la vi tri can them vao trong danh sach CTHD (nhap lieu tu ban phim tinh toan tu ham gotoxy)
int Insert_list_CTHD (struct List_CT_HOADON &list_CTHD,int i , struct CT_HD_INFO INFO){
	
	
	if ( i<0 || i > list_CTHD.sizeHD || list_CTHD.sizeHD == 0)
	return 0;
	//if (i == 0) i=1;
	for (int j = list_CTHD.sizeHD ; j >=i; j--)
	
	 list_CTHD.INFO[j+1] = list_CTHD.INFO[j];
	 list_CTHD.INFO[i] = INFO;
	 //list_CTHD.sizeHD ++;
	 
	return 1;
}
// xoa phan tu thu i nhap tu ban phim ( tinh toan dua vao ham gotoxy)
int DEL_ITEM_CTHD(List_CT_HOADON &list_CTHD, int i){
	
	int j;
	if (i < 0 || i > list_CTHD.sizeHD || list_CTHD.sizeHD == 0 )
	return 0;
	if (i == 0) i=1;
	for ( j = i; j < list_CTHD.sizeHD; j++)
	list_CTHD.INFO[j-1] = list_CTHD.INFO [j];
	list_CTHD.sizeHD --;
	return 1;
		
}
void Clear_list_CTHD(struct List_CT_HOADON list_CTHD){
	
	for (int i =0; i < list_CTHD.sizeHD; i ++){
		list_CTHD.INFO[i].MAVT ="";
		list_CTHD.INFO[i].SoLuong = 0;
		list_CTHD.INFO[i].DonGia = 0;
	}
	

	}
// vitri cua info trong CTHD
int Search_list_CTHD (struct List_CT_HOADON list_CTHD,struct CT_HD_INFO CTHD_IF){
	for (int vitri =0; vitri < list_CTHD.sizeHD; vitri ++)
	if (list_CTHD.INFO[vitri].MAVT == CTHD_IF.MAVT && list_CTHD.INFO[vitri].SoLuong == CTHD_IF.SoLuong)
	return vitri;
	return -1;
		
}
//vitri Mavt trong list CTHD
int Search_Mavt(struct List_CT_HOADON list_CTHD,string Mavt){
	for (int vitri =0; vitri < list_CTHD.sizeHD; vitri ++)
	if (list_CTHD.INFO[vitri].MAVT == Mavt )
	return vitri;
	return -1;
}
void Creat_list_CTHD(struct List_CT_HOADON &list_CTHD){
	
	
	cout << " so phan tu cua danh sach CTHD: ";
	cin >> list_CTHD.sizeHD;

	}
	
	
void Traverse_list_CTHD(struct List_CT_HOADON list_CTHD){
	
	int i;
	if (list_CTHD.sizeHD == 0 )
	cout << " danh sach rong ";
	
	for ( i = 0; i < list_CTHD.sizeHD; i++)
	cout << list_CTHD.INFO[i].MAVT << " " << list_CTHD.INFO[i].SoLuong << " \n";
	
	
}
int Pos_Empty_CTHD(struct List_CT_HOADON* list_CTHD){
	
		for ( int i = 0; i < list_CTHD->sizeHD; i++){
			if (list_CTHD->INFO[i].MAVT.empty())
			return i;
		}
		return 0;
	
}
	int Is_VT_Have_CTHD(struct NHANVIEN NhanVien,string s){
		struct HOADON *q;
	for ( int i = 0; i < Pos_Empty_NV(NhanVien);i++){
		q = NhanVien.NV[i]->HD;
		for (q; q != NULL ; q = q->pNext){
				for (int j = 0;j < Pos_Empty_CTHD(q->DATA_HD.CT_HD);j++){
					if (atoi(s.c_str()) == atoi(q->DATA_HD.CT_HD->INFO[j].MAVT.c_str())){
						return 1;
					}
					
				}
		}
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
/////				CAC HAM DANH SACH LIEN KET CAC HOA DON CUA 1 NHAN VIEN 			/////////////
			


void Creat_Node_DaTa_HoaDon(struct DATA_HOADON &DATA_HD,int n){
	///////////
	if( n == 1 ){
		DATA_HD.loai = "Xuat";
	}
	else if ( n == 0){
		DATA_HD.loai = "Nhap";
	}
	while (true){
	gotoxy(68,5);
	cout << "  ";
	gotoxy(73,5);
	cout <<"  ";
	gotoxy(79,5);
	cout <<"    ";
	gotoxy(88,5);
	cout << "                            ";
	while ( true){
		gotoxy(68,5);
		cout <<"   ";
		gotoxy(68,5);
		string s ;
		cin >> s;
		if (Check_Number(s ) == true){
		DATA_HD.ngaylap.ngay = atoi(s.c_str());
		break;
		}
	}	
	while ( true){
		gotoxy(73,5);
		cout <<"    ";
		gotoxy(73,5);
		string s ;
		cin >> s;
		if (Check_Number(s ) == true){
		DATA_HD.ngaylap.thang = atoi(s.c_str());
		break;
		}
	} 
	while ( true){
		gotoxy(79,5);
		cout <<"     ";
		gotoxy(79,5);
		string s ;
		cin >> s;
		if (Check_Number(s ) == true){
		DATA_HD.ngaylap.nam = atoi(s.c_str());
		break;
		}
	} 		

		if (DATA_HD.ngaylap.nam % 4 == 0){
		if(DATA_HD.ngaylap.thang < 1 || DATA_HD.ngaylap.thang > 12){
			gotoxy(88,5);
			cout << "Nhap thang sai hay nhap lai";
			}
		else if (DATA_HD.ngaylap.thang == 2){
			
				if (DATA_HD.ngaylap.ngay < 1 || DATA_HD.ngaylap.ngay > 29 )
				{
					gotoxy(88,5);
					cout << " Nhap ngay sai hay nhap lai!";
				}
				else break;
			}
		else if (DATA_HD.ngaylap.thang == 1 || DATA_HD.ngaylap.thang == 3 || DATA_HD.ngaylap.thang == 3 || DATA_HD.ngaylap.thang == 5 || DATA_HD.ngaylap.thang == 7 ||DATA_HD.ngaylap.thang == 8 || DATA_HD.ngaylap.thang == 10 || DATA_HD.ngaylap.thang == 12)
			 {
				if (DATA_HD.ngaylap.ngay <1 || DATA_HD.ngaylap.ngay > 31)
				{
					gotoxy(88,5);
					cout << "Nhap Ngay sai hay nhap lai";
				}
				else break;
				
			}
		else {
				if (DATA_HD.ngaylap.ngay <1 || DATA_HD.ngaylap.ngay > 30){
					gotoxy(88,5);
					cout << " Nhap Ngay sai hay nhap lai";
				}
				else break;
			}
		getch();	
		}
	
	else {
		if(DATA_HD.ngaylap.thang < 1 || DATA_HD.ngaylap.thang > 12){
			gotoxy(88,5);
			cout << "Nhap thang sai hay nhap lai";
			}
		else if (DATA_HD.ngaylap.thang == 2){
			
				if (DATA_HD.ngaylap.ngay < 1 || DATA_HD.ngaylap.ngay > 28 )
				{
					gotoxy(88,5);
					cout << " Nhap ngay sai hay nhap lai!";
				}
				else break;
			}
		else if (DATA_HD.ngaylap.thang == 1 || DATA_HD.ngaylap.thang == 3 || DATA_HD.ngaylap.thang == 3 || DATA_HD.ngaylap.thang == 5 || DATA_HD.ngaylap.thang == 7 ||DATA_HD.ngaylap.thang == 8 || DATA_HD.ngaylap.thang == 10 || DATA_HD.ngaylap.thang == 12)
			 {
				if (DATA_HD.ngaylap.ngay <1 || DATA_HD.ngaylap.ngay > 31)
				{
					gotoxy(88,5);
					cout << "Nhap Ngay sai hay nhap lai";
				}
				else break;
			}
		else {
				if (DATA_HD.ngaylap.ngay <1 || DATA_HD.ngaylap.ngay > 30){
					gotoxy(88,5);
					cout << " Nhap Ngay sai hay nhap lai";
				}
				else break;
			}
		getch();	
	}
	}
	gotoxy(70,6);
	string HD = "HD";
	DATA_HD.SoHD = HD += to_string(SoHoaDon_Auto);
	cout << DATA_HD.SoHD;
	getch();
}
struct HOADON *Creat_Node_Dshd(struct DATA_HOADON DATA_HD1){
	
	struct HOADON *p = new struct HOADON; /// cap phat vung nho cho NODE p
	p->DATA_HD.CT_HD = new List_CT_HOADON;
	p -> DATA_HD  = DATA_HD1;
	p -> pNext = NULL;
	return p;
}
// them node p vao dau dslk

void Add_Node_Head(struct NHANVIEN &NhanVien, struct HOADON *p,int i){
	
	if (NhanVien.NV[i]->HD == NULL){
		NhanVien.NV[i]->HD  = p; // node dau cx la node cuoi la p
		
	}
	else {
		p -> pNext = NhanVien.NV[i]->HD; // cho con tro node can them lien ket voi node dau pHead
		NhanVien.NV[i]->HD = p;  // cap nhat lai pHead la node p
		
	}
}
int Count_amount_Hoadon(struct NHANVIEN NhanVien){
	struct HOADON *q;
		int SoHoaDon = 0;
		for ( int i = 0; i < Pos_Empty_NV(NhanVien);i++){
			q = NhanVien.NV[i]->HD;
				for (q; q != NULL ; q = q->pNext){
					SoHoaDon++;			
				}
		}	
					   	
	return SoHoaDon;
	
}
// han tra ve -1 neu a < b, 0 neu a = b, 1 neu a > b  
int Compare_Date(struct ngaylap a, struct ngaylap b){
	
	if (a.nam > b.nam){
		return 1;
	}
	else if(a.nam == b.nam){
		if (a.thang == b.thang){
			if (a.ngay == b.ngay)
			return 0;
			else if (a.ngay > b.ngay)
			return 1;
			else 
			return -1;
		}
		else if (a.thang < b.thang)
		return -1;
		else return 1;

	}
	else return -1;
}
int Search_Ma_HD(struct NHANVIEN NhanVien, string MaHD){
 	struct HOADON *q;
	for ( int i = 0; i < Pos_Empty_NV(NhanVien);i++){
		q = NhanVien.NV[i]->HD;
		for (q ; q != NULL ; q = q->pNext){ 
			if (q->DATA_HD.SoHD == MaHD)
			return i;

		}
	}
	return -1;
}
void Traverse_Case_6(struct NHANVIEN NhanVien){
	for (int t = 0; t < 17;t++){
	
	gotoxy(19,10+t);
	cout << "   ";
	gotoxy(29,10+t);
	cout << "                 ";
	gotoxy(55,10+t);
	cout << "     ";
	gotoxy(67,10+t);
	cout << "        ";
	gotoxy(78,10+t);
	cout << "            ";
	gotoxy(95,10+t);
	cout << "                 ";
	}
	gotoxy(95,28);
	cout << "                  ";
	char input;
	while(input != 27){
		gotoxy(68,2);
		cout << "                        ";
		gotoxy(72,3);
		cout << "                        ";
		gotoxy(72,4);
		cout << "                        ";		
		gotoxy(72,5);
		cout << "                        ";
		string MaHD;
		gotoxy(72,2);
	cin >> MaHD;
	if (Search_Ma_HD(NhanVien, MaHD) == -1){
		gotoxy(68,2);
		cout << " khong tim thay hoa don";
		input = getch();
	}
	else {
		for ( int i = 0; i < Pos_Empty_NV(NhanVien);i++){
			struct HOADON *q = NhanVien.NV[i]->HD;
			struct DATA_NHANVIEN *p = NhanVien.NV[i];
		for (q; q != NULL ; q = q->pNext){ 
			if (q->DATA_HD.SoHD == MaHD)
			{	
				int Tong = 0;
				gotoxy(72,2);
				cout << q->DATA_HD.SoHD;
				gotoxy(72,3);
				cout << q->DATA_HD.loai;
				gotoxy(72,4);
				cout << p->HO << " " << p->TEN;
				gotoxy(72,5);
				cout <<q->DATA_HD.ngaylap.ngay << " / " << q->DATA_HD.ngaylap.thang << " / " << q->DATA_HD.ngaylap.nam;
				for (int j = 0; j < Pos_Empty_CTHD(q->DATA_HD.CT_HD) ; j++){
					gotoxy(19,10+j);
					cout << j+1;
					gotoxy(29,10+j);
					Traverse_Tree_case_6 (T,q->DATA_HD.CT_HD->INFO[j].MAVT,j);
					gotoxy(55,10+j);
					cout << q->DATA_HD.CT_HD->INFO[j].MAVT;
					gotoxy(67,10+j);
					cout <<q->DATA_HD.CT_HD->INFO[j].SoLuong;
					gotoxy(78,10+j);
					cout << fixed << setprecision(0) << q->DATA_HD.CT_HD->INFO[j].DonGia;
					gotoxy(95,10+j);
				//	cout << fixed << setprecision(0) <<(NhanVien.NV[i].HD->DATA_HD.CT_HD->INFO[j].SoLuong)*(NhanVien.NV[i].HD->DATA_HD.CT_HD->INFO[j].DonGia);
					Print_Number_With_point ((q->DATA_HD.CT_HD->INFO[j].SoLuong)*(q->DATA_HD.CT_HD->INFO[j].DonGia));
					Tong +=	(q->DATA_HD.CT_HD->INFO[j].SoLuong)*(q->DATA_HD.CT_HD->INFO[j].DonGia);
					
				}
					gotoxy(95,28);
				//	cout << fixed << setprecision(0) << Tong << "  VND";
					Print_Number_With_point(Tong);
				break;
			}

		}
	}
		
		break;
		
		}
	}
	
	input = getch();
	}
	

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////									LIEN KET CAC DANH SACH									//////////////////	
void Add_CTHD_To_HD(HOADON *hoadon,struct List_CT_HOADON list_CTHD){
	
	hoadon->DATA_HD.CT_HD = new List_CT_HOADON;
	for (int i = 0; i < Pos_Empty_CTHD(list_CTHD);i++ ){
		hoadon->DATA_HD.CT_HD->INFO[i] = list_CTHD.INFO[i];
		
	}
	

}

void Add_HoaDon_To_NV(struct NHANVIEN &NhanVien,struct HOADON* HoaDon,int i){
	
	NhanVien.NV[i]->HD = HoaDon;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////CAC HAM LAM VIEC VOI FILE////////////////////////////////

// doc file hoa don va chi tiet hoa don vao danh sach nhan vien

//
void Read_File_HD_Add_NV(ifstream &filein1,struct NHANVIEN &NhanVien ){
	
	HOADON* hoadon;

	
	filein1.open("HD3.TXT", ios_base::in);
	
	if (filein1.fail()== true)
	{
		cout << "FILE K TON TAI";
		
	}
	else{
	int Sohoadon;
	filein1 >> Sohoadon;
	filein1 >> SoHoaDon_Auto;
	string enter;
	getline(filein1,enter);	
	for (int i = 0; i < Sohoadon; i++){
	DATA_HOADON DATA_HD2;
	DATA_HD2.CT_HD = new List_CT_HOADON;
	List_CT_HOADON CTHD;
		
	// nhap thong tin vao HD
	string Manv;
	getline(filein1,Manv);
	getline(filein1,DATA_HD2.SoHD,'	');
	getline(filein1, DATA_HD2.loai,'	');
	filein1 >> DATA_HD2.ngaylap.ngay;
	filein1 >> DATA_HD2.ngaylap.thang;
	filein1 >> DATA_HD2.ngaylap.nam;
	string line;
	getline(filein1,line);
	
	
	// nhap thong tin vao CTHD
	int sovattu;
	filein1 >> sovattu;
	getline(filein1,line);
	for (int j = 0 ; j < sovattu; j++){
		
		getline (filein1,CTHD.INFO[j].MAVT,'	');
		filein1 >> CTHD.INFO[j].SoLuong;
		filein1 >> CTHD.INFO[j].DonGia;
		getline(filein1,line);
	
	}
	
	for (int j = 0; j < CTHD.sizeHD;j++){
		DATA_HD2.CT_HD->INFO[j] = CTHD.INFO[j];
		
	}
	hoadon = Creat_Node_Dshd(DATA_HD2);
	Clear_list_CTHD(CTHD);
	Add_Node_Head(NhanVien, hoadon ,Search_Manv(NhanVien,Manv) );
	//them CTHD vao Hoa Don
	
	}
	
		}
		
	filein1.close();	
}				

// doc file vao sach sach tuyen tinh nhan vien
void Read_File_List_NV(ifstream &filein,struct NHANVIEN &NhanVien){
	
	
	filein.open("NhanVien.TXT",ios_base::in);
//	if (filein.fail()== true)
//	{	
//		cout << "FILE D TON TAI";
		
//	}	
		int i = -1;
		while (filein.eof()==false){
			i += 1;
			getline(filein , NhanVien.NV[i]->MANV,'	');
			getline(filein , NhanVien.NV[i]->HO,'	');
			getline(filein , NhanVien.NV[i]->TEN,'	');
			getline(filein , NhanVien.NV[i]->PHAI);
		
		}	
	filein.close();	
}
void Write_File_List_NV(ofstream &fileout,struct NHANVIEN NhanVien){
		
	
	fileout.open("NhanVien.TXT",ios::out|ios::trunc);
	
	for (int i = 0; i <Pos_Empty_NV(NhanVien); i++){
		
		fileout << NhanVien.NV[i]->MANV << "	" ;
		fileout << NhanVien.NV[i]->HO << "	" ;
		fileout << NhanVien.NV[i]->TEN << "	";
		fileout << NhanVien.NV[i]->PHAI << "\n";
	}
	fileout.close();
}
void Write_File_HD_CTHD(ofstream &fileout,struct NHANVIEN NhanVien){
	fileout.open("HD3.TXT",ios::out|ios::trunc);
	if (fileout.fail() == true)
	cout << "file nl";
	else {
			fileout << Count_amount_Hoadon(NhanVien) << "\t";
			fileout << SoHoaDon_Auto << "\n";
	for ( int i = 0; i < Pos_Empty_NV(NhanVien);i++){
		struct HOADON *q = NhanVien.NV[i]->HD;
		struct DATA_NHANVIEN *p = NhanVien.NV[i];
			for (q; q != NULL ; q = q->pNext){
				fileout <<p->MANV << "\n";
				fileout << q->DATA_HD.SoHD << "	";
				fileout << q->DATA_HD.loai << "	";
				fileout << q->DATA_HD.ngaylap.ngay << "	";
				fileout << q->DATA_HD.ngaylap.thang << "	";
				fileout << q->DATA_HD.ngaylap.nam << "\n";
				fileout << Pos_Empty_CTHD(q->DATA_HD.CT_HD) << "\n";
				for (int j = 0;j < Pos_Empty_CTHD(q->DATA_HD.CT_HD);j++){
			
					fileout << q->DATA_HD.CT_HD->INFO[j].MAVT <<"	";
					fileout << q->DATA_HD.CT_HD->INFO[j].SoLuong <<"	";
					fileout << q->DATA_HD.CT_HD->INFO[j].DonGia <<"\n";
								}
							}	
						}
	}
	fileout.close();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////	
///////////////					CAC HAM THUC HIEN CASE 8 						////////////////////

void swap_Max(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}
 
// Hàm selection sort
void selectionSort_Max(float arr[], int n)
{
    int i, j, max_idx;
    
    for (i = 0; i < n-1; i++)
    {
    
    max_idx = i;
    for (j = i+1; j < n; j++)
        if (arr[j] > arr[max_idx])
        max_idx = j;
 
    
        swap(arr[max_idx], arr[i]);
    }
}
	int Sohoadoncanin;
	float TriGia[100];
void Print_Case_8(struct NHANVIEN NhanVien,struct ngaylap NgayDau,struct ngaylap NgayCuoi ){
	int Vitri = 0; // vi tri tri gia trong mang TriGia
	
	float Temp = 0  ; // bien tam chua tri gia hoa don
	int dem = 0; // dem so hoa don
	for ( int t = 0; t < Pos_Empty_NV(NhanVien);t++){
		struct HOADON *q = NhanVien.NV[t]->HD;
		for (q ; q != NULL ; q = q->pNext){
		//	cout << NhanVien.NV[t].HD->DATA_HD.SoHD << "\n";
				if ((Compare_Date(q->DATA_HD.ngaylap, NgayDau) == 1 || Compare_Date(q->DATA_HD.ngaylap, NgayDau) == 0) && (Compare_Date(q->DATA_HD.ngaylap, NgayCuoi) == -1 || Compare_Date(q->DATA_HD.ngaylap, NgayDau) == 0)){
				
				for (int j = 0;j < Pos_Empty_CTHD(q->DATA_HD.CT_HD);j++){
					 
					 Temp += (q->DATA_HD.CT_HD->INFO[j].SoLuong)*(q->DATA_HD.CT_HD->INFO[j].DonGia);
					// cout << fixed << setprecision(0) << Temp << "\n";
					 												
						}
					//cout << fixed << setprecision(0) << Temp << "\n";	
					TriGia[Vitri] = Temp;
					Vitri ++;
					dem ++;
					q->DATA_HD.TriGia = Temp;
					Temp = 0;	
					
						}
				}
					}   
	selectionSort_Max(TriGia,dem);


	if ( dem > 10){
		Sohoadoncanin = 10;
		for (int i = 10; i < dem ; i++  ){
		
			if ( TriGia[i] == TriGia[9] ){
				Sohoadoncanin = i+1;
				
			}
					
		}		
	}
	else {
		Sohoadoncanin = dem;
	}


}

/////////////////////////////////////////////////////////////////////////////////////////////////////
void draw_case1 (){
	color_set();
	system("cls");
	SetBGColor(0);
	gotoxy(5,2);
	cout << string(80, char(219));
	for (int i = 3; i < 25; i++) {
		gotoxy(5, i);
		cout << char(219);
	
	}
	gotoxy(5, 25);
	cout << string(80, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(85,i);
		cout << char(219);
	}
	gotoxy(6,3);
	SetBGColor(15);
	cout <<" MA VAT TU |        	 TEN VAT TU 	      | DON VI TINH | SO LUONG TON  ";
	gotoxy(6,4);
	cout <<"------------------------------------------------------------------------------";
	gotoxy(55,28);
	cout <<"*NHAN ESC DE TRO VE MENU\n";
	gotoxy(54,29);
	cout <<"*NHAN ENTER DE CHON CHUC NANG\n";
	gotoxy(53,30);
	cout <<"*SU DUNG PHIM MUI TEN DE LUA CHON\n";
	gotoxy(87,2);
	cout << string(41, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(87,i);
		cout << char(219);}
	gotoxy(87,25);
	cout << string(41, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(128,i);
		cout << char(219);
	}
	gotoxy(100,3);
	cout <<"BANG HIEU CHINH";
	gotoxy(88,4);
	cout << "----------------------------------------";
	gotoxy(17,4);
	for (int i =3; i<25;i++){
		gotoxy(17,i);
		cout <<"|";}
	gotoxy(54,4);
	for (int i =3; i<25;i++){
		gotoxy(54,i);
		cout <<"|";
	}
	gotoxy(68,4);
	for (int i =3; i<25;i++){
		gotoxy(68,i);
		cout <<"|";}
	gotoxy(90,6);	
	cout << "MA VT      [                         ]";
	gotoxy(90,9);
	cout << "TEN VT     [                         ]";
	gotoxy(90,12);
	cout << "DVI TINH   [                         ]";
	gotoxy(90,15);
	cout << "SLUONG TON [                         ]";
	
	Trasever_List_Case_1(T, 20);

		 //////chon trang /////
	 int trang;
	trang = Count_Node_Tree(T) / 20; // 20 so dong toi da cua bang 
	gotoxy(56,26);
	cout << "Trang ";
	gotoxy(64,26);
	for (int i = -1; i < trang; i++){
	
	cout << "[" <<i+2 << "]" << " ";
	}
	gotoxy(64,26);
	SetBGColor(light_cyan);
	cout << "[" << "1" << "]";
	SetBGColor(15);
	 /////////////////////
	
	
	 int luachon1 = 1;
	position luachon_case1[3];
	string case1[5]={"[them vat tu]","[ xoa vat tu]","[  cap nhat ]"};
	for (int i= 0;i < 3;i++){
		luachon_case1[i].x=101;
		luachon_case1[i].y=20+i;
		gotoxy(luachon_case1[i].x,luachon_case1[i].y);
		cout << case1[i];
		}
	gotoxy (luachon_case1[0].x,luachon_case1[0].y);
	cout<< case1[0];
	while (true){
	 if(kbhit){
		 char input = getch();
		 if (input == -32){
		 	input = getch();
		 	switch (input){
		 		case 80 : {gotoxy(luachon_case1[luachon1].x,luachon_case1[luachon1].y);
		 			 SetBGColor(15);
					 cout <<case1[luachon1];
                     luachon1++;
                     if(luachon1 > 3){
                     	luachon1 = 0;
					 }
					 gotoxy(luachon_case1[luachon1].x,luachon_case1[luachon1].y);
					 SetBGColor(light_cyan);   //light_cyan
					 cout <<case1[luachon1]; 
					 
					break;
				 } 
				case 72: {
					gotoxy(luachon_case1[luachon1].x,luachon_case1[luachon1].y);
		 			 SetBGColor(15);
					 cout <<case1[luachon1];
                     luachon1--;
                     if(luachon1 < 0){
                     	luachon1 = 3;
					 }
					 gotoxy(luachon_case1[luachon1].x,luachon_case1[luachon1].y);
					 SetBGColor(light_cyan);
					 cout <<case1[luachon1]; 
					break;
				}
		 		}
}
else if(input == 13)
				{
					switch (luachon1) {
						case 0 : {// thuc hien them vat tu
					
						ShowConsoleCursor(true);
						SetBGColor(15);
						gotoxy(90,15);
						cout << "SLUONG TON [                         ]";
						gotoxy(103,6);
	
						cout << "               ";
						
						gotoxy(103,9);
//						cin.ignore();
						cout<<"                       ";
						gotoxy(103,12);
//						cin.ignore();
						cout <<"                     ";
						gotoxy(103,15);
						cout << "                    ";
						struct DaTa_Tree Data;
						Creat_Data_Tree(Data);
						Add_Node_Tree(T,Data);
						SoVatTu_Auto ++;
						Trasever_List_Case_1(T, 20);
						Write_Tree (fileout,T);
						sleep(2);
						gotoxy(103,6);
	
						cout << "               ";
						
						gotoxy(103,9);
//						cin.ignore();
						cout<<"                       ";
						gotoxy(103,12);
//						cin.ignore();
						cout <<"                     ";
						gotoxy(103,15);
						cout << "                    ";
						gotoxy(97,18);
						cout <<" Them Vat Tu Thanh Cong";
						getch();
						gotoxy(97,18);
						cout <<"                        ";
							break;
						}
						case 1 :{ // thuc hien xoa vat tu
						ShowConsoleCursor(true);
						gotoxy(101,24);
						cout << luachon1;
						SetBGColor(15);
						gotoxy(90,15);
						cout << "TIM KIEM   [                         ]";						
						gotoxy(103,6);
						cout <<"                      ";
						gotoxy(103,9);
						cout <<"                ";
						gotoxy(120,9);
						cout << "       ";
						gotoxy(103,12);
						cout <<"                      ";
				//		gotoxy(101,24);
				//		cout << luachon1;
    					gotoxy(92,17);
    					cout << "                                 ";						
						gotoxy(103,15);
						
						string Mavattu;
						cin >> Mavattu;
    					gotoxy(92,17);
    					cout << "                                  ";
    					if (Is_VT_Have_CTHD(NhanVien,Mavattu) == 1){
    						gotoxy(92,17);
    						cout << "Vat Tu da co trong hoa don ko xoa";
    						gotoxy(103,15);
						    cout <<"                       ";
    						break;
						}
						if (Is_SLT_Eq_0(T,Mavattu) == 0 ){
							gotoxy(92,17);
    						cout << "Vat Tu con hang trong kho ko xoa";
    						gotoxy(103,15);
						    cout <<"                       ";
    						break;
							
						}
						if ( Find_Node_Tree_case1(T,Mavattu) == 0)  //return == 0 neu ko tim thay
    					{
    						gotoxy(92,17);
    						cout << "khong tim thay vat tu can xoa";
    						gotoxy(103,15);
						    cout <<"                       ";
							
							break;
							
						}
						else if ( Find_Node_Tree_case1(T,Mavattu) == 1){
							Find_Node_Case1(T,Mavattu);
							gotoxy(94,17);
    						cout << "Ban co thuc su muon xoa VT ko? ";
    						gotoxy(97,18);
    						cout << " y: yes | n: no ";
						
						while (true){
						
						
						if (kbhit){
						char input3;
							input3 = getch();
						if (input3 == 121){
							gotoxy(103,6);
							cout <<"                      ";
							gotoxy(103,9);
							cout <<"                ";
							gotoxy(120,9);
							cout << "       ";
							gotoxy(103,12);
							cout <<"                      ";
    						gotoxy(92,17);
    						cout << "                                ";					   
    						gotoxy(97,18);
    						cout << "                     ";							
							Delete_Node_Tree(T,Mavattu);

				//			Trasever_List_Case_1(T, 20);
				//			DEL_ITEM_NHANVIEN(NhanVien, Search_list_NV(NhanVien, Data_NV)+1);
							//ofstream fileout1;
							Write_Tree (fileout,T);
							Trasever_List_Case_1(T, 20);
				//			Write_File_List_NV(fileout, NhanVien);
							sleep (1);
							gotoxy(94,17);
							cout << "Xoa Vat Tu Thanh Cong";
							sleep(2);
							gotoxy(94,17);
    						cout << "                                ";
    						gotoxy(97,18);
    						cout << "                     ";
							
				//       		Traverse_list_NV_case3(NhanVien,Pos_Empty_NV(NhanVien));
				       		
				       		break;
				       		
					   }
					   else if (input3 == 110) {
					   
						gotoxy(103,6);
						cout <<"                      ";
						gotoxy(103,9);
						cout <<"                ";
						gotoxy(120,9);
						cout << "       ";
						gotoxy(103,12);
						cout <<"                      ";
    					gotoxy(92,17);
    					cout << "                                ";					   
    					gotoxy(97,18);
    					cout << "                     ";					   
					   
					   break;
						}
					   //else if (input3 == 27)
					   
					   }
				}
						gotoxy(103,15);
						cout << "             ";
						gotoxy(94,17);
    					cout << "                                 ";
    					gotoxy(97,18);
    					cout << "                     ";
						
							
						
					}	
								
							break;	
							
						}
						case 2 : {// thuc hien cap nhat
						ShowConsoleCursor(true);
						SetBGColor(15);
						gotoxy(90,15);
						cout << "TIM KIEM   [                         ]";								
						gotoxy(103,6);
						cout <<"                      ";
						gotoxy(103,9);
						cout <<"                ";
						gotoxy(120,9);
						cout << "       ";
						gotoxy(103,12);
						cout <<"                      ";
    					gotoxy(92,17);
    					cout << "                                  ";						
						SetBGColor(15);
						gotoxy(103,15);
						string Mavattu;
						cin >> Mavattu;
    					gotoxy(92,17);
    					cout << "                                    ";
    					
						if ( Find_Node_Tree_case1(T,Mavattu) == 0)  //return == 0 neu ko tim thay
    					{
    						gotoxy(92,17);
    						cout << "khong tim thay vat tu can sua";
    						gotoxy(103,15);
						    cout <<"                       ";
							
							break;
							
						}
						else if ( Find_Node_Tree_case1(T,Mavattu) == 1){
							gotoxy(94,17);
    						cout << "Ban co thuc su muon sua VT ko? ";
    						gotoxy(97,18);
    						cout << " y: yes | n: no ";					
						while (true){
						
						
						if (kbhit){
						char input3;
							input3 = getch();
						if (input3 == 121){
						
				//			DEL_ITEM_NHANVIEN(NhanVien, Search_list_NV(NhanVien, Data_NV)+1);
							//ofstream fileout1;
							Find_Node_Case1(T,Mavattu);
							
				
				//			Write_File_List_NV(fileout, NhanVien);
						//////////////////// sua ten VT //////////////////
							char Ten;
							while (true) {
							gotoxy(94,17);
    						cout << "                                ";
    						gotoxy(97,18);
    						cout << "                     ";								
							gotoxy(103 + Tenvattu_fix.size(),9);	
							Ten = getch();
							if (Ten == 8){
								
								gotoxy(103 + Tenvattu_fix.size() - 1,9);
								cout <<" ";
								Tenvattu_fix.pop_back();
							}
						
							else if (Ten >= 'a' && Ten <= 'z' || Ten == 32 || Ten >= 'A' && Ten <= 'Z' || Ten >= '0' && Ten <= '9'){
								Tenvattu_fix += Ten;
								gotoxy(103,9);
								cout << Tenvattu_fix;
								}
							if(Ten == 13)
							break;
							if (Tenvattu_fix.empty())
							Tenvattu_fix = " ";
							}
							////////////// sua don vi tinh VT ////////////////
							char Donvitinh;
							while (true) {
							gotoxy(94,17);
    						cout << "                                ";
    						gotoxy(97,18);
    						cout << "                     ";								
							gotoxy(103 + Donvitinh_VT_Fix.size(),12);	
							Donvitinh = getch();
							if (Donvitinh == 8){
								
								gotoxy(103 + Donvitinh_VT_Fix.size() - 1,12);
								cout <<" ";
								Donvitinh_VT_Fix.pop_back();
							}
						
							else if (Donvitinh >= 'a' && Donvitinh <= 'z' || Donvitinh == 32 || Donvitinh >= 'A' && Donvitinh <= 'Z'|| Donvitinh >= '0' && Donvitinh <= '9'){
								Donvitinh_VT_Fix += Donvitinh;
								gotoxy(103,12);
								cout << Donvitinh_VT_Fix;
								}
							if(Donvitinh == 13)
							break;
							if (Donvitinh_VT_Fix.empty())
							Donvitinh_VT_Fix = " ";	
							}
							Fix_Node_Case1(T,Mavattu);
							Trasever_List_Case_1(T,20);
							Write_Tree (fileout,T);
							gotoxy(92,17);
							cout << "	Sua Vat Tu Thanh Cong ";
							sleep (2);
							gotoxy(103,6);
							cout <<"                      ";
							gotoxy(103,9);
							cout <<"                ";
							gotoxy(120,9);
							cout << "       ";
							gotoxy(103,12);
							cout <<"                      ";
    						gotoxy(92,17);
    						cout << "                                  ";														
    						gotoxy(97,18);
    						cout << "                     ";
							
				//       		Traverse_list_NV_case3(NhanVien,Pos_Empty_NV(NhanVien));
				       		
				       		break;
				       		
					   }
					   else if (input3 == 110) 
					   
					   
					   break;
					   
					   //else if (input3 == 27)
					   
					   }
				}
						gotoxy(103,15);
						cout << "             ";
						gotoxy(94,17);
    					cout << "                                 ";
    					gotoxy(97,18);
    					cout << "                     ";
														
								}
							break;
						}	
					}
					
}
else if(input == 27){
	
	color_set();
	system("cls");
	SetBGColor(15);
	//SetBGColor(0);
	menu();
}
switch (input){
	    	case 50: {
	    		gotoxy(64,26);
	    		cout << "                                          ";
				
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(68,26);
				SetBGColor(light_cyan);
				cout << "[" << "2" << "]";
				SetBGColor(15);
				Trasever_List_Case_1(T, 40);
				break;
			}
			case 49:{
				gotoxy(64,26);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(64,26);
				SetBGColor(light_cyan);
				cout << "[" << "1" << "]"<<" ";
				
				SetBGColor(15);
				Trasever_List_Case_1(T, 20);
				
				break;
			}
			case 51:{
				gotoxy(64,26);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(72,26);
				SetBGColor(light_cyan);
				cout << "[" << "3" <<"]";
				SetBGColor(15);
				Trasever_List_Case_1(T, 60);
				break;
			}
	    	case 52:{
				gotoxy(64,26);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(76,26);
				SetBGColor(light_cyan);
				cout << "[" << "4" <<"]";
				SetBGColor(15);
				Trasever_List_Case_1(T, 80);
				break;
			}
	    	case 53:{
				gotoxy(64,26);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(80,26);
				SetBGColor(light_cyan);
				cout << "[" << "5" <<"]";
				SetBGColor(15);
				Trasever_List_Case_1(T, 100);
				break;
			}
	    	
				}
}
}

	}

	
void draw_case2(){
	color_set();
	system("cls");
	SetBGColor(15);
	gotoxy(27,2);
	cout << string(80, char(219));
	for (int i = 3; i < 25; i++) {
		gotoxy(27, i);
		cout << char(219);
	
	}
	gotoxy(27, 25);
	cout << string(80, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(107,i);
		cout << char(219);
	}
	gotoxy(28,3);
	cout <<" MA VAT TU |        	 TEN VAT TU 	      | DON VI TINH | SO LUONG TON ";
	gotoxy(28,4);
	cout <<"------------------------------------------------------------------------------";

	gotoxy(55,28);
	cout <<"*NHAN ESC DE TRO VE MENU\n";
	gotoxy(53,29);
	cout <<"*SU DUNG PHIM SO DE LUA CHON TRANG\n";
	gotoxy(39,4);
	for (int i =3; i<25;i++){
		gotoxy(39,i);
		cout <<"|";}
	gotoxy(78,4);
	for (int i =3; i<25;i++){
		gotoxy(78,i);
		cout <<"|";
	}
	gotoxy(92,4);
	for (int i =3; i<25;i++){
		gotoxy(92,i);
		cout <<"|";}
	Tree V;
	Creat_Tree(V);
	Read_Tree_case2(filein,V);	
	Trasever_case_2(V);	
	
			 //////chon trang /////
	int trang;
	trang = Count_Node_Tree(T) / 20; // 20 so dong toi da cua bang 
	gotoxy(56,26);
	cout << "Trang ";
	gotoxy(64,26);
	for (int i = -1; i < trang; i++){
	
	cout << "[" <<i+2 << "]" << " ";
	}
	gotoxy(64,26);
	SetBGColor(light_cyan);
	cout << "[" << "1" << "]";
	SetBGColor(15);
	 /////////////////////	
		
	while (true){
		if (kbhit){
		char input1 = getch();
		if (input1 == 27)
		{
		system("cls");	
		menu();
		break;
	    }
	    switch (input1){
	    	case 50: {
	    		gotoxy(64,26);
	    		cout << "                                          ";
				
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(68,26);
				SetBGColor(light_cyan);
				cout << "[" << "2" << "]";
				SetBGColor(15);
	//			Traverse_list_NV_case4(NhanVien,40);
				Trasever_List_Case_2(V, 40);
				
				break;
			}
			case 49:{
				gotoxy(64,26);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(64,26);
				SetBGColor(light_cyan);
				cout << "[" << "1" << "]"<<" ";
				
				SetBGColor(15);
	//			Traverse_list_NV_case4(NhanVien,20);
				Trasever_List_Case_2(V, 20);
				
				break;
			}
			case 51:{
				gotoxy(64,26);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(72,26);
				SetBGColor(light_cyan);
				cout << "[" << "3" <<"]";
				SetBGColor(15);
				Trasever_List_Case_2(V,60);
				break;
			}
	    	case 52:{
				gotoxy(64,26);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(76,26);
				SetBGColor(light_cyan);
				cout << "[" << "4" <<"]";
				SetBGColor(15);
				Trasever_List_Case_2(V,80);
				break;
			}
	    	case 53:{
				gotoxy(64,26);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(80,26);
				SetBGColor(light_cyan);
				cout << "[" << "5" <<"]";
				SetBGColor(15);
				Trasever_List_Case_2(V,100);
				break;
			}
	    	
				}
	  
	
				  }	
	}
		
}
void draw_case3 (){
	ShowConsoleCursor(true);
	color_set();
	system("cls");
	SetBGColor(0);
	gotoxy(5,2);
	
	cout << string(80, char(219));
	for (int i = 3; i < 25; i++) {
		gotoxy(5, i);
		cout << char(219);
	
	}
	gotoxy(5, 25);
	cout << string(80, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(85,i);
		cout << char(219);
	}
	gotoxy(6,3);
	SetBGColor(15);
	cout <<" MA NHAN VIEN |        	  TEN NHAN VIEN           | GIOI TINH |  DIA CHI  ";
	gotoxy(6,4);
	cout <<"------------------------------------------------------------------------------";
	gotoxy(55,28);
	cout <<"*NHAN ESC DE TRO VE MENU\n";
	gotoxy(54,29);
	cout <<"*NHAN --> DE HIEU CHINH NHAN VIEN\n";
	gotoxy(53,30);
	cout <<"*SU DUNG PHIM MUI TEN DE LUA CHON\n";
	gotoxy(87,2);
	cout << string(41, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(87,i);
		cout << char(219);}
	gotoxy(87,25);
	cout << string(41, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(128,i);
		cout << char(219);
	}
	gotoxy(100,3);
	cout <<"BANG HIEU CHINH";
	gotoxy(88,4);
	cout << "----------------------------------------";
	gotoxy(20,4);
	for (int i =3; i<25;i++){
		gotoxy(20,i);
		cout <<"|";}
	gotoxy(58,4);
	for (int i =3; i<25;i++){
		gotoxy(58,i);
		cout <<"|";
	}
	gotoxy(70,4);
	for (int i =3; i<25;i++){
		gotoxy(70,i);
		cout <<"|";}
	
	gotoxy(90,6);	
	cout << "MA NV      [                         ]";
	gotoxy(90,9);
	cout << "TEN NV     [                 |       ]";
	gotoxy(90,12);
	cout << "GIOI TINH  [                         ]";
	gotoxy(90,15);
	cout << "TIM KIEM   [                         ]";
	
	ifstream filein;

	Traverse_list_NV_case3(NhanVien,Pos_Empty_NV(NhanVien));
	 //////chon trang /////
	 int trang;
	trang = Pos_Empty_NV(NhanVien) / 20; // 20 so dong toi da cua bang 
	gotoxy(56,26);
	cout << "Trang ";
	gotoxy(64,26);
	for (int i = -1; i < trang; i++){
	
	cout << "[" <<i+2 << "]" << " ";
	}
	gotoxy(64,26);
	SetBGColor(light_cyan);
	cout << "[" << "1" << "]";
	SetBGColor(15);
	 /////////////////////
	 int luachon = 1;
	position luachon_case1[3];
	string case1[5]={"[them nhan vien]","[ xoa nhan vien]","[   cap nhat   ]"};
	for (int i= 0;i < 3;i++){
		luachon_case1[i].x=101;
		luachon_case1[i].y=20+i;
		gotoxy(luachon_case1[i].x,luachon_case1[i].y);
		cout << case1[i];
		}
	gotoxy (luachon_case1[0].x,luachon_case1[0].y);
	cout<< case1[0];
	while (true){
	 if(kbhit){
		 char input = getch();
		 if (input == -32){
		 	input = getch();
		 	switch (input){
		 		case 80 : {gotoxy(luachon_case1[luachon].x,luachon_case1[luachon].y);
		 			 SetBGColor(15);
					 cout <<case1[luachon];
                     luachon++;
                     if(luachon > 3){
                     	luachon = 0;
					 }
					 gotoxy(luachon_case1[luachon].x,luachon_case1[luachon].y);
					 SetBGColor(light_cyan);   //light_cyan
					 cout <<case1[luachon]; 
					 
					break;
				 } 
				case 72: {
					gotoxy(luachon_case1[luachon].x,luachon_case1[luachon].y);
		 			 SetBGColor(15);
					 cout <<case1[luachon];
                     luachon--;
                     if(luachon < 0){
                     	luachon = 3;
					 }
					 gotoxy(luachon_case1[luachon].x,luachon_case1[luachon].y);
					 SetBGColor(light_cyan);
					 cout <<case1[luachon]; 
					break;
				}
		 		}
}
else if(input == 13)
				{
					struct DATA_NHANVIEN Data_NV;
					switch (luachon) {
						case 0 : {// thuc hien them nhan vien
						
						SetBGColor(15);
						gotoxy(103,6);
						cout <<"                      ";
						gotoxy(103,9);
						cout <<"                ";
						gotoxy(120,9);
						cout << "       ";
						gotoxy(103,12);
						cout <<"                      ";
						SetBGColor(15);
						gotoxy(92,17);
    					cout << "                                  ";
						
						Traverse_list_NV_case3(NhanVien,Pos_Empty_NV(NhanVien)-1);
						char input3;
						while ( true){
	 					if(kbhit){
		 				 
		 				Creat_Node_NV(Data_NV);
						Insert_list_NHANVIEN (NhanVien ,Pos_Empty_NV(NhanVien) , Data_NV);

						//ofstream fileout;
		 				Write_File_List_NV(fileout, NhanVien);
		 				
						Traverse_list_NV_case3(NhanVien,Pos_Empty_NV(NhanVien)-1);
						gotoxy(94,17);
    					cout << "                                  ";
						gotoxy(94,17);
    					cout << "Them Nhan Vien Thanh Cong!";
						sleep(2);
						gotoxy(94,17);
    					cout << "                                  ";						    					
		 					//Traverse_list_NV_case4(NhanVien);
						break;
						
		 				
		 			    }
					    }
						gotoxy(103,6);
						cout <<"                      ";
						gotoxy(103,9);
						cout <<"                ";
						gotoxy(120,9);
						cout << "       ";
						gotoxy(103,12);
						cout <<"                      ";
						SetBGColor(15);
							break;
						}
						case 1 :{ // thuc hien xoa nhan vien
						SetBGColor(15);
						gotoxy(103,6);
						cout <<"                      ";
						gotoxy(103,9);
						cout <<"                ";
						gotoxy(120,9);
						cout << "       ";
						gotoxy(103,12);
						cout <<"                      ";
					//	gotoxy(101,24);
					//	cout << luachon;
    					gotoxy(92,17);
    					cout << "                                ";						
						gotoxy(103,15);
						
						Creat_Node_NV_MNV(Data_NV);
						
    					gotoxy(92,17);
    					cout << "                                  ";
    					if (Is_NhanVien_Have_HD(NhanVien,Data_NV) == 1){
    						gotoxy(92,17);
    						cout << "nhan vien da lap hoa don ko xoa";
    						gotoxy(103,15);
						    cout <<"                       ";
    						break;
						}
						if ( Search_list_NV(NhanVien,Data_NV)== -3)  //return == -3
    					{
    						gotoxy(92,17);
    						cout << "khong tim thay nhan vien can xoa";
    						gotoxy(103,15);
						    cout <<"                       ";
							
							break;
							
						}
						else {
							gotoxy(94,17);
    						cout << "                               ";
    						gotoxy(97,18);
    						cout << "                    ";
							gotoxy(103,6);
							cout << NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->MANV;
							gotoxy(103,9);
							cout << NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->HO ;
							gotoxy(120,9);
							cout << NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->TEN;
							gotoxy(103,12);
							cout << NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->PHAI ;
							gotoxy(94,17);
    						cout << "Ban co thuc su muon xoa ko? ";
    						gotoxy(97,18);
    						cout << " y: yes | n: no ";
						
						while (true){
						
						
						if (kbhit){
						char input3;
							input3 = getch();
						if (input3 == 121){
						
							DEL_ITEM_NHANVIEN(NhanVien, Search_list_NV(NhanVien, Data_NV)+1);
							//ofstream fileout1;
							
							Write_File_List_NV(fileout, NhanVien);
							
							gotoxy(103,6);
							cout <<"                      ";
							gotoxy(103,9);
							cout <<"                ";
							gotoxy(120,9);
							cout << "       ";
							gotoxy(103,12);
							cout <<"                      ";
							gotoxy(94,17);
    						cout << "                                ";
    						gotoxy(97,18);
    						cout << "                      ";
							gotoxy(94,17);
							cout << " Xoa Nhan Vien Thanh Cong";
							sleep(2);						
							gotoxy(94,17);
    						cout << "                                ";
    						gotoxy(97,18);
    						cout << "                      ";
							
				       		Traverse_list_NV_case3(NhanVien,Pos_Empty_NV(NhanVien));
				       		
				       		break;
				       		
					   }
					   else if (input3 == 110) 
					   
					   
					   break;
					   
					   //else if (input3 == 27)
					   
					   }
				}
						gotoxy(103,15);
						cout << "             ";
						gotoxy(94,17);
    					cout << "                                ";
    					gotoxy(97,18);
    					cout << "                     ";
						
							
						
					}	
						break;
					}
					
						case 2 : {// thuc hien cap nhat
						SetBGColor(15);
						gotoxy(103,6);
						cout <<"                      ";
						gotoxy(103,9);
						cout <<"                ";
						gotoxy(120,9);
						cout << "       ";
						gotoxy(103,12);
						cout <<"                      ";
    					gotoxy(92,17);
    					cout << "                                ";						
						SetBGColor(15);
						gotoxy(103,15);
						Creat_Node_NV_MNV(Data_NV);
						
    					gotoxy(92,17);
    					cout << "                                   ";
    					
						if ( Search_list_NV(NhanVien,Data_NV)== -3)  //return == -3
    					{
    						gotoxy(92,17);
    						cout << "khong tim thay nhan vien can sua";
    						gotoxy(103,15);
						    cout <<"                       ";
							
							break;
							
						}
						else {
							gotoxy(94,17);
    						cout << "Ban co thuc su muon sua ko? ";
    						gotoxy(97,18);
    						cout << " y: yes | n: no ";
						while (true){
						
						
						if (kbhit){
						char input3;
							input3 = getch();
						if (input3 == 121){
							gotoxy(94,17);
    						cout << "                               ";
    						gotoxy(97,18);
    						cout << "                    ";
							gotoxy(103,6);
							cout << NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->MANV;
							gotoxy(103,9);
							cout << NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->HO ;
							gotoxy(120,9);
							cout << NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->TEN;
							gotoxy(103,12);
							cout << NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->PHAI ;
							gotoxy(103+NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->MANV.size(),9);
							/// sua Ho Nhan Vien
							while (true){
								if(kbhit){
									gotoxy(103+NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->HO.size(),9);
									char Ho = getch();
									if (Ho == 8 ){
										if(NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->HO.empty())
										NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->HO = ' ';
										gotoxy(103+NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->HO.size()-1,9);
										cout <<" ";
										NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->HO.pop_back();
																		
									}
									else if (Ho == 13 || Ho == 27)
									break;
									
									else if (Ho >= 'a' && Ho <= 'z' || Ho == 32 || Ho >= 'A' && Ho <= 'Z' || Ho >= '0' && Ho <= '9'){
										
										gotoxy(103+NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->HO.size(),9);
										NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->HO = NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->HO + Ho;
										
									}
									
									gotoxy(103,9);
									cout << NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->HO;
								}
							}
							// Sua Ten Nhan Vien
							while (true){
									gotoxy(120+NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->TEN.size(),9);
									char Ten = getch();
									if (Ten == 8 ){
										if(NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->TEN.empty())
										NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->TEN = ' ';
										gotoxy(120+NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->TEN.size()-1,9);
										cout <<" ";
										NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->TEN.pop_back();
																		
									}
									else if (Ten == 13 || Ten == 27)
									break;
									else if (Ten >= 'a' && Ten <= 'z' || Ten == 32 || Ten >= 'A' && Ten <= 'Z' || Ten >= '0' && Ten <= '9'){
										
										gotoxy(121+NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->TEN.size()-1,9);
										
										NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->TEN = NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->TEN + Ten;
										
										
									}
									gotoxy(120,9);
									cout << NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->TEN;
									
							// Sua Phai Nhan Vien	
							}
							while (true){
									gotoxy(120+NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->PHAI.size(),12);
									char Phai = getch();
									if (Phai == 8 ){
										gotoxy(103,12);
										cout << "       ";
										NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->PHAI.clear();
										gotoxy(103,12);
										//cin.ignore();
										getline(cin,NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->PHAI);
										while(true){
										if (NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->PHAI == "NAM" || NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->PHAI == "NU" || NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->PHAI == "Nam" || NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->PHAI == "Nu" || NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->PHAI == "nam" ||NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->PHAI == "nu"){
										break;
										}
										else 
										gotoxy(103,12);
										cout <<"                     ";
										gotoxy(103,12);
										cin.ignore();
										cin >> NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->PHAI;
									}
																		
									}
									else if (Phai == 13 || Phai == 27)
									break;
									
									
									
								
							}
							
							//ofstream fileout1;
							Write_File_List_NV(fileout, NhanVien);
							DeLete_Node_NV(Data_NV);
							// xoa man hinh
							gotoxy(94,17);
    						cout << "                               ";
    						gotoxy(94,17);
    						cout << "Cap Nhat Nhan Vien Thanh Cong";
    						sleep(2);
							gotoxy(103,6);
							cout <<"                      ";
							gotoxy(103,9);
							cout <<"                ";
							gotoxy(120,9);
							cout << "       ";
							gotoxy(103,12);
							cout <<"                      ";							    						
    						gotoxy(94,17);
    						cout << "                               ";
    						gotoxy(97,18);
    						cout << "                     ";
							gotoxy(103,15);
    						cout << "                ";
				       		Traverse_list_NV_case3(NhanVien,Pos_Empty_NV(NhanVien));
				       		
				       		break;
				       		
					   }
					   else if (input3 == 110) 
					   		gotoxy(94,17);
    						cout << "                               ";
    						gotoxy(97,18);
    						cout << "                     ";
    						gotoxy(103,15);
    						cout << "                ";
					   
					   break;
					   
					   //else if (input3 == 27)
					   
					   }
				}
						
						
						
						
						
						
							break;
						}	
					}
					
}
}
else if(input == 27){
	
	color_set();
	system("cls");
	SetBGColor(15);
	//SetBGColor(0);
	menu();
}
switch (input){
	    	case 50: {
	    		SetBGColor(15);
	    		gotoxy(64,26);
	    		cout << "                                          ";
				
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(68,26);
				SetBGColor(light_cyan);
				cout << "[" << "2" << "]";
				SetBGColor(15);
				Page_Traverse_list_NV_case3(NhanVien,40);
				break;
			}
			case 49:{
				SetBGColor(15);
				gotoxy(64,26);
	    		cout << "                                          ";
				
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(64,26);
				SetBGColor(light_cyan);
				cout << "[" << "1" << "]"<<" ";
				
				SetBGColor(15);
				Page_Traverse_list_NV_case3(NhanVien,20);
				
				break;
			}
			case 51:{
				SetBGColor(15);
				gotoxy(64,26);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(72,26);
				SetBGColor(light_cyan);
				cout << "[" << "3" <<"]";
				SetBGColor(15);
				Page_Traverse_list_NV_case3(NhanVien,60);
				break;
			}
	    	case 52:{
	    		SetBGColor(15);
				gotoxy(64,26);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(76,26);
				SetBGColor(light_cyan);
				cout << "[" << "4" <<"]";
				SetBGColor(15);
				Page_Traverse_list_NV_case3(NhanVien,80);
				break;
			}
	    	case 53:{
	    		SetBGColor(15);
				gotoxy(64,26);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(80,26);
				SetBGColor(light_cyan);
				cout << "[" << "5" <<"]";
				SetBGColor(15);
				Page_Traverse_list_NV_case3(NhanVien,100);
				break;
			}
	    	
		}



}

}
	
	
}

void draw_case4(){
	struct NHANVIEN NhanVien1;
	cap_phat(NhanVien1);
	Read_File_List_NV(filein,NhanVien1);
//	Read_File_HD_Add_NV(filein1,NhanVien1);
//	Write_File_HD_CTHD(fileout1,NhanVien);	
	color_set();
	system("cls");
	SetBGColor(15);
	gotoxy(27,2);
	cout << string(80, char(219));
	for (int i = 3; i < 25; i++) {
		gotoxy(27, i);
		cout << char(219);
	
	}
	gotoxy(27, 25);
	cout << string(80, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(107,i);
		cout << char(219);
	}
	gotoxy(28,3);
	cout <<" MA NHAN VIEN |        	  TEN NHAN VIEN           | GIOI TINH |  DIA CHI  ";
	gotoxy(28,4);
	cout <<"------------------------------------------------------------------------------";
	gotoxy(55,28);
	cout <<"*NHAN ESC DE TRO VE MENU\n";
	gotoxy(53,29);
	cout <<"*SU DUNG PHIM SO DE LUA CHON TRANG\n";
	gotoxy(42,4);
	for (int i =3; i<25;i++){
		gotoxy(42,i);
		cout <<"|";}
	gotoxy(82,4);
	for (int i =3; i<25;i++){
		gotoxy(82,i);
		cout <<"|";
	}
	gotoxy(94,4);
	for (int i =3; i<25;i++){
		gotoxy(94,i);
		cout <<"|";}

//	Read_File_HD_Add_NV(filein,NhanVien);
	Traverse_list_NV_case4(NhanVien1,20);	
	
	int trang;
	trang = Pos_Empty_NV(NhanVien1) / 20; // 20 so dong toi da cua bang 
	gotoxy(56,26);
	cout << "Trang ";
	gotoxy(64,26);
	for (int i = -1; i < trang; i++){
	
	cout << "[" <<i+2 << "]" << " ";
	}
	gotoxy(64,26);
	SetBGColor(light_cyan);
	cout << "[" << "1" << "]";
	SetBGColor(15);
	
	while (true){
		if (kbhit){
		char input1 = getch();
		if (input1 == 27)
		{
		system("cls");
		Free_Memory(NhanVien1);	
		menu();
		break;
	    }
	    switch (input1){
	    	case 50: {
	    		gotoxy(64,26);
	    		cout << "                                          ";
				
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(68,26);
				SetBGColor(light_cyan);
				cout << "[" << "2" << "]";
				SetBGColor(15);
				Traverse_list_NV_case4(NhanVien1,40);
				break;
			}
			case 49:{
				gotoxy(64,26);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(64,26);
				SetBGColor(light_cyan);
				cout << "[" << "1" << "]"<<" ";
				
				SetBGColor(15);
				Traverse_list_NV_case4(NhanVien1,20);
				
				break;
			}
			case 51:{
				gotoxy(64,26);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(72,26);
				SetBGColor(light_cyan);
				cout << "[" << "3" <<"]";
				SetBGColor(15);
				Traverse_list_NV_case4(NhanVien1,60);
				break;
			}
	    	case 52:{
				gotoxy(64,26);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(76,26);
				SetBGColor(light_cyan);
				cout << "[" << "4" <<"]";
				SetBGColor(15);
				Traverse_list_NV_case4(NhanVien1,80);
				break;
			}
	    	case 53:{
				gotoxy(64,26);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,26);
				cout << "Trang ";
				gotoxy(64,26);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(80,26);
				SetBGColor(light_cyan);
				cout << "[" << "5" <<"]";
				SetBGColor(15);
				Traverse_list_NV_case4(NhanVien1,100);
				break;
			}
	    	
				}
	  }	
	}
	
}

void draw_case5(){
	struct DATA_NHANVIEN Data_NV;
	struct DATA_HOADON DATA_HD;
	struct List_CT_HOADON list1_CTHD;
	color_set();
	system("cls");
	SetBGColor(15);
	gotoxy(17,7);
	cout << string(100, char(219));
	for (int i = 7; i < 30; i++) {
		gotoxy(17, i);
		cout << char(219);
	
	}
	gotoxy(17, 30);
	cout << string(100, char(219)) << endl;
	for (int i = 7;i <= 30;i++){
		gotoxy(117,i);
		cout << char(219);
	}
	
	gotoxy(18,8);
	cout <<" stt	|   	Ten Vat Tu	  |   Ma VT   |   So Luong   |   Don Gia  |	Thanh Tien	 ";
	gotoxy(18,9);
	cout << "--------------------------------------------------------------------------------------------------";
	gotoxy(57,1);
	cout << " HOA DON BAN HANG";
	gotoxy(40,4);
	cout << "Loai phieu (xuat/nhap):  [         /        ]";
	gotoxy(40,3);
	cout << "Ma Nhan Vien Lap Phieu:  [                  ]  [                             ]";
	gotoxy(40,5);
	cout << "Ngay Lap :               [     /     /      ]  [                             ]";
	gotoxy(40,6);
	cout << "So Hoa Don:              [                  ]  [                             ]";
	gotoxy(18,27);
	cout << "--------------------------------------------------------------------------------------------------";
	gotoxy(79,28);
	cout << "Tong Tien :   ";
	
	for (int i =10; i<27;i++){
		gotoxy(24,i);
		cout <<"|";}
	for (int i =10; i<27;i++){
		gotoxy(50,i);
		cout <<"|";}
	for (int i =10; i<27;i++){
		gotoxy(62,i);
		cout <<"|";}
	for (int i =10; i<27;i++){
		gotoxy(77,i);
		cout <<"|";}
	for (int i =10; i<27;i++){
		gotoxy(90,i);
		cout <<"|";}
	gotoxy(52,10);	
	gotoxy(55,31);
	cout <<"*NHAN ESC DE LUU HOA DON\n";
	gotoxy(55,32);
	cout <<"*NHAN PHIM X DE XOA VAT TU\n";
	gotoxy(50,33);
	cout <<"* Dung Phim Mui Ten De Lua Chon Nhap/Xuat ";
	//gotoxy(68,10);	
	///////////////////////////////////////////////////////////////////////////////////	
	char input;
	while (true){
	//struct DATA_NHANVIEN Data_NV;
	ShowConsoleCursor(true);
	gotoxy(72,3);
	DeLete_Node_NV(Data_NV);
	Creat_Node_NV_MNV(Data_NV);
	gotoxy(89,3);
    cout << "                        ";
	if ( Search_list_NV(NhanVien,Data_NV)== -3){  //return == -3
    
		gotoxy(72,3);
		cout << "         ";				
    	gotoxy(89,3);
    	cout << "khong tim thay nhan vien ";
    	//gotoxy(47,3);
		//cout <<"           ";
		//gotoxy(60,3);
    	//cout << "                         ";					
		}
	else {
		gotoxy(89,3);
		cout << NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->HO << " " <<NhanVien.NV[Search_list_NV(NhanVien,Data_NV)]->TEN;
        break;
		}
	
	input = getch();
	if (input == 27 )
	{
	system("cls");
	menu();
	}
}
		
		
	//////////////////////////////////////////////////////////////////////////////////	
	
	
	
	char input1,input2;
	string NX[3]={"NHAP","XUAT"};	
	gotoxy(69,4);
	cout << NX[0];
	gotoxy(77,4);
	cout << NX[1];
	
		
	while (true){
			
		
		ShowConsoleCursor(false);
	 	if(kbhit){
		  input1 = getch();
		 
		 
		if (input1 == 13){
		break;	
		}
		else if (input1 == 75){
			while(true){
			
			gotoxy(69,4);
			SetBGColor(light_cyan);
			cout << NX[0];
			SetBGColor(15);
			gotoxy(77,4);
			cout << NX[1];
			lcnhapxuat = 0;
			ShowConsoleCursor(false);
			break;	
		}
			
			
		}
		else if (input1 == 77){
			while(true){
				ShowConsoleCursor(false);
				gotoxy(77,4);
				SetBGColor(light_cyan);
				cout << NX[1];
				SetBGColor(15);
				gotoxy(69,4);
				cout << NX[0];
				lcnhapxuat = 1;
				ShowConsoleCursor(false);
				break;
			}
		}		 
		else if(input1 == 27){
	
			color_set();
			system("cls");
			SetBGColor(15);
			//SetBGColor(0);
			gotoxy(45, 5);
			cout << "---------------------------\n";
			gotoxy(45, 6);
			cout << "| BAN CO MUON LUU HAY KO? |\n";
			gotoxy(45, 7);
			cout << "|            |            |\n"; 
			gotoxy(45, 8);
			cout << "|  Y : yes   |   N : NO   |\n";
			gotoxy(45, 9);
			cout << "|            |            |\n";
			gotoxy(45, 10);
			cout << "---------------------------\n";
			input1 = getch();
			 if (input1 == 121){
				
				color_set();
				system("cls");
				SetBGColor(15);
				menu();
				break;
			}
			else if (input1 == 110)
			{
				//color_set();
				
				system("cls");
				//SetBGColor(15);
				draw_case5();
			}
			
		
			}
				 
				 
}

	vitricase5 ={0,0};			

}
struct HOADON* hoadon;

while (true){
	if (kbhit){
		input1 = getch();
		if(input1 == 13){
				while(input1 != 27){ 
			
		 	ShowConsoleCursor(true);
		 	gotoxy(20,10+vitricase5.y);
			cout << vitricase5.x+1;
			gotoxy(90,6);
			cout     << "                         ";
			 //nhap MA VT cho CT_HD
			 
			 
			// nhap MA VT cho CT HD
			
		 		//input1 = getch();
		 		if (input1 == 13){
				 gotoxy(21,10+vitricase5.y);
				 //cout << vitricase5.y + 1;
				 struct CT_HD_INFO INFO;
				 Creat_node_CTHD(INFO);
				 
				 
				 list1_CTHD.sizeHD = 16;
				 Insert_list_CTHD (list1_CTHD, vitricase5.y ,INFO);
				 
				 //gotoxy(68,10+vitricase5.y);
				 //cout << vitricase5.y;
		 		
				 if (vitricase5.y == 16 ){ //vitri cuoi bang
				 vitricase5.x = 0;
				 vitricase5.y = 0;
				 //break;
				 }
				 else {
				 vitricase5.x++;
		 		 vitricase5.y++;
		 		 //break;
				 }
				 
				 }
				  
		 		break;
		 		}
		 		Output_Case5(list1_CTHD);
				 }
				 
			else if (input1 == 88 || input1 == 120) // chu X hoac x
				{
					gotoxy(90,6);
					cout     << "                         ";
					gotoxy(90,6);
					string Mavt;
					cout << "Ma Vat Tu can xoa: ";
					cin >> Mavt;
					if (Search_Mavt(list1_CTHD,Mavt) == -1){
						gotoxy(90,6);
						cout << "khong thay VT can xoa";
					}
					else {
						gotoxy (90,6);
						cout << "ban that su muon xoa ko?";
						

						gotoxy (90,6);
						cout << "                        ";
						if (lcnhapxuat == 1){
				
							
							Fix_VT_Xuat(T,list1_CTHD.INFO[Search_Mavt(list1_CTHD,Mavt)].MAVT,list1_CTHD.INFO[Search_Mavt(list1_CTHD,Mavt)].SoLuong);
						//	cout <<	list1_CTHD.INFO[Search_Mavt(list1_CTHD,Mavt)+1].MAVT <<"\n";
						//	cout << list1_CTHD.INFO[Search_Mavt(list1_CTHD,Mavt)+1].SoLuong;	
						//	system("pause");
						}
						else if (lcnhapxuat == 0) {
							
							Fix_VT_Nhap(T,list1_CTHD.INFO[Search_Mavt(list1_CTHD,Mavt)+1].MAVT,list1_CTHD.INFO[Search_Mavt(list1_CTHD,Mavt)+1].SoLuong);
												
					
						}							
					DEL_ITEM_CTHD(list1_CTHD, Search_Mavt(list1_CTHD,Mavt)+1);
						vitricase5.y = vitricase5.y-1;
						vitricase5.x = vitricase5.x-1;
					for (int j = 0; j < 16 ;j++){
						gotoxy(30,10+j);
						cout << "                   ";					
						gotoxy(52,10+j);
						cout << "         ";
						gotoxy(68,10+j);
						cout << "         ";
						gotoxy(78,10+j);
						cout << "            ";
						gotoxy(95,10+j);
						cout << "                 ";
						gotoxy(95,28);
						cout << "                ";
						}
						tong = 0;
					for (int i = 0; i < Pos_Empty_CTHD(list1_CTHD);i++){
	//					gotoxy(52,10+i);
	//					cout << "         ";
						
						gotoxy(52,10+i);
						cout << list1_CTHD.INFO[i].MAVT;

						//vi tri So Luong vat tu
	//					gotoxy(68,10+i);
	//					cout << "         ";
						gotoxy(30,10+i);
					//	cout << atoi(list1_CTHD.INFO[i].MAVT.c_str()) << " " <<atoi( T->DATA.MaVT.c_str());
						Find_Print_Deleta_case5(T,Cut_enter(list1_CTHD.INFO[i].MAVT),i);
						gotoxy(68,10+i);
						cout << list1_CTHD.INFO[i].SoLuong;
						// vi tri don gia vat tu
	//					gotoxy(81,10+i);
	//					cout << "           ";
						gotoxy(78,10+i);
						cout << list1_CTHD.INFO[i].DonGia;
	//					gotoxy(95,10+i);
	//					cout << "                ";
						gotoxy(95,10+i);
				//		cout << fixed << setprecision(0) << list1_CTHD.INFO[i].SoLuong * list1_CTHD.INFO[i].DonGia;
						//gotoxy (105,10+i);
						//cout << "cccc";
						Print_Number_With_point (list1_CTHD.INFO[i].SoLuong * list1_CTHD.INFO[i].DonGia);
						tong = tong + (list1_CTHD.INFO[i].SoLuong)*(list1_CTHD.INFO[i].DonGia);
						gotoxy(95,28);
						cout << "                ";
						gotoxy(95,28);
				//		cout << fixed << setprecision(0) << tong << "   VND";
						Print_Number_With_point(tong);
						// vi tri don gia vat tu
					//	gotoxy(78,10+i);
					//	cout << "           ";	
					}
				
				}
				 }	
			else if(input1 == 27  ){
			
			
			Creat_Node_DaTa_HoaDon(DATA_HD,lcnhapxuat);

			//Add_HoaDon_To_NV(NhanVien,hoadon,Search_list_NV(NhanVien,Data_NV));
			color_set();
			system("cls");
			SetBGColor(15);
			//SetBGColor(0);
			while ( true){
			
			gotoxy(45, 5);
			cout << "---------------------------\n";
			gotoxy(45, 6);
			cout << "| BAN CO MUON LUU HAY KO? |\n";
			gotoxy(45, 7);
			cout << "|            |            |\n"; 
			gotoxy(45, 8);
			cout << "|  Y : yes   |   N : NO   |\n";
			gotoxy(45, 9);
			cout << "|            |            |\n";
			gotoxy(45, 10);
			cout << "---------------------------\n";
			char input2 = getch();
			 if (input2 == 121){
				hoadon = Creat_Node_Dshd(DATA_HD);
				Add_CTHD_To_HD(hoadon,list1_CTHD);
				Add_Node_Head(NhanVien, hoadon , Search_list_NV(NhanVien,Data_NV));
				
				SoHoaDon_Auto ++;
				Write_File_HD_CTHD(fileout1,NhanVien);
				
	/*			if (lcnhapxuat = 0){
				if (lcnhapxuat == 1){
				
				for (int i = 0; i < Pos_Empty_CTHD(list1_CTHD);i++){
					Fix_VT_Xuat(T,list1_CTHD.INFO[i].MAVT,list1_CTHD.INFO[i].SoLuong);
					
				}	
			//	system("pause");
				}
				else if (lcnhapxuat == 0) {
				for (int i = 0; i < Pos_Empty_CTHD(list1_CTHD);i++){
					Fix_VT_Nhap(T,list1_CTHD.INFO[i].MAVT,list1_CTHD.INFO[i].SoLuong);
				}					
					
				}
				*/
				Write_Tree (fileout,T);
	//			}
				tong = 0; // sau nay lap hoa don tong tri gia tro lai  = 0 //
				color_set();
				system("cls");
				SetBGColor(15);
				draw_case5();
				break;
			}
			else if (input2 == 110)
			{
				//color_set();
				if (lcnhapxuat == 1){
				
				for (int i = 0; i < Pos_Empty_CTHD(list1_CTHD);i++){
					Fix_VT_Xuat(T,list1_CTHD.INFO[i].MAVT,list1_CTHD.INFO[i].SoLuong);
					
				}	
			//	system("pause");
				}
				else if (lcnhapxuat == 0) {
				for (int i = 0; i < Pos_Empty_CTHD(list1_CTHD);i++){
					Fix_VT_Nhap(T,list1_CTHD.INFO[i].MAVT,list1_CTHD.INFO[i].SoLuong);
				}					
					
				}			
				system("cls");
				draw_case5();
			}
			
						}
			}	 
				 
		}
	}
}





		
		
	///////////////////////////////////////////////////////////////////////////////////	
		
		


void draw_case6(){

//	Write_File_HD_CTHD(fileout1,NhanVien);	
	color_set();
	system("cls");
	SetBGColor(15);
	gotoxy(17,7);
	cout << string(100, char(219));
	for (int i = 7; i < 30; i++) {
		gotoxy(17, i);
		cout << char(219);
	
	}
	gotoxy(17, 30);
	cout << string(100, char(219)) << endl;
	for (int i = 7;i <= 30;i++){
		gotoxy(117,i);
		cout << char(219);
	}
	
	gotoxy(18,8);
	cout <<" stt	|   	Ten Vat Tu	  |   Ma VT   |   So Luong   |   Don Gia  |	Thanh Tien	 ";
	gotoxy(18,9);
	cout << "--------------------------------------------------------------------------------------------------";
	gotoxy(57,1);
	cout << " HOA DON BAN HANG";
	gotoxy(40,3);
	cout << "Loai phieu (xuat/nhap):  [                              ]";
	gotoxy(40,4);
	cout << "Ten Nhan Vien Lap Phieu: [                              ]";
	gotoxy(40,5);
	cout << "Ngay Lap :               [                              ]";
	gotoxy(18,27);
	cout << "--------------------------------------------------------------------------------------------------";
	gotoxy(79,28);
	cout << "Tong Tien :   ";
	gotoxy(40,2);
	cout << "Ma Hoa Don:              [                              ]";
	gotoxy(55,32);
	cout <<"*NHAN ESC DE TRO VE MENU\n";
	
	for (int i =10; i<27;i++){
		gotoxy(24,i);
		cout <<"|";}
	for (int i =10; i<27;i++){
		gotoxy(50,i);
		cout <<"|";}
	for (int i =10; i<27;i++){
		gotoxy(62,i);
		cout <<"|";}
	for (int i =10; i<27;i++){
		gotoxy(77,i);
		cout <<"|";}
	for (int i =10; i<27;i++){
		gotoxy(90,i);
		cout <<"|";}
	
		while (true){
		if (kbhit){
		ShowConsoleCursor(true);	
		Traverse_Case_6(NhanVien);
		char input1 = getch();
		if (input1 == 27)
		{
		system("cls");	
		menu();
		break;
	    }
				  }	
	}	
	
	
}
void Input_Case_7(struct NHANVIEN NhanVien,struct ngaylap &NgayDau,struct ngaylap &NgayCuoi){
	for (int t = 0; t < 20; t++){
		gotoxy(22,10+t);
		cout << "         ";
		gotoxy(35,10+t);
		cout <<	"            ";
		gotoxy(52,10+t);
		cout << "       ";
		gotoxy(63,10+t);
		cout << "                            ";
		gotoxy(100,10+t);
		cout << "              ";
		
	}

	while (true){
	gotoxy(58,4);
	cout <<"  ";
	gotoxy(61,4);
	cout << "  ";
	gotoxy(64,4);
	cout << "    ";		
	gotoxy(82,4);
	cout << "  ";
	gotoxy(85,4);
	cout << "  ";
	gotoxy(88,4);
	cout << "    ";
	gotoxy(50,5);
	cout << "                                                           ";		
	while (true){
	gotoxy(58,4);
	cout <<"  ";
	gotoxy(61,4);
	cout << "  ";
	gotoxy(64,4);
	cout << "    ";

	gotoxy(50,5);
	cout << "                                                           ";

	
	while ( true){
		gotoxy(58,4);
		cout <<"  ";
		gotoxy(58,4);
		string s ;
		cin >> s;
		if (Check_Number(s ) == true){
		NgayDau.ngay = atoi(s.c_str());
		break;
		}
	}
	while ( true){
		gotoxy(61,4);
		cout <<"  ";
		gotoxy(61,4);
		string s ;
		cin >> s;
		if (Check_Number(s ) == true){
		NgayDau.thang = atoi(s.c_str());
		break;
		}
	}
	while ( true){
		gotoxy(64,4);
		cout <<"    ";
		gotoxy(64,4);
		string s ;
		cin >> s;
		if (Check_Number(s ) == true){
		NgayDau.nam = atoi(s.c_str());
		break;
		}
	}


	// chuan hoa du lieu ngay dau
	if (NgayDau.nam % 4 == 0){
		if(NgayDau.thang < 1 || NgayDau.thang > 12){
			gotoxy(50,5);
			cout << "Nhap thang  Dau sai hay nhap lai";
			}
		else if (NgayDau.thang == 2){
			
				if (NgayDau.ngay < 1 || NgayDau.ngay > 29 )
				{
					gotoxy(50,5);
					cout << " Nhap ngay Dau sai hay nhap lai!";
				}
				else break;
			}
		else if (NgayDau.thang == 1 || NgayDau.thang == 3 || NgayDau.thang == 3 || NgayDau.thang == 5 || NgayDau.thang == 7 ||NgayDau.thang == 8 || NgayDau.thang == 10 || NgayDau.thang == 12)
			 {
				if (NgayDau.ngay <1 || NgayDau.ngay > 31)
				{
					gotoxy(50,5);
					cout << "Nhap Ngay Dau sai hay nhap lai";
				}
				else break;
				
			}
		else {
				if (NgayDau.ngay <1 || NgayDau.ngay > 30){
					gotoxy(50,5);
					cout << " Nhap Ngay Dau sai hay nhap lai";
				}
				else break;
			}
		getch();
		}
	
	else {
		if(NgayDau.thang < 1 || NgayDau.thang > 12){
			gotoxy(50,5);
			cout << "Nhap thang Dau sai hay nhap lai";
			}
		else if (NgayDau.thang == 2){
			
				if (NgayDau.ngay < 1 || NgayDau.ngay > 28 )
				{
					gotoxy(50,5);
					cout << " Nhap ngay Dau sai hay nhap lai!";
				}
				else break;
			}
		else if (NgayDau.thang == 1 || NgayDau.thang == 3 || NgayDau.thang == 3 || NgayDau.thang == 5 || NgayDau.thang == 7 ||NgayDau.thang == 8 || NgayDau.thang == 10 || NgayDau.thang == 12)
			 {
				if (NgayDau.ngay <1 || NgayDau.ngay > 31)
				{
					gotoxy(50,5);
					cout << "Nhap Ngay Dau sai hay nhap lai";
				}
				else break;
				
			}
		else {
				if (NgayDau.ngay <1 || NgayDau.ngay > 30){
					gotoxy(50,5);
					cout << " Nhap Ngay Dau sai hay nhap lai";
				}
				else break;
			}
		getch();
	}	
}
	//////////////////////////// chuan hoa du lieu ngay cuoi ///////////////////////////
	while (true){
	gotoxy(82,4);
	cout << "  ";
	gotoxy(85,4);
	cout << "  ";
	gotoxy(88,4);
	cout << "    ";
	gotoxy(50,5);
	cout << "                                                           ";	
	while ( true){
		gotoxy(82,4);
		cout <<"  ";
		gotoxy(82,4);
		string s ;
		cin >> s;
		if (Check_Number(s ) == true){
		NgayCuoi.ngay = atoi(s.c_str());
		break;
		}
	}
	while ( true){
		gotoxy(85,4);
		cout <<"  ";
		gotoxy(85,4);
		string s ;
		cin >> s;
		if (Check_Number(s ) == true){
		NgayCuoi.thang = atoi(s.c_str());
		break;
		}
	}
	while ( true){
		gotoxy(88,4);
		cout <<"    ";
		gotoxy(88,4);
		string s ;
		cin>> s;
		if (Check_Number(s ) == true){
		NgayCuoi.nam = atoi(s.c_str());
		break;
		}
	}
		if (NgayCuoi.nam % 4 == 0){
		if(NgayCuoi.thang < 1 || NgayCuoi.thang > 12){
			gotoxy(50,5);
			cout << "Nhap thang cuoi sai hay nhap lai";
			}
		else if (NgayCuoi.thang == 2){
			
				if (NgayCuoi.ngay < 1 || NgayCuoi.ngay > 29 )
				{
					gotoxy(50,5);
					cout << " Nhap ngay cuoi sai hay nhap lai!";
				}
				else break;
			}
		else if (NgayCuoi.thang == 1 || NgayCuoi.thang == 3 || NgayCuoi.thang == 3 || NgayCuoi.thang == 5 || NgayCuoi.thang == 7 ||NgayCuoi.thang == 8 || NgayCuoi.thang == 10 || NgayCuoi.thang == 12)
			 {
				if (NgayCuoi.ngay <1 || NgayCuoi.ngay > 31)
				{
					gotoxy(50,5);
					cout << "Nhap Ngay cuoi sai hay nhap lai";
				}
				else break;
				
			}
		else {
				if (NgayCuoi.ngay <1 || NgayCuoi.ngay > 30){
					gotoxy(50,5);
					cout << " Nhap Ngay cuoi sai hay nhap lai";
				}
				else break;
			}
		getch();	
		}
	
	else {
		if(NgayCuoi.thang < 1 || NgayCuoi.thang > 12){
			gotoxy(50,5);
			cout << "Nhap thang cuoi sai hay nhap lai";
			}
		else if (NgayCuoi.thang == 2){
			
				if (NgayCuoi.ngay < 1 || NgayCuoi.ngay > 28 )
				{
					gotoxy(50,5);
					cout << " Nhap ngay cuoi sai hay nhap lai!";
				}
				else break;
			}
		else if (NgayCuoi.thang == 1 || NgayCuoi.thang == 3 || NgayCuoi.thang == 3 || NgayCuoi.thang == 5 || NgayCuoi.thang == 7 ||NgayCuoi.thang == 8 || NgayCuoi.thang == 10 || NgayCuoi.thang == 12)
			 {
				if (NgayCuoi.ngay <1 || NgayCuoi.ngay > 31)
				{
					gotoxy(50,5);
					cout << "Nhap Ngay cuoi sai hay nhap lai";
				}
				else break;
				
			}
		else {
				if (NgayCuoi.ngay <1 || NgayCuoi.ngay > 30){
					gotoxy(50,5);
					cout << " Nhap Ngay cuoi sai hay nhap lai";
				}
				else break;
			}
		getch();
	}
}
	//////////////Chuan hoa du lieu ngay dau va ngay cuoi///////////////


	if (NgayDau.nam > NgayCuoi.nam){
		gotoxy(50,5);
		cout << " Nam ngay dau ko the lon hon nam ngay cuoi";
	}
	else if (NgayDau.nam == NgayCuoi.nam){
	
	 	if (NgayDau.thang > NgayCuoi.thang){
		gotoxy(50,5);
		cout << " thang ngay dau ko the lon hon thang ngay cuoi";
		}
	
		else if (NgayDau.thang == NgayCuoi.thang){
			if (NgayDau.ngay > NgayCuoi.ngay){
				gotoxy(50,5);
				cout << "  ngay dau ko the lon hon ngay cuoi";
			}
			else break;
		}
	
	}
	else break;
	getch();
	}
	
}

int traverse_Case_7(struct NHANVIEN NhanVien,struct ngaylap NgayDau,struct ngaylap NgayCuoi,int t){

	//////////////////////////Xuat Thong Tin Vao Case 7/////////////////////////////
	for (int t = 0; t < 20; t++){
		gotoxy(22,10+t);
		cout << "         ";
		gotoxy(35,10+t);
		cout <<	"            ";
		gotoxy(52,10+t);
		cout << "       ";
		gotoxy(63,10+t);
		cout << "                            ";
		gotoxy(100,10+t);
		cout << "                ";
		
	}
	int dong = 0;
	int HoaDonDaIN = 0;

		for ( int i = 0; i < Pos_Empty_NV(NhanVien);i++){
			struct HOADON *q = NhanVien.NV[i]->HD;
			struct DATA_NHANVIEN *p = NhanVien.NV[i];
			for (q ; q != NULL ; q = q->pNext){
				
				if ((Compare_Date(q->DATA_HD.ngaylap, NgayDau) == 1 || Compare_Date(q->DATA_HD.ngaylap, NgayDau) == 0) && (Compare_Date(q->DATA_HD.ngaylap, NgayCuoi) == -1 || Compare_Date(q->DATA_HD.ngaylap, NgayDau) == 0)){
					if (HoaDonDaIN >= t-20 && HoaDonDaIN < t){
					
					gotoxy(22,10+dong);
					cout << 	q->DATA_HD.SoHD;
					gotoxy(35,10+dong);
					cout <<		q->DATA_HD.ngaylap.ngay <<"/"<< q->DATA_HD.ngaylap.thang <<"/"<<q->DATA_HD.ngaylap.nam;
					gotoxy(52,10+dong);
					cout << q->DATA_HD.loai;
					gotoxy(63,10+dong);
					cout << p->HO << " " << p->TEN;
					gotoxy(100,10+dong);
					int tong = 0;
					for (int j = 0; j < Pos_Empty_CTHD(q->DATA_HD.CT_HD); j++){
						
						tong += (q->DATA_HD.CT_HD->INFO[j].SoLuong)*(q->DATA_HD.CT_HD->INFO[j].DonGia);						
					}
					//cout << fixed << setprecision(0) << tong ;
					Print_Number_With_point (tong);
					dong ++;
					}
					HoaDonDaIN ++;
				}   
			}	
		}
	
	
	return HoaDonDaIN;
}
	///////////////////////////////////////////////////////////////////////////////	

void draw_case7(){
	ShowConsoleCursor(true);
//	Write_File_HD_CTHD(fileout1,NhanVien);	
	color_set();
	system("cls");
	SetBGColor(15);
	gotoxy(17,7);
	cout << string(100, char(219));
	for (int i = 7; i < 30; i++) {
		gotoxy(17, i);
		cout << char(219);
	
	}
	gotoxy(17, 30);
	cout << string(100, char(219)) << endl;
	for (int i = 7;i <= 30;i++){
		gotoxy(117,i);
		cout << char(219);
	}
	gotoxy(44,3);
	cout <<"   BANG LIET KE CAC HOA DON TRONG KHOANG THOI GIAN";
	gotoxy(48,4);
	cout <<"TU NGAY:|   /  /   ";
	
	gotoxy(68,4);
	cout <<"| DEN NGAY: |   /  /   ";
	gotoxy(92,4);
	cout <<"|";
	gotoxy(18,8);
	cout <<"  SO HD	 |	NGAY LAP | LOAI HD |		HO TEN NV LAP   	| TRI GIA HOA DON";
	gotoxy(18,9);
	cout <<"--------------------------------------------------------------------------------------------------";
	
	gotoxy(55,32);
	cout <<"*NHAN ESC DE TRO VE MENU\n";
	gotoxy(33,4);
	for (int i =8; i<30;i++){
		gotoxy(33,i);
		cout <<"|";}
	gotoxy(49,4);
    for (int i =8; i<30;i++){
		gotoxy(49,i);
		cout <<"|";
	}
	gotoxy(59,4);
	for (int i =8; i<30;i++){
		gotoxy(59,i);
		cout <<"|";}
	gotoxy(96,4);
	for (int i =8; i<30;i++){
		gotoxy(96,i);
		cout <<"|";}
		struct ngaylap NgayDau;
		struct ngaylap NgayCuoi;
		int trang;
		Input_Case_7(NhanVien,NgayDau,NgayCuoi);
		trang = traverse_Case_7(NhanVien,NgayDau,NgayCuoi,20) / 20; // 20 so dong toi da cua bang
		gotoxy(56,31);
		cout << "Trang ";
		gotoxy(64,31);
		for (int i = -1; i < trang; i++){
		
		cout << "[" <<i+2 << "]" << " ";
		}
		gotoxy(64,31);
		SetBGColor(light_cyan);
		cout << "[" << "1" << "]";
		SetBGColor(15);
		while (true){
		if (kbhit){
		ShowConsoleCursor(true);
	//	traverse_Case_7(NhanVien);
		

		char input1 = getch();
		if (input1 == 27)
		{
		system("cls");	
		menu();
		break;
	    }
		 
	
	
	    switch (input1){
	    	case 50: {
	    		gotoxy(64,31);
	    		cout << "                                          ";
				
				SetBGColor(15);
				gotoxy(56,31);
				cout << "Trang ";
				gotoxy(64,31);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(68,31);
				SetBGColor(light_cyan);
				cout << "[" << "2" << "]";
				SetBGColor(15);
	//			Traverse_list_NV_case4(NhanVien,40);
				traverse_Case_7(NhanVien,NgayDau,NgayCuoi,40);
				
				break;
			}
			case 49:{
				gotoxy(64,31);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,31);
				cout << "Trang ";
				gotoxy(64,31);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(64,31);
				SetBGColor(light_cyan);
				cout << "[" << "1" << "]"<<" ";
				
				SetBGColor(15);
	//			Traverse_list_NV_case4(NhanVien,20);
				traverse_Case_7(NhanVien,NgayDau,NgayCuoi,20);
				break;
			}
			case 51:{
				gotoxy(64,31);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,31);
				cout << "Trang ";
				gotoxy(64,31);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(72,31);
				SetBGColor(light_cyan);
				cout << "[" << "3" <<"]";
				SetBGColor(15);
	//			Traverse_list_NV_case4(NhanVien,60);
				traverse_Case_7(NhanVien,NgayDau,NgayCuoi,60);
				break;
			}
	    	case 52:{
				gotoxy(64,31);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,31);
				cout << "Trang ";
				gotoxy(64,31);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(76,31);
				SetBGColor(light_cyan);
				cout << "[" << "4" <<"]";
				SetBGColor(15);
	//			Traverse_list_NV_case4(NhanVien,80);
				traverse_Case_7(NhanVien,NgayDau,NgayCuoi,80);
				break;
			}
	    	case 53:{
				gotoxy(64,31);
	    		cout << "                                          ";
				SetBGColor(15);
				gotoxy(56,31);
				cout << "Trang ";
				gotoxy(64,31);
				for (int i = -1; i < trang; i++){
				cout << "[" <<i+2 << "]" << " ";
				}
				gotoxy(80,31);
				SetBGColor(light_cyan);
				cout << "[" << "5" <<"]";
				SetBGColor(15);
	//			Traverse_list_NV_case4(NhanVien,100);
				traverse_Case_7(NhanVien,NgayDau,NgayCuoi,100);
				break;
			}
	    	
				}
	  	
		    
				  }	
	}

	
}
/*
void trasever_case_8(struct NHANVIEN NhanVien){

		Print_Case_8(NhanVien,NgayDau,NgayCuoi);
		int dong = 0;			
		for ( int t = 0; t < Pos_Empty_NV(NhanVien);t++){
			struct HOADON *q = NhanVien.NV[t]->HD;
			struct DATA_NHANVIEN *p = NhanVien.NV[t];
			for (q; q != NULL ; q = q->pNext){
				
				for ( int i = 0; i < Sohoadoncanin;i++ ){
					if (TriGia[i] == q->DATA_HD.TriGia){
						gotoxy(22,10+dong);
						cout << 	q->DATA_HD.SoHD;
						gotoxy(35,10+dong);
						cout <<		q->DATA_HD.ngaylap.ngay <<"/"<< q->DATA_HD.ngaylap.thang <<"/"<<q->DATA_HD.ngaylap.nam;
						gotoxy(52,10+dong);
						cout << q->DATA_HD.loai;
						gotoxy(63,10+dong);
						cout << p->HO << " " << p->TEN;
						gotoxy(100,10+dong);
						cout << fixed << setprecision(0) << q->DATA_HD.TriGia ;
						dong ++;
						break;
					}
				}
			}
	}					
					
	Sohoadoncanin = 0;	
	TriGia[100] = 0;			
					
}
*/
void draw_case8(){
	ShowConsoleCursor(true);
//	Write_File_HD_CTHD(fileout1,NhanVien);	
	color_set();
	system("cls");
	SetBGColor(15);
	gotoxy(17,7);
	cout << string(100, char(219));
	for (int i = 7; i < 30; i++) {
		gotoxy(17, i);
		cout << char(219);
	
	}
	gotoxy(17, 30);
	cout << string(100, char(219)) << endl;
	for (int i = 7;i <= 30;i++){
		gotoxy(117,i);
		cout << char(219);
	}
	gotoxy(44,3);
	cout <<"BANG LIET KE 10 HOA DON CO DOANH THU CAO NHAT ";
	gotoxy(48,4);
//	cout <<"TU NGAY:|   /   /  ";
	
	gotoxy(68,4);
//	cout <<"| DEN NGAY: |   /   /  ";
	gotoxy(92,4);
//	cout <<"|";
	gotoxy(18,8);
	cout <<"  SO HD	 |	NGAY LAP | LOAI HD |		HO TEN NV LAP   	| TRI GIA HOA DON";
	gotoxy(18,9);
	cout <<"--------------------------------------------------------------------------------------------------";
	
	
	gotoxy(55,32);
	cout <<"*NHAN ESC DE TRO VE MENU\n";
	gotoxy(33,4);
	for (int i =8; i<30;i++){
		gotoxy(33,i);
		cout <<"|";}
	gotoxy(49,4);
    for (int i =8; i<30;i++){
		gotoxy(49,i);
		cout <<"|";
	}
	gotoxy(59,4);
	for (int i =8; i<30;i++){
		gotoxy(59,i);
		cout <<"|";}
	gotoxy(96,4);
	for (int i =8; i<30;i++){
		gotoxy(96,i);
		cout <<"|";}
	gotoxy(48,4);
	cout <<"TU NGAY:|   /  /   ";
	
	gotoxy(68,4);
	cout <<"| DEN NGAY: |   /  /    ";		
	struct ngaylap NgayDau;
	struct ngaylap NgayCuoi;
	Input_Case_7(NhanVien,NgayDau,NgayCuoi);	
	//////////////////////////////////
		
	
	Print_Case_8(NhanVien,NgayDau,NgayCuoi);
		int dong = 0;			
		for ( int t = 0; t < Pos_Empty_NV(NhanVien);t++){
			struct HOADON *q = NhanVien.NV[t]->HD;
			struct DATA_NHANVIEN *p = NhanVien.NV[t];
			for (q; q != NULL ; q = q->pNext){
				
				for ( int i = 0; i < Sohoadoncanin;i++ ){
				if ((Compare_Date(q->DATA_HD.ngaylap, NgayDau) == 1 || Compare_Date(q->DATA_HD.ngaylap, NgayDau) == 0) && (Compare_Date(q->DATA_HD.ngaylap, NgayCuoi) == -1 || Compare_Date(q->DATA_HD.ngaylap, NgayDau) == 0)){
					
					if (TriGia[i] == q->DATA_HD.TriGia){
						gotoxy(22,10+dong);
						cout << 	q->DATA_HD.SoHD;
						gotoxy(35,10+dong);
						cout <<		q->DATA_HD.ngaylap.ngay <<"/"<< q->DATA_HD.ngaylap.thang <<"/"<<q->DATA_HD.ngaylap.nam;
						gotoxy(52,10+dong);
						cout << q->DATA_HD.loai;
						gotoxy(63,10+dong);
						cout << p->HO << " " << p->TEN;
						gotoxy(100,10+dong);
					//	cout << fixed << setprecision(0) << NhanVien.NV[t].HD->DATA_HD.TriGia ;
						Print_Number_With_point (q->DATA_HD.TriGia);
						dong ++;
						break;
					}}
				}
			}
		}					
					
	Sohoadoncanin = 0;	
	TriGia[100] = 0;		
//	Read_File_HD_Add_NV(filein1,NhanVien);
	//trasever_case_8(NhanVien);	
	/////////////////////////////////////////
		while (true){
		if (kbhit){
		char input1 = getch();
		if (input1 == 27)
		{
		system("cls");
		menu();
		break;
	    }
				  }	
	// thuc hien case 8
	
	
		
				  
				  
				  
				  
				  
				  
	}
}
int Search_VT_Case9(struct List_VT_case9 VTC9,string s){
	
	for(int i = 0; i < VTC9.size;i++){
		if(VTC9.DATA[i].MAVT == s)
		return i;
	}
	return -1;
}
int Pos_Empty_VTC9(struct List_VT_case9 VTC9){
	for (int i = 0; i < VTC9.size;i++){
		if (VTC9.DATA[i].MAVT.empty())
		return i;
	}
	return -1;
}
int Pos_Empty_TriGia_VTC9(struct List_VT_case9 VTC9){
	for (int i = 0; i < VTC9.size;i++){
		if (VTC9.DATA[i].DoanhThu == 0)
		return i;
	}
	return -1;
}

void Traverse_Tree_Prt_DATA(Tree T,struct List_VT_case9 &VTC9){
		if (T != NULL)
	{
		VTC9.DATA[Pos_Empty_VTC9(VTC9)].MAVT = T->DATA.MaVT;
		Traverse_Tree_Prt_DATA(T->pLeft,VTC9);
		Traverse_Tree_Prt_DATA(T->pRight,VTC9);
	}
}
int Prt_Case9(Tree T,string s,int dong){
		if (T == NULL)
	 {
	 	
		return 0;
		}
     
     if (Cut_enter(T->DATA.MaVT ) > s) {
        if(Prt_Case9(T->pLeft,s,dong) == 1)
			return 1;
		else return 0;	
	 }
     else if (Cut_enter(T->DATA.MaVT ) < s){
        if(Prt_Case9(T->pRight,s,dong) == 1)
			return 1;
		else return 0;
      	
	 }
	
	 else{
			gotoxy(22,10+dong);
			cout << 	T->DATA.MaVT;
			gotoxy(35,10+dong);
			cout <<	T->DATA.DonViTinh	;
			gotoxy(52,10+dong);
			cout << T->DATA.SoLuongTon;
			gotoxy(63,10+dong);
			cout << T->DATA.TenVatTu;
			gotoxy(100,10+dong);
				 
	 }
	
}
void draw_case9(NHANVIEN NhanVien){
	struct List_VT_case9 VTC9;
	ShowConsoleCursor(true);
//	Write_File_HD_CTHD(fileout1,NhanVien);	
	color_set();
	system("cls");
	SetBGColor(15);
	gotoxy(17,7);
	cout << string(100, char(219));
	for (int i = 7; i < 30; i++) {
		gotoxy(17, i);
		cout << char(219);
	
	}
	gotoxy(17, 30);
	cout << string(100, char(219)) << endl;
	for (int i = 7;i <= 30;i++){
		gotoxy(117,i);
		cout << char(219);
	}
	gotoxy(44,3);
	cout <<"   BANG LIET KE 10 VAT TU CO DOANH THU CAO NHAT ";
	gotoxy(48,4);
//	cout <<"TU NGAY:|   /   /  ";
	
	gotoxy(68,4);
//	cout <<"| DEN NGAY: |   /   /  ";
	gotoxy(92,4);
//	cout <<"|";
	gotoxy(18,8);
	cout <<"  MA VT	 |	DVI TINH | SL  TON |		 TEN VAT TU     	| TRI GIA VAT TU  ";
	gotoxy(18,9);
	cout <<"--------------------------------------------------------------------------------------------------";
	
	
	gotoxy(55,32);
	cout <<"*NHAN ESC DE TRO VE MENU\n";
	gotoxy(33,4);
	for (int i =8; i<30;i++){
		gotoxy(33,i);
		cout <<"|";}
	gotoxy(49,4);
    for (int i =8; i<30;i++){
		gotoxy(49,i);
		cout <<"|";
	}
	gotoxy(59,4);
	for (int i =8; i<30;i++){
		gotoxy(59,i);
		cout <<"|";}
	gotoxy(96,4);
	for (int i =8; i<30;i++){
		gotoxy(96,i);
		cout <<"|";}
	gotoxy(48,4);
	cout <<"TU NGAY:|   /  /   ";
	
	gotoxy(68,4);
	cout <<"| DEN NGAY: |   /  /    ";		
	struct ngaylap NgayDau;
	struct ngaylap NgayCuoi;
	Input_Case_7(NhanVien,NgayDau,NgayCuoi);	
	
// duyet cay in MAVT vao struct DATA.........
		
	Traverse_Tree_Prt_DATA(T,VTC9);

		for ( int t = 0; t < Pos_Empty_NV(NhanVien);t++){
			struct HOADON *q = NhanVien.NV[t]->HD;
			struct DATA_NHANVIEN *p = NhanVien.NV[t];
			for (q; q != NULL ; q = q->pNext){
				
				if(q->DATA_HD.loai == "Xuat"){
				if ((Compare_Date(q->DATA_HD.ngaylap, NgayDau) == 1 || Compare_Date(q->DATA_HD.ngaylap, NgayDau) == 0) && (Compare_Date(q->DATA_HD.ngaylap, NgayCuoi) == -1 || Compare_Date(q->DATA_HD.ngaylap, NgayDau) == 0)){
						for (int i = 0; i < q->DATA_HD.CT_HD->sizeHD;i++){
							VTC9.DATA[Search_VT_Case9(VTC9,q->DATA_HD.CT_HD->INFO[i].MAVT)].DoanhThu += q->DATA_HD.CT_HD->INFO[i].SoLuong*q->DATA_HD.CT_HD->INFO[i].DonGia;
						}
				}
				}
			}
		}
	DATA_VT_CASE9 data;
		
	for ( int i = 0 ; i < Pos_Empty_VTC9(VTC9);i++){
		
		for (int j = 0; j < Pos_Empty_VTC9(VTC9);j++){
			if (VTC9.DATA[i].DoanhThu > VTC9.DATA[j].DoanhThu ){		
				data.MAVT = VTC9.DATA[j].MAVT;
				data.DoanhThu = VTC9.DATA[j].DoanhThu;
				VTC9.DATA[j].MAVT = VTC9.DATA[i].MAVT;
				VTC9.DATA[j].DoanhThu = VTC9.DATA[i].DoanhThu;
				VTC9.DATA[i].MAVT = data.MAVT;
				VTC9.DATA[i].DoanhThu = data.DoanhThu; 			
			}
		}
	}
	
	int sovattucanin = 10;
	if (Pos_Empty_TriGia_VTC9(VTC9) <= 10)
	sovattucanin = Pos_Empty_TriGia_VTC9(VTC9);
	else {
	
		for ( int i = 9 ; i < Pos_Empty_VTC9(VTC9);i++){
			if (VTC9.DATA[i+1].DoanhThu == VTC9.DATA[9].DoanhThu)
			sovattucanin++;
		}
	}
	for (int i = 0; i < sovattucanin; i++){
		Prt_Case9(T,VTC9.DATA[i].MAVT,i);
		gotoxy(100,10+i);
		cout << VTC9.DATA[i].DoanhThu;
	}
	
//	system("cls");
//	for (int i = 0; i < Pos_Empty_VTC9(VTC9);i++){
//		cout << VTC9.DATA[i].MAVT << "\t" << VTC9.DATA[i].DoanhThu <<"\n";
//	}	
				
		while (true){
		if (kbhit){
		char input1 = getch();
		if (input1 == 27)
		{
		system("cls");
		menu();
		break;
	    }
				  }	
		}
}

bool login()
{
	system("cls") ;
	gotoxy(30, 5);
	cout << string(57, char(219));
	for (int i = 6; i < 10; i++) {
		gotoxy(30, i);
		cout << char(219);
		for (int j = 0; j < 55; j++)cout << " ";
		cout << char(219);
	}
	gotoxy(30, 10);
	cout << string(57, char(219)) << endl;
	gotoxy(33, 7);
	cout << "Username:   ";
	gotoxy(33, 8);
	cout << "Password:   ";
	gotoxy(38,13);
	cout << "*DUNG PHIM MUI TEN DE DI CHUYEN LEN XUONG";
	gotoxy(42,14);
	cout << " * NHAN ENTER DE DANG NHAP";
	gotoxy(45,7);
	
	string user_name = "", user_password = "";
	
	int user_name_index = 45;
	int user_password_index = 45;
	int start_pos = 45;
	int UserNameField = 7, UserPasswordField = 8;
	int FieldSelect = 0;
	while (true) {
		if (_kbhit()) {
			
			char user_input = _getch();
			if (user_input == -32){
			user_input = _getch();
			if (user_input == 80) {			//ARROW-DOWN is pressed
				if (FieldSelect == 1) {
					FieldSelect = 0;
					gotoxy(user_name_index, UserNameField);
				}
				else if (FieldSelect == 0) {
					FieldSelect = 1;
					gotoxy(user_password_index, UserPasswordField);
				}
			}
			else if (user_input == 72) {		//ARROW-UP is pressed
				if (FieldSelect == 1) {
					FieldSelect = 0;
					gotoxy(user_name_index, UserNameField);
				}
				else if (FieldSelect == 0) {
					FieldSelect = 1;
					gotoxy(user_password_index, UserPasswordField);
				}
			}
		}
			//Check input from keyboards is visible or not?:
			else if (Check_ASCII_words(user_input)) {
				if (FieldSelect == 1) {
					user_password += user_input;
					gotoxy(user_password_index, UserPasswordField);
					cout << "*";
					user_password_index++;
				}
				else if (FieldSelect == 0) {
					user_name += user_input;
					gotoxy(user_name_index, UserNameField);
					cout << user_name;
				}
			}
			//pop back the buffer:
			else if (user_input == 8) {		//BACKSPACES is pressed
				if (FieldSelect == 1) {
					if (!user_password.empty()) {
						//vector <string> user_password ;
						user_password.erase(user_password.begin()+user_password.size()-1);
						gotoxy(start_pos, UserPasswordField);
						cout << string(user_password.size(), '*') << ' ';
						--user_password_index;
					}
				}
				else if (FieldSelect == 0) {
					if (!user_name.empty()) {
					//	vector <string> user_name ;
						user_name.erase(user_name.begin() + user_name.size()-1);
						gotoxy(user_name_index, UserNameField);
						cout << user_name << " ";
					}
				}
			}
			else if (user_input == 13) {			//ENTER is pressed
				break;
			}
		}
    }

if (user_name == "admin" && user_password == "1097") {
		gotoxy(49, 10);
		cout << "Login successful" << endl;
		getch();
		cap_phat(NhanVien);
		Read_File_List_NV(filein,NhanVien);
		Read_File_HD_Add_NV(filein1,NhanVien);
		Creat_Tree (T);
		Read_Tree (filein,T);
		return true;
	}

	else {
		gotoxy(49, 10);
		cout << "Login error" << endl;
	
		getch();
		return false;
	}

}
void  menu(){
	ShowConsoleCursor(false);
    int x =40, y =5;
	int FieldSelect = 0;
	string Menu[9]={"1. NHAP VAT TU","2. IN DANH SACH VAT TU TON KHO","3. NHAP NHAN VIEN","4. IN DANH SACH NHAN VIEN","5. LAP HOA DON NHAP, XUAT","6. IN HOA DON THEO SO HOA DON","7. THONG KE HOA DON THEO KHOANG THOI GIAN ","8. IN 10 HOA DON CO DOANH THU CAO NHAT","9. IN 10 VAT TU VO DOANH THU CAO NHAT"};
	position vitri [9];
	gotoxy(x+14,y-2);
	cout<< "MENU";
	gotoxy(x+5,y+20);
	cout <<"*NHAN ENTER DE CHON CHUC NANG\n";
	gotoxy(x+4,y+21);
	cout <<"*NHAN ESC DE THOAT CHUONG TRINH\n";
	gotoxy(x+3,y+22);
	cout <<"*SU DUNG PHIM MUI TEN DE LUA CHON\n";
	
	for (int i= 0;i < 9;i++){
		vitri[i].x=x;
		vitri[i].y=y+i;
		gotoxy(vitri[i].x,vitri[i].y);
		cout << Menu[i];
		}
		
	gotoxy (vitri[0].x,vitri[0].y);
	cout<< Menu[0];
	while (true){
	 if(kbhit){
		 char input = getch();
		 if (input == -32){
		 	input = getch();
		 	switch (input){
		 		case 80 : {
		 			 gotoxy(vitri[FieldSelect].x,vitri[FieldSelect].y);
		 			 SetBGColor(15);
					 cout <<Menu[FieldSelect];
                     FieldSelect++;
                     if(FieldSelect > 8){
                     	FieldSelect = 0;
					 }
					 gotoxy(vitri[FieldSelect].x,vitri[FieldSelect].y);
					 SetBGColor(light_cyan);   //light_cyan
					 cout <<Menu[FieldSelect]; 
					 
					break;
				 } 
				case 72: {
					gotoxy(vitri[FieldSelect].x,vitri[FieldSelect].y);
		 			 SetBGColor(15);
					 cout <<Menu[FieldSelect];
                     FieldSelect--;
                     if(FieldSelect < 0){
                     	FieldSelect = 8;
					 }
					 gotoxy(vitri[FieldSelect].x,vitri[FieldSelect].y);
					 SetBGColor(light_cyan);
					 cout <<Menu[FieldSelect]; 
					break;
				}
				
				case 77:{
					break;
					}
			}
		}
			else if(input == 13){
				
				
				break;
	
			}
				else if(input ==27)
				{
					SetBGColor(light_cyan);
					system("cls");
					//SetBGColor(light_cyan); 
					//color_set();
					Free_Memory(NhanVien);
					gotoxy(45,5);
					cout << " Product of NghiaLe Student of PTIT";
					gotoxy(51,6);
					cout <<"supplies manage ver1.0";
					string thanks[30]= {"THANKS","FOR","USING","MY","PROGRAM"};
					string GoodBye[20] ={"G","O","O","D",".",".","B","Y","E"," ","!","!"};
					gotoxy(47,9);
					for (int i;i <=16; i++){
						cout << thanks[i] <<"  ";
						Sleep(100);
				    }   
					gotoxy(56,11);	
					for (int i=0;i <=16; i++){
						cout << GoodBye[i];
						Sleep(100);
					}
					
				while(true){
				}
				}	
						}
					}
				
				switch(FieldSelect) {
						case 0: {	
						gotoxy(x+5,y+10);
						gotoxy(x+5,y+10); "ban chon chuc nang 1";		// noi thuc hien chuc nang 1
						draw_case1();
						
					
							break;
						}
						case 1: {
						gotoxy(x+5,y+11);
						cout << "ban chon chuc nang 2";		// noi thuc hien chuc nang 2
						draw_case2();	
					
							break;
						}
						case 2: {
						gotoxy(x+5,y+12);
						cout << "ban chon chuc nang 3";		// noi thuc hien chuc nang 3
						draw_case3();	
					
							break;
						}
						case 3: {
						gotoxy(x+5,y+13);
						cout << "ban chon chuc nang 4";		// noi thuc hien chuc nang 4
						draw_case4();	
					
							break;
						}
						case 4: {
						gotoxy(x+5,y+14);
						cout << "ban chon chuc nang 5";		// noi thuc hien chuc nang 5
						draw_case5();
							break;
						}
						case 5: {
						gotoxy(x+5,y+15);
						cout << "ban chon chuc nang 6";		// noi thuc hien chuc nang 6
						system("cls");
						draw_case6();
							break;
							
						}
						case 6: {
						gotoxy(x+5,y+16);
						cout << "ban chon chuc nang 7";		// noi thuc hien chuc nang 7
						draw_case7();	
					
							break;
						}
						case 7: {
							gotoxy(x+5,y+17);
						//	cout << "ban chon chuc nang 8";		// noi thuc hien chuc nang 8
							draw_case8();
						/*(	system("cls");
						for ( int i = 0; i < Pos_Empty_NV(NhanVien);i++){
							cout << "---------------------------------------------------------------------------------------------------------------\n";

							cout << NhanVien.NV[i].MANV << " "<< NhanVien.NV[i].HO << " "<< NhanVien.NV[i].TEN << " "<< NhanVien.NV[i].PHAI << "\n";
							cout << "--------------------------------------------------------------------------------------------------------------\n";
							for (NhanVien.NV[i].HD; NhanVien.NV[i].HD != NULL ; NhanVien.NV[i].HD = NhanVien.NV[i].HD->pNext){
								cout << NhanVien.NV[i].HD->DATA_HD.loai << " " <<NhanVien.NV[i].HD->DATA_HD.SoHD << " "<<NhanVien.NV[i].HD->DATA_HD.ngaylap.ngay << "/" <<NhanVien.NV[i].HD->DATA_HD.ngaylap.thang<< "/" << NhanVien.NV[i].HD->DATA_HD.ngaylap.nam<< "\n";
								for (int j = 0;j < Pos_Empty_CTHD(NhanVien.NV[i].HD->DATA_HD.CT_HD);j++){
									cout << NhanVien.NV[i].HD->DATA_HD.CT_HD->INFO[j].MAVT << " " <<NhanVien.NV[i].HD->DATA_HD.CT_HD->INFO[j].SoLuong<< " "<<NhanVien.NV[i].HD->DATA_HD.CT_HD->INFO[j].DonGia << "\n";
								}
							}	
						}
				//		int i = 0;
				//		int j = 0;    
				//		cout << NhanVien.NV[i].HD->DATA_HD.CT_HD->INFO[j].MAVT << " " <<NhanVien.NV[i].HD->DATA_HD.CT_HD->INFO[j].SoLuong<< " "<<NhanVien.NV[i].HD->DATA_HD.CT_HD->INFO[j].DonGia << "\n";
*/						while (true){
								if (kbhit){
								
								char input1 = getch();
								if (input1 == 27)
								{
									system("cls");	
									menu();
									break;
	    						}
				  				}	
						}
							break;
						}
						case 8:{
							//draw_case9(NhanVien); // chuc nang 9
								color_set();
	system("cls");
	SetBGColor(0);
	gotoxy(5,2);
	cout << string(80, char(219));
	for (int i = 3; i < 25; i++) {
		gotoxy(5, i);
		cout << char(219);
	
	}
	gotoxy(5, 25);
	cout << string(80, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(85,i);
		cout << char(219);
	}
	gotoxy(6,3);
	SetBGColor(15);
	cout <<" MA VAT TU |        	 TEN VAT TU 	      | DON VI TINH | SO LUONG TON  ";
	gotoxy(6,4);
	cout <<"------------------------------------------------------------------------------";
	gotoxy(55,28);
	cout <<"*NHAN ESC DE TRO VE MENU\n";
	gotoxy(54,29);
	cout <<"*NHAN ENTER DE CHON CHUC NANG\n";
	gotoxy(53,30);
	cout <<"*SU DUNG PHIM MUI TEN DE LUA CHON\n";
	gotoxy(87,2);
	cout << string(41, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(87,i);
		cout << char(219);}
	gotoxy(87,25);
	cout << string(41, char(219)) << endl;
	for (int i = 2;i <= 25;i++){
		gotoxy(128,i);
		cout << char(219);
	}
	gotoxy(100,3);
	cout <<"BANG HIEU CHINH";
	gotoxy(88,4);
	cout << "----------------------------------------";
	gotoxy(17,4);
	for (int i =3; i<25;i++){
		gotoxy(17,i);
		cout <<"|";}
	gotoxy(54,4);
	for (int i =3; i<25;i++){
		gotoxy(54,i);
		cout <<"|";
	}
	gotoxy(68,4);
	for (int i =3; i<25;i++){
		gotoxy(68,i);
		cout <<"|";}
	gotoxy(90,6);	
	cout << "MA VT      [                         ]";
	gotoxy(90,9);
	cout << "TEN VT     [                         ]";
	gotoxy(90,12);
	cout << "DVI TINH   [                         ]";
	gotoxy(90,15);
	cout << "SLUONG TON [                         ]";
							break;
						}
						
			}
				}
			
				

