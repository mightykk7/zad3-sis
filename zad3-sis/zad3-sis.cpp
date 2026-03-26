// zad3-sis.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

union dopInfo {
    bool isVoen;
    char homeAddress[100];
};
struct People {
    char FIO[80];
    int birthyear;
    char gender[10];
    char familystatus[50];
    dopInfo info;
};

int main()
{
    setlocale(0, "rus");
    People peoples[8];
    strcpy_s(peoples[0].FIO, "Иванов Иван Иванович");
    peoples[0].birthyear = 2004;
    strcpy_s(peoples[0].gender, "муж");
    strcpy_s(peoples[0].familystatus, "женат");
    peoples[0].info.isVoen = true;

    strcpy_s(peoples[1].FIO, "Максимов Максим Максимович");
    peoples[1].birthyear = 2000;
    strcpy_s(peoples[1].gender, "муж");
    strcpy_s(peoples[1].familystatus, "разведён");
    peoples[1].info.isVoen = true;

    strcpy_s(peoples[2].FIO, "Иванова Мария Ивановна");
    peoples[2].birthyear = 1999;
    strcpy_s(peoples[2].gender, "жен");
    strcpy_s(peoples[2].familystatus, "замужем");
    strcpy_s(peoples[2].info.homeAddress, "ул. Ленина, д.15");

    strcpy_s(peoples[3].FIO, "Петрова Анастасия Сергеевна");
    peoples[3].birthyear = 2003;
    strcpy_s(peoples[3].gender, "жен");
    strcpy_s(peoples[3].familystatus, "в браке не состояла ни разу");
    strcpy_s(peoples[3].info.homeAddress, "ул. Ленина, д.30");

    strcpy_s(peoples[4].FIO, "Стрелкова Анна Андреевна");
    peoples[4].birthyear = 1998;
    strcpy_s(peoples[4].gender, "жен");
    strcpy_s(peoples[4].familystatus, "разведена");
    strcpy_s(peoples[4].info.homeAddress, "ул. Восточная, д.37");

    strcpy_s(peoples[5].FIO, "Ивницкая Диана Максимовна");
    peoples[5].birthyear = 1997;
    strcpy_s(peoples[5].gender, "жен");
    strcpy_s(peoples[5].familystatus, "замужем");
    strcpy_s(peoples[5].info.homeAddress, "ул. Восточная, д.37");

    strcpy_s(peoples[6].FIO, "Мезенцева Юлия Николаевна");
    peoples[6].birthyear = 1995;
    strcpy_s(peoples[6].gender, "жен");
    strcpy_s(peoples[6].familystatus, "замужем");
    strcpy_s(peoples[6].info.homeAddress, "ул. Восточная, д.37");

    strcpy_s(peoples[7].FIO, "Мезенцев Данил Витальевич");
    peoples[7].birthyear = 1993;
    strcpy_s(peoples[7].gender, "муж");
    strcpy_s(peoples[7].familystatus, "женат");
    peoples[7].info.isVoen = true;
   

    People marriedwomen[8];
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (strcmp(peoples[i].gender,"жен") == 0 && strcmp(peoples[i].familystatus, "замужем") ==0) {
            marriedwomen[count] = peoples[i];
            count++;
        }
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (marriedwomen[j].birthyear > marriedwomen[j+1].birthyear) {
                People kopia = marriedwomen[j];
                marriedwomen[j] = marriedwomen[j+1];
                marriedwomen[j + 1] = kopia;
            }
        }
    }
    std::cout << "Упорядоченный по году рождения список женщин, которые состоят в браке.";
    std::cout << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << "ФИО: " << marriedwomen[i].FIO <<" " << marriedwomen[i].birthyear << " " << marriedwomen[i].info.homeAddress<< std::endl;
    }
}