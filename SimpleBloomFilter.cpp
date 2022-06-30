#include <bits/stdc++.h>

using namespace std;

int count_digits(long long n)
{
    // Convert to string.
    string num = to_string(n);
    
    // Return the size of string.
    return num.size();
}

class SimpleBloomFilter {
    private:
        int bit_array[1000] = {0};

        // Returns the last 3 digits(8,9,10) of phone number [in order]
        int hash_func_1(long long number) {
            return (number%1000);
        }

        // Returns the 5,6,7 digits of phone number [in order]
        int hash_func_2(long long number) {
            return ((number/1000)%1000);
        }

        // Returns the 2,3,4 digits of phone number [in order]
        int hash_func_3(long long number) {
            return ((number/1000000)%1000);
        }

        // Returns the first digit of phone number along with the two digit country code [in order]
        int hash_func_4(long long number) {
            return ((number/1000000000)%1000);
        }
    public:
        void insert (long long number) {

            // Changing the bit to 1 when considering last 3 digits(8,9,10 - in order) as index.
            int index1 = hash_func_1(number);
            bit_array[index1] = 1;

            // Changing the bit to 1 when considering 5,6,7 digits (in order) as index.
            int index2 = hash_func_2(number);
            bit_array[index2] = 1;

            // Changing the bit to 1 when considering 2,3,4 digits (in order) as index.
            int index3 = hash_func_3(number);
            bit_array[index3] = 1;

            // Changing the bit to 1 when considering first digit along with the two country code digits.
            int index4 = hash_func_4(number);
            bit_array[index4] = 1;
        }

        bool lookup(long long number) {
            bool exists = false;
            bool exists1;
            bool exists2;
            bool exists3;
            bool exists4;

            // Checking if the last 3(8,9,10 - in order) digits of a number already exist in the bloom filter.
            int index1 = hash_func_1(number);
            if (bit_array[index1] == 1) exists1 = true;
            else exists1 = false;

            // Checking if the 5,6,7 (in order) digits of a number already exist in the bloom filter.
            int index2 = hash_func_2(number);
            if (bit_array[index2] = 1) exists2 = true;
            else exists2 = false;

            // Checking if the 2,3,4 (in order) digits of a number already exist in the bloom filter.
            int index3 = hash_func_3(number);
            if (bit_array[index3] = 1) exists3 = true;
            else exists3 = false;

            // Checking if the first digit along with country code two digits of a number already exist in the bloom filter.
            int index4 = hash_func_4(number);
            if (bit_array[index4] = 1) exists4 = true;
            else exists4 = false;

            // Only if all 4 conditions are satisfied, we can say the number already exists.
            if(exists1 && exists2 && exists3 && exists4) exists = true;

            return exists;
        }
};

int main() {
    // Driver Function
    int query;
    SimpleBloomFilter sbf;
    do {
        cout << "Please enter your preferred action.\n 0 - Insert Phone Number\n 1 - Lookup Phone Number\n 2 - Exit" << endl;
        cin >> query;
        if (query == 0) {
            cout << "Please enter the number you want to insert. (12 digits)" << endl;
            long long number;
            cin >> number;
            if(count_digits(number) == 12) {
                sbf.insert(number);
                cout << number << " is inserted." << endl;
            }
            else cout << "Please enter a valid 12 digit number." << endl;   
        }
        else if (query == 1) {
            cout << "Please enter the number you want to look up in the directory. (12 digits)" << endl;
            long long number;
            cin >> number;
            if (count_digits(number) == 12) {
                bool exists = sbf.lookup(number);
                if(exists == true) cout << number << " is probably present." << endl; // probably is used as Bloom Filter can give a False Positive result sometimes.
                else cout << number << " is absent." << endl; // probably is not used as Bloom Filter never gives a False Negative result.
            }
            else cout << "Please enter a valid 12 digit number." << endl;
        }
        else if (query == 2) {
            break;
        }
        else cout << "Please enter a valid option." << endl;
    } while(query != 2);
    return 0;
}