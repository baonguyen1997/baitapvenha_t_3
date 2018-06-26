#include<iostream>
#include<string>
using namespace std;
#include<fstream>
#include<stdio.h>
#include<vector>
/*
class Dangnhap {
private:
	string hoten;
	string ngaysing;
	string noio;
	string gt;
	string thongtin;
public:

		   // Print employee information to the screen 
		   void nhap(){
			   cout << "Nhap ho va ten "; std::cin >> hoten;
			   cout << "ngay sinh  "; std::cin >> ngaysing;
			   cout << "noi o hien tai "; std::cin >> noio;
			   cout << "gioi tinh "; std::cin >> gt;
			   cout << "thong tin them "; std::cin >> thongtin;

		   }
		   void print()    {    
			   std::cout << "Name: " << hoten << "  : " << ngaysing << "  : " << noio << "  : " << gt << "  : " << thongtin << '\n';
		//	   std::cout << "Name: " << m_name << "  Id: " << m_id << "  Wage: $" << m_wage << '\n';
		   }
};*/
struct thongtinnguoidung
{
	string hoten;
	string ngaysinh;
	string noio;
	string gt;
	string thongtin;
	string tin;
	string cttinnhan;
	// mang mon hoc 

};
typedef struct thongtinnguoidung ThongTinNguoiDung;
void Dovfile(ifstream &thongtin, ThongTinNguoiDung &sv)
{
	getline(thongtin, sv.hoten, ','); cout << sv.hoten << "\n";
	getline(thongtin, sv.ngaysinh, ','); cout << sv.ngaysinh << "\n";
	getline(thongtin, sv.noio);	cout << sv.noio << "\n";
	getline(thongtin, sv.gt, ','); cout << sv.gt << "\n";
	getline(thongtin, sv.thongtin, '.'); cout << sv.thongtin << "\n";
	cout << "*************************************";

};
void hienthi(ifstream &thongtin, vector< ThongTinNguoiDung>  &dssv){
	while (thongtin.eof() == false)
	{
		ThongTinNguoiDung sv;
		Dovfile(thongtin, sv);
	}
	//cout << sv.hoten;
};/*
class TiNhan
{
public:
private:
public:
*/
	void tinnhangui(ifstream listtinnhan){
	string tin;
	while (listtinnhan.eof() == false)
	{
		getline(listtinnhan, tin, '.');
		cout << tin<<"\n----------------------\n";
	}
	
};

