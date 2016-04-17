#include "functions.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


comp::comp()
{
 staff = 0;
 power = 0;
 unit =0;
 name = new char[100];
 ip = new char[16];
}

comp::comp(int pow,int un, int st, char *nam, char *IP ) 
{
   
   power = pow;
   unit = un;
   staff = st;
   name = new char[100];
   strcpy (name,nam);
   ip = new char[16];
   strcpy (ip,IP);
   
}

int comp::zamena (int pow, int un, char *nam, char *IP)
{
   power = pow;
   unit = un;
   name = new char[100];
   strcpy (name,nam);
   ip = new char[16];
   strcpy (ip,IP);
}   

int comp::show() 
{
   std::cout << "\n Number staff's:" << staff;
   std::cout << "\n Name: " << name ;
   std::cout << "\n IP: " << ip;
   std::cout << "\n Power: " << power;
   std::cout << "\n Unit: " << unit ;

}


int comp::operator > (comp ob2)
{return (staff > ob2.staff);}


int comp::operator < (comp ob2)
{return (staff < ob2.staff);}


comp& comp::operator = (comp & ob)
{
   staff=ob.staff;
   power=ob.power;
   unit=ob.unit;
   name = new char[100];
   strcpy (name,ob.name);
   ip = new char[16];
   strcpy (ip,ob.ip);
   return *this;

}



int comp::get_unit()
{
 return unit;
}


int comp::get_power()
{
 return power;
}

int comp::get_staff()
{
 return staff;
}


char* comp::get_name()
{
 return name;
}

char* comp::get_ip()
{
 return ip;
}

/*comp::~comp()
{
 delete []name;
 delete []ip;//? []
}*/


int menu()// МЕНЮ 
{
     int c;
     
     cout << "\n\n";
     cout << "1. Считать базу" << "\n";
     cout << "2. Добавить компьютер в шкаф" << "\n";
     cout << "3. Вывести информацию" << "\n";
     cout << "4. Редактирование" << "\n";
     cout << "5. Удалить шкаф" << "\n";
     cout << "6. Удалить компьютер" << "\n";
     cout << "7. Поиск" << "\n";
     cout << "8. Показать мощность шкафа" << "\n";
     cout << "9. Сохранить информацию" << "\n";
     cout << "10. Выход" << "\n";
     
     do {
     
     cout << "\n" << "Введите нужный номер: ";
     cin >> c;
     
     } while (c<1||c>10);
       return c;
   

}




int add (vector<comp> &ob) //ДОБАВЛЕНИЕ КОМПЬЮТЕРА
{
   int pow, un, st;
   char *nam = new char [100], *IP = new char [100];
   
  
   
   cout <<"\n" <<"Введите номер шкафа" << "\n";
   cin >> st;
   
   cout << "Введите имя компьютера" << "\n";
   cin >> nam;
   
   cout << "Введите мощность компьютера" << "\n";    
   cin >> pow;
   
   cout << "Введите размеры компьютера(в юнитах)" << "\n";
   cin >> un;
   
   if (ogran_unit(ob,st,un)==1){cout << "\n" << "Компьютер с такими размерами не влазит в шкаф" << "\n" ; return 1;}
   
   cout << "Введите IP адрес" << "\n";
   cin >> IP;
   
   ob.push_back (comp(pow,un,st, nam, IP ));
   
   return 1;

}

int ogran_unit(vector<comp> &ob, int s, int u)
{
 int i,summ=0;
 
 for (i=0;i<ob.size();i++)
           {
            if (s==ob[i].get_staff()) summ=summ+ob[i].get_unit();
           }
 if ((summ+u)>40) return 1;
 return 0;


}

int see (vector<comp> &ob) // ВЫВОД
{
  int i;
  
  if (ob.empty()==0) {    
       for(i=0;i<ob.size();i++)
          
           {
            cout<<"\n\n";
            ob[i].show();
           };
           
           std::cout<<"\n";
  }


}


int sortirovka(vector<comp> &ob)
{

 comp cop;
 int i, flag;
 
if (ob.empty()==0){ 
 while (1) 
 {

 flag=0;

 for (i=0;i<ob.size()-1;i++)
   { 
     if (ob[i]>ob[i+1])
           {
            cop=ob[i+1];
            ob[i+1]=ob[i];
            ob[i]=cop;
            flag=1;
           }
   }        
    if (flag==0) break;
  }
  } if(ob.empty()==1) cout <<"\n"<< "Нет элементов в базе!";  
   return 1;       
}


