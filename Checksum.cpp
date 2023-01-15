#include <bits/stdc++.h>

using namespace std;

string onesComplement(string data) {
    for(int i=0;i<data.length();i++) {
        if(data[i]=='0') {
            data[i]='1';
        }
        else {
            data[i]='0';
        }
    }
    return data;
}

string Checksum(string data,int blockSize) {
    int n=data.length();
    int padLength=0;
    string result="";
    if((n%blockSize)!=0) {
        padLength=blockSize-(n%blockSize);
    }
    for(int i=0;i<padLength;i++) {
        data='0'+data;
    }
    for(int i=0;i<blockSize;i++) {
        result=result+data[i];
    }
    for(int i=blockSize;i<n;i=i+blockSize) {
        string nextBlock="";
        string additions="";
        int sum=0;
        int carry=0;
        for(int j=i;j<i+blockSize;j++) {
            nextBlock=nextBlock+data[j];
        }
        for(int k=blockSize-1;k>=0;k--) {
            sum=sum+(result[k]-'0')+(nextBlock[k]-'0');
            carry=sum/2;
            if(sum==0) {
                additions='0'+additions;
                sum=carry;
            }
            else if(sum==1) {
                additions='1'+additions;
                sum=carry;
            }
            else if(sum==2) {
                additions='0'+additions;
                sum=carry;
            }
            else {
                additions='1'+additions;
                sum=carry;
            }
        }
        string final="";
        if(carry==1) {
            sum=carry;
            for(int l=blockSize-1;l>=0;l--) {
                sum=sum+(additions[l]-'0');
                carry=sum/2;
                if(sum==0) {
                    final='0'+final;
                    sum=carry;
                }
                else if(sum==1) {
                    final='1'+final;
                    sum=carry;
                }
                else {
                    final='0'+final;
                    sum=carry;
                }
            }
            result=final;
        }
        else {
            result=additions;
        }
    }
    return onesComplement(result);
}


bool Checker(string sentMessage,string recievedMessage,int blockSize) {
    string senderChecksum=Checksum(sentMessage,blockSize);
    string recieverChecksum=Checksum(recievedMessage+senderChecksum,blockSize);
    
    if(count(recieverChecksum.begin(),recieverChecksum.end(),'0')==blockSize) {
        return true;
    }
    return false;
}

int main() {
    string sentMessage,recievedMessage;
    int blockSize;
    cout<<"enter the sent message(enter string of 0's and 1's):"<<endl;
    cin>>sentMessage;
    cout<<"enter the recieved message(enter string of 0's and 1's):"<<endl;
    cin>>recievedMessage;
    cout<<"enter the block size:"<<endl;
    cin>>blockSize;
    
    if(Checker(sentMessage,recievedMessage,blockSize)) {
        cout<<"No Error"<<endl;
    }
    else {
        cout<<"Error"<<endl;
    }
    return 0;
}
