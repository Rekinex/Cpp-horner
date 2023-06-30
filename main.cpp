#include<iostream>
using namespace std;

int silnia(int n)
{
    int silnia=1;
    if(n==0)
    {
        return 1;
    }
    else{
	for(int i=n;i>1;i--)
		silnia*=i;}
	return silnia;
}

void pochodna(float *A, int n,int p)
{
    int i;
    for(int j=0;j<=n;j++)
    {
        for(i=0;i<=n-j;i++)
        {
            A[i]=A[i]+(A[i-1]*p);
        }
    }
    int k=0;
    for(i=n;i>=0;i--)
    {
        //cout<<a[i]<<endl;
        A[i]*=silnia(k);
        //cout<<a[i]<<endl;
        k++;
    }
    for(i=n-1;i>= 0;i--)
    {
        cout<<n-i<<" pochodna: "<<A[i]<<endl;
    }
}

int main (){
    int n,i;
    float p,wynik;
    int wybor=1;
    while(wybor!=0)
    {
    cout<<"0-Wyjscie"<<endl;
    cout<<"1-Horner"<<endl;
    cin>>wybor;
    cout<<"Podaj stopien: "<<endl;
    cin>>n;
    float *A;
    A=new float[n+1];
    cout<<"Podaj punkt: "<<endl;
    cin>>p;
    cout<<"Podaj wspolczynniki: "<<endl;
    for (i=0; i<=n; i++)
    {
        cout<<"Podaj wspolczynnik przy potedze "<<n-i<<": ";
        cin>>A[i];
    }
    wynik=A[0];
    for (i=1; i<=n; i++)
    wynik=wynik*p+A[i];
    cout<<"Wynik: "<<wynik<<endl<<endl;
    pochodna(A,n,p);
    delete [] A;
    A=0;
    return 0;
}
}
