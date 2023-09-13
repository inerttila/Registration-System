#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 100
#define filename "inertprojekt.txt"

using namespace std;

struct qytetaret {
    int numri;
    char emri[20];
    int gjendja;
    char mbiemri[20];
    int  ID;
    char adresa[50];
    int numri_tel;
} rregjistrimi[MAX];

int pozicionimi = 0;

FILE* f;

int gjej_qytetar(int numri);
void menu(void);
void rregjistro(void);
void modifiko(void);
void kerko(void);
void kerko_id(void);
void afisho(void);
void rradhit(void);
void ruaj(void);
void lexo(void);

int main() {
    if (!(f = fopen(filename, "r"))) {
        f = fopen(filename, "w");
    }
    lexo();

    int opsioni;
    menu();

    cout << "\nZgjidhni nje opsion nga menu: \n";
    cin >> opsioni;

    while (1) {
        switch (opsioni) {
            case 1:
                system("cls");
                menu();
                rregjistro();
                break;
            case 2:
                system("cls");
                menu();
                modifiko();
                break;
            case 3:
                system("cls");
                menu();
                kerko();
                break;
            case 4:
                system("cls");
                menu();
                kerko_id();
                break;
            case 5:
                system("cls");
                menu();
                afisho();
                break;
            case 6:
                system("cls");
                menu();
                rradhit();
                break;
            case 7:
                system("cls");
                menu();
                ruaj();
                break;
            case 8:
                return 0;
            default:
                cout << "Opsioni i zgjedhur nuk eshte i sakte.";
                break;
        }
        cout << "\n\nZgjidhni nje opsion tjeter:";
        cin >> opsioni;
    }
}

//-----------------------------------------------------------------

void menu(void)
{
	cout<<"MENU";
	cout<<"\n------------------------------";
	cout<<"\n1.Regjistro nje qytetar te ri.\n";
	cout<<"\n2.Modifiko te dhenat e nje qytetari.\n";
	cout<<"\n3.Kerko sipas emrit.\n";
	cout<<"\n4.Kerko sipas ID.\n";
	cout<<"\n5.Afisho te dhenat e ruajtura me pare.\n";
	cout<<"\n6.Rradhit qytetaret sipas emrit.\n";
	cout<<"\n7.Ruaj te dhenat ne file.\n";
	cout<<"\n8.Dil nga programi.\n";
}

int gjej_qytetar(int numri)
{
	int i;
	for(i=0;i<pozicionimi;i++)
	{
		if(rregjistrimi[i].ID==numri)
		{

			return i;
		}
	}

return -1;

}

//-------------------------------------------------------------------

void rregjistro(void)
{
	cout<<"\n\nRregjistro nje qytetar te ri";
	cout<<"\n------------------------------\n";

	if(pozicionimi==MAX)
	{
        cout<<"Rregjistri eshte i mbushur, nuk kemi vend per qytetar tjeter.";
        return;
	}

	int ID;
	cout<<"jepni ID e qytetarit qe deshironi te shtoni:\n";
	cin>>ID;

	int index=gjej_qytetar(ID);
	if(index>=0)
	{
        cout<<"Ky qytetar ekziston. Nuk lejohet qe ta shtoni serish.";
        return;
	}
	else
	{
        rregjistrimi[pozicionimi].ID=ID;

        cout<<"Shkruaj emrin e qytetarit : ";
        cin>>rregjistrimi[pozicionimi].emri;
        cout<<"Shkruaj mbiemrin e qytetarit  : ";
        cin>>rregjistrimi[pozicionimi].mbiemri;
        cout<<"Shkruaj adresen e qytetarit : ";
        cin>>rregjistrimi[pozicionimi].adresa;
        cout<<"Shkruaj numrin e telefonit te qytetarit :";
        cin>>rregjistrimi[pozicionimi].numri_tel;


        pozicionimi++;

        cout<<"\nQYTETARI U SHTUA!";
	}
}

//-------------------------------------------------------------------------------------

void modifiko(void)
{
	cout<<"\n\nMODIFIKIMI I NJE QYTETARI";
	cout<<"\n------------------------------\n";
	int ID;
	cout<<"\nJepni ID e qytetarit qe doni te modifikoni:\n";
	cin>>ID;

	int i=gjej_qytetar(ID);
	if(i>=0)
	{

        int ndryshimi;
        cout<<"Jepni emrin e ri te qytetarit:\n";
        cin>>rregjistrimi[i].emri;
        cout<<"Jepni mbiemrin e ri te qytetarit:\n";
        cin>>rregjistrimi[i].mbiemri;
        cout<<"Jepni numrin e ri te telefonit te  qytetarit:\n";
        cin>>rregjistrimi[i].numri_tel;
        cout<<"Jepni adresen e re te qytetarit:\n";
        cin>>rregjistrimi[i].adresa;

        cout<<"\nQYTETARI U NDRYSHUA!";
	}
        else
	{
        cout<<"Ky qytetar me kete ID nuk ekziston!\n";
        return;
	}
}

