// 헤더 선언
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include "LoginUI.h"

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void join();
void login();
void logout();
void registerBike();
void rentBike();
void getRentalInfo();
void program_exit();

// 변수 선언
std::ofstream out_fp;
std::ifstream in_fp;

// Global LoginUI instance
LoginUI* loginUI = nullptr;

void login() {
    if (loginUI == nullptr) {
        loginUI = new LoginUI();
    }
    loginUI->requestLogin();
}

int main()
{
  // 파일 입출력을 위한 초기화
  in_fp.open(INPUT_FILE_NAME);
  out_fp.open(OUTPUT_FILE_NAME);

  doTask();

  // Cleanup
  if (loginUI != nullptr) {
    delete loginUI;
  }

  out_fp.close();
  in_fp.close();

  return 0;
}

void doTask()
{
  // 메뉴 파싱을 위한 level 구분을 위한 변수
  int menu_level_1 = 0, menu_level_2 = 0;
  int is_program_exit = 0;
    
  while(!is_program_exit)
  {
    // 입력파일에서 메뉴 숫자 2개를 읽기
    in_fp >> menu_level_1 >> menu_level_2;

    
    // 메뉴 구분 및 해당 연산 수행
    switch(menu_level_1)
    {
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
            login();
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