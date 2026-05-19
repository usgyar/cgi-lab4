#pragma once

#include <string>
#include <unordered_map>
#include <stdexcept>

class Encryption {
private:
     static constexpr const char* ALPHABET =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";

    static std::unordered_map<char, size_t> buildCharIndex() {
        std::unordered_map<char, size_t> index;
        for (size_t i = 0; i < std::char_traits<char>::length(ALPHABET); ++i) {
            index[ALPHABET[i]] = i;
        }
        return index;
    }

    static const std::unordered_map<char, size_t> CHAR_INDEX;
    static constexpr size_t ALPHABET_SIZE = 63; 

    static bool isEncodable(char c) {
        return CHAR_INDEX.find(c) != CHAR_INDEX.end();
    }

public:
    static std::string encrypt(const std::string& message, const std::string& key) {
        if (key.empty()) {
            throw std::invalid_argument("Key cannot be empty");
        }

        std::string result;
        result.reserve(message.size());

        for (size_t i = 0; i < message.size(); ++i) {
            char msgChar = message[i];
            char keyChar = key[i % key.size()];

            if (isEncodable(msgChar) && isEncodable(keyChar)) {
                size_t msgIdx = CHAR_INDEX.at(msgChar);
                size_t keyIdx = CHAR_INDEX.at(keyChar);
                size_t encryptedIdx = (msgIdx + keyIdx) % ALPHABET_SIZE;
                result += ALPHABET[encryptedIdx];
            }
            else {
                // Символы вне алфавита копируются без изменений
                result += msgChar;
            }
        }
        return result;
    }

    static std::string decrypt(const std::string& encryptedMessage, const std::string& key) {
        if (key.empty()) {
            throw std::invalid_argument("Key cannot be empty");
        }

        std::string result;
        result.reserve(encryptedMessage.size());

        for (size_t i = 0; i < encryptedMessage.size(); ++i) {
            char encChar = encryptedMessage[i];
            char keyChar = key[i % key.size()];

            if (isEncodable(encChar) && isEncodable(keyChar)) {
                size_t encIdx = CHAR_INDEX.at(encChar);
                size_t keyIdx = CHAR_INDEX.at(keyChar);
                size_t decryptedIdx = (encIdx + ALPHABET_SIZE - keyIdx) % ALPHABET_SIZE;
                result += ALPHABET[decryptedIdx];
            }
            else {
                result += encChar;
            }
        }
        return result;
    }
};

const std::unordered_map<char, size_t> Encryption::CHAR_INDEX =
Encryption::buildCharIndex();