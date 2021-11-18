#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    throw system_error(error_code());
    return "01:01:01";
}

class TimeServer {
public:
    string GetCurrentTime() {
        string curr_time;
        try {
            curr_time =  AskTimeServer();
        } catch(system_error& syserr) {
            return last_fetched_time;
        }
        
        last_fetched_time = curr_time;
        return curr_time;
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}