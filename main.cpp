// 헤더 선언
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "LoginUI.h"

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 클래스 인스턴스 선언
LoginUI* loginUI = nullptr;

// 함수 선언
void doTask();
void join();
void logout();
void registerBike();
void rentBike();
void getRentalInfo();
void program_exit();
void initializeSystem();
void cleanupSystem();

// 변수 선언
std::ofstream out_fp;
std::ifstream in_fp;

void initializeSystem() {
    // 파일 입출력을 위한 초기화
    in_fp.open(INPUT_FILE_NAME);
    out_fp.open(OUTPUT_FILE_NAME);
    
    // UI 객체 초기화
    loginUI = new LoginUI(out_fp);
}

void cleanupSystem() {
    // UI 객체 정리
    if (loginUI != nullptr) {
        delete loginUI;
    }
    
    // 파일 정리
    out_fp.close();
    in_fp.close();
}

void doTask() {
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    std::string line, input;
    int is_program_exit = 0;
    
    while(!is_program_exit) {
        // 한 줄 전체를 읽어옴
        std::getline(in_fp, line);
        
        // 빈 줄이면 건너뜀
        if(line.empty()) continue;
        
        // 첫 번째와 두 번째 숫자를 파싱
        std::istringstream inputStringStream(line);
        inputStringStream >> menu_level_1 >> menu_level_2;
        
        // 나머지 부분을 input으로 저장
        std::getline(inputStringStream, input);
        
        // 메뉴 구분 및 해당 연산 수행
        switch(menu_level_1) {
            case 1:
            {
                switch(menu_level_2)
                {
                    case 1:   // "1.1. 회원가입" 메뉴 부분
                    {
                        // 해당 기능 수행 
                        join();
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 2:
            {
                switch(menu_level_2)
                {
                    case 1:   // "2.1. 로그인" 메뉴 부분
                    {
                        loginUI->requestLogin(input);
                        break;
                    }
                    case 2:   // "2.2. 로그아웃" 메뉴 부분
                    {
                        logout();
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 3:
            {
                switch(menu_level_2)
                {
                    case 1:   // "3.1. 자전거 등록" 메뉴 부분
                    {
                        registerBike();
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 4:
            {
                switch(menu_level_2)
                {
                    case 1:   // "4.1. 자전거 대여" 메뉴 부분
                    {
                        rentBike();
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 5:
            {
                switch(menu_level_2)
                {
                    case 1:   // "5.1. 대여 정보 조회" 메뉴 부분
                    {
                        getRentalInfo();
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 7:
            {
                switch(menu_level_2)
                {
                    case 1:   // "7.1. 종료" 메뉴 부분
                    {
                        is_program_exit = 1;
                        break;
                    }        
                }
            }
        }
    }
}

int main() {
    initializeSystem();
    doTask();
    cleanupSystem();
    return 0;
}