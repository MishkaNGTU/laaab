#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "functions.h"

using namespace std;


int main()
{
 char po;
 vector <comp> ob;
 char *namefile = new char[100];
 
 cout<< "\n" <<"Укажите имя файла: ";
 cin>>namefile;
 ifstream fin(namefile); 
 if (fin)
        {
         fin.close();
         cout<<"\n" <<"Такой файл уже существует" << "\n";
        }
  for (;;)
         {
          po = menu();
          switch (po)
                   {
                    case 1:read(ob,namefile);
                    break;
                    
                    case 2:add(ob);
                    break;
                    
                    case 3: sortirovka(ob); see(ob) ;
                    break;
                    
                    case 4:redact(ob) ;
                    break;
                    
                    case 5:destaff(ob);
                    break;
                    
                    case 6: delcomp(ob);
                    break;
                    
                    case 7: search(ob);
                    break;
                    
                    case 8: get_power_staff(ob);
                    break;
                    
                    case 9:write(ob,namefile);
                    break;
                      
                    case 10: return 1;
                  
                   
                   
                   
                   
                   } 
         }
  
return 0;


}
