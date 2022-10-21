
#include <iostream>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int l_staples = 0;
    int r_staples = 0;
    int all_l_staplcount = 0;
    int all_r_staplcount = 0;
    int middl_of_exp = 0;
    int l_stapl_aftmid = 0;
    int r_stapl_aftmid = 0;
    int i = 0;
    char exp[] = "))))))))(((99((00(hh))hhg)jj))";
    middl_of_exp = sizeof(exp) / 2;
    bool check_mid = i == middl_of_exp;
    bool check_staple = exp[i] == '(' || ')';
    for (i ; i < sizeof(exp); i++)
    {
        if (check_mid == false)
        {
            if (check_staple)
            {
                l_staples = exp[i] == '(' ? ++l_staples : l_staples;
                r_staples = exp[i] == ')' ? ++r_staples : r_staples;
                check_mid = i == middl_of_exp;
            }
        }
        else
        {
            if (check_staple)
            {
                l_stapl_aftmid = exp[i] == '(' ? ++l_stapl_aftmid : l_stapl_aftmid;
                r_stapl_aftmid = exp[i] == ')' ? ++r_stapl_aftmid : r_stapl_aftmid;
            }
        }

    }
    all_l_staplcount = l_staples + l_stapl_aftmid;
    all_r_staplcount = r_staples + r_stapl_aftmid;
    if (all_l_staplcount > all_r_staplcount)
        cout << "Открывающих скобок больше" ;
    else if (all_l_staplcount == all_r_staplcount)
        cout << "Поровну";
    else
        cout << "Закрывающих скобок больше";
    if (all_l_staplcount > all_r_staplcount && l_staples > l_stapl_aftmid)
        cout << "  слева" << " на " << l_staples - r_staples ;
    else if (all_l_staplcount == all_r_staplcount)
        cout << "";
    else if (all_l_staplcount > all_r_staplcount && l_staples < l_stapl_aftmid)
        cout << "  справа" << " на " << l_stapl_aftmid - r_stapl_aftmid;
    else
        cout << "";
    if (all_l_staplcount < all_r_staplcount && r_staples > r_stapl_aftmid)
        cout << "  слева" << " на " << r_staples - l_staples;
    else if (all_l_staplcount == all_r_staplcount)
        cout << "";
    else if (all_l_staplcount < all_r_staplcount && r_staples < r_stapl_aftmid)
        cout << "  справа" << " на " << r_stapl_aftmid - l_stapl_aftmid ;
    else
        cout << "";
    return 0;
}

