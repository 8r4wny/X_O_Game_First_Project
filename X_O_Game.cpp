#include <iostream>

using namespace std;

char currentPlayer = 'X';
char c[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char x[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void draw();
void replace(int, char);
void initChar();
bool checkIf(int);
bool checkXwinner();
bool checkOwinner();

int main()
{
    int input;
    int Do = 1;
    cout << "Welcome in the great X-O game\n";
    cout << "Enter a number between 1 to 9\n";
    while(Do != 0) {
        int counter = 0;
        initChar();
        draw();
        currentPlayer = 'X';
        while(counter < 9){
            cout << "round " << currentPlayer << endl;
            cin >> input;
            while(!checkIf(input)) {
                cout << "The number you entered is wrong or reserved\n"; 
                cout << "Enter anthor number\n";
                cin >> input;
            }
            if(counter % 2 == 0) {
                replace(input, currentPlayer);
                cout << endl;
                currentPlayer = 'O';
            } else {
                replace(input, currentPlayer);
                cout << endl;
                currentPlayer = 'X';
            }
            draw();
            counter++;

            if(checkXwinner() > checkOwinner()) {
                cout << "X Win\n";
                break;
            }
            if(checkXwinner() < checkOwinner()) {
                cout << "O Win\n";
                break;
            }      
        }

        if(++counter > 10) 
            cout << "Equality\n";

        cout << "Do you want play again?\nEnter any number to play again enter 0 to exit\n";
        cin >> Do;
        if(Do == 0) {
            cout << "Good bay\n";
            exit(0);
        }
    }
    return 0;
}

void initChar() {
    char j = '1';
    for(int i = 0; i < 9; i++, j++) {
        c[i] = j;
    }
}

void draw() {
    cout << "\n\t" << c[0] << "\t|\t" << c[1] << "\t|\t" << c[2];
    cout << "\n\t\t|\t \t|\t ";
    cout << "\n----------------+---------------+---------------\n";
    cout << "\t" << c[3] << "\t|\t" << c[4] << "\t|\t" << c[5];
    cout << "\n\t\t|\t \t|\t ";
    cout << "\n----------------+---------------+---------------\n";
    cout << "\t" << c[6] << "\t|\t" << c[7] << "\t|\t" << c[8];
    cout << "\n\t\t|\t \t|\t \n";
    
    /*for (size_t i = 0; i < 40; i++)
    {
        cout << " ";
        if(i == 7)
            cout << c[0];
        if(i == 14)
            cout << "|";
        if(i == 21)
            cout << c[1];
        if(i == 28)
            cout << "|";
        if(i == 35)
            cout << c[2];
    }*/
    
}

void replace(int input, char xOro) {
    switch(input) {
        case 1: c[0] = xOro;
            break;
        case 2: c[1] = xOro;
            break;
        case 3: c[2] = xOro;
            break;
        case 4: c[3] = xOro;
            break;
        case 5: c[4] = xOro;
            break;
        case 6: c[5] = xOro;
            break;
        case 7: c[6] = xOro;
            break;
        case 8: c[7] = xOro;
            break;
        case 9: c[8] = xOro;
            break;
    }
}

bool checkIf(int input) {

    if(input < 1 || input > 9)
        return false;
    return (c[input - 1] == x[input - 1]) ? true : false;
}

bool checkXwinner() {
    bool ro1 = (c[0] == 'X' && c[1] == 'X' && c[2] == 'X');
    bool ro2 = (c[3] == 'X' && c[4] == 'X' && c[5] == 'X');
    bool ro3 = (c[6] == 'X' && c[7] == 'X' && c[8] == 'X');

    bool cl1 = (c[0] == 'X' && c[3] == 'X' && c[6] == 'X');
    bool cl2 = (c[1] == 'X' && c[4] == 'X' && c[7] == 'X');
    bool cl3 = (c[2] == 'X' && c[5] == 'X' && c[8] == 'X');

    bool di1 = (c[0] == 'X' && c[4] == 'X' && c[8] == 'X');
    bool di2 = (c[2] == 'X' && c[4] == 'X' && c[6] == 'X');

    return (ro1 || ro2 || ro3 || cl1 || cl2 || cl3 || di1 || di2) ? true : false;
}

bool checkOwinner() {
    bool ro1 = (c[0] == 'O' && c[1] == 'O' && c[2] == 'O');
    bool ro2 = (c[3] == 'O' && c[4] == 'O' && c[5] == 'O');
    bool ro3 = (c[6] == 'O' && c[7] == 'O' && c[8] == 'O');

    bool cl1 = (c[0] == 'O' && c[3] == 'O' && c[6] == 'O');
    bool cl2 = (c[1] == 'O' && c[4] == 'O' && c[7] == 'O');
    bool cl3 = (c[2] == 'O' && c[5] == 'O' && c[8] == 'O');

    bool di1 = (c[0] == 'O' && c[4] == 'O' && c[8] == 'O');
    bool di2 = (c[2] == 'O' && c[4] == 'O' && c[6] == 'O');

    return (ro1 || ro2 || ro3 || cl1 || cl2 || cl3 || di1 || di2) ? true : false;
}

