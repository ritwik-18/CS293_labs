#include "rle.h"

// Constructor
rle::rle(int gamma): gamma(gamma){}

// Convert integer to gamma-bit binary string
string rle::f(int i)
{ 
    string res = "";
    string s = std::to_string(i);
    res = (s[0] == '0') ? "0" : "1";
   
    return ""; }

// Convert gamma-bit binary string to integer
int rle::g(string i)
{ return 0; }

// Compress the input file
string rle::compress(string input_string)
{ return ""; }

// Decompress the input file
string rle::decompress(string input_string)
{ return ""; }