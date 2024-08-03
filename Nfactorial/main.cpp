#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class CinemaTicketSystem{
public:
    void control_panel();
    void addMovie();
    void showAllMovies();
    void addUser();
    void buyTicket();
    void cancelTicket();
};

void CinemaTicketSystem::control_panel(){
    cout << "\n\n\t\t\t\tЗдравствуйте, у вас есть следующие доступные функции:";
    cout << "\n\n1. Добавить новый фильм";
    cout << "\n2. Показать все доступные фильмы";
    cout << "\n3. Добавить нового пользователя";
    cout << "\n4. Купить билет";
    cout << "\n5. Отменить покупку билета";
    cout << "\n6. Выйти";
}

void CinemaTicketSystem::addMovie(){
    fstream file;
    int currentID = 0;
    string movieName;
    cout << "Введите название фильма: ";
    cin >> movieName;
    
    bool isValid = true;
    //  Введите в эти кавычки расположение файла где находиться "movies.txt"
    file.open("/Users/myrzanizimbetov/Desktop/cpp-projects/Nfactorial/movies.txt", ios::in);
    if(file.is_open()){
        std::string line;
        while(getline(file, line)){
            if(line.find(movieName) != std::string::npos){
                cout << "Фильм который Вы ввели уже существует! \n";
                isValid = false;
            }
            else{
                if(isdigit(line[0])){
                    currentID++;
                }
            }
        }
        currentID++;
        file.close();
    }
    
    if(isValid){
        //  Введите в эти кавычки расположение файла где находиться "movies.txt"
        file.open("/Users/myrzanizimbetov/Desktop/cpp-projects/Nfactorial/movies.txt", ios::app);
        if(file.is_open()){
            file << to_string(currentID) + " " + movieName + "\n\n";
            file.close();
        }
    } else{
        addMovie();
    }
}

void CinemaTicketSystem::showAllMovies(){
    fstream file;
    //  Введите в эти кавычки расположение файла где находиться "movies.txt"
    file.open("/Users/myrzanizimbetov/Desktop/cpp-projects/Nfactorial/movies.txt", ios::in);
    cout << "\n\n\t\t\t\tДоступные фильмы для Вас:\n";
    if(file.is_open()){
        string line;
        while(getline(file, line)){
            if(line != ""){
                cout << line << endl;
            }
        }
        file.close();
    }
}

void CinemaTicketSystem::addUser(){
    fstream file;
    int currentID = 0;
    string username;
    cout << "Введите никнейм: ";
    cin >> username;
    
    bool isValid = true;
    //  Введите в эти кавычки расположение файла где находиться "users.txt"
    file.open("/Users/myrzanizimbetov/Desktop/cpp-projects/Nfactorial/users.txt", ios::in);
    if(file.is_open()){
        std::string line;
        while(getline(file, line)){
            if(line.find(username) != std::string::npos){
                cout << "Никнейм который Вы ввели уже существует! \n\n";
                isValid = false;
            }
            else{
                if(isdigit(line[0])){
                    currentID++;
                }
            }
        }
        currentID++;
        file.close();
    }
    
    if(isValid){
        //  Введите в эти кавычки расположение файла где находиться "users.txt"
        file.open("/Users/myrzanizimbetov/Desktop/cpp-projects/Nfactorial/users.txt", ios::app);
        if(file.is_open()){
            file << to_string(currentID) + " " + username + "\n";
            file.close();
        }
        cout << "\n\nПоздравляем! Вы зарегистрировались на нашей системе!" << endl;
        cout << "Ваш никнейм: " + username << endl;
        cout << "Ваш идентификатор: " + to_string(currentID) << "\n\n";
    } else{
        addUser();
    }
}

