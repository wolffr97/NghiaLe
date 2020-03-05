#include <iostream>
#include "md5.h"
using namespace std;
int main() {

    
    while (1) {
        

            string data;
            cout << " chuoi can ma hoa: ";
            cin >> data;
            string data_hex_digest;

            md5 hash;
            hash.update(data.begin(), data.end());
            hash.hex_digest(data_hex_digest);

            cout << data_hex_digest << endl;
            



    }

}