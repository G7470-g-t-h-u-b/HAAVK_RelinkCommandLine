#include "GraphicAPI.h"
#include "stdio.h"

KbEventFunc(a){
    printf("yes\n");
}

void b(void *arg){
    printf("no\n");
}

KbEventFunc(c){
    int *ptr = arg;
    printf("%d", *ptr);
}

int main(){
    WIN sec = InitImaGraph("C:\\Users\\Administrator\\Desktop\\GAPI\\V3.0.0\\test.bmp", 50, "w2", 255);
    int num1 = 1;
    int num2 = 2;
    AddKbEvent(sec, 65, a, b, NULL, NULL, Once);
    AddKbEvent(sec, 13, c, c, &num1, &num2, Continuous);
    Draw
    (
        sec,
        FillRectan(sec, 50, 50, 100, 100, RGB(255, 0, 0));
        FillRectan(sec, 200, 200, 300, 300, RGB(0, 0, 255));
    )
    /*
    FillRectan(sec, 50, 50, 100, 100, RGB(255, 0, 0));
    FillRectan(sec, 200, 200, 300, 300, RGB(0, 0, 255));
    RefreshWin(sec);
    */
    system("pause");
}