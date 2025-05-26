#include "LogoutUI.h"

/*
    함수 이름 : LogoutUI::LogoutUI()
    기능	  : LogoutUI 생성자
    전달 인자 : 출력 파일 스트림
    반환값    : 없음
*/
LogoutUI::LogoutUI(ofstream& outFile) : outputFile(outFile) {
    logoutController = new LogoutController();
}

/*
    함수 이름 : LogoutUI::requestLogout()
    기능	  : 로그아웃 요청을 처리하고 결과를 출력
    전달 인자 : 없음
    반환값    : 없음
*/
void LogoutUI::requestLogout() {
    string userId = logoutController->logout();

    outputFile << "2.2. 로그아웃" << endl;
    if (!userId.empty()) {
        outputFile << "> " << userId << endl << endl;
    } else {
        outputFile << "> " << "logout failed" << endl << endl;
    }
} 