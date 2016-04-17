#include "comp.h"
#include <vector>

int menu();
int add(std::vector<comp> &ob);
int see(std::vector<comp> &ob);
int sortirovka(std::vector<comp> &ob);
int write(std::vector<comp> &ob, char *namefile);
int read(std::vector<comp> &ob, char *namefile);
int redact(std::vector<comp> &ob);
int destaff(std::vector<comp> &ob);
int delcomp(std::vector<comp> &ob);
int search(std::vector<comp> &ob);
int searchname(std::vector<comp> &ob);
int searchpower(std::vector<comp> &ob);
int searchunit(std::vector<comp> &ob);
int searchip(std::vector<comp> &ob);
int searchstaff(std::vector<comp> &ob);
int get_power_staff(std::vector<comp> &ob);
int ogran_unit (std::vector<comp> &ob, int s, int u);