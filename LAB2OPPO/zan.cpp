#include "zan.h"
void Zan::load_txt(std::istream& ist)
{
    currdate.set_Date(ist);
    currtime.set_time(ist);
    ist >> name;
    //check_name;
}

void Zan::print_txt(std::ostream& ost)
{
    currdate.print_Date();
    ost << currtime.hour << ":" << currtime.min << " ";
    ost << name << " ";
}

void Zan::check_name()
{
    std::string AllowedSymbols = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
    for (int i = 0; i < name.size(); i++)
    {
        if (AllowedSymbols.find(name[i]) == -1)
        {
            {throw std::runtime_error("Symbols not allowed"); }
        }
    }
}
