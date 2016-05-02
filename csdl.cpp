#include<string>
#include<string.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include <iomanip>  
using namespace std;


class Zone{
		private:
		int id;
		string name;
		string diachi;
		int soluong;
		
		public:
			Zone();
			Zone(int id, string name, string diachi);
			
			int getID();
			string getName();
			string getDiaChi();
			int getSoluong();
			
			void setID(int id);
			void setName(string name);
			void setDiaChi(string diachi);
			void setSoluong(int soluong);
			
			Zone operator=(Zone z){
				this->id=z.id;
				this->name=z.name;
				this->diachi=z.diachi;
				this->soluong=z.soluong;
			}
	};
	
	Zone::Zone(){
		
	}
	
	Zone::Zone(int id, string name, string diachi){
		
	}
	
	int Zone::getID(){
		return id;
	}
	
	string Zone:: getName(){
		return name;
	}
	
	string Zone::getDiaChi(){
		return diachi;
	}
	int Zone::getSoluong(){
		return soluong;
	}
	void Zone::setDiaChi(string diachi){
		this->diachi=diachi;
	}
	
	void Zone::setID(int id){
		this->id=id;
	}
	
	void Zone::setName(string name){
		this->name=name;
	}
	
	void Zone::setSoluong(int soluong){
		this->soluong=soluong;
	}

class Parking{
	private :
		int id;
		int vexe;
		int pos;
		bool trangthai;
		int zone;
		string biensoxe;
	public :
		Parking();
		Parking(int id,int vexe, int pos, bool trangthai, int idzone, string biensoxe);
		int getvexe();
		int getID();
		int getPos();
		bool getTrangThai();
		int getZone();
		string getBiensoxe();
		
		void setID(int id);
		void setVeXe(int vexe);
		void setPos(int pos);
		void setTrangThai(bool trangthai);
		void setZone(int zone);
		void setBiensoxe(string biensoxe);
		
		Parking operator=(Parking p){
			this->id=p.id;
			this->vexe=p.vexe;
			this->pos=p.pos;
			this->trangthai=p.trangthai;
			this->zone=p.zone;
			this->biensoxe=p.biensoxe;
			return *this;
		}
};

Parking::Parking(){
}

Parking::Parking(int id, int vexe, int pos, bool trangthai, int  idzone, string biensoxe){
	this->id=id;
	this->vexe=vexe;
	this->pos=pos;
	this->trangthai=trangthai;
	this->zone=idzone;
	this->biensoxe=biensoxe;
}

int Parking:: getvexe(){
	return vexe;
}

int Parking:: getID(){
	return id;
}

int Parking:: getPos(){
	return pos;
}

bool Parking::getTrangThai(){
	return trangthai;
} 

int Parking::getZone(){
	return zone;
}

string Parking::getBiensoxe(){
	return biensoxe;
}

void Parking::setID(int id){
	this->id = id;
}

void Parking::setVeXe(int vexe){
	this->vexe = vexe;
}

void Parking::setPos(int pos){
	this->pos = pos;
}

void Parking::setTrangThai(bool trangthai){
	this->trangthai = trangthai;
}

void Parking::setZone(int zone){
	this->zone = zone;
}

void Parking::setBiensoxe(string biensoxe){
	this->biensoxe = biensoxe;
}




class QLParking{
	private:
		Parking ds[1000];
		Zone  dszone[100];
		int m;
		int nzone;
	public:
		QLParking();
	
		void addParking(Parking p);
		bool addZone(Zone z);
		bool updateParking(Parking p);
		string getNamebyidZone(int idzone){
			for(int i=0; i<nzone; i++){
				if(dszone[i].getID()==idzone){
					return dszone[i].getName()+" "+dszone[i].getDiaChi();
				}
			}
			return "?";
		}
		bool XemDanhSachViTriTrong();
		Parking getParkingBySTT(int stt);
		void TimkiemViTriXe(string biensoxe);
		void TimkiemViTriXe(int vexe);
		
		void showZone(){
			for(int i=0; i<nzone; i++){
				cout<<setw(5)<<dszone[i].getID()<<setw(20)<<dszone[i].getName()<<setw(50)<<dszone[i].getDiaChi()<<setw(10)<<dszone[i].getSoluong()<<endl;
			}
			cout<<endl;
			for(int i=0; i<m; i++){
				cout<<setw(5)<<ds[i].getID()<<setw(20)<<ds[i].getvexe()<<setw(10)<<ds[i].getPos()<<setw(10)<<ds[i].getTrangThai()<<setw(10)<<ds[i].getZone()<<setw(10)<<ds[i].getBiensoxe()<<endl;
			}
		}
		
		~QLParking();
};

QLParking::QLParking(){
	ifstream f1;
	f1.open("Zone.txt", ios::in);
	int n;
	nzone=0;
	f1>>n;
	for(int i=0; i<n; i++){
		int nso;
		f1>>nso;
		dszone[nzone].setID(nso);
		string xau;
		getline(f1,xau);
		getline(f1,xau);
		dszone[nzone].setName(xau);
		getline(f1,xau);
		dszone[nzone].setDiaChi(xau);
		f1>>nso;
		dszone[nzone++].setSoluong(nso);
	}
	f1.close();
	
	ifstream f2;
	f2.open("Parking.txt",ios::in);
	f2>>n;
	m=0;
	for(int i=0; i<n; i++){
		int so; string xau;
		f2>>so;
		ds[m].setID(so);
		f2>>so;
		ds[m].setVeXe(so);
		f2>>so;
		ds[m].setPos(so);
		f2>>so;
		bool kt=true;
		if(so==1){
			kt=true;
		}else{
			kt=false;
		}
		ds[m].setTrangThai(kt);
		f2>>so;
		ds[m].setZone(so);
		getline(f2, xau);
		getline(f2, xau);
		ds[m++].setBiensoxe(xau);
		
	}
	f2.close();
}