int zapis_f(std::ostream & stream,const comp &ob)
{
    stream<<ob.staff<<"\n";
    stream<<ob.name<<"\n";
    stream<<ob.power<<"\n";
    stream<<ob.unit<<"\n";
    stream<<ob.ip;
    return 1;
}

int write(std::vector<comp> &ob, char *namefile) // Запись в файл
{
  int i;
  std::ofstream fox(namefile, ios::out | ios::binary);
  if(ob.size()>0)
            {
              zapis_f(fox,ob[0]);
              for (i=1;i<ob.size();i++)
               {
                fox<<"\n";
                zapis_f(fox,ob[i]);
               }   
            }
  fox.close();
  cout <<"\n" << "Данные сохранены в файле: "<< namefile <<"\n";
}

int chtenie_f (std::istream & stream,comp &ob )
{
    stream>>ob.staff;
    stream>>ob.name;
    stream>>ob.power;
    stream>>ob.unit;
    stream>>ob.ip;
    return 1;
}



int read(std::vector<comp> &ob, char *namefile) //чтение из файла
{
 std::ifstream fin(namefile,ios::in|ios::binary );
 int i=0;
 ob.clear();
 if(!fin)
        {
         return 0;
        }
  ob.push_back(comp());      
  while (1)
          {
           if (fin.eof()==1) break;
           ob.push_back(comp());
           chtenie_f(fin, ob[i]);
           i++;
          }
          ob.pop_back();      
  fin.close();
  cout << "\n"<<"Данные успешно считаны! "<<"\n";
  return 1;      

}


int redact(vector<comp> &ob)
{
 int pow, un, st, shk,flag,i;
 char *nam = new char [100], *IP = new char [100], *cmp = new char[100]; 
 
 cout <<"\n" <<"Введите номер шкафа: ";
 cin >> shk;
 
 cout <<"\n" << "Введите название компьютера: ";         
                       cin >> cmp;
 
        for (i=0;i<ob.size();i++)
          {
             if ((ob[i].get_staff()==shk) && ((strcmp(cmp,ob[i].get_name())==0) ))
                      {
                                       
                                        cout <<"\n" <<"Введите новое название компьютера: ";
                                        cin >> nam;
                                           
                                        cout <<"\n" << "Введите новую мощность компьютера: ";    
                                        cin >> pow;
    
                                        cout <<"\n" << "Введите новые размеры компьютера: ";
                                        cin >> un;
   
                                        cout <<"\n"<< "Введите новый IP адрес: ";
                                        cin >> IP;
   
                                        ob[i].zamena( pow,un, nam, IP);
                                        flag=1;
                                        break;  
                                       
                      }  
          }
         if (flag==0) cout << "\n" << "!!!Нет такого компьютера!!!";
return 1;          
}

int destaff (vector<comp> &ob)// Удалить шкаф
{
  int shk,i,index,flag=0;
  cout << "Введите номер шкафа, кторый хотите удалить: ";
  cin >> shk;
  
  
  
     
      for (i=0;i<ob.size();i++)
                 {
                  if (shk==ob[i].get_staff()){ index=i;
                  break; }
                 }
      while(1)
          {
           if (shk==ob[index].get_staff()) {ob.erase(ob.begin()+index);flag=1; } 
           else break;
           
           
           if (index>=ob.size()) break;  
          }   
if (flag==1) cout << "\n" << "Шкаф удален!";
else cout << "\n" << "Нет такого шкафа!";
return 1;
}



int delcomp (vector<comp> &ob) // Удалить компьютер
{
     int shk, i,flag;
     char  *cmp = new char[100];  
    
     cout << "\n"<<"Введите номер шкафа, в котором хотите удалить компьютер: ";
     cin >> shk;

     cout << "\n" <<"Введите название компьютера: ";
     cin >> cmp;
     
              for (i=0;i<ob.size();i++)
                              {
                                flag=0;
                                if ((shk==ob[i].get_staff())&&(strcmp(cmp,ob[i].get_name())==0))
                                                              {
                                                               ob.erase(ob.begin()+i);
                                                               flag=1;
                                                               cout << "\n" << "Компьютер удален"; 
                                                               break;
                                                              }
                                                             
                              }
if (flag==0) {  cout << "\n" << "!!!Нет такого компьютера!!!"; }                                                           
return 1;              
}


