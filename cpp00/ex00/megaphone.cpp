#include <iostream>
#include <string>

class Megaphone {
    int y;
public:
    Megaphone(char **argv, int argc);
    //~Megaphone(void);
};

Megaphone::Megaphone(char **argv, int argc) {
    y = 1;

    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else {
        while (y < argc) {
            int i = 0;
            while (argv[y][i]) {
                putchar(toupper(argv[y][i++]));
            }
            std::cout << " ";
            y++;
        }
    }
}

int main(int argc, char **argv){
    Megaphone Mega(argv, argc);
    std::cout << std::endl;
    return 0;
}
