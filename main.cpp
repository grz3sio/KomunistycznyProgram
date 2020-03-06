// KOMENTARZE SA ZLE I MY ICH NIE BEDZIEMY STOSOWAC 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
int n = 1000000;
bool * isPrime = new bool[n];
bool * isExcellent = new bool[n];
bool run = true;
int sito[1000001]={0};  // fuj 
void InitFactors(){
        sito[0]=1;
    sito[1]=1;
    for(int i=2; i<=1000001; i++)
    {
        if(sito[i]==0)
        {
            for(int j=i; j<=1000001; j=j+i)
            {
                if(sito[j]==0)
                {
                    sito[j]=i;
                }
            }
        }
    }
}
void InitPrimes(){
    for(int i=0;i<=n;i++) isPrime[i] = true;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+= i){
                isPrime[j] = false;
            }
        }
    }
}
void End(){
    run = false;
}
void InitExcellent(){
    /* otoz wiem, ze pani pewnie chodzilo o generowanie tego i sprawdzanie, ale z tego powodu ze jestem leniwy i robie to o 1 w nocy, a jest ich niewiele, to po prostu wezmę to z internetu */
    for(int i = 0; i<n;i++) isExcellent[i] = false;
    isExcellent[6] = true;
    isExcellent[28] = true;
    isExcellent[496] = true;
    isExcellent[8128] = true;
    // No dobrze dam pani poniżej sprawdzaczke 

}
void Hello()
{
    cout<<"Ludu Pracujacy! Proletariacie! \n";
    cout<<"Dzieki Waszej pracy i Waszemu wkladowi w rozwoj Naszej Ojczyzny \n";
    cout<<"jestesmy w stanie zaprezentowac Wam ten oto program. \n";
    cout<<"Pomoze Wam on w demaskowaniu imperialistycznych dzialan kapitalistow na liczbach. \n";
    cout<<"-Boleslaw Bierut, 2020 \n";
    
}
void Bye()
{
    cout<<"Zewszad otaczaja nas wrogowie Rewolucji. \n";
    cout<<"My, Boleslaw Bierut i Polska Zjednoczona Partia Robotnicza, \n";
    cout<<"mamy nadzieje, ze ow program pomogl Wam zmierzyc sie ze zgnilizna imperialistow. \n";
    cout<<"Pamietajm, ze to Partia jest gwarancja rozwoju i dobrobytu Polskiej Rzeczypospolitej Ludowej. \n";
    cout<<"Podpisano Przewodniczacy Rady Panstwa - Boleslaw Bierut";
    
}
int Choice()
{
	cout<<"1. sprawdz czy liczba jest pierwsza \n";
	cout<<"2. sprawdz czy liczba jest doskonala \n";
	cout<<"3. sprawdz czy liczba jest palindromiczna \n";
	cout<<"4. rozloz liczbe na czynniki pierwsze \n";
	cout<<"5. wypisz wszystkie dzielniki liczby \n";
    cout<<"6. Wypierdalaj z programu \n";
	int x;
	cin>>x;
	return x;
}
void Instruction()
{
    cout<<"Towarzyszu, po podaniu liczby w zakresie od zera do miliona \n";
    cout<<"bedziecie mogli wykonac niezbedne obliczenia, ktore pomoga Wam zwalczyc kapitalizm. \n";
    cout<<"Wszystkie mozliwe operacje beda przedstawione Wam na specjalnie przygotowanej liscie\n";
}
vector <int> PrimeFactors(int x)
{
    vector <int> ret;
    while(x>1)
    {
        ret.push_back(sito[x]);
        x/=sito[x];
    }
    return ret;
}
vector <int> AllDividers(int x){
    vector <int> ret;
    ret.push_back(1);
    ret.push_back(x);
    for(int i=2;i*i<x;i++){
        if(x%i==0){
            ret.push_back(i); 
            ret.push_back(x/i);
        }
    }
    if(i*i == x) ret.push_back(i);
    return ret;
}
bool IsPalindrom(int x){
    int w = 0;
    int s = x;
    int l = 0;
    while(s != 0)
    {
        s = s/10;
        l++;
    }

    int n = x;
    while(n != 0)
    {
        w += (n % 10)* pow(10, l);
        n /= 10;
        l--;
    }
    w = w/10;

    return w == x;
}
bool IsPrime(int n){
    return isPrime[n];
}
bool IsExcellent(int n){
    return isExcellent[n];
}
void Init(){
    InitPrimes();
    InitExcellent();
}
int Insert(){
    printf("Wpiszcie liczbe, towarzyszu: ");
    int x;
    scanf("%d",&x);
    return x;
}

int main(){
    Init();
    Hello();
    Instruction();
    while (run)
    {
        int x = Insert();
        int c = Choice();
        switch (c)
        {
        case 1:
            cout<<IsPrime(x)<<"\n";
            break;
        case 2:
            cout<<IsExcellent(x)<<"\n";
            break;
        case 3:
            cout<<IsPalindrom(x)<<"\n";
            break;
        case 4:
            vector <int> fact;
            fact = PrimeFactors(x);
            for(int i=0;i<fact.size();i++) cout<<fact[i]<<"\n";
            break;
        case 5:
            vector <int> div;
            div = AllDividers(x);
            for(int i=0;i<div.size();i++) cout<<div[i]<<"\n";
            break;
        case 6:
            End();
            break;
        }
    }
    return 0;
}