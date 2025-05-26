#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LoginUI.h"
#include "SignUpUI.h"
#include "LogoutUI.h"
#include "RentBikeUI.h"
#include "RentBikeController.h"

using namespace std;

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void initializeSystem(ifstream& inputFile, ofstream& outputFile);
void cleanupSystem(ifstream& inputFile, ofstream& outputFile);
void doTask(ifstream& inputFile, ofstream& outputFile, LoginUI* loginUI, SignUpUI* signUpUI, LogoutUI* logoutUI, RentBikeUI* rentBikeUI);

int main() {
    // File 입출력을 위한 스트림
    ifstream inputFile;
    ofstream outputFile;
    
    // UI 객체
    LoginUI* loginUI = new LoginUI(outputFile);
    SignUpUI* signUpUI = new SignUpUI(outputFile);
    LogoutUI* logoutUI = new LogoutUI(outputFile);
    RentBikeUI* rentBikeUI = new RentBikeUI(outputFile);

    // 시스템 초기화
    initializeSystem(inputFile, outputFile);

    // 테스트용 자전거 추가
    RentBikeController::addBike(new Bike("BIKE001"));
    RentBikeController::addBike(new Bike("BIKE002"));

    // 명령어 처리
    doTask(inputFile, outputFile, loginUI, signUpUI, logoutUI, rentBikeUI);

    // 정리
    cleanupSystem(inputFile, outputFile);
    delete loginUI;
    delete signUpUI;
    delete logoutUI;
    delete rentBikeUI;

    return 0;
}

void initializeSystem(ifstream& inputFile, ofstream& outputFile) {
    // 파일 입출력을 위한 초기화
    inputFile.open(INPUT_FILE_NAME);
    outputFile.open(OUTPUT_FILE_NAME);
}

void cleanupSystem(ifstream& inputFile, ofstream& outputFile) {
    // 파일 정리
    outputFile.close();
    inputFile.close();
}

void doTask(ifstream& inputFile, ofstream& outputFile, LoginUI* loginUI, SignUpUI* signUpUI, LogoutUI* logoutUI, RentBikeUI* rentBikeUI) {
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menuLevel1 = 0, menuLevel2 = 0;
    string line, input;
    int isProgramExit = 0;
    
    while(!isProgramExit) {
        // 한 줄 전체를 읽어옴
        getline(inputFile, line);
        
        // 빈 줄이면 건너뜀
        if(line.empty()) continue;
        
        // 첫 번째와 두 번째 숫자를 파싱
        istringstream iss(line);
        iss >> menuLevel1 >> menuLevel2;
        
        // 나머지 부분을 input으로 저장
        getline(iss, input);
        
        // 메뉴 구분 및 해당 연산 수행
        switch(menuLevel1) {
            case 1: {
                switch(menuLevel2) {
                    case 1:   // "1.1. 회원가입" 메뉴 부분
                    {
                        signUpUI->requestSignUp(input);
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 2: {
                switch(menuLevel2) {
                    case 1:   // "2.1. 로그인" 메뉴 부분
                    {
                        loginUI->requestLogin(input);
                        break;
                    }
                    case 2:   // "2.2. 로그아웃" 메뉴 부분
                    {
                        logoutUI->requestLogout();
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 4: {
                switch(menuLevel2) {
                    case 1:   // "4.1. 자전거 대여" 메뉴 부분
                    {
                        rentBikeUI->requestRental(input);
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 7: {
                switch(menuLevel2) {
                    case 1:   // "7.1. 종료" 메뉴 부분
                    {
                        isProgramExit = 1;
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
        }
    }
}