#include <iostream>

using namespace std;

string xor1(string a,string b) {
    string data="";
    for(int i=1;i<b.length();i++) {
        if(a[i]==b[i]) {
            data+='0';
        }
        else {
            data+='1';
        }
    }
    cout<<data<<endl;
    return data;
}

string mod2Div(string Data, string key) {
    Data=Data+string(key.length()-1,'0');
    int n=Data.length();
    int pick=key.length();
    string temp=Data.substr(0,pick);
    while(pick<n) {
        if(temp[0]=='1') {
            temp=xor1(temp,key)+Data[pick];
        }
        else {
            temp=xor1(string(key.length(),'0'),temp)+Data[pick];
        }
        pick+=1;
    }
    if(temp[0]=='1') {
        temp=xor1(temp,key);
    }
    else {
        temp=xor1(string(key.length(),'0'),temp);
    }
       return temp;
}


string mod2DivR(string Data, string key) {
    int n=Data.length();
    int pick=key.length();
    string temp=Data.substr(0,pick);
    while(pick<n) {
        if(temp[0]=='1') {
            temp=xor1(temp,key)+Data[pick];
        }
        else {
            temp=xor1(string(key.length(),'0'),temp)+Data[pick];
        }
        pick+=1;
    }
    if(temp[0]=='1') {
        temp=xor1(temp,key);
    }
    else {
        temp=xor1(string(key.length(),'0'),temp);
    }
       return temp;
}

bool encodeData(string senderData,string recieverData,string key) {
    string senderRem=mod2Div(senderData,key);
    cout<<senderRem<<endl;
    string recieverRem=mod2DivR(recieverData+senderRem,key);
    cout<<recieverRem<<endl;

    for(int i=0;i<recieverRem.length();i++) {
        if(recieverRem[i]=='1') {
            return false;
        }
    }
    return true;
}

int main() {
    string senderData,key,recieverData;
    cout<<"enter the sender data:"<<endl;
    cin>>senderData;
    cout<<"enter the reciever data:"<<endl;
    cin>>recieverData;
    cout<<"enter the key:"<<endl;
    cin>>key;

    if(encodeData(senderData,recieverData,key)) {
        cout<<"No Error"<<endl;
    }
    else {
        cout<<"error"<<endl;
    }
}