void QLParking::addParking(Parking p){
	bool timkiem=false;
	for (int i=0; i<m; i++){
		if(ds[i].getPos()==p.getPos() && ds[i].getZone()==p.getZone()){
			timkiem=true;
			break;
		}
	}
	if(!timkiem)ds[m++]=p;
}

bool QLParking::addZone(Zone z){
	for (int i=0; i<nzone; i++){
		if(z.getName().compare(dszone[i].getName())==0){
			cout<<"trung ten";
			return false;
		}
	}
	dszone[nzone++]=z;
	return true;
}
bool QLParking::updateParking(Parking p){
	for(int i=0; i<m; i++){
		if(ds[i].getID()==p.getID()){
			ds[i]=p;
			return true;
		}
	}
	
	return false;
}

bool QLParking::XemDanhSachViTriTrong(){
	bool kt=false;
	int vt=1;
	cout<<setw(5)<<"STT"<<setw(10)<<"Ve xe"<<setw(20)<<"Thu tu de xe"<<setw(30)<<"Vi tri de xe"<<setw(20)<<"Bien So Xe"<<endl;
	for(int i=0; i<m; i++){
		if(!ds[i].getTrangThai()){
			cout<<setw(5)<<vt++<<setw(10)<<ds[i].getvexe()<<setw(20)<<ds[i].getPos()<<setw(30)<<getNamebyidZone(ds[i].getZone())<<setw(20)<<ds[i].getBiensoxe()<<endl;
			kt=true;
		}
	}
	return kt;
}
	
Parking QLParking::getParkingBySTT(int stt){
	int vt=1;
	for(int i=0; i<m; i++){
		if(!ds[i].getTrangThai()){
			if(vt==stt)return ds[i];
		}
	}
}
	
void QLParking::TimkiemViTriXe(string biensoxe){
	for (int i=0; i<m; i++){
		if(ds[i].getTrangThai() && ds[i].getBiensoxe().compare(biensoxe)==0){
			cout<<getNamebyidZone(ds[i].getZone())<<" o cho thu "<<ds[i].getPos()<<endl;
			return;
		}
	}
	cout<<"khong co ket qua"<<endl;
}

void  QLParking::TimkiemViTriXe(int vexe){
	for (int i=0; i<m; i++){
		if(ds[i].getTrangThai() && ds[i].getvexe()==vexe){
			cout<<getNamebyidZone(ds[i].getZone())<<" o cho thu "<<ds[i].getPos()<<endl;
			return;
		}
	}	
	cout<<"khong co ket qua"<<endl;
}

QLParking::~QLParking(){
	ofstream f1;
	f1.open("Zone.txt", ios::out);
	f1<<nzone<<endl;
	for(int i=0; i<nzone; i++){
		f1<<dszone[i].getID()<<endl;
		f1<<dszone[i].getName()<<endl;
		f1<<dszone[i].getDiaChi()<<endl;
		f1<<dszone[i].getSoluong()<<endl;
	}
	ofstream f2;
	f2.open("Parking.txt", ios::out);
	f2<<m<<endl;
	for(int i=0; i<m; i++){
		f2<<ds[i].getID()<<endl;
		f2<<ds[i].getvexe()<<endl;
		f2<<ds[i].getPos()<<endl;
		int tt;
		if(ds[i].getTrangThai())tt=1;else tt=0;
		f2<<tt<<endl;
		f2<<ds[i].getZone()<<endl;
		f2<<ds[i].getBiensoxe()<<endl;
	}
	f2.close();
	f1.close();
}

int main(){
	QLParking ql;
	ql.showZone();
	int chon=0;
	char traloi='Y';
	do{
		cout<<"moi ban chon cac chuc nang sau :"<<endl;
		cout<<"1. Them xe vao"<<endl;
		cout<<"2. Lay xe ra"<<endl;
		cout<<"3. Xem cho de xe con trong"<<endl;
		cout<<"4. Tim kiem xe theo ve xe"<<endl;
		cout<<"5. Tim kiem xe theo bien so xe"<<endl;
		cout<<"6. Them cho de xe"<<endl;
		cout<<"7. Them zone"<<endl;
		cout<<"8. Thoat"<<endl;
		cout<<"Ban hay nhan mot trong 8 so de chon chuc nang"<<endl;
		cin>>chon;
		switch(chon){
			case 1:{
				if(!ql.XemDanhSachViTriTrong()){
					cout<<"het cho de xe"<<endl;
					break;
				}
				cout<<"moi ban nhap so STT cua cho trong"; 
				int stt;
				cin>>stt;
				cout<<"moi ban nhap bien so xe";
				string biensoxe;
				cin>>biensoxe;
				Parking p; 
				p=ql.getParkingBySTT(stt);
				p.setBiensoxe(biensoxe);
				p.setTrangThai(true);
				if(ql.updateParking(p)){
					cout<<"update thanh cong";
					cout<<"\nve xe cua ban la "<<p.getID()<<endl;
				}else{
					cout<<"update that bai";
				}
			}
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			default:
				break;
		}
		cout<<"Ban co muon tiep tuc khong (Y/N)";
		cin>>traloi;
		if(traloi>'Z')traloi-=32;
	}while(chon!=8 && traloi=='Y');
	return 0;
}

