#include "BicycleRentalSystem.h"
#include <sstream>

void BicycleRentalSystem::initializeSystem() {
    // 파일 입출력을 위한 초기화
    inputFile.open(INPUT_FILE_NAME);
    outputFile.open(OUTPUT_FILE_NAME);
    
    // UI 객체 초기화
    loginUI = new LoginUI(outputFile);
    signUpUI = new SignUpUI(outputFile);
}

void BicycleRentalSystem::cleanupSystem() {
    // UI 객체 정리
    if (loginUI != nullptr) {
        delete loginUI;
    }
    if (signUpUI != nullptr) {
        delete signUpUI;
    }
    
    // 파일 정리
    outputFile.close();
    inputFile.close();
}

void BicycleRentalSystem::doTask() {
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
                        // logout();
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

void BicycleRentalSystem::run() {
    initializeSystem();
    doTask();
    cleanupSystem();
}