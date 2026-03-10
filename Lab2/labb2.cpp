#include <iostream>
#include <string>
#include <vector>

class SimpleRLE {
public:
    // Encode a string using RLE
    std::string encode(const std::string& input) {
        if (input.empty()) return "";

        std::string output;
        size_t i = 0;

        while (i < input.length()) {
            char current = input[i];
            int count = 1;

            // Count consecutive identical characters
            while (i + count < input.length() && input[i + count] == current) {
                count++;
            }

            // Store as "character count"
            output += current;
            output += std::to_string(count);

            i += count;
        }

        return output;
    }

    // Decode an RLE encoded string
    std::string decode(const std::string& input) {
        std::string output;

        for (size_t i = 0; i < input.length(); i += 2) {
            if (i + 1 >= input.length()) break;

            char c = input[i];
            int count = input[i + 1] - '0'; // Convert char digit to int

            // Append character 'count' times
            for (int j = 0; j < count; j++) {
                output += c;
            }
        }

        return output;
    }
};

int main() {
    SimpleRLE rle;
    std::string input;

    std::cout << "Enter a string to encode: ";
    std::getline(std::cin, input);

    // Encode
    std::string encoded = rle.encode(input);
    std::cout << "Encoded: " << encoded << std::endl;

    // Decode
    std::string decoded = rle.decode(encoded);
    std::cout << "Decoded: " << decoded << std::endl;

    // Verify
    if (input == decoded) {
        std::cout << "Success: Decoded string matches original!" << std::endl;
    }
    else {
        std::cout << "Error: Decoded string does not match original!" << std::endl;
    }

    return 0;
}