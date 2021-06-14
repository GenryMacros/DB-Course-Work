#pragma once


#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <sqlext.h>
#include <locale.h>
#include "Userinfo.h"

WCHAR connectionString[] = L"Driver={SQL Server};DSN='';SERVER=desktop-7ehadf0\\sqlexpress;DATABASE=STUDENT_FACUL;UID=sa;PWD=12345";

class SQLserver {
public:
	SQLserver(SQLserver& cop) = delete;
	SQLserver(const SQLserver& cop) = delete;
	static SQLserver& getSqlServer() {
		static SQLserver server(connectionString);
		return server;
	}
    bool Connect() {
        rc = SQLAllocEnv(&hEnv);

        rc = SQLAllocConnect(hEnv, &hDbc);

        rc = SQLDriverConnect(hDbc, NULL, (WCHAR*)connectionString,
            SQL_NTS, (WCHAR*)szConnStrOut,
            255, (SQLSMALLINT*)&iConnStrLength2Ptr, SQL_DRIVER_NOPROMPT);

        if (SQL_SUCCEEDED(rc))
        {
            wprintf(L"Successfully connected to database. Data source name: \n  %s\n",
                szConnStrOut);
            return true;
        }
        else {
            DisplayError(SQL_HANDLE_DBC, hDbc);
        }
    }
    void Disconnect() {
        SQLDisconnect(hDbc);
        SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
        SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
    }
    bool LogIn(const wchar_t* login,const wchar_t* password,UserInfo& user) {
       wchar_t* Table;
       wchar_t* nextTable;
       wchar_t* ID;
       if (login[0] == L's')
       {
           wchar_t t[]= L"Student_Log";
           wchar_t s[] = L"Student_ID";
           wchar_t r[] = L"Students";
           Table = t;
           nextTable = r;
           ID = s;
       }
       else {
           wchar_t t[] = L"Teacher_Log";
           wchar_t s[] = L"Teacher_ID";
           wchar_t r[] = L"Teachers";
           Table = t;
           nextTable = r;
           ID = s;
       }
       std::wstring cmd = L"SELECT";
       cmd += L' ';
       cmd +=  ID ;
       cmd += L' ';
       cmd += L"FROM";
       cmd += L' ';
       cmd += Table ;
       cmd += L' ';
       cmd += L"WHERE sLogin=";
       cmd += L"'";
       cmd += login;
       cmd += L"'";
       cmd += L' ';
       cmd += L"AND sPassword=";
       cmd += L"'";
       cmd += password;
       cmd += L"'";

       rc = SQLAllocStmt(hDbc, &hStmt);
       rc = SQLPrepare(hStmt, (SQLWCHAR*)cmd.c_str(), SQL_NTS);
       rc = SQLExecute(hStmt);
       SQLSMALLINT num;
       if (SQL_SUCCEEDED(rc)) {
           rc = SQLFetch(hStmt);
           SQLWCHAR buf[40];
           std::wstring id;
           rc = SQLGetData(hStmt, 1, SQL_C_WCHAR, buf, sizeof(buf), &ret);
           id = buf;
           int num = 1;
           int IDbuf = 0;
           for (int i = 3; i >= 0; i--) {
               if (!buf[i]) continue;
               IDbuf += ((int)((char)wctob(buf[i]))-'0') * num;
               num *= 10;
           } 
           user.setID(IDbuf);
           rc= SQLFreeStmt(hStmt, SQL_CLOSE);
           cmd.clear();
           std::wstring cmd = L"SELECT";
           cmd += L' ';
           cmd += L"First_Name";
           cmd += L',';
           cmd += L"Last_Name";
           cmd += L',';
           cmd += L"Patronymic";
           cmd += L' ';
           cmd += L"FROM";
           cmd += L' ';
           cmd += nextTable; 
           cmd += L' '; 
           cmd += L"WHERE";
           cmd += L' ';
           cmd += ID;
           cmd += L'=';
           cmd += buf;
           rc = SQLPrepare(hStmt, (SQLWCHAR*)cmd.c_str(), SQL_NTS);
           rc = SQLExecute(hStmt);
           if (SQL_SUCCEEDED(rc)) {
               rc = SQLFetch(hStmt);
               SQLWCHAR buf[40];
               rc = SQLGetData(hStmt, 1, SQL_C_WCHAR, buf, sizeof(buf), &ret);
               std::string Buffer;
               for (int i = 0; buf[i] != ' ' && i < 40; i++) {
                  Buffer += (char)(wctob(buf[i]));
                }
               user.setName(Buffer);
               rc = SQLGetData(hStmt, 2, SQL_C_WCHAR, buf, sizeof(buf), &ret);
               Buffer.clear();
               for (int i = 0; buf[i] != ' ' && i < 40; i++) {
                   Buffer += (char)(wctob(buf[i]));
                }
               user.setlName(Buffer);
               rc = SQLGetData(hStmt, 3, SQL_C_WCHAR, buf, sizeof(buf), &ret);
               Buffer.clear();
                for (int i = 0; buf[i] != ' ' && i < 40; i++) {
                    Buffer += (char)(wctob(buf[i]));
                }
                user.setPatro(Buffer);
                Buffer.clear();
                for (int i = 0; buf[i] != ' ' && i < 40; i++) {
                    Buffer += (char)(wctob(nextTable[i]));
                }
                rc = SQLFreeStmt(hStmt, SQL_CLOSE);
               
           }
           else
           {
               DisplayError(SQL_HANDLE_STMT, hStmt);
               rc = SQLFreeConnect(hDbc);
               rc = SQLFreeStmt(hStmt, SQL_CLOSE);
               return false;
           }
           //INSERT @result(Phone,Mail)
         //  SELECT Phone, Mail FROM Student_Contact WHERE Student_ID = 1
           cmd.clear();
           cmd = L"EXEC GetStudentInfo ";
           cmd += id;
         
           rc = SQLPrepare(hStmt, (SQLWCHAR*)cmd.c_str(), SQL_NTS);
           rc = SQLExecute(hStmt);
           rc = SQLFetch(hStmt);

           rc = SQLGetData(hStmt, 1, SQL_C_WCHAR, buf, sizeof(buf), &ret);
           std::string Buffer;
           for (int i = 0; buf[i] != ' ' && i < 40; i++) {
               Buffer += (char)(wctob(buf[i]));
           }
           user.setGroup(Buffer);
           rc = SQLGetData(hStmt, 2, SQL_C_WCHAR, buf, sizeof(buf), &ret);
           Buffer.clear();
           for (int i = 0; buf[i] != ' ' && i < 40; i++) {
               Buffer += (char)(wctob(buf[i]));
           }
           user.setCourse(Buffer[0]);
           rc = SQLGetData(hStmt, 3, SQL_C_WCHAR, buf, sizeof(buf), &ret);
           Buffer.clear();
           for (int i = 0; buf[i] != '\0' && i < 40; i++) {
               Buffer += (char)(wctob(buf[i]));
           }
           user.setspecialityName(Buffer);
           rc = SQLGetData(hStmt, 4, SQL_C_WCHAR, buf, sizeof(buf), &ret);
           Buffer.clear();
           for (int i = 0; buf[i] != '\0' && i < 40; i++) {
               Buffer += (char)(wctob(buf[i]));
           }
           user.setcathedraName(Buffer);
           rc = SQLGetData(hStmt, 5, SQL_C_WCHAR, buf, sizeof(buf), &ret);
           Buffer.clear();
           for (int i = 0; buf[i] != '\0' && i < 40; i++) {
               Buffer += (char)(wctob(buf[i]));
           }
           user.setfacultyName(Buffer);
           rc = SQLGetData(hStmt, 6, SQL_C_WCHAR, buf, sizeof(buf), &ret);
           Buffer.clear();
           for (int i = 0; buf[i] != '\0' && i < 40; i++) {
               Buffer += (char)(wctob(buf[i]));
           }
           user.setPhone(Buffer);
           rc = SQLGetData(hStmt, 7, SQL_C_WCHAR, buf, sizeof(buf), &ret);
           Buffer.clear();
           for (int i = 0; buf[i] != '\0' && i < 40; i++) {
               Buffer += (char)(wctob(buf[i]));
           }
           user.setMail(Buffer);
           rc = SQLFreeConnect(hDbc);
           return true;
       }
       else
       {
      
           DisplayError(SQL_HANDLE_STMT, hStmt);
       }
       rc = SQLFreeConnect(hDbc);
       rc = SQLFreeStmt(hStmt, SQL_CLOSE);
       return false;

    }
    bool CheckFaculs(int Student_ID) {
        std::wstring cmd = L"Exec ";
        cmd += L"CheckIfFaculs ";
        cmd +=std::to_wstring(Student_ID);

        rc = SQLAllocStmt(hDbc, &hStmt);
        rc = SQLPrepare(hStmt, (SQLWCHAR*)cmd.c_str(), SQL_NTS);
        rc = SQLExecute(hStmt);
        if (SQL_SUCCEEDED(rc)) {
            rc = SQLFetch(hStmt);
            SQLWCHAR buf[5];
            rc = SQLGetData(hStmt, 1, SQL_C_WCHAR, buf, sizeof(buf), &ret);

            int IDbuf = 0;
            IDbuf += ((int)((char)wctob(buf[0])) - '0');
              
            rc = SQLFreeConnect(hDbc);
            rc = SQLFreeStmt(hStmt, SQL_CLOSE);
            return IDbuf;
        }
        else
        {
            DisplayError(SQL_HANDLE_STMT, hStmt);
        }
        throw "Connection error";
    }
    bool GetAvaliableFacultys(int Student_ID,int* Ids,list<std::string>& faculNames) {
       std::wstring cmd = L"Exec ";
        cmd += L"SelectAvaliableFaculs ";
        cmd += std::to_wstring(Student_ID);

        rc = SQLAllocStmt(hDbc, &hStmt);
        rc = SQLPrepare(hStmt, (SQLWCHAR*)cmd.c_str(), SQL_NTS);
        rc = SQLExecute(hStmt);
        SQLSMALLINT num;
        if (SQL_SUCCEEDED(rc)) {
            rc = SQLFetch(hStmt);
            SQLWCHAR buf[15];
            int fieldsCount=0;
            SQLNumResultCols(hStmt, &fieldCount);
            if (fieldCount > 0)
            {
                int currentStr = 0;
                while (SQL_SUCCEEDED(rc)) {
                    rc = SQLGetData(hStmt, 1, SQL_C_WCHAR, buf, sizeof(buf), &ret);
                    std::wstring id=buf;
                    int num = 1;
                    int IDbuf = 0;
                    for (int i = 3; i >= 0; i--) {
                        if (!buf[i]) continue;
                        IDbuf += ( (int)((char)wctob(buf[i])) - '0' ) * num;
                        num *= 10;
                    }
                    Ids[currentStr] = IDbuf;
                    std::string str;
                        rc = SQLGetData(hStmt, 2, SQL_C_WCHAR, buf, sizeof(buf), &ret);
                        for (int i = 0; buf[i] != '\0' && i < 15; i++) {
                            str += (char)(wctob(buf[i]));
                        }
                        faculNames.add(str);
                        currentStr++;
                        rc = SQLFetch(hStmt);
                    }
                rc = SQLFreeConnect(hDbc);
                rc = SQLFreeStmt(hStmt, SQL_CLOSE);
                return true;
                }
            }
        else
        {
            DisplayError(SQL_HANDLE_STMT, hStmt);
        }
        rc = SQLFreeConnect(hDbc);
        rc = SQLFreeStmt(hStmt, SQL_CLOSE);
        return false;
        }
    bool GetStudentFaculty(UserInfo& user) {
     //SELECT 
         
           SQLWCHAR buf[40];
           
     
            rc = SQLFreeStmt(hStmt, SQL_CLOSE);
            std::wstring cmd = L" SELECT Total_Hours, Subject_Name, Grade = (SELECT Grade FROM Student_Facultative WHERE Student_ID =";
            cmd += std::to_wstring(user.getID());
            cmd += L") FROM Faculty_Facultative WHERE Facultative_ID = (SELECT Facultative_ID FROM Student_Facultative WHERE Student_ID =";
            cmd += std::to_wstring(user.getID());
            cmd += L")";
       
            rc = SQLAllocStmt(hDbc, &hStmt);
            rc = SQLPrepare(hStmt, (SQLWCHAR*)cmd.c_str(), SQL_NTS);
            rc = SQLExecute(hStmt);
            if (SQL_SUCCEEDED(rc)) {
                SQLWCHAR buf[20];
                rc = SQLFetch(hStmt);
                std::wstring id;
                rc = SQLGetData(hStmt, 1, SQL_C_WCHAR, buf, sizeof(buf), &ret);
                id = buf;
                int num = 1;
                int IDbuf = 0;
                for (int i = 3; i >= 0; i--) {
                    if (!buf[i]) continue;
                    IDbuf += ((int)((char)wctob(buf[i])) - '0') * num;
                    num *= 10;
                }
                user.setFacultativeHours(IDbuf);
                
               
                rc = SQLGetData(hStmt, 2, SQL_C_WCHAR, buf, sizeof(buf), &ret);
                std::string Buffer;
                for (int i = 0; buf[i] != '\0' && i < 20; i++) {
                    Buffer += (char)(wctob(buf[i]));
                }
                user.setFacultativeName(Buffer);
                rc = SQLGetData(hStmt, 3, SQL_C_WCHAR, buf, sizeof(buf), &ret);
                IDbuf = 0;
                num = 1;
                for (int i = 3; i >= 0; i--) {
                    if (!buf[i]) continue;
                    IDbuf += ((int)((char)wctob(buf[i])) - '0') * num;
                    num *= 10;
                }
                user.setFacultativeGrade(IDbuf);
                rc = SQLFreeStmt(hStmt, SQL_CLOSE);
                return true;

            }
            else
            {
                DisplayError(SQL_HANDLE_STMT, hStmt);
                rc = SQLFreeConnect(hDbc);
                rc = SQLFreeStmt(hStmt, SQL_CLOSE);
                return false;
            }
        

    }
    bool setFacultys(int ID,int StudentId) {
        std::wstring cmd = L"UPDATE Student_Facultative SET Facultative_ID=";

        cmd += std::to_wstring(ID);
        cmd += L' ';
        cmd += L"WHERE Student_ID=";
        cmd += std::to_wstring(StudentId);

        rc = SQLAllocStmt(hDbc, &hStmt);
        rc = SQLPrepare(hStmt, (SQLWCHAR*)cmd.c_str(), SQL_NTS);
        rc = SQLExecute(hStmt);
        if (SQL_SUCCEEDED(rc)) {
            rc = SQLFreeConnect(hDbc);
            rc = SQLFreeStmt(hStmt, SQL_CLOSE);
            return true;
        }
         
        
        else
            DisplayError(SQL_HANDLE_STMT, hStmt);
        
        rc = SQLFreeConnect(hDbc);
        rc = SQLFreeStmt(hStmt, SQL_CLOSE);
        return false;
      }
    bool FindTeacherContacts(int StudentID,std::string& subjName,std::string& FullName,std::string& Phone,std::string& Mail) {
        std::wstring cmd = L"Exec ";
        cmd += L"Get_Teacher_Contacts ";
        cmd +=L"'"+ std::wstring(subjName.begin(),subjName.end()) + L"'";
        cmd += L",";
        cmd += std::to_wstring(StudentID);

        rc = SQLAllocStmt(hDbc, &hStmt);
        rc = SQLPrepare(hStmt, (SQLWCHAR*)cmd.c_str(), SQL_NTS);
        rc = SQLExecute(hStmt);
        SQLSMALLINT num;
        if (SQL_SUCCEEDED(rc)) {
            rc = SQLFetch(hStmt);
            SQLWCHAR buf[30];
           
                int currentStr = 0;
                while (SQL_SUCCEEDED(rc)) {
                    rc = SQLGetData(hStmt, 1, SQL_C_WCHAR, buf, sizeof(buf), &ret);
                  
                    for (int i = 0; buf[i] != ' ' && i < 30; i++) {
                        Phone += (char)(wctob(buf[i]));
                    }
                    rc = SQLGetData(hStmt, 2, SQL_C_WCHAR, buf, sizeof(buf), &ret);
                    for (int i = 0; buf[i] != ' ' && i < 30; i++) {
                        Mail += (char)(wctob(buf[i]));
                    }
                    rc = SQLGetData(hStmt, 3, SQL_C_WCHAR, buf, sizeof(buf), &ret);
                    for (int i = 0; buf[i] != '\0' && i < 30; i++) {
                        if (i != 0 && buf[i] == ' ' && buf[i - 1] == ' ')
                            continue;
                        FullName += (char)(wctob(buf[i]));
                    }
                 
                }
                rc = SQLFreeConnect(hDbc);
                rc = SQLFreeStmt(hStmt, SQL_CLOSE);
                return true;
            
        }
        else
        {
            DisplayError(SQL_HANDLE_STMT, hStmt);
        }
        rc = SQLFreeConnect(hDbc);
        rc = SQLFreeStmt(hStmt, SQL_CLOSE);
        return false;
    }
    bool GetStudentSubjects(int StudentID,list<std::string>& subjs, list<int>& grades) {
        std::wstring cmd = L"Exec ";
        cmd += L"GetStudentSubj_Name_Grade ";
        cmd += std::to_wstring(StudentID);

        rc = SQLAllocStmt(hDbc, &hStmt);
        rc = SQLPrepare(hStmt, (SQLWCHAR*)cmd.c_str(), SQL_NTS);
        rc = SQLExecute(hStmt);
        SQLSMALLINT num;
        if (SQL_SUCCEEDED(rc)) {
            rc = SQLFetch(hStmt);
            SQLWCHAR buf[30];

            int currentStr = 0;
            while (SQL_SUCCEEDED(rc)) {
                std::string newSubj;
                int newNum = 0;

                rc = SQLGetData(hStmt, 1, SQL_C_WCHAR, buf, sizeof(buf), &ret);
              
                for (int i = 0; buf[i] != '\0' && i < 30; i++) {
                    newSubj += (char)(wctob(buf[i]));
                }
                subjs.add(newSubj);
                rc = SQLGetData(hStmt, 2, SQL_C_WCHAR, buf, sizeof(buf), &ret);
                if (rc == SQL_SUCCESS_WITH_INFO) {
                    for (int i = 0; buf[i] != ' ' && i < 30; i++) {
                        newNum += (char)(wctob(buf[i]));
                    }
                    grades.add(newNum);
                }
                else {
                    grades.add(0);
                }
              
                rc = SQLFetch(hStmt);
                currentStr++;
            }
            rc = SQLFreeConnect(hDbc);
            rc = SQLFreeStmt(hStmt, SQL_CLOSE);

            return true;

        }
        else
        {
            DisplayError(SQL_HANDLE_STMT, hStmt);
        }
        rc = SQLFreeConnect(hDbc);
        rc = SQLFreeStmt(hStmt, SQL_CLOSE);
        return false;
    }
    bool GetStudentSubjectData(int ID,std::string subj,std::string& patro,std::string& mail,std::string& phone) {
        std::wstring cmd = L"Exec ";
        cmd += L"GetSubjectInfo ";
        cmd += std::to_wstring(ID);
        cmd += L',';
        cmd += L"'";
        cmd += std::wstring(subj.begin(),subj.end());
        cmd += L"'";
        rc = SQLAllocStmt(hDbc, &hStmt);
        rc = SQLPrepare(hStmt, (SQLWCHAR*)cmd.c_str(), SQL_NTS);
        rc = SQLExecute(hStmt);
        SQLSMALLINT num;
        if (SQL_SUCCEEDED(rc)) {
            rc = SQLFetch(hStmt);
            SQLWCHAR buf[30];
            int fieldsCount = 0;
            SQLNumResultCols(hStmt, &fieldCount);
            if (fieldCount > 0)
            {
                int currentStr = 0;
              
                    rc = SQLGetData(hStmt, 1, SQL_C_WCHAR, buf, sizeof(buf), &ret);
                    for (int i = 0; buf[i] != '\0' && i < 30; i++) {
                        if (i != 0 && buf[i] == ' ' && buf[i - 1] == ' ')
                            continue;
                        patro += (char)(wctob(buf[i]));
                    }
                    rc = SQLGetData(hStmt, 2, SQL_C_WCHAR, buf, sizeof(buf), &ret);
                    for (int i = 0; buf[i] != '\0' && i < 30; i++) {
                        mail += (char)(wctob(buf[i]));
                    }
                    rc = SQLGetData(hStmt, 3, SQL_C_WCHAR, buf, sizeof(buf), &ret);
                    for (int i = 0; buf[i] != '\0' && i < 30; i++) {
                        phone += (char)(wctob(buf[i]));
                    }
                    currentStr++;
                  
                rc = SQLFreeConnect(hDbc);
                rc = SQLFreeStmt(hStmt, SQL_CLOSE);
                return true;
            }
        }
        else
        {
            DisplayError(SQL_HANDLE_STMT, hStmt);
        }
        rc = SQLFreeConnect(hDbc);
        rc = SQLFreeStmt(hStmt, SQL_CLOSE);
        return false;
    }
    
private:

