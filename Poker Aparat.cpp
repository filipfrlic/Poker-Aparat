#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <stdio.h>


using namespace std;

int ulog;
int novac = 1000;
char ime[30];

void unos(char *znakovni_niz)
{
	cin.getline(znakovni_niz, 150);
	if (cin.gcount()==1)
	  	 cin.getline (znakovni_niz,150);
};

struct tkarte{
	int vrijednost;
	int boja;
}deck[52], trenutne_karte[5];

void bubbleSort(){
	tkarte karte;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < (4-i);j++){
			if(trenutne_karte[j].vrijednost > trenutne_karte[j+1].vrijednost){
				tkarte temp = trenutne_karte[j];
				trenutne_karte[j] = trenutne_karte[j+1];
				trenutne_karte[j+1] = temp;
			}
		}
	}
}

bool par(){
	int brojac = 0;
	for(int i = 0; i < 5; i++){
		for(int j = i+1; j < 5;j++){
			if(trenutne_karte[i].vrijednost == trenutne_karte[j].vrijednost)
			brojac++;
		}
	}
	if(brojac > 0) return true;
	else return false;
}

bool dvaPara(){
	int temp = 0;
	for(int i = 0; i < 5; i++){
		for(int j = i+1;j<5;j++){
			if(trenutne_karte[i].vrijednost == trenutne_karte[j].vrijednost)
				if(temp == 0) temp = trenutne_karte[i].vrijednost;
				else if(temp!= trenutne_karte[i].vrijednost) return true;
		}
	}
	return false;
}

bool tris(){
	int poljeTest[5];
	poljeTest[0] = 0;
	poljeTest[1] = 0;
	poljeTest[2] = 0;
	poljeTest[3] = 0;
	poljeTest[4] = 0;
	
	for(int i = 0; i < 5; i++){
		for(int j = i+1;j<5;j++){
			if(trenutne_karte[i].vrijednost == trenutne_karte[j].vrijednost) poljeTest[i]++;
		}
	}
	for(int i = 0; i <5;i++){
	if(poljeTest[i]> 1) return true;
	}
}


bool poker(){
	int poljeTest[5];
	poljeTest[0] = 0;
	poljeTest[1] = 0;
	poljeTest[2] = 0;
	poljeTest[3] = 0;
	poljeTest[4] = 0;
	
	for(int i = 0;i < 5;i++){
		for(int j = i+1; j<5;j++){
		if(trenutne_karte[i].vrijednost == trenutne_karte[j].vrijednost) poljeTest[i]++;
		}
	for(int i = 0; i < 5; i++) if (poljeTest[i] > 2) return true;
	}
}

bool skala(){
	bubbleSort();
	int brojac = 0;
	for(int i = 0; i < 4;i++){
		int sljedeca = trenutne_karte[i].vrijednost +1;
		if(sljedeca!=trenutne_karte[i+1].vrijednost) return false;
	}
	return true;
}

bool boja(){
	int brojac = 0;
	for(int i = 1;i < 5;i++){
		if(trenutne_karte[0].boja == trenutne_karte[i].boja) brojac++;
	}
	if(brojac > 3) return true;
	else return false;
}

bool fullHouse(){
	if(tris() && dvaPara()) return true;
	else return false;
}

bool skalaBoja(){
	if(skala() && boja()) return true;
	else return false;
}

bool skalaBojaDoAsa(){
	if(skala() && boja() && trenutne_karte[0].vrijednost == 10) return true;
	else return false;
}

void provjera(){
	if(skalaBojaDoAsa()){
		cout << "Skala u boji do asa!"<<endl;
		novac = novac + ulog*250;
		cout << "Dobitak: " <<ulog*250<<endl;
		return;
	}
	if(skalaBoja()){
		cout << "Skala u boji!"<<endl;
		novac = novac + ulog*50;
		cout << "Dobitak: " <<ulog*50<<endl;
		return;
	}
	if(poker()){
		cout << "Poker!"<<endl;
		novac = novac + ulog*25;
		cout << "Dobitak: "<<ulog*25<<endl;
		return;
	}
	if(fullHouse()){
		cout << "Full House!"<<endl;
		novac = novac + ulog*9;
		cout << "Dobitak: " <<ulog*9<<endl;
		return;
	}
	if(boja()){
		cout << "Boja!"<<endl;
		novac = novac + ulog*6;
		cout << "Dobitak: " <<ulog*6<<endl;
		return;
	}
	if(skala()){
		cout << "Skala!"<<endl;
		novac = novac + ulog*4;
		cout << "Dobitak: " <<ulog*4<<endl;
		return;
	}
	if(tris()){
		cout << "Tris!"<<endl;
		novac = novac + ulog*3;
		cout << "Dobitak: " <<ulog*3<<endl;
		return;
	}
	if(dvaPara()){
		cout << "Dva Para!"<<endl;
		novac = novac + ulog*2;
		cout << "Dobitak: " <<ulog*2<<endl;
		return;
	}
	if(par()){
		cout << "Par!"<<endl;
		novac = novac + ulog;
		cout << "Dobitak: "<<ulog<<endl;
		return;
	}
	else cout << endl <<"Dobitak: 0"<<endl;
}

