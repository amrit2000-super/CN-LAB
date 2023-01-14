#include <bits/stdc++.h>

using namespace std;

int calculatePublicKey(int a,int k,int q) {
    return fmod(pow(a,k),q);
}

int calculateSecretKey(int K,int k,int q) {
    return fmod(pow(K,k),q);
}

int main() {
    int q,a,x,y,X,Y,K1,K2;
    //q and a are publicly known
    cout<<"enter the values of q(prime number),a(primitive root of q):"<<endl;
    cin>>q>>a;
    
    //private keys of a and b
    cout<<"enter the private keys of userA<q and userB<q respectively:"<<endl;
    cin>>x>>y;
    
    //calculating public key of userA 
    X=calculatePublicKey(a,x,q);
    
    //calculating public key of userB
    Y=calculatePublicKey(a,y,q);
    
    //secret key by userA
    K1=calculateSecretKey(Y,x,q);
    
    //secret key by userB
    K2=calculateSecretKey(X,y,q);
    
    //printing values
    cout<<"Private key of A:"<<" "<<x<<endl;
    cout<<"Public key of A:"<<" "<<X<<endl;
    cout<<"Secret Key of A:"<<" "<<K1<<endl;
    cout<<"Private Key of B:"<<" "<<y<<endl;
    cout<<"Private key of B:"<<" "<<Y<<endl;
    cout<<"Secret Key of B:"<<" "<<K2<<endl;
    return 0;
}
