#include "rle.h"
#include<cmath>
#include<iostream>

// Constructor
rle::rle(int gamma): gamma(gamma){}

// Convert integer to gamma-bit binary string
string rle::f(int i)
{ 
    string res = "";
    int qt = i / 2;
    if(qt >= 2){
        int rem = i % 2;
        char srem = char(rem+48);
        res.push_back(srem);
    while(qt >= 2){
        int rem = qt % 2;
        char srem = char(rem+48);
        res.insert(res.cbegin() ,srem);
        qt = qt/2;
    }
    res.insert(res.cbegin(),char(qt+48));
    }
    else{
        int rem = i % 2;
        char srem = char(rem+48);
        res.push_back(srem);
        res.insert(res.cbegin(),char(qt+48));
    }
    int zer = rle::gamma - res.size();
    while(zer>0){
        res.insert(res.cbegin(),char(48));
        zer--;
    }
    return res; }

// Convert gamma-bit binary string to integer
int rle::g(string i)
{
    int res = 0;
    int pow = 1;
    for (int j = i.size()-1; j >=0; j--){
        res += (int(i[j])-48)*pow;
        pow *= 2;
    }
    return res; }

// Compress the input file
string rle::compress(string input_string)
{
    int count = 1;
    string res = "";
    int cmp = int(input_string[0])-48;
    res += (std::to_string(cmp));
    for(int i = 1; i < input_string.size(); i++){
        if((int(input_string[i])-48 == cmp) && count < pow(2,gamma)-1){
            count++;
            cmp = int(input_string[i])-48;
        }
        else if((int(input_string[i])-48 == cmp) && count++ == pow(2,gamma)-1){

            res += rle::f(count-1);
            cmp = int(input_string[i])-48;
            res += rle::f(0);
            count = 1;
        }
        else{
            res += rle::f(count);
            cmp = int(input_string[i])-48;
            count = 1;
        }
    }
    res += rle::f(count);
    return res; }

// Decompress the input file
// string rle::decompress(string input_string)
// {
//     string res = "";
//     int val = int(input_string[0])-48;
//     res.push_back(input_string[0]);
//     int end = (input_string.size()-1)/rle::gamma;
//     int i = 0;
//     while(i < end){
//         string count = input_string.substr((rle::gamma*i + 1), (rle::gamma -1));
//         int c = rle::g(count);
//         if(c < pow(2,gamma)-1){
//             for (int i = 0; i < c ; i++){
//                 res.push_back(char(val+48));
//             }
//             val += (val+1)%2;
//             i++;
//         }
//         else{
//             string nxt = input_string.substr((rle::gamma*(i+1) + 1), (rle::gamma -1));
//             int nxtval = rle::g(nxt);
//             if( val == nxtval){

//             }
//         }

//     }
//     return ""; }

// int main(){
//     rle i(2);
//     std::cout << i.f(0) << std::endl;
//     string s = "100000011";
//     std::cout << i.compress(s) << std::endl;
// }

string rle::compress(string input_string){ 
    string out="";
    out+=input_string[0];
    int max=(1<<gamma)-1;
    int last=input_string[0];
    int count=0;
    for(char x : input_string){
        // cout<<x;
        if(x==last){
            count++;
        }
        else{
            out+=f(count);
            last=x;
            count=1;
        }
        if(count>max){
            out+=f(count);
            out+=f(0);
            count=1;
        }
    }
    // out+=f(count);
    return out; 
}

// Decompress the input file
string rle::decompress(string input_string){ 
    int add=input_string[0];
    string out="";
    for(int i=1;i<input_string.size();i+=gamma){
        int j=g(input_string.substr(i,gamma));
        while(j--){
            out+=add;
        }
        if(add=='0') add='1';
        else add='0';
    } 
    return out+'\n';
}