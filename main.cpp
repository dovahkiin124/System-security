#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
     int a,i=0;
     string text,old,password1,password2,pass,name,password0,age,user,word,word1;
     string creds[2],cp[2];
     cout<<"       Security System(Sistem de securitate)          "<<endl;
     cout<<"________________________________"<<endl;
     cout<<"|      1.Inregistreaza-te       |"<<endl;
     cout<<"|      2.Logheaza_te            |"<<endl;
     cout<<"|      3.Schimba parola         |"<<endl;
     cout<<"|      4.Sfarsit de program     |"<<endl;
     cout<<"_______                     _____"<<endl;
    do
    {
        cout<<endl<<endl;
        cout<<"Introdu optiunea dorita:-";
        cin>>a;
        switch(a)
        {
            case 1:
            {
                cout<<"________________________"<<endl<<endl;
                cout<<"|_____Inregistreaza-te__|"<<endl;
                cout<<"|_______________________|"<<endl;
                cout<<"Introduceti numele dumneavoastra:";
                cin>>name;
                cout<<"\nIntroduceti parola dumneavoastra:";
                cin>>password0;
                cout<<"\nIntroduceti varsta dumneavoastra:";
                cin>>age;

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()){
                    of1<<name<<"\n";
                    of1<<password0;
                    cout<<"Inregistrare facuta cu succes!"<<endl;

                }
                break;
            }
            case 2: {
                i = 0;
                cout << "________________________" << endl << endl;
                cout << "|_____Logheaza-te_______|" << endl;
                cout << "|_______________________|" << endl;

                ifstream of2;
                of2.open("file.txt");
                cout << "Introduceti numele dumneavoastra:";
                cin >> user;
                cout << "\nIntroduceti parola dumneavoastra:";
                cin >> pass;

                if (of2.is_open()) {
                    while (!of2.eof())
                    {
                        while (getline(of2, text)) {
                            istringstream iss(text);
                            iss >> word;
                            creds[i] = word;
                            i++;

                        }

                        if (user == creds[0] && pass == creds[1])
                        {
                            cout << "------Logarea a fost facuta cu succes-----";
                            cout << endl << endl;
                            cout << "Detalii: " << endl;
                            cout << "Nume: " + name << endl;
                            cout << "Parola: " + pass << endl;
                            cout << "Varsta: " + age << endl;


                        } else
                        {
                            cout << endl << endl;
                            cout << "Parola sau numele sunt gresite" << endl;
                            cout << "|      1.apasati 2 pentru logare               |" << endl;
                            cout << "|      1.apasati 3 pentru a schimba parola     |" << endl;

                        }
                    }
                }
                break;
            }

            case 3:
            {
                i=0;
                cout<<"__________Schimba parola_____________"<<endl;

                ifstream of0;
                of0.open("file.txt");
                cout<<"Introdu vechea parola:";
                cin>>old;
                if(of0.is_open())
                {
                    while(of0.eof())
                    {
                        while(getline(of0,text))
                        {
                            istringstream iss(text);
                            iss>>word1;
                            cp[i]=word1;
                            i++;

                        }

                        if(old==cp[1])
                        {
                            of0.close();

                            ofstream of1;
                            if(of1.is_open())
                            {
                                cout<<"Introduceti noua voastra parola:";
                                cin>>password1;
                                cout<<"Introduceti noua voastra parola din now:";
                                cin>>password2;
                                if(password1==password2)
                                {
                                    of1<<cp[0]<<"\n";
                                    of1<<password1;
                                    cout<<"Parola introdusa cu succes"<<endl;

                                }
                                else
                                {
                                    of1<<cp[0]<<"\n";
                                    of1<<old;
                                    cout<<"Parola introdusa nu se potriveste"<<endl;

                                }

                            }
                            else
                            {
                                cout<<"Introduceti o parola valida"<<endl;

                            }
                            break;
                        }

                    }
                }
            }
            case 4:
            {
                cout<<"___________Va multumim!_____________";
                break;

            }

            default:
            {
                cout<<"Introduceti o optiune valida!"<<endl;

            }

        }

    }
    while(a!=4);
    return 0;

}
