#include <iostream>
#include <string>
using namespace std;

class Megaphone {
    int y;
public:
    Megaphone(char **argv, int argc);
    //~Megaphone(void);
};

Megaphone::Megaphone(char **argv, int argc) {
    y = 1;

    if (argc < 2)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else {
        while (y < argc) {
            int i = 0;
            while (argv[y][i]) {
                putchar(toupper(argv[y][i++]));
            }
            cout << " ";
            y++;
        }
    }
}

int main(int argc, char **argv){
    Megaphone Mega(argv, argc);
    cout << endl;
    return 0;
}
