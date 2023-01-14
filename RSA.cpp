#include <bits/stdc++.h>

using namespace std;

int gcd(int x,int y) {
    int rem=0;
    while(y!=0) {
        rem=x%y;
        x=y;
        y=rem;
    }
    return x;
}



int calculatePublicKey(int e,int phin) {
    while(e<phin) {
        if(gcd(e,phin)==1) {
            return e;
        }
        else {
            e++;
        }
    }
    return 2;
}

int calculatePrivateKey(int d,int e,int phin) {
    while(1) {
        if(fmod(d*e,phin)==1) {
            return d;
        }
        else {
            d++;
        }
    }
}

int main() {
    int p,q,e,d,phin,n;
    e=2;
    //p and q are publicly known
    cout<<"enter the values of p,q:"<<endl;
    cin>>p>>q;
    
    //calculating phin and n
    phin=(p-1)*(q-1);
    n=p*q;
    
    //calculating public key e
    e=calculatePublicKey(e,phin);
    d=e;
    
    //calculating private key d
    d=calculatePrivateKey(d,e,phin);
    
    //plaintext
    long long int m=0;
    cout<<"enter plain text:"<<endl;
    cin>>m;
    
    //ciphertext
    long long int c=fmod(pow(m,e),n);
    
    //decryption
    long long int dc=fmod(pow(c,d),n);
    
    //printing values
    cout<<"PlainText:"<<" "<<m<<endl;
    cout<<"PublicKey:"<<" "<<e<<endl;
    cout<<"PrivateKey:"<<" "<<d<<endl;
    cout<<"CipherText"<<" "<<c<<endl;
    cout<<"DecryptedData"<<" "<<dc<<endl;
    return 0;
    
}
