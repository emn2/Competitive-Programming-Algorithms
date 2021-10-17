#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--){
        int day;
        string month;

        cin >> day >> month;

        if(month == "Mar" && day >= 21) cout << "Aries\n";
        else if(month == "Apr" && day <= 20) cout << "Aries\n";

        else if(month == "Apr" && day >= 21) cout << "Taurus\n";
        else if(month == "May" && day <= 20) cout << "Taurus\n";

        else if(month == "May" && day >= 21) cout << "Gemini\n";
        else if(month == "Jun" && day <= 21) cout << "Gemini\n";

        else if(month == "Jun" && day >= 22) cout << "Cancer\n";
        else if(month == "Jul" && day <= 22) cout << "Cancer\n";

        else if(month == "Jul" && day >= 23) cout << "Leo\n";
        else if(month == "Aug" && day <= 22) cout << "Leo\n";

        else if(month == "Aug" && day >= 23) cout << "Virgo\n";
        else if(month == "Sep" && day <= 21) cout << "Virgo\n";

        else if(month == "Sep" && day >= 22) cout << "Libra\n";
        else if(month == "Oct" && day <= 22) cout << "Libra\n";

        else if(month == "Oct" && day >= 23) cout << "Scorpio\n";
        else if(month == "Nov" && day <= 22) cout << "Scorpio\n";

        else if(month == "Nov" && day >= 23) cout << "Sagittarius\n";
        else if(month == "Dec" && day <= 21) cout << "Sagittarius\n";

        else if(month == "Dec" && day >= 22) cout << "Capricorn\n";
        else if(month == "Jan" && day <= 20) cout << "Capricorn\n";

        else if(month == "Jan" && day >= 21) cout << "Aquarius\n";
        else if(month == "Feb" && day <= 19) cout << "Aquarius\n";
        
        else if(month == "Feb" && day >= 20) cout << "Pisces\n";
        else if(month == "Mar" && day <= 20) cout << "Pisces\n";
    }
}
