#include <fstream>
class comp {
                   
    int power, unit, staff;
    char *name, *ip;
    
    public:
    comp();
    comp(int pow, int un, int st, char *nam, char *IP);
    int zamena(int pow, int un, char *nam, char *IP);
   // ~comp();
    int operator>(comp ob2);
    int operator<(comp ob2);
    comp& operator=(comp & ob);
    int show();
    char* get_ip();
    int get_unit();
    int get_power();
    int get_staff();
    char* get_name();
    friend int zapis_f (std::ostream & stream,const comp &ob);
    friend int chtenie_f (std::istream & stream,comp &ob ); 
};
