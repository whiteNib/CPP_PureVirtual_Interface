// CPP_CodingPractice240117.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 
// 인터페이스/ 순수 가상함수

#include <iostream>
#define interface struct
using namespace std;

//class Socket { // 인터페이스
//public:
//    virtual void plugIn() = 0;
//    virtual void unPlug() = 0;
//};

interface Socket {
    virtual void plugIn() = 0;
    virtual void unPlug() = 0;
};

class Samsang : public Socket {
public:


    // socket을(를) 통해 상속됨
    void plugIn() override
    {
        gogo();
        gogo();
    }

    void unPlug() override
    {
        bye();
    }

private:
    void gogo() {
        cout << "지직\n";
    }
    void bye() {
        cout << "지직지직\n";
    }

};

class Dansang : public Socket 
{
public:
    // socket을(를) 통해 상속됨
    void plugIn() override
    {
        cout << "220V\n";
    }
    void unPlug() override
    {
        cout << "BYE\n";
    }
};

class TV {
public:
    Socket* sock;

    TV(Socket* sock) {
        this->sock = sock;
    }

    void tvOn() {
        sock->plugIn();
        cout << "TV를 켠다!\n";
    }

    void tvOff() {
        sock->unPlug();
        cout << "TV를 끈다\n";
    }
};

int main()
{
    /*Socket* s = new Samsung();
    s->plugIn();
    cout << "TV 재밌네요\n";
    s->unPlug();

    s = new Dansang();
    s->plugIn();
    cout << "TV\n";
    s->unPlug();

    delete s;*/

    TV* tv = new TV(new Dansang());

    tv->tvOn();
    tv->tvOff();


}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