void stvoriDeck(){
	tkarte karte;
	int brojac = 0;
	for(int i = 0; i < 5; i++){
		karte.boja = i;
		for(int j = 2; j < 16; j++){
			karte.vrijednost = j;
			deck[brojac] = karte;
		}
	}	
}

bool provjeraIstih(tkarte karte){
	for(int i = 0; i < 5; i++){
		if(karte.vrijednost == trenutne_karte[i].vrijednost && karte.boja == trenutne_karte[i].boja){
			return true;
		}
	}
	return false;
}

void pretvoriKartu(int vrijednost, int boja){
	switch(boja){
		case 1: cout << "H"; break;
		case 2: cout << "T"; break;
		case 3: cout << "K"; break;
		case 4: cout << "P"; break;
	}
	switch(vrijednost){
		case 11: cout << "J"; break;
		case 12: cout << "Q"; break;
		case 13: cout << "K"; break;
		case 14: cout << "A"; break;
	}	
}

void generatorKarata(){
	tkarte karte;
	bool iste = true;
	int n;
	for(int i = 0; i < 5; i++){
		ponovo:
			karte.boja = rand()%4 + 1;
			karte.vrijednost = rand()%13+2;
			while(provjeraIstih(karte)){
				goto ponovo;
		}
		trenutne_karte[i] = karte;
	}
}

void ispisKarata(){
	tkarte karte;
	for(int i = 0; i < 5; i++){
		pretvoriKartu(trenutne_karte[i].vrijednost, trenutne_karte[i].boja);
		if(trenutne_karte[i].vrijednost < 11)
			cout << trenutne_karte[i].vrijednost;
		cout << " ";
	}
	cout <<endl;
}

void zadrzi(){
	char karteNove[5];
	tkarte karte;
	cout << "Koje karte zelite zadrzati(d/n): ";
	unos(karteNove);
	for(int i = 0; i < 5; i++){
		if(karteNove[i] =='n' || karteNove[i] == 'N'){
			ponovo:
				karte.boja = rand()%4 + 1;
				karte.vrijednost = rand()%13 + 2;
				while(provjeraIstih(karte)) goto ponovo;
				
				trenutne_karte[i] = karte;
		}
	}
	ispisKarata();
}

void pocetniEkran(){
	cout << "Dobrodosli u igru Poker!"<<endl;
	cout << "Pocetni novac = 1000kn"<<endl<<endl;
	cout << "Upisite ime: "; unos(ime);
	cout << "Upisite ulog: "; cin >> ulog;
}

int main(){
	srand(time(0));
	stvoriDeck();
	int izbor;
	pocetniEkran();
	while(1){
		cout << "[1] VRTI\t[2] Promjena uloga\t[9] Izlaz   Izbor: ";
		cin >> izbor;
		switch(izbor){
			case 1:{
				system("cls");
				if(novac <=0){
					cout << "Ostali ste bez novca\nIGRA JE GOTOVA";
					return 0;
				}
				else if(novac < ulog){
					cout <<"Prevelik ulog!"<<endl;
					cout << "Ulog: ";
					cin >> ulog;
					system("cls");
				}
				novac = novac - ulog;
				cout << "Novac: " <<novac<<"kn"<<endl;
				cout << "Ulog: "<<ulog<<endl;
				generatorKarata();
				ispisKarata();
				zadrzi();
				provjera();
				break;
			}
			case 2:
				cout << "Ulog: ";
				cin >> ulog;
				break;
			case 9: return 0;
		}
	}
	return 0;
}
  

