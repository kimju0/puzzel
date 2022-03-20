/*
3     , 6     , 9     , 12(846,466)
2     , 5     , 8     , 11
1(0,0), 4     , 7     , 10
play : 13
end  : 14
*/
#include <bangtal.h>
 
SceneID scene1;
ObjectID play, end, piece[13];
/*
int x[4] = {0,282,564,846}, y[3] = {0,233,466}
*/
int x[12] = { 0,282,564,846, 0,282,564,846, 0,282,564,846}, y[12] = { 0, 233, 466, 0, 233, 466, 0, 233, 466, 0, 233, 466 };
bool start= false, position[13] = {false, false, false, false, false, false, false, false, false, false, false, false, false };

void ArrangePuzzel(const char* image, ObjectID object, int X, int Y) {
    object = createObject(image);
    locateObject(object, scene1, X, Y);
    showObject(object);
}

void playGame() {
    hideObject(1);
    hideObject(13);
    position[1] = true;
}

void moveObject(ObjectID object, int X, int Y) {
    if (position[2] == true) {
        if (X == x[4] and Y == y[1]) {
            position[1] = true;
            x[4] = 0;
            y[1] = 233;
            locateObject(object, scene1, x[4], y[1]);
            showObject(object);
        }
        position[2] = false;
    }
    if (position[1] == true) { 
        if (X == x[4] and Y == y[1]) {
            position[2] = true;
            x[4] = 0;
            y[1] = 0; 
            locateObject(object, scene1, x[4], y[1]);
            showObject(object);
        }
        position[1] = false;
    }
    
    if (position[3] == true) {
        locateObject(object, scene1, 0, 466);
        showObject(object);
        position[3] = false;
    }
    if (position[4] == true) {
        locateObject(object, scene1, 282, 0);
        showObject(object);
        position[4] = false;
    }
    if (position[5] == true) {
        locateObject(object, scene1, 282, 233);
        showObject(object);
        position[5] = false;
    }
    if (position[6] == true) {
        locateObject(object, scene1, 282, 466);
        showObject(object);
        position[6] = false;
    }
    if (position[7] == true) {
        locateObject(object, scene1, 564, 0);
        showObject(object);
        position[7] = false;
    }
    if (position[8] == true) {
        locateObject(object, scene1, 564, 233);
        showObject(object);
        position[8] = false;
    }
    if (position[9] == true) {
        locateObject(object, scene1, 564, 466);
        showObject(object);
        position[9] = false;
    }
    if (position[10] == true) {
        locateObject(object, scene1, 846, 0);
        showObject(object);
        position[10] = false;
    }
    if (position[11] == true) {
        locateObject(object, scene1, 846, 233);
        showObject(object);
        position[11] = false;
    }
    if (position[12] == true) {
        locateObject(object, scene1, 846, 466);
        showObject(object);
        position[12] = false;
    }
}

void startend(ObjectID object, int X, int Y, MouseAction action) {
    if (object == 14) {
        endGame();
    }
    if (object == 13) {
        playGame();
        start = true;
    }
    if (start == true) { 
        if (object == 2) {
            moveObject(2, x[4], y[1]);
        }
        if (object == 3) {
            moveObject(3, x[8], y[2]);
        }
        if (object == 4) {
            moveObject(4, x[1], y[3]);
        }
        if (object == 5) {
            moveObject(5, x[5], y[4]);
        }
        if (object == 6) {
            moveObject(6, x[9], y[5]);
        }
        if (object == 7) {
            moveObject(7, x[2], y[6]);
        }
        if (object == 8) {
            moveObject(8, x[6], y[7]);
        }
        if (object == 9) {
            moveObject(9, x[10], y[8]);
        }
        if (object == 10) {
            moveObject(10, x[3], y[9]);
        }
        if (object == 11) {
            moveObject(11, x[7], y[10]);
        }
        if (object == 12) {
            moveObject(12, x[11], y[11]);
        }
    }
}

int main()
{
    setMouseCallback(startend);

    scene1 = createScene("scene", "Images/castle.jpg");

    ArrangePuzzel("images/piece/9.jpg", piece[9], x[0], y[0]);
    ArrangePuzzel("images/piece/5.jpg", piece[5], x[4], y[1]);
    ArrangePuzzel("images/piece/1.jpg", piece[1], x[8], y[2]);
    ArrangePuzzel("images/piece/10.jpg", piece[10], x[1], y[3]);
    ArrangePuzzel("images/piece/6.jpg", piece[6], x[5], y[4]);
    ArrangePuzzel("images/piece/2.jpg", piece[2], x[9], y[5]);
    ArrangePuzzel("images/piece/11.jpg", piece[11], x[2], y[6]);
    ArrangePuzzel("images/piece/7.jpg", piece[7], x[6], y[7]);
    ArrangePuzzel("images/piece/3.jpg", piece[3], x[10], y[8]);
    ArrangePuzzel("images/piece/12.jpg", piece[12], x[3], y[9]);
    ArrangePuzzel("images/piece/8.jpg", piece[8], x[7], y[10]);
    ArrangePuzzel("images/piece/4.jpg", piece[4], x[11], y[11]);
    ArrangePuzzel("images/play.png", play, 500, 100);
    ArrangePuzzel("images/end.png", end, 600, 100);

    startGame(scene1);
}