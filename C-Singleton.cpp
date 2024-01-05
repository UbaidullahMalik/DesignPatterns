#include <iostream>
using namespace std;

class Logger{
    private:
    static Logger* instance;
    Logger(){
        cout<<"Logger Object Created - Singleton Pattern\n";
    }
    public:
    bool operator == (const Logger& object){
        return (this->instance == object.instance);

    }
    static Logger* getInstance(){
        return instance;
    }
};

Logger* Logger::instance = new Logger();

int main(){
    Logger* obj = Logger::getInstance();
    Logger* obj2 = Logger::getInstance();
    if(obj == obj2)
    {
        cout<<"Both Objects are same\n";
    }
    else
    {
        cout<<"Both Objects are different\n";
    }
    return 0;
}
