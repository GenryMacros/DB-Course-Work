#pragma once
#include "Server.h"

class UserInfo {
public:
	UserInfo() = default;
    void createUser(std::string& name, std::string& last_name, std::string& patro, std::string& Type, int ID) {
		this->name = name;
		this->last_name = last_name;
		this->patro = patro;
		this->Type = Type;
		this->ID = ID;
	}
	std::string& getName() {
		return name;
	}
	void setName(std::string& newname) {
		name = newname;
	}
	std::string& getlName() {
		return last_name;
	}
	void setlName(std::string& newname) {
		last_name = newname;
	}
	std::string& getPatro() {
		return patro;
	} 
	void setPatro(std::string& newpatro) {
		patro = newpatro;
	}
	const std::string getFullName() {
		return std::string(name + " " + last_name + " " + patro);
	}
	std::string& getType() {
		return Type;
	}
	void setType(std::string& newtype) {
		Type = newtype;
	}
	int& getID() {
		return ID;
	}
	void setID(const int newid) {
		ID = newid;
	}
	void setGroup(std::string& newgroup) {
		groupName = newgroup;
	}
	std::string& getGroup() {
		return groupName;
	}
	void setspecialityName(std::string& newspec) {
		specialityName = newspec;
	}
	std::string& getspecialityName() {
		return specialityName;
	}
	void setcathedraName(std::string& newcath) {
		cathedraName = newcath;
	}
	std::string& getcathedraName() {
		return cathedraName;
	}
	void setfacultyName(std::string& newfac) {
		facultyName = newfac;
	}
	std::string& getfacultyName() {
		return facultyName;
	}
	void setCourse(const char newcourse) {
		course = newcourse;
	}
	char getCourse() {
		return course;
	}
	void setPhone(std::string& newphone) {
		phone = newphone;
	}
	std::string& getPhone() {
		return phone;
	}
	void setMail(std::string& newmail) {
		mail = newmail;
	}
	std::string& getMail() {
		return mail;
	}
	void setFacultativeGrade(int newFacultativeGrade) {
		FacultativeGrade = newFacultativeGrade;
	}
	int getFacultativeGrade() {
		return FacultativeGrade;
	}
	void setFacultativeHours(int newFacultativeHours) {
		FacultativeHours = newFacultativeHours;
	}
	int getFacultativeHours() {
		return FacultativeHours;
	}
	void setFacultativeName(std::string& newFacultativeName) {
		FacultativeName = newFacultativeName;
	}
	std::string& getFacultativeName() {
		return FacultativeName;
	}
	bool isFaculGet() {
		return FacultativeName.length() != 0;
	}
private:
	UserInfo(UserInfo& cop) = delete;
	UserInfo(const UserInfo& cop) = delete;
	std::string name;
	std::string last_name;
	std::string patro;
	std::string groupName;
	char course;
	std::string specialityName;
	std::string cathedraName;
	std::string facultyName;
	std::string phone;
	std::string mail;
	std::string FacultativeName;
	int ID;
	int FacultativeGrade;
	int FacultativeHours;
	std::string Type;

};