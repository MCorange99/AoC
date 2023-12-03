#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

std::vector<std::string> split(const std::string &str, char delim);
bool starts_with(std::string &str, const char* _substr);

int main() {

    int com = 0;

    std::ifstream input_file("input", std::ios_base::in);
    std::string input_text;
    
    if (input_file.is_open()) {
        std::stringstream buffer;
        buffer << input_file.rdbuf();
        input_text = buffer.str();
    } else {
        std::printf("Unable to open file");
        return 1;
    }


    std::vector<std::string> lines = split(input_text, '\n');

    for (std::string line : lines) {
        std::string buf;

        for (int i=0; i< line.length(); ++i) {
            switch (line[i]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                buf.push_back(line[i]);
                break;
            
            default:
                std::string sub_str = line.substr(i);
                if (starts_with(sub_str, "one")) {
                    buf.push_back('1');
                } else
                if (starts_with(sub_str, "two")) {
                    buf.push_back('2');
                } else
                if (starts_with(sub_str, "three")) {
                    buf.push_back('3');
                } else
                if (starts_with(sub_str, "four")) {
                    buf.push_back('4');
                } else
                if (starts_with(sub_str, "five")) {
                    buf.push_back('5');
                } else
                if (starts_with(sub_str, "six")) {
                    buf.push_back('6');
                } else
                if (starts_with(sub_str, "seven")) {
                    buf.push_back('7');
                } else
                if (starts_with(sub_str, "eight")) {
                    buf.push_back('8');
                } else
                if (starts_with(sub_str, "nine")) {
                    buf.push_back('9');
                }

                break;
            }
        }
        
        std::string buf2;

        buf2.push_back(buf[0]);
        
        if (buf.length() > 1) {
            buf2.push_back(buf[buf.length() -1]);
        } else {
            buf2.push_back(buf[0]);
        }

        com += atoi(buf2.c_str());
        std::printf("'%s' -> '%s'\n", line.c_str(), buf2.c_str());
    }

    std::printf("com: %d\n", com);
}

std::vector<std::string> split(const std::string &str, char delim) {
    std::vector<std::string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
}

bool starts_with(std::string &str, const char* _substr) {
    std::string substr = _substr;
    if (str.length() < substr.length()) {
        return false;
    }


    for (int i=0; i< substr.length(); ++i) {
        if (str[i] != substr[i]) {
            return false;
        }
    }

    return true;
}