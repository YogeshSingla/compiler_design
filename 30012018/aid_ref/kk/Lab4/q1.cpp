#include <bits/stdc++.h>

using namespace std;

int main()
{
        map< string , pair<int,int> > mp;
        
        //begin code
        mp["begin"].first = 1;
        mp["begin"].second = 0;

        //end code
        mp["end"].first = 2;
        mp["end"].second = 0;

        //if code
        mp["if"].first = 3;
        mp["if"].second = 0;

        //else code
        mp["else"].first = 4;
        mp["else"].second = 0;

        //then code
        mp["then"].first = 5;
        mp["then"].second = 0;

        //== code
        mp["=="].first = 8;
        mp["=="].second = 1;
        
        //!= code
        mp["!="].first = 8;
        mp["!="].second = 2;

        //>= code
        mp[">="].first = 8;
        mp[">="].second = 3;

        //<= code
        mp["<="].first = 8;
        mp["<="].second = 4;

        //< code
        mp["<"].first = 8;
        mp["<"].second = 5;

        //> code
        mp[">"].first = 8;
        mp[">"].second = 6;

        vector< char > identifier;
        vector< int >  constant;

        while(true)
        {
                string s;
                cin >> s;

                if(s == "begin" or s == "end" or s == "else" or s == "then")
                {        
                        cout << mp[s].first << " " << mp[s].second << endl;
                        continue;
                }
                if(s == "if")
                {
                        string s1;
                        cout << mp[s].first << " " << mp[s].second << endl;
                        cin >> s1;
                        for(int i = 0; i < s1.length(); i++)
                        {
                                if(s1[i] >= '1' and s1[i] <= '9')
                                        cout << "constant\n";
                                else if(s1[i] >= 'a' and s1[i] <= 'z')
                                        cout << "identifier\n";
                                else if(s1[i] == '=' and s1[i+1] == '=' and i < s1.length())
                                        cout << mp["=="].first << " " << mp["=="].second << endl;
                                else if(s1[i] == '!' and s1[i+1] == '=' and i < s1.length())
                                        cout << mp["!="].first << " " << mp["!="].second << endl;
                                else if(s1[i] == '>' and s1[i+1] == '=' and i < s1.length())
                                        cout << mp[">="].first << " " << mp[">="].second << endl;
                                else if(s1[i] == '<' and s1[i+1] == '=' and i < s1.length())
                                        cout << mp["<="].first << " " << mp["<="].second << endl;
                                else if(s1[i] == '<')
                                        cout << mp["<"].first << " " << mp["<"].second << endl;
                                else if(s1[i] == '>')
                                        cout << mp[">"].first << " " << mp[">"].second << endl;
                                else if(s1[i] == '(' or s1[i] == ')')
                                        continue;
                        }
                }
                for(int i = 0;i < s.length(); ++i)
                {
                        if(s[i] >= 'a' and s[i] <= 'z')
                        {        
                                cout << "It is an identifier\n";
                                identifier.push_back(s[i]);
                        }
                        
                        if(s[i] >= '0' and s[i] <= '9')
                        {
                                cout << "It is a constant\n";
                                constant.push_back(s[i] - '0');
                        }
                        else if(s[i] == '=' and s[i+1] == '=' and i < s.length())
                                cout << mp["=="].first << " " << mp["=="].second << endl;
                        else if(s[i] == '!' and s[i+1] == '=' and i < s.length())
                                cout << mp["!="].first << " " << mp["!="].second << endl;
                        else if(s[i] == '>' and s[i+1] == '=' and i < s.length())
                                cout << mp[">="].first << " " << mp[">="].second << endl;
                        else if(s[i] == '<' and s[i+1] == '=' and i < s.length())
                                cout << mp["<="].first << " " << mp["<="].second << endl;
                        else if(s[i] == '<')
                                cout << mp["<"].first << " " << mp["<"].second << endl;
                        else if(s[i] == '>')
                                cout << mp[">"].first << " " << mp[">"].second << endl; 
						                      
                }

        }
        return 0;
}