int search (vector<comp> &ob)
{
  int pow,un,st,c;
  char *name = new char[100], *IP = new char[100]; 
  char po;
  cout <<"\n" << "Введите атрибут, по которому будете искать" << "\n";
  cout <<"\n" << "1. Название компьютера";
  cout <<"\n" << "2. Мощность компьютера";
  cout <<"\n" << "3. Размеры компьютера";
  cout <<"\n" << "4. Номер шкафа";
  cout <<"\n" << "5. IP адрес";
  cout <<"\n" << "6. Выход"; 
  do {
     
     cout << "\n" << "Введите нужный номер: " << "\n";
     cin >> c;
     
     } while (c<1||c>6);
 
  
  
  
       
         po=c;
         
         switch(po)
              {
               case 1:searchname(ob);
               break;
               
               case 2:searchpower(ob);
               break;
               
               case 3:searchunit(ob);
               break;
               
               case 4:searchstaff(ob);
               break;
               
               case 5:searchip(ob);
               break;
               
               case 6:return 1;
               break;
              }      
         

}


int searchname (vector<comp> &ob)
{
 int i,flag=0;
 char *cmp = new char[100];
 
 cout <<"\n" << "Введите название компьютера: ";
 cin >> cmp;
 
       for (i=0;i<ob.size();i++)
           {
            if (strcmp(cmp,ob[i].get_name())==0) {flag=1; cout << "\n"; ob[i].show();}
           }
if (flag==0) cout << "\n" << "Ничего не найдено" << "\n" ;            

return 1;
}



int searchip (vector<comp> &ob)
{
 int i,flag=0;
 char *IP = new char[100];
 
 cout <<"\n" << "Введите IP адрес: ";
 cin >> IP;
 
       for (i=0;i<ob.size();i++)
           {
            if (strcmp(IP,ob[i].get_ip())==0) {flag=1;cout << "\n"; ob[i].show();}
           }
if (flag==0) cout << "\n" << "Ничего не найдено" << "\n" ;            

return 1;
}


int searchunit (vector<comp> &ob)
{
 int i,flag=0,un;
 
 cout <<"\n" << "Введите размеры компьютера: ";
 cin >> un;
 
       for (i=0;i<ob.size();i++)
           {
            if (un==ob[i].get_unit()) {flag=1;cout << "\n"; ob[i].show();}
           }
if (flag==0) cout << "\n" << "Ничего не найдено" << "\n" ;            

return 1;
}



int searchstaff (vector<comp> &ob)
{
 int i,flag=0,st;
 
 cout <<"\n" << "Введите номер шкафа: ";
 cin >> st ;
 
       for (i=0;i<ob.size();i++)
           {
            if (st==ob[i].get_staff()) {flag=1;cout << "\n"; ob[i].show();}
           }
if (flag==0) cout << "\n" << "Ничего не найдено" << "\n" ;            

return 1;
}



int searchpower (vector<comp> &ob)
{
 int i,flag=0,pow;
 
 cout <<"\n" << "Введите мощность компьютера: ";
 cin >> pow ;
 
       for (i=0;i<ob.size();i++)
           {
            if (pow==ob[i].get_power()) {flag=1;cout << "\n"; ob[i].show();}
           }
if (flag==0) cout << "\n" << "Ничего не найдено" << "\n" ;            

return 1;
}


int get_power_staff (vector<comp> &ob)
{
   int i,st,summ=0,flag=0;  
  
   cout << "Введите номер шкафа, у которого хотите узнать мощность: ";
   cin >> st; 
   
   for (i=0;i<ob.size();i++)
           {
            if (st==ob[i].get_staff()) {summ=summ+ob[i].get_power();flag=1;}
            
           }
   if (flag==1) cout <<"\n" <<"Мощность "<< st << " шкафа равна: " << summ;
   else cout << "\n" <<"Нет такого шкафа";
   
   return 1;

} 