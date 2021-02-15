#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

string toInfix(vector<string>& tokens){
    string token;
    string result;
    string a,b;

    token = tokens[tokens.size()-1];
    tokens.pop_back();

    if ((token[token.length()-1] >= '0') && (token[token.length()-1] <= '9'))
        return token;

    else{
        if (token != "abs"){
            a = toInfix(tokens);
            b = toInfix(tokens);
            result = a + " " + token + " " + b;
        }
        else{
            a = toInfix(tokens);
            result = token + "(" + a + ")";
        }

        if ((token[token.length()-1] == '+') || ( token[token.length()-1] == '-')){
            result = "(" + result + ")";
        }
        return result;
    }
}

float evaluate(vector<string>& tokens){
    string token;
    string a,b;

    token = tokens[tokens.size()-1];

    if ((token[token.length()-1] >= '0') && (token[token.length()-1] <= '9'))
        return stof(token);
    else{

        a = evaluate(tokens);
        b = evaluate(tokens);


        if (token[token.length()-1] == '+'){
            if (token != "abs")
                return stof(a) + stof(b);
            else
                return abs(stof(a) + stof(b));
        }
        else if (token[token.length()-1] == '-'){
            if (token != "abs")
                return stof(a) - stof(b);
            else
                return abs(stof(a) - stof(b));
        }
        if (token[token.length()-1] == '*'){
            if (token != "abs")
                return stof(a) * stof(b);
            else
                return abs(stof(a) * stof(b));
        }
        if (token[token.length()-1] == '/'){
            if (token != "abs")
                return stof(a) / stof(b);
            else
                return abs(stof(a) / stof(b));
        }
    }
}

const vector<string> split(const string& s,const char& c){
    vector<string> tokens;
    string buffer = {""};

    for (auto n : s){
        if (n != c)
            buffer += n;
        else
            if((n == c) && (buffer != "")){
                tokens.push_back(buffer);
                buffer = "";
            }
    }

    if (buffer != "")
        tokens.push_back(buffer);

    return tokens;
}

int main()
{
    string polish = "+ * 3 4 abs * 5 -3";
    string infix;
    float value;
    vector<string> tokens{split(polish, ' ')};

    reverse(tokens.begin(),tokens.end());

    cout << "Polish notation: " << polish << endl;
    infix = toInfix(tokens);
    cout << "Infix notation: " << infix << endl;
    value = evaluate(tokens);
    cout << "Value of expression: " << value << endl;

    return 0;
}
