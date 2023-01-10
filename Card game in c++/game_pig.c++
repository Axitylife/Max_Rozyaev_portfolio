Maxim Chernikov, [02.12.2022 13:12]
#include <iostream>
#include <string>
#include <list>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;


int main()
{

    setlocale(LC_ALL, "Russian");

    int kartvIgre; 
    int vsego_igrokov = 3;
    cout << "Введите колличетсво карт";
  
    bool exit = false;
    while (exit == false)
    {
       cin >> kartvIgre;
       if (kartvIgre % vsego_igrokov == 0)
       {
           exit = true;
           
       }
       else
       {
            cout << "Есть остаток" << endl;
       }
    } 
    
    
    int* koloda = new int[kartvIgre];

    cout << "Чтобы автоматически перемешать карты нажмите: 1 " << endl;

    int xy;
    cin >> xy;
     

    if (xy == 1)
    {
      
        for (int i = 0; i < kartvIgre; i++) 
        {
            koloda[i] = i + 1;

        }

        for (int i = 0; i < kartvIgre; i++)
        {
            swap(koloda[i], koloda[rand() % kartvIgre]); // Переделать рандом
        }

    }
     else
    {
        for (int i = 0; i < kartvIgre; i++)
        {
            cin >> koloda[i]; 
        }
        cout << "=====================" << endl;

    }
    
    for (int i = 0; i < kartvIgre; i++)
    {
       
        cout << koloda[i] << endl;
    }

    int j = 0;

    list<int> koloda_pervogo_igroka;
    list<int> koloda_vtorogo_igroka;
    list<int> koloda_tretiego_igroka;


    for (int i = 0; i < kartvIgre; i++)
    {      
        if (j > 2)
        {
            j = 0;
        }
        switch (j)
        {
        case 0:
        {
            koloda_pervogo_igroka.push_front(koloda[i]);
        }
            break;
        case 1:
        {
            koloda_vtorogo_igroka.push_front(koloda[i]);
        }
            break;
        case 2:
        {
            koloda_tretiego_igroka.push_front(koloda[i]);
        }
            break;
        default: cout << "error в свиче раздачи карт " << endl;
            break;
        }      
        j++;
    }
 
        int winner = 0;
        int hodi = 1;

        int tekusea_karta_pervogo_igroka = 0;
        int tekusea_karta_vtoroga_igroka = 0;
        int tekusea_karta_tretiego_igroka = 0;

        bool player1win = false;
        bool player2win = false;
        bool player3win = false;

        while (hodi < 1000000 && !player1win && !player2win && !player3win)   //=======++
        {                                                                                   //Запрос < чем заполненое время + 10 = крутимся, если нет, то вываливаемся. >> 
            
            if (koloda_pervogo_igroka.size() > 0)
            {
                tekusea_karta_pervogo_igroka = koloda_pervogo_igroka.front();
                koloda_pervogo_igroka.pop_front();
            }
            else
            {
                tekusea_karta_pervogo_igroka = 0;
            }
            if (koloda_vtorogo_igroka.size() > 0)
            {
                tekusea_karta_vtoroga_igroka = koloda_vtorogo_igroka.front();
                koloda_vtorogo_igroka.pop_front();
            }
            else
            {
                tekusea_karta_vtoroga_igroka = 0;
            }
            if (koloda_tretiego_igroka.size() > 0)
            {
                tekusea_karta_tretiego_igroka = koloda_tretiego_igroka.front();
                koloda_tretiego_igroka.pop_front();
            }
            else
            {
                tekusea_karta_tretiego_igroka = 0; 
            }

            //=======================================================

Maxim Chernikov, [02.12.2022 13:12]
if (tekusea_karta_pervogo_igroka == kartvIgre)//1
            {
                if (tekusea_karta_vtoroga_igroka == 1)
                {
                    if (tekusea_karta_pervogo_igroka > 0)
                    {
                        koloda_vtorogo_igroka.push_back(tekusea_karta_pervogo_igroka);  // вставил в конец списка (колоды) карту
                    }
                    if (tekusea_karta_vtoroga_igroka > 0)
                    {
                        koloda_vtorogo_igroka.push_back(tekusea_karta_vtoroga_igroka);
                    }
                    if (tekusea_karta_tretiego_igroka>0)
                    {
                        koloda_vtorogo_igroka.push_back(tekusea_karta_tretiego_igroka);
                    }
                }
                else if (tekusea_karta_tretiego_igroka == 1)
                {
                    if (tekusea_karta_pervogo_igroka > 0)
                    {
                        koloda_tretiego_igroka.push_back(tekusea_karta_pervogo_igroka);  // вставил в конец списка (колоды) карту
                    }
                    if (tekusea_karta_vtoroga_igroka > 0)
                    {
                        koloda_tretiego_igroka.push_back(tekusea_karta_vtoroga_igroka);
                    }
                    if (tekusea_karta_tretiego_igroka > 0)
                    {
                        koloda_tretiego_igroka.push_back(tekusea_karta_tretiego_igroka);
                    } 
                }
                else
                {
                    if (tekusea_karta_pervogo_igroka > 0)
                    {
                        koloda_pervogo_igroka.push_back(tekusea_karta_pervogo_igroka);  // вставил в конец списка (колоды) карту
                    }
                    if (tekusea_karta_vtoroga_igroka > 0)
                    {
                        koloda_pervogo_igroka.push_back(tekusea_karta_vtoroga_igroka);
                    }
                    if (tekusea_karta_tretiego_igroka > 0)
                    {
                        koloda_pervogo_igroka.push_back(tekusea_karta_tretiego_igroka);
                    }   
                }
            }
            else if (tekusea_karta_vtoroga_igroka == kartvIgre)//2
            {
                if (tekusea_karta_pervogo_igroka == 1)
                {    
                    if (tekusea_karta_pervogo_igroka > 0)
                    {
                        koloda_pervogo_igroka.push_back(tekusea_karta_pervogo_igroka);  // вставил в конец списка (колоды) карту
                    }
                    if (tekusea_karta_vtoroga_igroka > 0)
                    {
                        koloda_pervogo_igroka.push_back(tekusea_karta_vtoroga_igroka);
                    }
                    if (tekusea_karta_tretiego_igroka > 0)
                    {
                        koloda_pervogo_igroka.push_back(tekusea_karta_tretiego_igroka);
                    }
                }
                else if (tekusea_karta_tretiego_igroka == 1)
                {
                    if (tekusea_karta_pervogo_igroka > 0)
                    {
                        koloda_tretiego_igroka.push_back(tekusea_karta_pervogo_igroka);  // вставил в конец списка (колоды) карту
                    }
                    if (tekusea_karta_vtoroga_igroka > 0)
                    {
                        koloda_tretiego_igroka.push_back(tekusea_karta_vtoroga_igroka);
                    }
                    if (tekusea_karta_tretiego_igroka > 0)
                    {
                        koloda_tretiego_igroka.push_back(tekusea_karta_tretiego_igroka);
                    }
                }
                else
                {
                    if (tekusea_karta_pervogo_igroka > 0)
                    {
                        koloda_vtorogo_igroka.push_back(tekusea_karta_pervogo_igroka);  // вставил в конец списка (колоды) карту
                    }
                    if (tekusea_karta_vtoroga_igroka > 0)
                    {

Maxim Chernikov, [02.12.2022 13:12]
koloda_vtorogo_igroka.push_back(tekusea_karta_vtoroga_igroka);
                    }
                    if (tekusea_karta_tretiego_igroka > 0)
                    {
                        koloda_vtorogo_igroka.push_back(tekusea_karta_tretiego_igroka);
                    }
                }
            
            }
            else if (tekusea_karta_tretiego_igroka == kartvIgre) //3 
            {
                if (tekusea_karta_pervogo_igroka == 1)
                {
                    if (tekusea_karta_pervogo_igroka > 0)
                    {
                        koloda_pervogo_igroka.push_back(tekusea_karta_pervogo_igroka);  // вставил в конец списка (колоды) карту
                    }
                    if (tekusea_karta_vtoroga_igroka > 0)
                    {
                        koloda_pervogo_igroka.push_back(tekusea_karta_vtoroga_igroka);
                    }
                    if (tekusea_karta_tretiego_igroka > 0)
                    {
                        koloda_pervogo_igroka.push_back(tekusea_karta_tretiego_igroka);
                    }
                }
                else if (tekusea_karta_vtoroga_igroka == 1)
                {
                    if (tekusea_karta_pervogo_igroka > 0)
                    {
                        koloda_vtorogo_igroka.push_back(tekusea_karta_pervogo_igroka);  // вставил в конец списка (колоды) карту
                    }
                    if (tekusea_karta_vtoroga_igroka > 0)
                    {
                        koloda_vtorogo_igroka.push_back(tekusea_karta_vtoroga_igroka);
                    }
                    if (tekusea_karta_tretiego_igroka > 0)
                    {
                        koloda_vtorogo_igroka.push_back(tekusea_karta_tretiego_igroka);
                    }
                }
                else
                {
                    if (tekusea_karta_pervogo_igroka > 0)
                    {
                        koloda_tretiego_igroka.push_back(tekusea_karta_pervogo_igroka);  // вставил в конец списка (колоды) карту
                    }
                    if (tekusea_karta_vtoroga_igroka > 0)
                    {
                        koloda_tretiego_igroka.push_back(tekusea_karta_vtoroga_igroka);
                    }
                    if (tekusea_karta_tretiego_igroka > 0)
                    {
                        koloda_tretiego_igroka.push_back(tekusea_karta_tretiego_igroka);
                    }
                }

Maxim Chernikov, [02.12.2022 13:12]
}
            else
            {
                if (tekusea_karta_pervogo_igroka > tekusea_karta_vtoroga_igroka && tekusea_karta_pervogo_igroka > tekusea_karta_tretiego_igroka)
                {
                    if (tekusea_karta_pervogo_igroka > 0)
                    {
                        koloda_pervogo_igroka.push_back(tekusea_karta_pervogo_igroka);  // вставил в конец списка (колоды) карту
                    }
                    if (tekusea_karta_vtoroga_igroka > 0)
                    {
                        koloda_pervogo_igroka.push_back(tekusea_karta_vtoroga_igroka);
                    }
                    if (tekusea_karta_tretiego_igroka > 0)
                    {
                        koloda_pervogo_igroka.push_back(tekusea_karta_tretiego_igroka);
                    }
                }
                else if (tekusea_karta_vtoroga_igroka > tekusea_karta_pervogo_igroka && tekusea_karta_vtoroga_igroka > tekusea_karta_tretiego_igroka)
                {
                    if (tekusea_karta_pervogo_igroka > 0)
                    {
                        koloda_vtorogo_igroka.push_back(tekusea_karta_pervogo_igroka);  // вставил в конец списка (колоды) карту
                    }
                    if (tekusea_karta_vtoroga_igroka > 0)
                    {
                        koloda_vtorogo_igroka.push_back(tekusea_karta_vtoroga_igroka);
                    }
                    if (tekusea_karta_tretiego_igroka > 0)
                    {
                        koloda_vtorogo_igroka.push_back(tekusea_karta_tretiego_igroka);
                    }
                }
                else
                {
                    if (tekusea_karta_pervogo_igroka > 0)
                    {
                        koloda_tretiego_igroka.push_back(tekusea_karta_pervogo_igroka);  // вставил в конец списка (колоды) карту
                    }
                    if (tekusea_karta_vtoroga_igroka > 0)
                    {
                        koloda_tretiego_igroka.push_back(tekusea_karta_vtoroga_igroka);
                    }
                    if (tekusea_karta_tretiego_igroka > 0)
                    {
                        koloda_tretiego_igroka.push_back(tekusea_karta_tretiego_igroka);
                    }
                }
            }
            if (koloda_pervogo_igroka.empty() && koloda_tretiego_igroka.empty()) 
            {
                player2win = true;
                winner = 2;
                break;
            }
            if (koloda_vtorogo_igroka.empty() && koloda_tretiego_igroka.empty()) 
            {
                player1win = true;
                winner = 1;
                break;
            }
            if (koloda_vtorogo_igroka.empty() && koloda_pervogo_igroka.empty()) 
            {
                player3win = true; 
                winner = 3;
                break;
            }
            
            hodi++;//==========++
        }
        koloda_vtorogo_igroka.empty();
        koloda_pervogo_igroka.empty();
        koloda_tretiego_igroka.empty();

        cout << "Игра окончена за " << hodi << " ход." << endl;

        if (winner == 0) 
        {
            cout << "Результат игры : ничья " << endl;
        }
        else 
        {
            cout << "Выйграл игрок номер " << winner << endl;
        }


        return 0;
}