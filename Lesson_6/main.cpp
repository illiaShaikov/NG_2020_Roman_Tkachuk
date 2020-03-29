#include <iostream>
#include <random>
#include <ctime>
#include <string>

using namespace std;

char generatedLevel [100][100];
char playerLevel [100][100];
int woodAmount = 0;
int stoneAmount = 0;
string screenMessages[15];

void generateLevel(int levelSize, int type) {
    if (type == 0) {
        // Let's generate player-visible level
        for (int row=0; row<levelSize; row++) {
            for (int column=0; column<levelSize; column++) {
                playerLevel[row][column] = '#';
            }
        }
    }
    else {
        for (int row=0; row<levelSize; row++) {
            for (int column=0; column<levelSize; column++) {
                int value = rand()%10;
                switch (value) {
                case 0: generatedLevel[row][column] = 't'; break;
                case 1: generatedLevel[row][column] = 's'; break;
                default: generatedLevel[row][column] = '.'; break;
                }
            }
        }
    }

}

void showLevel(int levelSize, int type) {
    if (type == 0) {
        for (int row=0; row<levelSize; row++) {
            for (int column=0; column<levelSize; column++) {
                cout << playerLevel[row][column];
            }
            cout << endl;
        }
    } else {
        for (int row=0; row<levelSize; row++) {
            for (int column=0; column<levelSize; column++) {
                cout << generatedLevel[row][column];
            }
            cout << endl;
        }
    }
}

void removePlayerFromMap(int levelSize) {
    for (int row=0; row<levelSize; row++) {
        for (int column=0; column<levelSize; column++) {
            if (playerLevel[row][column] == 'x') {
                playerLevel[row][column] = generatedLevel[row][column];
                return;
            }
        }
    }
}

void regeneratePlayerMap(int pPosX, int pPosY, int levelSize) {
    if (pPosX > 0) playerLevel[pPosY][pPosX-1] = generatedLevel[pPosY][pPosX-1];
    if (pPosX < levelSize-1) playerLevel[pPosY][pPosX+1] = generatedLevel[pPosY][pPosX+1];
    if (pPosY > 0) playerLevel[pPosY-1][pPosX] = generatedLevel[pPosY-1][pPosX];
    if (pPosY < levelSize-1) playerLevel[pPosY+1][pPosX] = generatedLevel[pPosY+1][pPosX];
    if (pPosY > 0 && pPosX > 0) playerLevel[pPosY-1][pPosX-1] = generatedLevel[pPosY-1][pPosX-1];
    if (pPosY < levelSize-1 && pPosX > 0) playerLevel[pPosY+1][pPosX-1] = generatedLevel[pPosY+1][pPosX-1];
    if (pPosY < levelSize-1 && pPosX < levelSize-1) playerLevel[pPosY+1][pPosX+1] = generatedLevel[pPosY+1][pPosX+1];
    if (pPosY > 0 && pPosX < levelSize-1) playerLevel[pPosY-1][pPosX+1] = generatedLevel[pPosY-1][pPosX+1];
}

void addMessage(string message) {
    for (int current = 0; current < 15; current++) {
        if (screenMessages[current].size() == 0) {
            screenMessages[current] = message;
            return;
        }
    }
}

bool detectResource (int posX, int posY) {
    switch (generatedLevel[posY][posX]) {
    case 't': woodAmount++; addMessage("You found some wood, sweet!"); break;
    case 's': stoneAmount++; addMessage("Stones... Nice building stuff"); break;
    default: return false;
    }
    generatedLevel[posY][posX] = '.';
    return true;
}

void clearMessages() {
    for (int current = 0; current < 15; current++) {
        screenMessages[current].clear();
    }
}

void showMessages() {
    for (int current=0; current < 15; current++) {
        if (screenMessages[current].size() != 0) {
            cout << screenMessages[current] << endl;
        }
    }
}

void gatherResource(int pPosX, int pPosY) {
    if (detectResource(pPosX, pPosY-1)) return;
    if (detectResource(pPosX+1, pPosY-1)) return;
    if (detectResource(pPosX+1, pPosY)) return;
    if (detectResource(pPosX+1, pPosY+1)) return;
    if (detectResource(pPosX, pPosY+1)) return;
    if (detectResource(pPosX-1, pPosY+1)) return;
    if (detectResource(pPosX-1, pPosY)) return;
    if (detectResource(pPosX-1, pPosY-1)) return;
}

bool processPlayerMove(int pPosX, int pPosY, int levelSize) {
    if (pPosX < 0 || pPosX >= levelSize ||
            pPosY < 0 || pPosY >= levelSize) {
        return false;
    }

    if (generatedLevel[pPosY][pPosX] == '.') {
        removePlayerFromMap(levelSize);
        playerLevel[pPosY][pPosX] = 'x';
        regeneratePlayerMap(pPosX, pPosY, levelSize);
        return true;
    } else {
        return false;
    }
}

int main()
{   
    int pPosX = 0;
    int pPosY = 0;
    srand(time(0));

    int levelSize = 0;
    cout << "Enter level size: ";
    cin >> levelSize;

    generateLevel(levelSize, 0);
    generateLevel(levelSize, 1);

    while (1) {
        showLevel(levelSize, 0);
        cout << endl;
        cout << "Wood: " << woodAmount << " | " << "Stone: " << stoneAmount << endl;
        showMessages();
        clearMessages();
        cout << "========================================================" << endl;
        cout << ">";
        char cmd;
        cin >> cmd;

        switch (cmd) {
        case 'w': if (processPlayerMove(pPosX, pPosY-1, levelSize)) pPosY--; break;
        case 's': if (processPlayerMove(pPosX, pPosY+1, levelSize)) pPosY++; break;
        case 'a': if (processPlayerMove(pPosX-1, pPosY, levelSize)) pPosX--; break;
        case 'd': if (processPlayerMove(pPosX+1, pPosY, levelSize)) pPosX++; break;
        case 'g': gatherResource(pPosX, pPosY); processPlayerMove(pPosX, pPosY, levelSize); break;
        }

    }

    return 0;
}
