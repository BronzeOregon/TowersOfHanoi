#include <iostream>
#include <stack>

using namespace std;

class disc{
    int size;

public: int getSize(){
        return size;
    }

public: int setSize(int s){
        size = s;
        return size;
    }



};

class tower {
    //using tS for LIFO
    stack<disc> tS;

    //method to transfer disc objects between stacks.


public:
    stack<disc> getStack() {
        return tS;
    }

    stack<disc> pushStack(disc d){
        tS.push(d);
        return tS;
    }

    stack<disc> popStack(){
        tS.pop();
        return tS;
    }

    disc moveDisc(tower t) {
        t.pushStack(tS.top());
        tS.pop();
        return tS.top();
    }

    void PrintStack() {
        // If tS is empty then return
        if (tS.empty()) {
            return;
        } else {

            //x holds popped variables.
            disc x = tS.top();


            tS.pop();

            // Recursively call the function PrintStack
            PrintStack();

            //prints from last call to recursive function
            cout << x.getSize() << "\n";

            // Push the same element onto the tS
            // to preserve the order
            tS.push(x);
        }
    }

    void printEmpty() {
        cout << "-";
    }

    bool checkSize(disc d, tower t) {
        int size;
        if(t.getStack().empty()){
            size=4;
        } else{
            size = t.getStack().top().getSize();
        }
        if (d.getSize() > size) {
            return false;
        } else {
            return true;
        }
    }
};





void printTowers(tower t1, tower t2, tower t3){
    disc x;
    disc y;
    disc z;


    if(t1.getStack().empty()&&t2.getStack().empty()&&t3.getStack().empty()){
        return;
    }else if(t1.getStack().empty()){

            cout << "- ";

        if(t2.getStack().empty()){

                cout << "- ";
            } else{

            y = t2.getStack().top();
            cout << y.getSize() << " ";
            t2.popStack();

        } if(t3.getStack().empty()){

                    cout << "-\n";
                    return;
            } else{

                z = t3.getStack().top();
                cout << z.getSize() << " \n";
                t3.popStack();

                printTowers(t1,t2,t3);
            }
    } else {

        x = t1.getStack().top();
        cout << x.getSize() << " ";
        t1.popStack();

        if (t2.getStack().empty()) {

            cout << "- ";

            if (t3.getStack().empty()) {

                cout << "-\n";

                printTowers(t1, t2, t3);
                return;
            } else {
                z = t3.getStack().top();
                cout << z.getSize() << " \n";
                t3.popStack();

                printTowers(t1, t2, t3);
                return;
            }

        } else {

            y = t2.getStack().top();
            cout << y.getSize() << " ";
            t2.popStack();

            if (t3.getStack().empty()) {

                cout << "-\n";
                printTowers(t1, t2, t3);
                return;

            } else {
                z = t3.getStack().top();
                cout << z.getSize() << " \n";
                t3.popStack();

                printTowers(t1, t2, t3);
                return;
            }

        }
    }
//        x = t1.getStack().top();
//        y = t2.getStack().top();
//        z = t3.getStack().top();
//
//        t1.getStack().pop();
//        t2.getStack().pop();
//        t3.getStack().pop();
//
//        cout << x.getSize() << " ";
//        cout << y.getSize() << " ";
//        cout << z.getSize() << "\n";

}

int main() {
    //generate 3 tower objects for discs to be inserted onto.
    tower t1;
    tower t2;
    tower t3;

    disc d1{};
    disc d2{};
    disc d3{};

    d1.setSize(1);
    d2.setSize(2);
    d3.setSize(3);

    //give the first stack 3 discs of sizes 1,2,3
    t1.pushStack(d3);
    t1.pushStack(d2);
    t1.pushStack(d1);

    printTowers(t1,t2,t3);

    cout << "There are 3 towers with 3 discs each. You must move a disc from one tower to the next, never placing a larger disc on a smaller one.\n";
    cout << "The game ends when all three discs are in order on the right tower.\n";

    bool game = true;

    while(game){
        cout << "Enter the tower you'd like to move a disc from. Towers are 1, 2, and 3, from left to right.\n";
        int in1;
        cin>>in1;
        if(in1==1){

            cout << "Please enter the tower you'd like to move the disc to.\n";
            int in2;
            cin>>in2;
            if(in2==1){

                cout << "The disc remains where it is. Judging.\n";

            } else if(in2==2){

                if(t1.checkSize(t1.getStack().top(),t2)){
                    t2.pushStack(t1.getStack().top());
                    t1.popStack();
                    cout << "The disc is moved.\n";
                    printTowers(t1,t2,t3);
                } else{
                    cout << "The disc is too large to be placed upon the one already there.\n";
                    printTowers(t1,t2,t3);
                }

            } else if(in2==3){

                if(t1.checkSize(t1.getStack().top(),t3)){
                    t3.pushStack(t1.getStack().top());
                    t1.popStack();
                    cout << "The disc is moved.\n";
                    printTowers(t1,t2,t3);
                } else{
                    cout << "The disc is too large to be placed upon the one already there.\n";
                    printTowers(t1,t2,t3);

                }

            }

        } else if(in1==2){

            cout << "Please enter the tower you'd like to move the disc to.\n";
            int in2;
            cin>>in2;
            if(in2==1){

                if(t2.checkSize(t2.getStack().top(),t1)){
                    t1.pushStack(t2.getStack().top());
                    t2.popStack();
                    cout << "The disc is moved.\n";
                    printTowers(t1,t2,t3);
                } else{
                    cout << "The disc is too large to be placed upon the one already there.\n";
                    printTowers(t1,t2,t3);

                }

            } else if(in2==2){

                cout << "The disc remains where it is. Judging.\n";

            } else if(in2==3){

                if(t2.checkSize(t2.getStack().top(),t3)){
                    t3.pushStack(t2.getStack().top());
                    t2.popStack();
                    cout << "The disc is moved.\n";
                    printTowers(t1,t2,t3);
                } else{
                    cout << "The disc is too large to be placed upon the one already there.\n";
                    printTowers(t1,t2,t3);

                }

            }

        } else if(in1==3){

            cout << "Please enter the tower you'd like to move the disc to.\n";
            int in2;
            cin>>in2;
            if(in2==1){

                if(t3.checkSize(t3.getStack().top(),t1)){
                    t1.pushStack(t3.getStack().top());
                    t3.popStack();
                    cout << "The disc is moved.\n";
                    printTowers(t1,t2,t3);
                } else{
                    cout << "The disc is too large to be placed upon the one already there.\n";
                    printTowers(t1,t2,t3);

                }

            } else if(in2==2){

                if(t3.checkSize(t3.getStack().top(),t2)){
                    t2.pushStack(t3.getStack().top());
                    t3.popStack();
                    cout << "The disc is moved.\n";
                    printTowers(t1,t2,t3);
                } else{
                    cout << "The disc is too large to be placed upon the one already there.\n";
                    printTowers(t1,t2,t3);

                }

            } else if(in2==3){

                cout << "The disc remains where it is. Judging.\n";

            }

        }

        if(t3.getStack().size()==3){
            game= !game;
        }
    }

    cout << "Congratulations, you win!";

    return 0;
}
