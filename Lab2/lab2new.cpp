#include <iostream>
#include <string>
using namespace std;

void encoderRLE(string&);
void decoderRLE(string&);

int main() {
    cout << "Enter your message text: ";
    string message;
    getline(cin, message);

    cout << "Your message: " << message << endl;

    encoderRLE(message);
    cout << "Encoded message: " << message << endl;

    cout << "More clear encoded message: ";
    for (size_t i = 0; i < message.size(); i += 2) {
        cout << message[i] << "("
            << static_cast<int>(static_cast<unsigned char>(message[i + 1]))
            << ")";
    }
    cout << endl;

    decoderRLE(message);
    cout << "Decoded message: " << message << endl;

    return 0;
}

void encoderRLE(string& text)
{
    if (text.empty()) return;

    string copy = text;
    text.clear();

    char current = copy[0];
    int count = 1;

    for (size_t i = 1; i < copy.size(); ++i) {
        if (copy[i] == current && count < 255) {
            count++;
        }
        else {
            // write chunk
            text.push_back(current);
            text.push_back(static_cast<char>(count));

            // reset
            current = copy[i];
            count = 1;
        }
    }

    // write last chunk
    text.push_back(current);
    text.push_back(static_cast<char>(count));

    cout << "The information encoded!" << endl;
}

void decoderRLE(string& encodedText)
{
    string copy = encodedText;
    encodedText.clear();

    for (size_t i = 0; i < copy.size(); i += 2) {
        char ch = copy[i];
        int count = static_cast<unsigned char>(copy[i + 1]);

        for (int j = 0; j < count; ++j) {
            encodedText.push_back(ch);
        }
    }
}
