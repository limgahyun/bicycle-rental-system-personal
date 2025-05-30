#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LoginUI.h"
#include "SignUpUI.h"
#include "LogoutUI.h"
#include "RentBikeUI.h"
#include "RegisterBikeUI.h"
#include "GetRentalInfoUI.h"
#include "ExitUI.h"
#include "RentBikeController.h"

using namespace std;

// 상수 선언
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void initializeSystem(ifstream& inputFile, ofstream& outputFile);
void cleanupSystem(ifstream& inputFile, ofstream& outputFile);
void doTask(ifstream& inputFile, ofstream& outputFile, LoginUI* loginUI, SignUpUI* signUpUI, LogoutUI* logoutUI, 
            RentBikeUI* rentBikeUI, RegisterBikeUI* registerBikeUI, GetRentalInfoUI* getRentalInfoUI, ExitUI* exitUI);

/*
    함수 이름 : main()
    기능	  : 프로그램 시작
    전달 인자 : 없음
    반환값    : 프로그램 종료 코드
*/
int main() {
    // File 입출력을 위한 스트림
    ifstream inputFile;
    ofstream outputFile;
    
    // UI 객체
    LoginUI* loginUI = new LoginUI(outputFile);
    SignUpUI* signUpUI = new SignUpUI(outputFile);
    LogoutUI* logoutUI = new LogoutUI(outputFile);
    RentBikeUI* rentBikeUI = new RentBikeUI(outputFile);
    RegisterBikeUI* registerBikeUI = new RegisterBikeUI(outputFile);
    GetRentalInfoUI* getRentalInfoUI = new GetRentalInfoUI(outputFile);
    ExitUI* exitUI = new ExitUI(outputFile);

    // 시스템 초기화
    initializeSystem(inputFile, outputFile);

    // 명령어 처리
    doTask(inputFile, outputFile, loginUI, signUpUI, logoutUI, rentBikeUI, registerBikeUI, getRentalInfoUI, exitUI);

    // 정리
    cleanupSystem(inputFile, outputFile);
    delete loginUI;
    delete signUpUI;
    delete logoutUI;
    delete rentBikeUI;
    delete registerBikeUI;
    delete getRentalInfoUI;
    delete exitUI;

    return 0;
}

/*
    함수 이름 : initializeSystem()
    기능	  : 파일 입출력을 위한 초기화
    전달 인자 : 입력 파일 스트림, 출력 파일 스트림
    반환값    : 없음
*/
void initializeSystem(ifstream& inputFile, ofstream& outputFile) {
    // 파일 입출력을 위한 초기화
    inputFile.open(INPUT_FILE_NAME);
    outputFile.open(OUTPUT_FILE_NAME);
}

/*
    함수 이름 : cleanupSystem()
    기능	  : 파일 입출력을 위한 정리
    전달 인자 : 입력 파일 스트림, 출력 파일 스트림
    반환값    : 없음
*/
void cleanupSystem(ifstream& inputFile, ofstream& outputFile) {
    // 파일 정리
    outputFile.close();
    inputFile.close();
}

/*
    함수 이름 : doTask()
    기능	  : 메뉴 파싱을 위한 처리
    전달 인자 : 입력 파일 스트림, 출력 파일 스트림, LoginUI, SignUpUI, LogoutUI, RentBikeUI, RegisterBikeUI, GetRentalInfoUI, ExitUI
    반환값    : 없음
*/
void doTask(ifstream& inputFile, ofstream& outputFile, LoginUI* loginUI, SignUpUI* signUpUI, LogoutUI* logoutUI, 
            RentBikeUI* rentBikeUI, RegisterBikeUI* registerBikeUI, GetRentalInfoUI* getRentalInfoUI, ExitUI* exitUI) {
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
            case 3: {
                switch(menuLevel2) {
                    case 1:   // "3.1. 자전거 등록" 메뉴 부분
                    {
                        registerBikeUI->requestRegisterBike(input);
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
            case 5: {
                switch(menuLevel2) {
                    case 1:   // "5.1. 자전거 대여 리스트" 메뉴 부분
                    {
                        getRentalInfoUI->requestRentalInfoList();
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 6: {
                switch(menuLevel2) {
                    case 1:   // "6.1. 종료" 메뉴 부분
                    {
                        exitUI->requestExit();
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