int main() {  
	//khai báo class
	int lc;
	int chon;
	bool kt;
	string tkdn;
	string mkdn;
	string tk = "baonguyen";
	string mk ="bao";
	// in phong hiển thị lựa chon vào những thư mục rêng
	while (kt = true){
		cout << " 1 : quan ly nguoi dung \n";
		cout << " 2 : qua ly tin nhan \n";
		cout << " 3 : quan ly ban be \n";
		cout << " 4 : thoat \n";
		cout << "<---------------------------------------------------->\n";
		cin >> lc;
		switch (lc)	{
		case 1:
			cout << " 1 : dang ky \n";
			cout << " 2 : dang nhap \n";
			cout << " 3 : dang xuat \n";
			cout << " 4 : tro ve \n";
			cout << "<---------------------------------------------------->\n";
			cin >> chon;
			switch (chon){
			case 1:
				cout << "tao tai khoan :"; cin >> tk;
				cout << " tao mat khau :"; cin >> mk;
				kt = true;
				break;
			case 2:
				cout << "tai khoan :"; cin >> tkdn;
				cout << "mat khau :"; cin >> mkdn;
				if (tkdn == tk && mkdn == mk){
					ifstream thongtin;
					thongtin.open("thongtin.txt", ios_base::in);
					vector<ThongTinNguoiDung> dssv;
					hienthi(thongtin, dssv);
					thongtin.close();
				}
				else cout << "tai khoan hoac mat khau sai moi nhap lai \n";
				break;
			case 3:
				cout << "da dang xuat \n";
				kt = true;
				break;
			case 4:
				kt = true;
				break;
			default: kt = true;
				break;
			}// ket thuc vong lap swith
			break;
		case 2:
		{
				  int chon;
				  char soantin[200];
				  cout << "1 :hien thi cac tin nhan da giui\n";
				  cout << "2 :hien thi cac thong tin chi tiet cua tin nhan\n";
				  cout << "3 :giui tin nhan\n";
				  cout << "4 :thoat\n";
				  cout << "<---------------------------------------------------->\n";

				  cin >> chon;
				  switch (chon)
				  {
				  case 1:{
							 string tingui;
							 cout << "danh sach tin nhan da gui";
							 ifstream listtinnhan;
							 listtinnhan.open("nhantin.txt", ios_base::in);
							 while (listtinnhan.eof() == false)
							 {
								 listtinnhan >> tingui;
								 if (tingui == ".")
								 {
									 cout << "\n";
								 }
								 cout << tingui;
								 cout << "*************************************";

							 }
							 listtinnhan.close();
							 break;
				  }
				  case 2:{
							 string ctgui;
							 cout << "danh sach nguoi da gui tin nhan";
							 ifstream cttinnhan;
							 cttinnhan.open("ctgui.txt", ios_base::in);
							 while (cttinnhan.eof() == false)
							 {
								 cttinnhan >> ctgui;
								 if (ctgui == ".")
								 {
									 cout << "\n";
								 }
								 cout << ctgui; 
								 cout << "*************************************";
							 }
							 cttinnhan.close();
							 break;
				  }
				  case 3:{
							 int j;
							 string tenguoigiui;
							 ofstream tinnhan;
							 tinnhan.open("nhantin.txt", ios_base::app);
							 ofstream ctnguoigui;
							 ctnguoigui.open("ctgui.txt", ios_base::app);
							 cout << "nhap thong tin nguoi giui\n";
							 cin >> tenguoigiui;

							 if (tenguoigiui == ""){
								 cout << "khong duoc de trong thong tin nguoi giui:"; chon = 3;
							 }
							 else{
								 cout << "soan tin nhan\n";
								 ctnguoigui << tenguoigiui << " .\n";
							 }
							 ctnguoigui.close();
							 cin >> soantin;
							 tinnhan << soantin << " " << ".\n";
							 tinnhan.close();

							 break;
					}

				  case 4:{
							 kt = true;
							 break;
				  }
				  default:
					  break;
				  }
				  break;
		}

		case 3:{
				   cout << "1 : them ban be\n";
				   cout << "2 : hien thi danh sach ban be\n";
				   cout << "3 : danh sach block\n";
				   cout << "4: tro lai\n";
				   cout << "<---------------------------------------------------->\n";

				   int ban;
				   cin >> ban;
				   switch (ban)
				   {
				   case 1:{
							  string banbenew;
							  string ss;
							  cout << "them ban be\n";
							  ofstream themban;
							  themban.open("banbe.txt", ios_base::app);
							  cin >> banbenew;
							  ifstream sosanh;
							  sosanh.open("banbe.txt", ios_base::in);
							  while (sosanh.eof() == false)
							  {
								  sosanh >> ss;
								  if (ss == ".")
								  {
									  cout << "\n";
								  }
								  if (ss == banbenew)
								  {
									  cout << "da co ban" << banbenew << " roi them ban khac \n";
								  }
								   themban << banbenew << " .\n";
								  
							  }
							  sosanh.close();
							  themban.close();
							  break;
				   }
				   case 2:
				   {
							 string hienthiban;
							 cout << "danh sach ban be :\n";
							 ifstream dsban;
							 dsban.open("banbe.txt", ios_base::in);
							 while (dsban.eof() == false)
							 {
								 dsban >> hienthiban;
								 if (hienthiban == "")
								 {
									 cout << "khong co ban be\n";
								 }
								 if (hienthiban == ".")
								 {
									 cout << "\n";
								 }
								 cout << hienthiban;
								 cout << "*************************************";

							 }
							 dsban.close();
							 break;
				   }
				   case 3:{
							  string banblock;
							  cout << "danh sach bi block\n";
							  ofstream block;
							  block.open("block.txt", ios_base::out);
							  block.close();
							  ifstream dsblock;
							  dsblock.open("block.txt", ios_base::in);
							  while (dsblock.eof() == false)
							  {
								  dsblock >> banblock;
								  if (banblock == "")
								  {
									  cout << "khong co ban bi block\n";
								  }
								  if (banblock == ".")
								  {
									  cout << "\n";
								  }
								  else
								  {
									  cout << banblock;
									  cout << "*************************************";

								  }
							  }

							  dsblock.close();
							  break;
				   }
				   case 4:
					   kt = true;
					   break;
				   default:
					   break;
				   }
				   break;
		}
		case 4:
			cout << "hen gap lai dip khac \n";
			kt = false;
			return 0;
			break;

		default:kt = true;
			break;
		}
	}

	system("pause");
	return 0;
}