//--------------------------------------------------------------------------

void kerko(void)
{
	char emri[20];
	int i;
	printf("Shkruaj emrin qe do te kerkosh:");
	scanf(" %s",emri);

	for(i=0;i<pozicionimi;i++)
	{
		if(strcmp(rregjistrimi[i].emri,emri)==0)
		{
			printf("U gjet!");
			return;
		}

	}

		printf("Nuk gjendet!");

}

//------------------------------------------------------------------------


void kerko_id(void)
{
	cout<<"\n\nKERKIMI I NJE QYTETARI";
	cout<<"\n------------------------------\n";

	int ID;
	cout<<"\nJepni ID e qytetetarit qe doni te kerkoni:\n";
	cin>>ID;


	int index=gjej_qytetar(ID);
	if(index>=0)

	{
	    cout<<"\nTe dhenat per qytetarin e kerkuar jane:\n";

	    cout<<"Qytetari "<<"\n";
	    cout<<"Emri: "<<rregjistrimi[index].emri<<"\n";
	    cout<<"Mbiemri: "<<rregjistrimi[index].mbiemri<<"\n";
	    cout<<"Adresa:"<<rregjistrimi[index].adresa<<"\n";
	    cout<<"Numri i telefonit :"<<rregjistrimi[index].numri_tel<<"\n";
	}
	else
	{
	    cout<<"Qytetari me  kte ID nuk ekziston.\n"<<ID;
	}
	return;
}

//---------------------------------------------------------------


void afisho(void)
{
	cout<<"\n\nAFISHIMI I QYTETARVE";
	cout<<"\n------------------------------\n";
	int i;
	for(i=0;i<pozicionimi;i++)
	    {
	        cout<<"\n_____________________________\n";
	        cout<<"Qytetari "<<"\n";
	        cout<<"Emri: "<<rregjistrimi[i].emri<<"\n";
	        cout<<"Mbiemri: "<<rregjistrimi[i].mbiemri<<"\n";
	        cout<<"ID :"<<rregjistrimi[i].ID<<"\n";
	        cout<<"Adresa:"<<rregjistrimi[i].adresa<<"\n";
	        cout<<"Numri i telefonit :"<<rregjistrimi[i].numri_tel<<"\n";
	        cout<<"_____________________________\n\n";
	    }
}

//-----------------------------------------------------------

void rradhit(void)
{
   int i , j;
   struct qytetaret temp;

   for(i=0;i<pozicionimi;i++)
   {
       for(j=i+1;j<pozicionimi;j++)
           {
               if(strcmp(rregjistrimi[i].emri,rregjistrimi[j].emri)>0)
                   {
                       temp=rregjistrimi[i];
                       rregjistrimi[j]=rregjistrimi[i];
                       rregjistrimi[j]=temp;
                   }

           }
   }

}

//----------------------------------------------------------

void ruaj ()
{
	f=fopen(filename,"w");
	fprintf(f, "%d\n",pozicionimi);
	int i;
	for(i=0; i<pozicionimi; i++)
	{
	       fprintf(f, "%s", rregjistrimi[i].adresa);
	       fprintf(f, "%s", rregjistrimi[i].emri);
	       fprintf(f, "%s", rregjistrimi[i].mbiemri);
	       fprintf(f, "%d", rregjistrimi[i].gjendja);
	       fprintf(f, "%d", rregjistrimi[i].ID);
	       fprintf(f, "%d", rregjistrimi[i].numri_tel);
	       fprintf(f, "%d\n", rregjistrimi[i].numri);
	}
	fclose(f);
}

//-----------------------------------------------------------

   void lexo ()
{
	f=fopen(filename,"r");
	fscanf(f,"%d", &pozicionimi);
	int i;
	for(i=0; i<pozicionimi; ++i)
	{
	       fscanf(f, "%s", rregjistrimi[i].adresa);
	       fscanf(f, "%s", rregjistrimi[i].emri);
	       fscanf(f, "%s", rregjistrimi[i].mbiemri);
	       fscanf(f, "%d", &rregjistrimi[i].gjendja);
	       fscanf(f, "%d", &rregjistrimi[i].ID);
	       fscanf(f, "%d", &rregjistrimi[i].numri_tel);
	       fscanf(f, "%d", &rregjistrimi[i].numri);
	   }
	   fclose(f);
}
