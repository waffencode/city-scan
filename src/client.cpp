#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <iomanip>
#include <fstream>
#include "client.h"

void client::m_show()
{
    SetConsoleTitle("Database Manager - ScanCity");
    std::cout << "Выберите действие, введя соответствующее число:" << std::endl;
    std::cout << "\t1 - Вывести данные об инфраструктурных объектах" << std::endl;
    std::cout << "\t2 - Добавить новые данные об инфраструктурном объекте" << std::endl;
    std::cout << "\t3 - Стереть данные об инфраструктурном объекте" << std::endl;
    std::cout << "\t4 - Справка" << std::endl;
    std::cout << "\tESC - Завершить работу программы" << std::endl;
}

void client::m_clearData()
{
    char key;
    std::cout << "\nВведите ключ (чтобы вернуться назад, нажмите ESC):" << std::endl;
    key = _getch();
    if ((int)key == 27) 
    {
        return;
    }
    else 
    {
        std::vector<std::string> links = _data_interface->read_link();
        size_t i = 0;
        for (const auto& link : links)
        {
            std::cout << "[" << ++i << "] " << link << std::endl; 
        }

        std::cout << "\n\t Введите номер ссылки для удаления её из списка отслеживаемых узлов" << std::endl;

        std::cin >> i;
        if (i <= links.size())
        {
            std::ofstream ofs;
            ofs.open("links.txt", std::ofstream::out | std::ofstream::trunc);
            ofs.close();

            links.erase(links.begin() + i - 1);
            for (const auto& link : links)
            {
                write_link(link);
            }
        }

        return;
    }
}

void client::m_offer()
{
    char desicion;
    std::cout << "\tДля выхода введите любой символ" << std::endl;
    desicion = _getch();
    switch (desicion)
    {
        default: return;
    }
}

void client::m_showDatabase()
{
    system("CLS");
    std::cout << "Database Manager [Version 1.0]" << std::endl << std::endl;
    char desicion;
    std::cout << "Выберите способ вывода:" << std::endl;
    std::cout << "\t1 - Показать все данные, сохраненные в базе" << std::endl;
    std::cout << "\t2 - Показать данные, относящиеся к транспортной системе" << std::endl;
    std::cout << "\t3 - Показать данные, относящиеся к системе водоснабжения" << std::endl;
    std::cout << "\t4 - Показать данные, относящиеся к системе электроснабжения" << std::endl;
    std::cout << "\tESC - Вернуться в начало" << std::endl << std::endl;
    do
    {
        desicion = _getch();
        switch (desicion)
        {
            case 49://1
            {
                std::cout << "Отслеживаемые объекты:" << std::endl;
                auto docs = _db->fetch_data();
                for (auto doc : docs)
                {
                    std::cout << "Объект: " << doc["name"] << "; Время записи: " << doc["timestamp"] << std::endl;
                }
                m_offer();
                return;
            }
            case 50:
            {
                std::cout << "Отслеживаемые объекты транспорта:" << std::endl;
                auto docs = _db->fetch_data("type like 'transport'");
                for (auto doc : docs)
                {
                    std::cout << "Объект: " << doc["name"] << "; Время записи: " << doc["timestamp"] << std::endl;
                }
                m_offer();
                return;
            }
            case 51:
            {
                std::cout << "Отслеживаемые объекты водоснабжения:" << std::endl;
                auto docs = _db->fetch_data("type like 'water'");
                for (auto doc : docs)
                {
                    std::cout << "Объект: " << doc["name"] << "; Время записи: " << doc["timestamp"] << std::endl;
                }
                m_offer();
                return;
            }
            case 52:
            {
                std::cout << "Отслеживаемые объекты энергетической инфраструктуры:" << std::endl;
                auto docs = _db->fetch_data("type like 'energy'");
                for (auto doc : docs)
                {
                    std::cout << "Объект: " << doc["name"] << "; Время записи: " << doc["timestamp"] << std::endl;
                }
                m_offer();
                return;
            }
            case 27://ESC
                return;
            default:
                std::cout <<"\""<< desicion << "\" - Неверный формат введенного значения, попробуйте ещё раз.\n";
        }
    } while(1);
}

void client::m_addNewData()
{
    system("CLS");
    std::cout << "Database Manager [Version 1.0]" << std::endl << std::endl;
    char desicion;
    std::cout << "Выберите действие:" << std::endl;
    std::cout << "\t1 - Ввести ссылку на endpoint API инфраструктурного объекта" << std::endl;
    std::cout << "\tESC - Вернуться в начало" << std::endl << std::endl;
    do
    {
        desicion = _getch();
        switch (desicion)
        {
            case 49:
            {
                std::cout << "\t Введите ссылку на endpoint API инфраструктурного объекта:" << std::endl;
                
                std::string link;
                std::cin >> link;
                write_link(link);
                return;
            }
            case 27://0
                return;
            default:
                std::cout <<"\""<< desicion << "\" - Неверный формат введенного значения, попробуйте ещё раз.\n";
        }
    } while(1);
}

void client::m_aboutProgram()
{
    system("CLS");
    std::cout << std::setw(60) << "О ПРОГРАММЕ" << std::endl;
    std::cout << "Database Manager - программа для взаимодействия с базой данных системы мониторинга городской инфраструктуры." << std::endl <<
    "Позволяет добавлять в базу новые данные об объектах, выводить на экран, редактировать и удалять существующие." << std::endl <<
    "Version 1.0\n2023\n\n";

    std::cout << "Нажмите любую клавишу чтобы продолжить" << std::endl;
    _getch();
}

void client::menu()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    do
    {
        _data_interface->request_all();
        system("CLS");
        std::cout << "Database Manager [Version 1.0]" << std::endl << std::endl;
        m_show();
        char desicion;
        desicion = _getch();
        switch (desicion)
        {
            case 49://1
                m_showDatabase();
                break;
            case 50:
                m_addNewData();
                break;
            case 51:
                system("CLS");
                std::cout << "Database Manager [Version 1.0]" << std::endl;
                m_clearData();
                break;
            case 52:
                m_aboutProgram();
                break;
            case 27://ESC
                exit(0);
                break;
            default:
                std::cout <<"\""<< desicion << "\" - Неверный формат введенного значения, попробуйте ещё раз.";
                std::cout << "\nНажмите любую клавишу чтобы продолжить" << std::endl;
                desicion = _getch();
                break;
        }
    } while(1);
}

void client::write_link(std::string link)
{
    std::ofstream file("links.txt", std::ios::app);
    file << std::endl << link;
    file.close();
}