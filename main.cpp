#include <iostream>
#include <string>
#include <chrono>
#include <cctype>

using Clock = std::chrono::system_clock;
using TimePoint = std::chrono::time_point<Clock>;
using Duration = std::chrono::duration<double>;

using std::string;
using std::cout;
using std::cin;

string to_lower(const string &str) {
    string result = str;
    for (char &c : result) {
        c = static_cast<unsigned char>(tolower(c));
    }
    return result;
}

int main(){
    TimePoint start, end;
    string input;

    cout << "Type 'start' as quickly as you can and press enter to see your reaction time or type 'quit' to exit: ";
    
    cin >> input;
    start = Clock::now();

    string lowered_input = to_lower(input);

    if (lowered_input == "quit"){
        cout << "\nUser entered quit. Exiting program.\n\n";
        return 0;
    }

    if (lowered_input != "start"){
        cout << "Error: Invalid input. Please try again.\n\n";
        return 0;
    }

    end = Clock::now();
    Duration elapsed_seconds = end - start;

    cout << "Reaction time: " << elapsed_seconds.count() << "s\n\n";
    return 0;
}