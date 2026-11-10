#ifndef USER_CLASS_H
#define USER_CLASS_H

#include <string>

enum class UserRole{
    Basic,
    Student,
    Teacher,
    Admin
};

enum class UserErrorMessage{
    Ok,
    PasswordToShort,
    NotAuthorized,
    MissinNumeric,
    InvalidPassword
};

class User
{
protected:
    std::string username_;
private:
    std::string password_;
    enum UserRole role_;
public:
    User(std::string username, std::string password, UserRole role);
    User(std::string username, std::string password);
    const UserRole& get_role() const;
    const std::string& get_username() const;
    bool authorize(const std::string& password) const;
    UserErrorMessage change_password(const std::string& old_password, const std::string& new_password);
};


#endif
