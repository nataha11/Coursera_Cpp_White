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