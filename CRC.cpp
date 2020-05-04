#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

//Convert int to binary string
string toBin(long long int num)
{
    string bin = "";
    while (num)
    {
        if (num & 1)
            bin = "1" + bin;
        else
            bin = "0" + bin;
        num = num >> 1;
    }
    return bin;
}

//Convert binary string to decimal
long long int toDec(string bin)
{
    long long int num = 0;
    for (int i = 0; i < bin.length(); i++)
    {
        if (bin.at(i) == '1')
            num += 1 << (bin.length() - i - 1);
    }
    return num;
}

//Compute CRC and codeword
void CRC(string dataword, string generator)
{
    int l_gen = generator.length();
    long long int gen = toDec(generator);

    long long int dword = toDec(dataword);

    // append 0s to dividend
    long long int dividend = dword << (l_gen - 1);

    // shft specifies the no. of least
    // significant bits not being XORed
    int shft = (int)ceill(log2l(dividend + 1)) - l_gen;
    long long int rem;

    while ((dividend >= gen) || (shft >= 0))
    {

        // bitwise XOR the MSBs of dividend with generator
        // replace the operated MSBs from the dividend with
        // remainder generated
        rem = (dividend >> shft) ^ gen;
        dividend = (dividend & ((1 << shft) - 1)) | (rem << shft);

        // change shft variable
        shft = (int)ceill(log2l(dividend + 1)) - l_gen;
    }

    // finally, AND the initial dividend with the remainder (=dividend)
    long long int codeword = (dword << (l_gen - 1)) | dividend;
    cout << "Remainder: " << toBin(dividend) << endl;
    cout << "Codeword : " << toBin(codeword) << endl;
}

int main()
{
    string dataword, generator;
    dataword = "10011101";
    generator = "1001";
    CRC(dataword, generator);
    return 0;
}