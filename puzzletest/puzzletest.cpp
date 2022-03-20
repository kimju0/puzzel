/*
3     , 6     , 9     , 12(846,466)
2     , 5     , 8     , 11
1(0,0), 4     , 7     , 10
play : 13
end  : 14
*/
#include <bangtal.h>

SceneID scene1;
ObjectID white, play, end, piece[13];
int x[4] = { 0,282,564,846 }, y[3] = { 0,233,466 };
bool start = false, position[13] = { false, false, false, false, false, false, false, false, false, false, false, false, false };

void ArrangePuzzel(const char* image, ObjectID object, int X, int Y, bool shown) {
    object = createObject(image);
    locateObject(object, scene1, X, Y);
    if (shown) {
        showObject(object);
    }
}

void playGame() {
    hideObject(1);
    hideObject(13);
    position[1] = true;
}

void moveObject(ObjectID object) {
    if (position[1] == true) {
        locateObject(object, scene1, x[0], y[0]);
        showObject(object);
        position[1] = false;
    }
    if (position[2] == true) {
        locateObject(object, scene1, x[0], y[1]);
        showObject(object);
        position[2] = false;
    }
    if (position[3] == true) {
        locateObject(object, scene1, x[0], y[2]);
        showObject(object);
        position[3] = false;
    }
    if (position[4] == true) {
        locateObject(object, scene1, x[1], y[0]);
        showObject(object);
        position[4] = false;
    }
    if (position[5] == true) {
        locateObject(object, scene1, x[1], y[1]);
        showObject(object);
        position[5] = false;
    }
    if (position[6] == true) {
        locateObject(object, scene1, x[1], y[2]);
        showObject(object);
        position[6] = false;
    }
    if (position[7] == true) {
        locateObject(object, scene1, x[2], y[0]);
        showObject(object);
        position[7] = false;
    }
    if (position[8] == true) {
        locateObject(object, scene1, x[2], y[1]);
        showObject(object);
        position[8] = false;
    }
    if (position[9] == true) {
        locateObject(object, scene1, x[2], y[2]);
        showObject(object);
        position[9] = false;
    }
    if (position[10] == true) {
        locateObject(object, scene1, x[3], y[0]);
        showObject(object);
        position[10] = false;
    }
    if (position[11] == true) {
        locateObject(object, scene1, x[3], y[1]);
        showObject(object);
        position[11] = false;
    }
    if (position[12] == true) {
        locateObject(object, scene1, x[3], y[2]);
        showObject(object);
        position[12] = false;
    }
}

void startend(ObjectID object, int x, int y, MouseAction action) {
    if (object == 14) {
        endGame();
    }
    if (object == 13) {
        playGame();
        start = true;
        showObject(white);
    }
    if (start == true) {
        if (object == 2) {
            moveObject(2);
            position[2] = true;
        }
        if (object == 3) {
            moveObject(3);
            position[3] = true;
        }

    }
}

int main()
{
    setMouseCallback(startend);

    scene1 = createScene("scene", "Images/castle.jpg");

    ArrangePuzzel("images/piece/5.jpg", piece[5], x[0], y[1], true);
    ArrangePuzzel("images/piece/1.jpg", piece[1], x[0], y[2], true);
    ArrangePuzzel("images/piece/10.jpg", piece[10], x[1], y[0], true);
    ArrangePuzzel("images/piece/6.jpg", piece[6], x[1], y[1], true);
    ArrangePuzzel("images/piece/2.jpg", piece[2], x[1], y[2], true);
    ArrangePuzzel("images/piece/11.jpg", piece[11], x[2], y[0], true);
    ArrangePuzzel("images/piece/7.jpg", piece[7], x[2], y[1], true);
    ArrangePuzzel("images/piece/3.jpg", piece[3], x[2], y[2], true);
    ArrangePuzzel("images/piece/12.jpg", piece[12], x[3], y[0], true);
    ArrangePuzzel("images/piece/8.jpg", piece[8], x[3], y[1], true);
    ArrangePuzzel("images/piece/4.jpg", piece[4], x[3], y[2], true);
    ArrangePuzzel("images/play.png", play, 500, 100, true);
    ArrangePuzzel("images/end.png", end, 600, 100, true);
    ArrangePuzzel("images/PIECE/white.jpg", white, x[0], y[0], true);

    startGame(scene1);
}