	SQLserver(WCHAR connectionString[]) {
        setlocale(LC_ALL, "Russian");
	}
    void DisplayError(SQLSMALLINT t, SQLHSTMT h) {
        SQLWCHAR       SqlState[6], Msg[SQL_MAX_MESSAGE_LENGTH];
        SQLINTEGER    NativeError;
        SQLSMALLINT   i, MsgLen;
        SQLRETURN     rc;

        SQLLEN numRecs = 0;
        SQLGetDiagField(t, h, 0, SQL_DIAG_NUMBER, &numRecs, 0, 0);

        i = 1;
        while (i <= numRecs && (rc = SQLGetDiagRec(t, h, i, SqlState, &NativeError,
            Msg, sizeof(Msg), &MsgLen)) != SQL_NO_DATA) {
            wprintf(L"Error %d: %s\n", NativeError, Msg);
            i++;
        }
    }
    
    HENV    hEnv = NULL;
    HDBC    hDbc = NULL;
    HSTMT hStmt = NULL;
    int iConnStrLength2Ptr;
    WCHAR szConnStrOut[256];
    SQLINTEGER rowCount = 0;
    SQLSMALLINT fieldCount = 0, currentField = 0;
    SQLWCHAR buf[128], colName[128];
    SQLINTEGER ret;
    RETCODE rc;
};