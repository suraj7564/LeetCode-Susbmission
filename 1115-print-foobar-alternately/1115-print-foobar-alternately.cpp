class FooBar {
private:
    int n;
    mutex m;
    int turn;
    condition_variable cv;
public:
    FooBar(int n) {
        this->n = n;
        turn = 0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n;i++ ) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.         
            
            unique_lock<mutex> lock(m);
            if(turn!=0){
                cv.wait(lock);
            }
        	printFoo();
            turn = 1;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n;i++ ) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            unique_lock<mutex> lock(m);
            if(turn!=1){
                cv.wait(lock);
            }
        	printBar();
            turn = 0;
            cv.notify_one();
        }
    }
};