void CinemaTicketSystem::buyTicket(){
    int userId, movieId, ticketId = 0;
    
    cout << "Введите Ваш идентификатор пользователя: ";
    cin >> userId;
    bool isUserExist = false;
    fstream userFile;
    //  Введите в эти кавычки расположение файла где находиться "users.txt"
    userFile.open("/Users/myrzanizimbetov/Desktop/cpp-projects/Nfactorial/users.txt", ios::in);
    if(userFile.is_open()){
        std::string line;
        while(getline(userFile, line)){
            string ID = line;
            for(char i : line){
                if(i == ' '){
                    break;
                }
                ID += i;
            }
            if(ID != "" && stoi(ID) == userId){
                isUserExist = true;
            }
        }
        userFile.close();
    }
    
    bool isMovieExist = false;
    if(isUserExist){
        cout << "Введите идентификатор фильма: ";
        cin >> movieId;
        
        fstream movieFile;
        //  Введите в эти кавычки расположение файла где находиться "movies.txt"
        movieFile.open("/Users/myrzanizimbetov/Desktop/cpp-projects/Nfactorial/movies.txt", ios::in);
        if(movieFile.is_open()){
            std::string line;
            while(getline(movieFile, line)){
                string ID = line;
                for(char i : line){
                    if(i == ' '){
                        break;
                    }
                    ID += i;
                }
                if(ID != "" && stoi(ID) == movieId){
                    isMovieExist = true;
                }
            }
            movieFile.close();
        }
    }
    
    if(isUserExist == true && isMovieExist == true){
        vector<string> lines;
        fstream file;
        //  Введите в эти кавычки расположение файла где находиться "tickets.txt"
        file.open("/Users/myrzanizimbetov/Desktop/cpp-projects/Nfactorial/tickets.txt", ios::in);
        if(file.is_open()){
            std::string line;
            while(getline(file, line)){
                if(line == ""){
                    continue;
                }
                else{
                    lines.push_back(line);
                }
            }
            ticketId = stoi(lines.back()) + 1;
            file.close();
        }
        
        //  Введите в эти кавычки расположение файла где находиться "tickets.txt"
        file.open("/Users/myrzanizimbetov/Desktop/cpp-projects/Nfactorial/tickets.txt", ios::app);
        if(file.is_open()){
            std::string line;
            file << to_string(ticketId) + "\n";
            file.close();
            cout << "\n\nПоздравляем! Вы купили билет!" << endl;
            cout << "Ваш идентификатор: " + to_string(ticketId) << "\n\n";
        }
    }
    else{
        cout << "\n\nНе существует такого идентификатора пользователя или фильма." << endl;
        buyTicket();
    }
}

void CinemaTicketSystem::cancelTicket(){
    int ticketId;
    cout << "Введите идентификатор билета: ";
    cin >> ticketId;
    
    bool isExist = false;
    
    vector<string> lines;
    fstream file;
    //  Введите в эти кавычки расположение файла где находиться "tickets.txt"
    file.open("/Users/myrzanizimbetov/Desktop/cpp-projects/Nfactorial/tickets.txt", ios::in);
    if(file.is_open()){
        std::string line;
        while(getline(file, line)){
            if(line == ""){
                continue;
            }
            else if(stoi(line) == ticketId){
                isExist = true;
            }
            else{
                lines.push_back(line);
            }
        }
        file.close();
    }
    
    if(isExist == false){
        cout << "\n\nНе существует билета с таким идентификатором!" << endl;
        cancelTicket();
    }
    else{
        //  Введите в эти кавычки расположение файла где находиться "tickets.txt"
        file.open("/Users/myrzanizimbetov/Desktop/cpp-projects/Nfactorial/tickets.txt", ios::out | ios::trunc);
        file.close();
        
        //  Введите в эти кавычки расположение файла где находиться "tickets.txt"
        file.open("/Users/myrzanizimbetov/Desktop/cpp-projects/Nfactorial/tickets.txt", ios::app);
        if(file.is_open()){
            for(int i = 0; i < lines.size(); i++){
                file << lines[i] << endl;
            }
            file.close();
        }
        
        cout << "\n\nУспешно отменено!" << endl;
    }
}

void CinemaTicketSystemRecord(){
    int choice;
    string x, y;
    CinemaTicketSystem a;
    
    while(1){
        a.control_panel();
        cout << "\n\nВведите свой выбор : ";
        cin >> choice;
        switch (choice) {
            case 1:
                do {
                    a.addMovie();
                    cout << "\n\nХотите еще добавить" << " другой фильм? " "(да/нет) : ";
                    cin >> x;
                } while (x == "да");
                break;
            
            case 2:
                a.showAllMovies();
                break;
            
            case 3:
                a.addUser();
                break;
                
            case 4:
                a.buyTicket();
                break;
                
            case 5:
                a.cancelTicket();
                break;
                
            case 6:
                exit(0);
                break;
            
            default:
                cout << "\n\nНедоступный выбор1\n";
        }
    }
}

int main(){
    CinemaTicketSystemRecord();
    return 0;
}
