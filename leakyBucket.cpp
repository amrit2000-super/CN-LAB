#include <bits/stdc++.h>

using namespace std;

int main() {
    int input_packet_size,output_packet_rate,no_of_queries,size_left,storage,bucket_size;
    storage=size_left=0;
    cout<<"enter the output packet rate:"<<endl;
    cin>>output_packet_rate;
    cout<<"enter the no of queries:"<<endl;
    cin>>no_of_queries;
    cout<<"enter the bucket_size:"<<endl;
    cin>>bucket_size;
    
    for(int i=0;i<no_of_queries;i++) {
        cout<<"enter the input packet size:"<<endl;
        cin>>input_packet_size;
        cout<<"incoming packet size:"<<" "<<input_packet_size<<endl;
        size_left=bucket_size-storage;
        if(input_packet_size<=size_left) {
            storage=storage+input_packet_size;
            cout<<"bucket buffer size:"<<" "<<storage<<" "<<"out of"<<" "<<bucket_size<<endl;
        }
        else {
            cout<<"packets dropped"<<" "<<(input_packet_size-(size_left))<<endl;
            cout<<"bucket buffer size:"<<" "<<storage<<" "<<"out of"<<" "<<bucket_size<<endl;
            storage=bucket_size;
        }
        cout<<"after going:"<<endl;
        storage=storage-output_packet_rate;
        cout<<"bucket buffer size:"<<" "<<storage<<" "<<"out of"<<" "<<bucket_size<<endl;
    }
    
}
