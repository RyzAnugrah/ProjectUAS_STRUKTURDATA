/*
Nama Program    : DRIVE-THRU BURGER KWEEN
Nama            : Rizky Anugerah & Mohamad Dhikri
NPM             : 140810180049 & 140810180075 
Kelas           : A
Deskripsi       : Kasir Restoran Burger Kween dengan Stack & Queue
*********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// =================================== QUEUE ===================================
struct elmt
{
	int num;
	elmt *next;
};
typedef elmt *pointer;
typedef pointer list;

struct Queue
{
	list head;
	list tail;
};
Queue Q;

void createQueue(Queue &Q)
{
	Q.head = NULL;
	Q.tail = NULL;
}

void createElmt(pointer &pBaru)
{
	pBaru = new elmt;
	cout << "Masukkan Nomor Menu : ";
	cin >> pBaru->num;
	pBaru->next = NULL;
}

void insertQueue(Queue &Q, pointer pBaru)
{
	if (Q.head == NULL && Q.tail == NULL)
	{
		Q.head = pBaru;
		Q.tail = pBaru;
	}
	else
	{
		Q.tail->next = pBaru;
		Q.tail = pBaru;
	}
}

void deleteQueue(Queue &Q, pointer pHapus)
{
	if (Q.head == NULL && Q.tail == NULL)
	{
		pHapus = NULL;
	}
	else
	{
		pHapus = Q.head;
		Q.head = Q.head->next;
		pHapus->next = NULL;
	}
}

void traversalQueue(Queue Q, int &frekwen, int &key, int nilai, int &harga)
{
	pointer pBantu;
	frekwen = 0;

	if (Q.head == NULL && Q.tail == NULL)
	{
		cout << "";
	}
	else
	{
		pBantu = Q.head;
		do
		{
			if (pBantu->num == key)
			{
				frekwen += 1;
			}
			pBantu = pBantu->next;
		} while (pBantu != NULL);
	}

	if (frekwen == 0)
	{
		frekwen = 0;
	}
	cout << frekwen << " " << endl;
	harga = frekwen * nilai;
	cout << "Harga : " << harga << endl;
}

// =================================== STACK ===================================
struct List
{
	int price;
	List *next;
};
typedef List *pointerS;
typedef pointerS Stack;

void createStack(Stack &Top)
{
	Top = NULL;
}

void createElmtS(pointerS &pBaru, int p)
{
	pBaru = new List;
	pBaru->price = p;
	pBaru->next = NULL;
}

void pop(Stack &Top, pointerS &pHapus)
{
	if (Top == NULL)
	{
		cout << "TIDAK ADA PESANAN" << endl;
		pHapus = NULL;
	}
	else if (Top->next == NULL)
	{
		pHapus = Top;
		Top = NULL;
		cout << "PESANAN AWAL BERHASIL DIHAPUS" << endl;
	}
	else
	{
		pHapus = Top;
		Top = Top->next;
		pHapus->next = NULL;
		cout << "PESANAN AWAL BERHASIL DIHAPUS" << endl;
	}
}

void push(Stack &Top, pointerS pBaru)
{
	pointerS last;
	if (Top == NULL)
		Top = pBaru;

	else
	{
		last = Top;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = pBaru;
	}
}

void traversalStack(Stack Top, int &jumlah)
{
	jumlah = 0;
	int i = 1;
	pointerS pBantu;
	
	if (Top == NULL)
	{
		cout << "TIDAK ADA PESANAN" << endl;
	}
	else
	{
		pBantu = Top;
		do
		{
			cout << "PEMBAYARAN KE-" << i << " : " << pBantu->price << endl;
			jumlah = pBantu->price;
			pBantu = pBantu->next;
			i += 1;
		} while (pBantu != NULL);
		cout << endl;
		cout << "TAGIHAN YANG DIBAYAR : " << jumlah << endl;
	}
}

void printStack(Stack Top, int &jumlah, string &username)
{
	ofstream input;
	input.open("PRINT-OUT TAGIHAN BURGER KWEEN.txt");
	jumlah = 0;
	int i = 1;
	pointerS pBantu;

	input << "==================================" << endl;
	input << "          TAGIHAN PESANAN         " << endl;
	input << "           BURGER KWEEN           " << endl;
	input << "         Bikini Bottom St.        " << endl;
	input << "==================================" << endl;
	input << "NAMA PELAYAN : " << username << endl << endl;
	if (Top == NULL)
	{
		input << "TIDAK ADA PESANAN" << endl;
	}
	else
	{
		pBantu = Top;
		do
		{
			input << "PEMBAYARAN KE-" << i << " : " << pBantu->price << endl;
			jumlah = pBantu->price;
			pBantu = pBantu->next;
			i += 1;
		} while (pBantu != NULL);
		input << endl;
		input << "TAGIHAN YANG DIBAYAR : " << jumlah << endl;
	}
	input << endl;
	input << "TERIMA KASIH TELAH DATANG" << endl;
	input << "KE BURGER KWEEN" << endl;
	input << "==================================" << endl;
	input.close();
}

int main()
{
	pointer p;
	pointerS ps;
	Stack S;
	string username, password;
	char pilih, next;
	int n, frekwen, bayar, harga, jumlah, menu;
	bayar = 0;

	awal:
	system("cls");
	cout << "==================================" << endl;
	cout << "=          WELCOME ADMIN         =" << endl;
	cout << "=          BURGER KWEEN          =" << endl;
	cout << "==================================" << endl;
	cout << "Masukkan Username	: "; cin >> username;
	cout << "Masukkan Password	: "; cin >> password;

	if (username == password)
	{
		createStack(S);
		do
		{
			system("cls");
			cout << "==================================" << endl;
			cout << "=        SELAMAT DATANG DI       =" << endl;
			cout << "=          BURGER KWEEN          =" << endl;
			cout << "==================================" << endl;
			cout << "= 1. PESAN MAKANAN               =" << endl;
			cout << "= 2. TAGIHAN PEMBAYARAN          =" << endl;
			cout << "= 3. HAPUS PESANAN AWAL          =" << endl;
			cout << "= 4. PRINT-OUT TAGIHAN           =" << endl;
			cout << "= 9. KELUAR                      =" << endl;
			cout << "==================================" << endl;

			cout << "Masukkan pilihan : "; cin >> menu;
			cout << endl;

			switch (menu)
			{
				case 1:
					do
					{
						system("cls");
						createQueue(Q);
						cout << "==================================" << endl;
						cout << "=          MENU MAKANAN          =" << endl;
						cout << "=          BURGER KWEEN          =" << endl;
						cout << "==================================" << endl;
						cout << "= 1. Cheese Burger : Rp.45.000   =" << endl;
						cout << "= 2. Double Wooper : Rp.50.000   =" << endl;
						cout << "= 3. Burger Deluxe : Rp.49.000   =" << endl;
						cout << "= 4. Kraby Patty   : Rp.70.000   =" << endl;
						cout << "= 5. Chum Plankton : Rp. 0       =" << endl;
						cout << "==================================" << endl;
						cout << endl;
						cout << "Masukkan Banyak Pemesanan : "; cin >> n;

						for (int i = 0; i < n; i++)
						{
							createElmt(p);
							insertQueue(Q, p);
						}
						cout << endl;

						system("cls");
						cout << "==================================" << endl;
						cout << "          DAFTAR PESANAN          " << endl;
						cout << "==================================" << endl;
						for (int i = 0; i < 6; i++)
						{
							if (i == 1)
							{
								cout << "Cheese Burger : ";
								traversalQueue(Q, frekwen, i, 45000, harga);
								bayar += harga;
							}
							else if (i == 2)
							{
								cout << "Double Wooper : ";
								traversalQueue(Q, frekwen, i, 50000, harga);
								bayar += harga;
							}
							else if (i == 3)
							{
								cout << "Burger Deluxe : ";
								traversalQueue(Q, frekwen, i, 49000, harga);
								bayar += harga;
							}
							else if (i == 4)
							{
								cout << "Kraby Patty : ";
								traversalQueue(Q, frekwen, i, 70000, harga);
								bayar += harga;
							}
							else if (i == 5)
							{
								cout << "Chum Plankton : ";
								traversalQueue(Q, frekwen, i, 0, harga);
								bayar += harga;
							}
							cout << endl;
						}
						createElmtS(ps, bayar);
						push(S, ps);
						cout << "TOTAL AKHIR PEMBAYARAN : " << bayar << endl;
						cout << "==================================" << endl << endl;
						cout << "Apakah anda ingin memesan lagi (Y/N) ? "; cin >> pilih;
					} while (pilih == 'Y' || pilih == 'y');
					break;

				case 2:
					system("cls");
					cout << "==================================" << endl;
					cout << "          TAGIHAN PESANAN         " << endl;
					cout << "==================================" << endl;
					traversalStack(S, jumlah);
					cout << "==================================" << endl;
					system("pause");
					break;

				case 3:
					system("cls");
					pop(S, ps);
					system("pause");
					break;

				case 4:
					system("cls");
					printStack(S, jumlah, username);
					cout << "TAGIHAN BERHASIL DI PRINT-OUT" << endl;
					system("pause");
					break;

				case 9:
					system("cls");
					cout << "TERIMA KASIH TELAH DATANG KE BURGER KWEEN" << endl;
					system("pause");
					return 0;
	
				default:
					cout << "INPUT SALAH" << endl;
					system("pause");
			}
		} while (next != 9);
	}
	else
	{
		cout << "USERNAME DAN PASSWORD SALAH" << endl;
		system("pause");
		goto awal;
	}
	return 0;
}
