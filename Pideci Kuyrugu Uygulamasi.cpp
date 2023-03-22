#include<iostream>
#include<fstream>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<conio.h>
#include<ostream>


using namespace std;

 class Musteri
 {
    
    string ad;
    string soyad;
    int adet;

    public:
    Musteri(string ad,string soyad,int adet)
    {
        this->ad = ad;
        this->soyad = soyad;
        this->adet = adet;
    }

    friend ostream& operator<<(ostream& ekran,Musteri& m) // ekrana cıktı almak icin yazdık. outputstream
    {
        ekran<<m.ad<<" "<<m.soyad<<" "<<m.adet<<" Adet Pide almak istiyor "<<endl;
        return ekran;

    }

 
 };
   
   class Pideci
   {
     
     queue<Musteri*> kuyruk;
     public:

     void pideSat()
     {
         
         if(kuyruk.empty()) // kuyruk bos mu diye kontrol ettik.
         {
         	
             cout<<"Kuyruk bos pide almayi bekleyen musteri yok"<<endl;
         }
         
         else
         {
         	
             Musteri* m = kuyruk.front();
             cout<<*m<<"Pideyi aldi"<<endl;
             kuyruk.pop();
             
         }
         

     }

     void KuyrugaGir(Musteri* m)
     {
         if(m)
         {
         	
            kuyruk.push(m);
         }
         
     }

     friend ostream& operator<<(ostream& ekran,Pideci& p);
     

   };
 
 ostream& operator<<(ostream& ekran,Pideci& p)
 {
    
    if (p.kuyruk.empty())
    {
    	
        ekran<<"Kuyruk bos pide almayi bekleyen musteri yok"<<endl;
        
    }
    else
    {
        int i;
        i=1;
        
        ekran<<"Kuyrukta bekleyen musteriler"<<endl;
        queue<Musteri*> kuyruk = p.kuyruk;
        while (!kuyruk.empty())
        
        {
        	
            Musteri *m = kuyruk.front(); // kuyruktaki ilk elemanı alıyoruz.
            ekran<<i<<"->"<<*m<<endl;
            kuyruk.pop(); // kuyruktan elemanı cıkarıyoruz
            i++;
            
        }
        

        ekran<<endl;
        
    }

    return ekran;

 }
    

int main()
{

    system("color B");
    Pideci pideci;
    Musteri m("Emir","Gurbuz",5);
    Musteri m2("Ronald","Ratzenberg",3);
    Musteri m3("Ataol","Behramoglu",2);
    Musteri m4("Suut Kemal","Yetkin",6);
    Musteri m5("Namik","Kemal",6);
    cout<<m<<endl;
    
    pideci.KuyrugaGir(&m);
    pideci.KuyrugaGir(&m2);
    pideci.KuyrugaGir(&m3);
    pideci.KuyrugaGir(&m4);
    pideci.KuyrugaGir(&m5);
    
    cout<<pideci<<endl;
    pideci.pideSat();
    cout<<pideci<<endl;
    pideci.pideSat();
    cout<<pideci<<endl;
    pideci.pideSat();
    cout<<pideci<<endl;
    pideci.KuyrugaGir(&m4);
    pideci.KuyrugaGir(&m5);
    cout<<pideci<<endl;
    pideci.pideSat();
    cout<<pideci<<endl;
    pideci.pideSat();
    cout<<pideci<<endl;



    return 0;
}
