#include "Member.h"

Member::Member() : User() {}

Member::Member(string id, string password, string phoneNumber) 
    : User(id, password), phoneNumber(phoneNumber) {}