#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

string toBinary(int num){
    int binary=0,w=1;
    if(num < 0)return "Underflow";
    else{
        while(num != 0){
            binary += num % 2 * w;
            num /= 2;
            w *= 10;
        }
    }
    string binaryString = to_string(binary);
    if(binaryString.length() > 8){
        binaryString = binaryString.substr(binaryString.length()-8);
    }
    return binaryString;
}

string signedMagnitude(int num){
    string sign = (num < 0 ? "1" : "0");
    string binary = toBinary((num < 0 ? -num : num));
    if(binary.length() > 7){
        binary = binary.substr(binary.length()-7);
    }
    stringstream bitstream;
    bitstream << sign << " " << setw(7) << setfill('0') << binary;
    
    return bitstream.str();
}
string onesComplement(int num){
    string binary = toBinary((num < 0 ? -num : num));
    stringstream bitstream;
    bitstream << setw(8) << setfill('0') << binary;
    binary = bitstream.str();

    if(num < 0){
        for(int i = 0;i<binary.length();i++){
            binary[i] = (binary[i] == '0' ? '1' : '0');
        }
    }
    return binary;
}

string twosComplement(int num){
    string binary = onesComplement(num);
    if(num >= 0)return binary;
    bool tmp = false;
    for(int i = binary.length()-1;i>=0;i--){
        if(i == binary.length()-1){
            if(binary[i] == '0'){
                binary[i] = '1';
                break;
            }else{
                binary[i] = '0';
                tmp = true;
            }
        }else{
            if(tmp){
                if(binary[i] == '0'){
                    binary[i] = '1';
                    tmp = false;
                }else{
                    if(tmp)binary[i] = '0';
                }
                
            }
        }
    }
    return binary;

}

string floatToIEEE754(float num) {
    union {
        float input;
        unsigned int output;
    } data;

    data.input = num;

    unsigned int sign = (data.output >> 31) & 1;
    unsigned int exponent = (data.output >> 23) & 0xFF;
    unsigned int mantissa = data.output & 0x7FFFFF;

    stringstream bitstream;
    
    bitstream << sign << " ";

    // Exponent
    for (int i = 7; i >= 0; --i) {
        bitstream << ((exponent >> i) & 1);
    }
    bitstream << " ";

    // Mantissa
    for (int i = 22; i >= 0; --i) {
        bitstream << ((mantissa >> i) & 1);
    }

    return bitstream.str();
}
int main() {
    float num;
    cin >> num;
    if (num == int(num)) { 
        int intNum = num;
        cout << "Unsigned:         " << setw(8) << setfill('0') << toBinary(intNum) << endl;
        cout << "Signed Magnitude: " << signedMagnitude(intNum) << endl;
        cout << "1's Complement:   " << onesComplement(intNum) << endl;
        cout << "2's Complement:   " << twosComplement(intNum) << endl;
        cout << "IEEE 754: " << floatToIEEE754(intNum) << endl;
    } else {
        cout << "IEEE 754: " << floatToIEEE754(num) << endl;
    }

    return 0;
}