#include "User.h"

User::User(std::string username, std::string password, UserRole role)
    :username_(username), password_(password), role_(role){}

User::User(std::string username, std::string password)
    :username_(username), password_(password), role_(UserRole::Basic){}


const UserRole& User::get_role() const{
    return role_;
}

const std::string& User::get_username() const{
    return username_;
}

bool User::authorize(const std::string& password) const{
    return password_ == password;
}

UserErrorMessage User::change_password(const std::string& old_password, const std::string& new_password){
    if(!authorize(old_password)){
        return UserErrorMessage::NotAuthorized;
    }

    if(new_password.length() < 5){
        return UserErrorMessage::PasswordToShort;
    }

    bool numeric_found = false;
    for(auto &c: new_password){
        if('0'<= c && c <= '9'){
            numeric_found = true;
            break;
        }
    }

    if(!numeric_found){
        return UserErrorMessage::MissinNumeric;
    }

    password_ = new_password;
    return UserErrorMessage::Ok;
}
