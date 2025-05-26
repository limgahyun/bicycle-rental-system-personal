// 헤더 선언
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "LoginUI.h"

using namespace std;

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

class BicycleRentalSystem {
private:
    ifstream in_fp;
    ofstream out_fp;
    LoginUI* loginUI;

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
        string line, input;
        int is_program_exit = 0;
        
        while(!is_program_exit) {
            // 한 줄 전체를 읽어옴
            getline(in_fp, line);
            
            // 빈 줄이면 건너뜀
            if(line.empty()) continue;
            
            // 첫 번째와 두 번째 숫자를 파싱
            istringstream iss(line);
            iss >> menu_level_1 >> menu_level_2;
            
            // 나머지 부분을 input으로 저장
            getline(iss, input);
            
            // 메뉴 구분 및 해당 연산 수행
            switch(menu_level_1) {
                case 1:
                {
                    switch(menu_level_2)
                    {
                        case 1:   // "1.1. 회원가입" 메뉴 부분
                        {
                            // 해당 기능 수행 
                            // join();
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
                            loginUI->requestLogin(input); // loginUI에게 로그인 요청
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
                case 3:
                {
                    switch(menu_level_2)
                    {
                        case 1:   // "3.1. 자전거 등록" 메뉴 부분
                        {
                            // registerBike();
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
                            // rentBike();
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
                            // getRentalInfo();
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                case 6:
                {
                    switch(menu_level_2)
                    {
                        case 1:   // "6.1. 종료" 메뉴 부분
                        {
                            is_program_exit = 1;
                            // 해당 기능 수행 
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

public:
    void run() {
        initializeSystem();
        doTask();
        cleanupSystem();
    }
};