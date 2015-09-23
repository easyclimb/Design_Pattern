//单例模式：保证一个类只有一个实例，并提供一个访问它的全局点
//singleton : only one instance of the C++ class exists.
//when to use ? for example:
//1.a logger class so only object has access to log files
//2.there is a single resource, and there should be a single object in charge of accessing the single resource
//lock is used when in multi-threads situation.

class A {
public:
    static A* getInstance();
private:
    A() {};  //
    A(A const&) {};
    A& operator=(A const&){};
    static A* instance;
};

A* A::getInstance() {
    if(!instance) {
        lock(syncRoot) {
            if(!instance) {  //recheck ! think why
                instance = new A();
            }
        }
    }
    return instance;
}
