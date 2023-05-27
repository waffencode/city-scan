#include <iostream>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <iomanip>

#include "client.h"
#include "database.h"

void client::m_show()
{
    SetConsoleTitle("Database Manager - ScanCity");
    std::cout << "Выберите действие, введя соответствующее число:" << std::endl;
    std::cout << "\t1 - Вывести данные об инфраструктурных объектах" << std::endl; //вывести данные
    std::cout << "\t2 - Добавить новые данные об инфраструктурном объекте" << std::endl; //добавить объект
    std::cout << "\t3 - Редактировать данные об инфраструктурном объекте" << std::endl;//редактировать данные объекта
    std::cout << "\t4 - Стереть данные об инфраструктурном объекте" << std::endl;//удалить данные
    std::cout << "\t5 - Создать резервную копию данных об инфраструктурном объекте" << std::endl;//экспортировать
    std::cout << "\t6 - Справка" << std::endl;//справка
    std::cout << "\tESC - Завершить работу программы" << std::endl;
}

void client::m_editData()
{
    char key;
    std::cout << "\nВведите ключ (чтобы вернуться назад, нажмите ESC):" << std::endl; //у каждого типа свои поля
    key = _getch();
    if ((int)key == 27) 
    {
        return;
    }
    else 
    {
        std::cout << "\nЗДЕСЬ НАДО НАПИСАТЬ ФУНКЦИЮ ДЛЯ РЕДАКТИРОВАНИЯ ПО КЛЮЧУ" << std::endl;
        _getch();
    }
}

void client::m_clearData()
{
    char key;
    std::cout << "\nВведите ключ (чтобы вернуться назад, нажмите ESC):" << std::endl; //у каждого типа свои поля
    key = _getch();
    if ((int)key == 27) 
    {
        return;
    }
    else 
    {
        std::cout << "\nЗДЕСЬ НАДО НАПИСАТЬ ФУНКЦИЮ ДЛЯ УДАЛЕНИЯ ПО КЛЮЧУ" << std::endl;
        _getch();
    }
}

void client::m_offer()
{ //редактировать, удалить
    char desicion;
    std::cout << "\nХотите редактировать или удалить запись?\n";
    std::cout << "\t1 - Редактировать" << std::endl;
    std::cout << "\t2 - Удалить" << std::endl;
    std::cout << "\tЛюбой другой символ - Выход в меню" << std::endl;
    desicion = _getch();
    switch (desicion)
    {
        case 49://1
            m_editData(); //редактирование по ключу
            return;
        case 50:
            m_clearData();//удаление по ключу
            return;
        default:          //выход в меню
            return;
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
                std::cout << "ЗДЕСЬ НАДО НАПИСАТЬ ФУНКЦИЮ ДЛЯ ВЫВОДА ВСЕХ ДАННЫХ" << std::endl;
                m_offer();
                return;
            case 50:
                std::cout << "ЗДЕСЬ НАДО НАПИСАТЬ ФУНКЦИЮ ДЛЯ ВЫВОДА ДАННЫХ О ТРАНСПОРТЕ" << std::endl;
                m_offer();
                return;
            case 51:
                std::cout << "ЗДЕСЬ НАДО НАПИСАТЬ ФУНКЦИЮ ДЛЯ ВЫВОДА ДАННЫХ О ВОДОСНАБЖЕНИИ" << std::endl;
                m_offer();
                return;
            case 52:
                std::cout << "ЗДЕСЬ НАДО НАПИСАТЬ ФУНКЦИЮ ДЛЯ ВЫВОДА ДАННЫХ ОБ ЭЛЕКТРОСНАБЖЕНИИ" << std::endl;
                m_offer();
                return;
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
    std::cout << "Выберите тип объекта:" << std::endl; //у каждого типа свои поля
    std::cout << "\t1 - Объект транспортной системы" << std::endl;
    std::cout << "\t2 - Объект системы водоснабжения" << std::endl;
    std::cout << "\t3 - Объект системы электроснабжения" << std::endl;
    std::cout << "\t4 - Другое" << std::endl;
    std::cout << "\tESC - Вернуться в начало" << std::endl << std::endl;
    do
    {
        desicion = _getch();
        switch (desicion)
        {
            case 49://1 транспортная
                std::cout << "ЗДЕСЬ НАДО НАПИСАТЬ ФУНКЦИЮ ДЛЯ ДОБАВЛЕНИЯ ДАННЫХ О ТРАНСПОРТЕ" << std::endl;
                //return; //раскомментировать, когда будет написана функция
                break;
            case 50:// водоснабжение
                std::cout << "ЗДЕСЬ НАДО НАПИСАТЬ ФУНКЦИЮ ДЛЯ ДОБАВЛЕНИЯ ДАННЫХ О ВОДОСНАБЖЕНИИ" << std::endl;
                //return; //раскомментировать, когда будет написана функция
                break;
            case 51:// электроснабжение
                std::cout << "ЗДЕСЬ НАДО НАПИСАТЬ ФУНКЦИЮ ДЛЯ ДОБАВЛЕНИЯ ДАННЫХ ОБ ЭЛЕКТРОСНАБЖЕНИИ" << std::endl;
                //return; //раскомментировать, когда будет написана функция
                break;
            case 52:// Другое (например, добавление нового типа)
                std::cout << "ЗДЕСЬ НАДО НАПИСАТЬ ФУНКЦИЮ ДЛЯ ДОБАВЛЕНИЯ ЧЕГО-НИБУДЬ" << std::endl;
                //return; //раскомментировать, когда будет написана функция
                break;
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
                m_editData();
                break;
            case 52:
                system("CLS");
                std::cout << "Database Manager [Version 1.0]" << std::endl;
                m_clearData();
                break;
            case 54:
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