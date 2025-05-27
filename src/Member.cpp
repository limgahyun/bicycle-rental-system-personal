#include "Member.h"

/*
    함수 이름 : Member::Member()
    기능	  : Member 생성자
    전달 인자 : 없음
    반환값    : 없음
*/
Member::Member(string id, string password, string phoneNumber) 
    : User(id, password), phoneNumber(phoneNumber) {}