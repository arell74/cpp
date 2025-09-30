#include <iostream>
#include <conio.h>
#include <windows.h>
#include <deque>
#include <ctime>
using namespace std;

// Ukuran game
const int WIDTH = 40;
const int HEIGHT = 20;

// Posisi
struct Point {
    int x, y;
};

// Variabel game
deque<Point> snake;
Point food;
char direction = 'R';
bool gameOver = false;
int score = 0;

void setup() {
    // Inisialisasi ular di tengah
    Point head = {WIDTH/2, HEIGHT/2};
    snake.push_front(head);
    
    // Spawn makanan
    food.x = rand() % (WIDTH - 2) + 1;
    food.y = rand() % (HEIGHT - 2) + 1;
}

void draw() {
    system("cls"); // Clear screen
    
    // Border atas
    for(int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;
    
    // Area game
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH + 2; j++) {
            if(j == 0 || j == WIDTH + 1)
                cout << "#"; // Border samping
            else {
                bool printed = false;
                
                // Cek apakah posisi kepala ular
                if(snake[0].x == j - 1 && snake[0].y == i) {
                    cout << "O";
                    printed = true;
                }
                
                // Cek apakah posisi badan ular
                if(!printed) {
                    for(int k = 1; k < snake.size(); k++) {
                        if(snake[k].x == j - 1 && snake[k].y == i) {
                            cout << "o";
                            printed = true;
                            break;
                        }
                    }
                }
                
                // Cek apakah posisi makanan
                if(!printed && food.x == j - 1 && food.y == i) {
                    cout << "*";
                    printed = true;
                }
                
                if(!printed)
                    cout << " ";
            }
        }
        cout << endl;
    }
    
    // Border bawah
    for(int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;
    
    cout << "Score: " << score << endl;
    cout << "Kontrol: W=Atas, S=Bawah, A=Kiri, D=Kanan, X=Keluar" << endl;
}

void input() {
    if(_kbhit()) {
        char key = _getch();
        key = toupper(key);
        
        // Cegah ular berbalik arah 180 derajat
        if(key == 'W' && direction != 'D')
            direction = 'W';
        else if(key == 'S' && direction != 'U')
            direction = 'S';
        else if(key == 'A' && direction != 'R')
            direction = 'A';
        else if(key == 'D' && direction != 'L')
            direction = 'D';
        else if(key == 'X')
            gameOver = true;
    }
}

void logic() {
    // Simpan posisi kepala lama
    Point newHead = snake[0];
    
    // Update posisi kepala berdasarkan arah
    switch(direction) {
        case 'W': newHead.y--; break; // Atas
        case 'S': newHead.y++; break; // Bawah
        case 'A': newHead.x--; break; // Kiri
        case 'D': newHead.x++; break; // Kanan
    }
    
    // Cek tabrakan dengan dinding
    if(newHead.x < 0 || newHead.x >= WIDTH || newHead.y < 0 || newHead.y >= HEIGHT) {
        gameOver = true;
        return;
    }
    
    // Cek tabrakan dengan badan sendiri
    for(int i = 0; i < snake.size(); i++) {
        if(snake[i].x == newHead.x && snake[i].y == newHead.y) {
            gameOver = true;
            return;
        }
    }
    
    // Tambahkan kepala baru
    snake.push_front(newHead);
    
    // Cek apakah makan makanan
    if(newHead.x == food.x && newHead.y == food.y) {
        score += 10;
        // Spawn makanan baru
        food.x = rand() % (WIDTH - 2) + 1;
        food.y = rand() % (HEIGHT - 2) + 1;
    } else {
        // Hapus ekor jika tidak makan
        snake.pop_back();
    }
}

int main() {
    srand(time(0));
    setup();
    
    while(!gameOver) {
        draw();
        input();
        logic();
        Sleep(100); // Delay 100ms
    }
    
    system("cls");
    cout << "\n\n";
    cout << "   ============================\n";
    cout << "        GAME OVER!\n";
    cout << "   ============================\n";
    cout << "        Score Anda: " << score << endl;
    cout << "   ============================\n\n";
    
    return 0;
}